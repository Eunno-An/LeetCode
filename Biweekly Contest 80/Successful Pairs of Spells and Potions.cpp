class Solution {
public:
    /*
    문제:
    두개의 양수 배열 spells와 potions가 주어진다. 각각 길이는 n과 m이다.
    spells[i]는 i번째 spell의 힘을 나타내고,
    potions[j]는 j번쨰 potion의 힘을 나타낸다.    
    마찬가지로 success라는 정수가 주어진다.
    spell과 potion의 pair는 만약 적어도 그들의 힘의 곱이 success를 넘어가면 성공적이라고 할 수 있다
    Return: pairs를 리턴해라. pairs[i] = i번째 spell과 successful한 pair를 형성하는 potion의 갯수
    
    제한:
    n과 m의 길이가 1 이상 십만 이하.
    spells[i]와 potions[i]도 1 이상 십만 이하. spells[i] * potions[i] 은 최대 백억. 따라서 long long을 써야 한다.
    
    
    해결방법:
    1) 브루트포스
    -> O(n*m) : 백억.
    2) 이분탐색
    -> 어짜피 개수만 저장하는 거니까, potions를 정렬하고 spells[i] * potions[j] >= success인 최소 j를 찾으면 된다.
    -> 유의할 점은 potions[i]는 중복될 수도 있다는 것이다.
    //
    */
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ret;
        sort(potions.begin(), potions.end());
        for(int i=0; i<n; i++){
            int now = spells[i];
            long long find = success / now;
            
            //여 부분 중요하다!
            if(success % now != 0)
                find += 1;
            
            //lower_bound 하면 된다.
            int idx = lower_bound(potions.begin(), potions.end(), find) - potions.begin();
            
            ret.push_back(m-idx);
        }
        return ret;
    }
};
