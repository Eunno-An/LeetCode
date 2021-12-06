//34번째 for문 부터 논리적 오류가 있다.
//예시: Input: aaaaa일 때를 생각해 보기.
      //재귀 순서 1
        //(3, 4)
        //(2, 3), (2, 4)
        //(1, 2), (1, 3), (1, 4)
        //(0, 1), (0, 2), (0, 3), (0, 4)
      
        
      //재귀 순서 2
        //(0, 1), (0, 2), (0, 3), (0, 4)
        //(1, 2), (1, 3), (1, 4)
        //(2, 3), (2, 4)
        //(3, 4)
      
        //우리는 작은 것(cache[i+1][j-1])부터 관찰해서, 더 큰 팰린드롬(cache[i][j])를 판단하는 것이므로
        //재귀 순서를 1과 같이 짜야 한다.
        //내가 짠 건 2번째임.
      
        //그리고 i<j 조건도 부합해야 한다.
class Solution {
public:
    //점화식 정의
    //P(i, j) 
    //true if the substring Si... Sj is a palindrome
    //false otherwise
    
    //Therefore
    //P(i, j) = P(i+1, j-1) ans Si == sj
    
    //기조 정의
    //P(i, i) = true;
    //P(i, i+1) = (Si == S(i+1)) 
   
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0)
            return "";
        
        bool cache[1001][1001];
        memset(cache, false, sizeof(cache));
        for(int i=0; i<n; i++)//기조정의
            cache[i][i] = true;
        
        for(int i=0; i<n-1; i++)
            if(s[i] == s[i+1])
                cache[i][i+1] = true;
        string ans="";
        ans += s[0]; // Input: "a" 인 경우의 예외처리
        
     
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j]){
                    if(j-i==1 || cache[i+1][j-1]){
                        cache[i][j] = true;
                        if(ans.size() < j-i+1){
                            ans = s.substr(i, j-i+1);
                        }    
                    }
                    
                }
            }
        }
        
       
        
        return ans;
        
    }
};
