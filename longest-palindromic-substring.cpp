//fail
//2차 복습 : 22 01 14. Fail 
class Solution {
public:
    /*
    문제:
    s라는 스트링이 주어지면, 가장 긴 팰린드롬 부분문자열을 구하여라.
    (팰린드롬: 뒤집어도 똑같은 문자열)
    
    핵심 아이디어:
    1)인덱스 i부터 j까지 뽑아서, 그게 팰린드롬인지 확인한다.
    팰린드롬인지 확인하는것은 i부터 j까지 문자열 요소중에 하나씩 뒤져보면서 확인한다.
    ->O(10억) = 10초
    
    2)DP
    isPalindrome(s, i, j) 함수를 호출하는 과정에서 너무 중복 탐색이 많이 일어난다.
    P(i, j) = s[i]...s[j]가 palindrome이라면 참을 리턴한다.
    점화식 P(i, j) = (P(i+1, j-1) && (S[i] == S[j]))이 성립한다.
    
    기저조건
    1. (i == j) true;
    2. P(i, i+1) = (S[i] ==  S[i+1])
    
    실수한점:
    DP까지는 생각했으나, 함수를 차분히 생각해야 하는데 막막해서 다가갈 엄두를 내지 못함.
    그리고 2중 for문 인덱싱 하는거 실수했음.
    */
    
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0)
            return "";
        
        bool cache[1001][1001];
        memset(cache, false, sizeof(cache));
        for(int i=0; i<n; i++)
            cache[i][i] = true;
        
        for(int i=0; i<n-1; i++)
            if(s[i] == s[i+1])
                cache[i][i+1]=true;
        
        string ans="";
        ans += s[0];//Input: "a"인 경우 예외처리
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j]){
                    if(j-i == 1 || cache[i+1][j-1]){
                        cache[i][j] = true;
                        if(ans.size() < j-i+1)
                            ans = s.substr(i, j-i+1);
                    }
                }
            }
        }
        
        return ans;   
    }
};
