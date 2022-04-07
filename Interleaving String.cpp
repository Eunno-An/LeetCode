1차 22-04-07 Fail
회고:
BruteForce로 잘못짰었음. 애초에..
  
  /*
  잘못짠 BruteForce
  bool help(string s1, string s2, string make, string s3){
        if(s1.empty())
            return (make + s2) == s3 ? true : false;
        if(s2.empty())
            return (make + s1) == s3 ? true : false;
        
        bool ret = false;
        for(int i=0; i<s1.size(); i++)
            for(int j=1; i + j<=s1.size(); j++)
                if(help(s1.substr(i+j), s2, make + s1.substr(i, j), s3)){
                    ret = true;
                    return ret;
                }
        for(int i=0; i<s2.size(); i++)
            for(int j=1; i+j <= s2.size(); j++)
                if(help(s1, s2.substr(i+j), make + s2.substr(i, j), s3)){
                    ret = true;
                    return ret;
                }
        return ret;
    }
    
   사실 위 코드는 이렇게 고칠 수 있다.
   bool help(string s1, string s2, string make, string s3){
        if(s1.empty())
            return (make + s2) == s3 ? true : false;
        if(s2.empty())
            return (make + s1) == s3 ? true : false;
        
        bool ret = false;
        
        if(help(s1.substr(1), s2, make + s1.substr(0, 1), s3)){
            ret = true;
            return ret;
        }
        
        if(help(s1, s2.substr(1), make + s2.substr(0, 1), s3)){
            ret = true;
            return ret;
        }
        return ret;
    }
    
    하지만 시간초과가 발생한다. 이래서 DP가 필요한데..
    내가 짠 잘못된 DP 코드는 이렇다.
    시간초과가 발생한다.
    int cache[101][101];
    bool help(string s1, int idx1, string s2, int idx2, string make, string s3){
        if(s1.empty())
            return (make + s2) == s3 ? true : false;
        if(s2.empty())
            return (make + s1) == s3 ? true : false;
        
        int& ret = cache[idx1][idx2];
        if(ret != -1)
            return ret == 1 ? true : false;
        
        if(help(s1.substr(1), 1, s2, 0, make + s1.substr(0, 1), s3)){
            ret = 1;
            return ret;
        }
        
        if(help(s1, 0, s2.substr(1), 1, make + s2.substr(0, 1), s3)){
            ret = 1;
            return ret;
        }
        
        return ret == 1? true : false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(cache, -1, sizeof(cache));
        if(s1.length() + s2.length() != s3.length())
            return false;
        
        
        string make = "";
        bool ret = help(s1, 0, s2, 0, make, s3);
        return ret;
    }
  */
  /*
  잘 굴러가는 코드 첨부*/
class Solution {
public:
    bool check(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==s1.length() and j==s2.length() and k==s3.length())
            return true;
        bool res=false;
        
        if(i!=s1.length())
            if(s1[i]==s3[k])
            res|=check(s1,s2,s3,i+1,j,k+1,dp);
        if(j!=s2.length())
            if(s2[j]==s3[k])
            res|=check(s1,s2,s3,i,j+1,k+1,dp);
        return dp[i][j]=res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(),m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        bool ans=check(s1,s2,s3,0,0,0,dp);
        return ans;
    }
};
