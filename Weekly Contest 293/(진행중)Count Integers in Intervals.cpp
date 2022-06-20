4.
intervals의 비어있는 set이 주어진다. 데이터구조를 구현해라.
-> intervals의 셋에 interval을 더한다.
-> 적어도 하나의 interval에서 존재하는 정수의 개수를 세라.

제한:
left와 right는 1 이상 십억 이하.
최대 add와 count에 대해서는 둘이 합쳐서 총 십만번 호출이 된다.
count는 최소 한번 호출된다.

해결방법:

생각의 흐름
integer들을 넣는건 쉽다.
1)구간의 해결 방법 두가지
-> add를 할 때마다 구간을 초기화 한다
-> count가 호출될 때마다 구간을 초기화 한다.(lazy propagation에서 생각해봄): add 5만, count 5만번 이라고 하면 25 * 10^8
= 25억이여서 time out 날 수도 있다.
-> 🎈add할 때마다 구간을 초기화 한다. 그떄 선형이 아니라 log로 줄이고, count가 호출되면 O(1)에 호출한다.

회고:
부족한점.

1. 마지막에 아이디어 생각은 했지만, map에도 lower_bound, upper_bound가 적용되는지 몰랐고, 그래서 할 수 가 없었다.
그리고 lower_bound와 upper_bound의 처음과 끝에 대한 예외처리도 어떻게 할줄을 몰라서 구현을 못했음.
그냥 모르는게 많았다.
2. iterator에 대한 지식! begin(iterator)와 prev(iterator)에 대한 지식이 없었다!
https://blog.naver.com/ytlee64/222643014441
이걸 참조하자. 이슈에 달아놓겠다.

class CountIntervals {
public:
    map<int, int> m;
    int cnt = 0;
    void add(int left, int right) {
        auto it = m.upper_bound(left);
        if (it != begin(m) && prev(it)->second >= left)
            it = prev(it);
        for (; it != end(m) && it->first <= right; m.erase(it++)) {
            left = min(left, it->first);
            right = max(right, it->second);
            cnt -= it->second - it->first + 1;
        }
        cnt += right - left + 1;
        m[left] = right;
    }
    int count() { return cnt; }
};
