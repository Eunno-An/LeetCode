정수 배열 nums와 original이 주어진다.
1번문제: 1분컷

2번문제:
0indexed의 이진 배열 nums가 주어진다. 길이는 n이다.
index i에 의해 왼쪽과 오른쪽으로 나뉘어 진다.(0 <= i <= n) i는 n과 같을수 있음에 주의하자.

nums_left = 0부터 i-1까지. nums_right = i부터 n-1까지
if i == 0 : nums_left is empty()
if i == n: nums_left  == nums

i의 division score라는 것은 nums_left에 있는 0의 개수와 nums_right에 있는 1의 개수의 총 합이다.

가능한 가장 높은 division score를 갖는 모든 distinct indices를 리턴해라.
순서는 상관없다.

제한:
1<=n<=100000(십만)

풀이:
1)가장 쉽게
모든 i에 대해서 왼쪽과 오른쪽을 선형 탐색 하면서 스코어를 판단한다.
->Time limit이 발생한다.

2)map을 이용한 개수 탐색 시간 줄이기
[1,0,1,0,1,1,0,1,0]
[4,0,2]
중요: multiset.erase(1)하면 1이란 요소가 다 지워진다!! 이것때메 오류났노.. 

3번문제:
k라는 길이를 가진 문자열 s가 주어지고, 정수 p와 m이 주어지는데,
hash(s, p, m) = (val(s[0]) * p0 + val(s[1]) * p1 + ... + val(s[k-1]) * pk-1) mod m.
이런 식이래
val(s[i])는 val('a') = 1이고, val('z') = 26임. 즉, 알파벳에서 s[i]의 인덱스.

s와 p, m, k, 그리고 hashValue가 주어지면, 
hash(sub, power, modulo) == hashValue를 만족하는
k길이의 s의 첫 부분문자열을 리턴해라
답은 항상 반드시 존재하니까 걱정 ㄴ

해결방법:
1)쉽게:
k길이만큼 substr따서, 
거기서 조건식을 검사한다.
시간복잡도는 괜찮을 것 같다.
단, OVERFLOW문제가 존재한다.
그래서 제곱을 할 때마다, mod하는 방식을 취해야 한다!!

class Solution {
public:
    long long binPow(int p, int i, int m) {
        long long res = 1;
        while (i > 0) {
            if (i & 1)
                res = res * p % m;
            p = (unsigned long long)p * p % m;
            i >>= 1;
        }
        return res;
    }
int getHashVal(string s, int p, int m) {
    int substrHash = 0;
    for (int i = 0; i < s.size(); i++) {
        unsigned long long ull_i = s[i] - 'a' + 1;//'a'는 1이라는것을 명심해!
        substrHash += ((ull_i % m) * (binPow(p, i, m) % m)) % m;
    }
    return substrHash;
}
string subStrHash(string s, int power, int modulo, int k, int hashValue) {
    string subStr = s.substr(0, k);
    int initVal = getHashVal(subStr, power, modulo);
    cout << initVal << endl;
    if(initVal == hashValue)
        return subStr;
    unsigned long long nowVal = initVal;
    for (int i = 1; i <= s.size() - k; i++) {
        nowVal -= ((s[i-1]-'a'+1));
        nowVal %= modulo;
        nowVal = nowVal / power;
        nowVal += ((s[i+k-1]-'a'+1) % modulo *  binPow(power, k-1, modulo) % modulo) % modulo;
        if(nowVal == hashValue)
            return s.substr(i, k);
    }
    return "OOPS!";
}
};
