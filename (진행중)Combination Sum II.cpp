class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //target이 되는 조합을 찾아라. 조합은 유니크하다.
        //candidates에서 사용되는건 딱 한번씩만 사용될 수 있다.
        
        //1 1 2 5 6 7 10
        
        //1 1 1 1, target = 3인 경우, 1 1 1이 네개 생기게 될 수도 있음.
        //그럼 pair를 이용해서 pair<숫자, 숫자의 등장 횟수>로 해서 각 수들을 사용할지 안사용할지 따져보면 2^N 시간이 걸리겠네. 그럼 2^100승이니까 안될거야.
        
        //ret[0] = 0을 만드는 가짓수들
        //ret[1] = 1을 만드는 셋들
        //ret[2] = 2를 만드는 셋들
        //...ret[i] = i를 만드는 셋들
        
        vector<int> chart(51);//chart[i] = count. i라는 수가 count만큼 등장한다. i는 최소 1, 최대 50이다.
        for(int i=0; i<candidates.size(); i++)
            chart[candidates[i]]++;
        
        vector<vector<vector<int>>> dp(target+1);
        dp[0] = {{}};
        for(int &i : candidates){
            for(int j=i; j<=target; j++){
                for(auto v : dp[j-i]){
                    if(chart[i]!=0){//i의 남은 횟수가 0이면 사용 불가??
                        v.push_back(i);
                        dp[j].push_back(v);
                        chart[i]--;
                    }
                }
            }
        }
        return dp[target];
    }
};
