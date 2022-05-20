1차 22-05-20 Fail
회고:
dp까진 했는데 dp 배열을 map으로 해버림. key는 string으로 해버리니까 시간초과가 남.
dp[i] = wordDict에 s의 i번째 인덱스로 끝나는 단어가 있는지?
s = "leetcode"

words = ["leet", "code"]

d[3] is True because there is "leet" in the dictionary that ends at 3rd index of "leetcode"

d[7] is True because there is "code" in the dictionary that ends at the 7th index of "leetcode" AND d[3] is True

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(), false);
        dp[0] = true;
        for(int i=0; i<=s.size(); i++){
            for(auto str: wordDict){
                if(dp[i]){
                    if(s.substr(i, str.size()).compare(str) == 0)
                        dp[i+str.size()]=true;
                }
            }
        }
        return dp[s.size()];
    }
    
    
};
