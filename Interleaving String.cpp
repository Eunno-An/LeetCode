1차 22-04-07 Fail
회고:
BruteForce로 잘못짰었음. 애초에..
  
2차 22-05-16 Fail
회고:
인덱스로 접근하는 것 까지는 잘 했으나
기저조건과 i1, i2에 대한 예외처리를 잘 못 하였음.
추가적으로, bool cache 2차원 배열로 사용하면 안됨. 왜냐하면 false라는 상태가 아직 안본상태이기도 하면서, 
interleaving이 아닌 경우 두개를 의미하기 때문임.
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

//2차 풀이 수정 코드
class Solution {
public:
    int cache[101][101];
    bool isInterleave(string& s1, string& s2, string& s3, int i1, int i2, int i3){

        
        if(i1 == s1.length() and i2 == s2.length() and i3 == s3.length())
            return true;
        
        int& ret = cache[i1][i2];
        if(ret != -1)
            return ret;
        bool res = false;
        
        if(i1 != s1.length() and s1[i1] == s3[i3])
            res |= isInterleave(s1, s2, s3, i1+1, i2, i3+1);
        if(i2 != s2.length() and s2[i2] == s3[i3])
            res |= isInterleave(s1, s2, s3, i1, i2+1, i3+1);
        return ret = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(cache, -1, sizeof(cache));
        return isInterleave(s1, s2, s3, 0, 0, 0);
    }
};
