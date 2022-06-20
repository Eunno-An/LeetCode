6분 33초
앨리스가 빌딩에 있는 몇몇의 층을 빌렸다.
이러한 층들 중에서 몇몇은 special floors가 되어야 한다고 다짐했다.
bottom과 top이라는 정수 두개가 주어진다. bottom~top까지의 모든 층을 빌렸다는 얘기이다.
special이라는 정수도 주어지는데, special[i]는 special 층을 의미한다.
special floor 없이 연속적인 층의 최대 수를 리턴해라.

제한:
special.length <= 십만
bottom <= special[i] <= top <= 십억
special의 모든 수는 유일하다.

해결방법:
구간을 다루는 문제.
1) 시뮬레이션
-> unordered_set<int>로 해서 special이 있는지 여부를 따진다. 그러면 십억의 시간복잡도가 나온다.


2) special을 sorting!
-> bottom이 첫번째 시작 인덱스가 되고, special부터 본다.
-> 그 다음에 연속되는 것은 special[0] + 1 ~ 그 다음 special[1]-1까지가 될 것.
-> 이런식으로 진행하면 시간 복잡도는 십만
-> 마지막에 top이랑 진행할 때는 top - start_idx 하고 +1을 해주어야 한다!

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int start_idx = bottom;
        int ret = -1;
        int n = special.size();
        int range;
        for(int i=0; i < n; i++){
            range = special[i] - start_idx;
            start_idx = special[i]+1;
            if(ret < range)
                ret = range;
            
        }
        range = top - start_idx + 1;
        if(ret < range)
            ret = range;
        return ret;
    }
};
