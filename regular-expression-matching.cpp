//정리
//해결방법 1: BruteForce
//1. 만약 이 문제가 *가 없었다면 단순히 반복문으로 해결해도 되는 문제
//2. 그러나 '*' 때문에, 재귀 형태로 접근이 필요해 보임.

/*
기저조건: 패턴을 다 썼을 때, s도 다 쓰면 일치.

재귀조건:
firstMatch: 첫번째 글자끼리 같은지 안같은지
1. p[0] == s[0] || p[0] == '.' : 첫번째 글자가 같거나, 패턴의 첫번째가 '.'일 때
이면서
2. s가 비어있지 않을 때!

IF
패턴이 두 글자 이상이고, 두번째 위치가 '*'일 때 (우리는 반드시 '*' 앞에 글자 하나가 온다는 것을 안다!)

1. '*'를 사용하지 않을때
-> isMatch(s, p.substr(2))
2. '*'를 한번 사용할 때
반드시 앞글자가 같아야 하고, s는 앞글자 하나를 사용했으며 패턴은 그대로 사용한다.
-> firstMatch && isMatch(s.substr(1), p);
둘 중에 하나만 같아도 일치하기 떄문에 
return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));

ELSE
만약 두번째 위치가 '*'가 아니거나 패턴이 한글자 일 때
return firstMatch && isMatch(s.substr(1), p.substr(1));

TimeComplexity : O(3 ^ max(m, n))
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        bool firstMatch = (!s.empty() && (p[0] == s[0] || p[0] == '.'));
        
        if(p.size() >= 2 && p[1] == '*')
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        else
            return firstMatch && isMatch(s.substr(1), p.substr(1));
    }
};

//완탐 함수 수정 및 추가
//DP(Top-down)
class Solution {
public:
    int dp[26][31];
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return helper(s, p, 0, 0);
    }
    bool helper(string s, string p, int i, int j){
        if(j == p.length()) return i == s.length();
        int& ret = dp[i][j];
        if(ret >= 0)
            return ret;
        
        bool firstMatch = (i<s.size() && (s[i] == p[j] || p[j] == '.'));
        
        if(j+1 < p.size() && p[j+1] == '*')
            ret = helper(s, p, i, j+2) || (firstMatch && helper(s, p, i+1, j));
        else
            ret = firstMatch && helper(s, p, i+1, j+1);
        
        return ret;
    }
};

//DP(Bottom-up)
//이게 제일 빠름. 4ms
class Solution {
public:
    int dp[26][31];
    bool isMatch(string s, string p) {
        memset(dp, 0, sizeof(dp));
        dp[s.size()][p.size()]=1;
        
        for(int i=s.size(); i>=0; i--){
            for(int j=p.size()-1; j>=0; j--){
                bool firstMatch = (i<s.size() && (p[j] == s[i] || p[j] == '.'));
                if(j+1 < p.size() && p[j+1] == '*')
                    dp[i][j] = dp[i][j+2] || (firstMatch && dp[i+1][j]);
                else
                    dp[i][j] = firstMatch && dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
    
};

