1차 22-04-03 Fail
조합 다루는 재귀를 잘 못하는것같다.
class Solution {
public:
    /*
    문제:
    A-Z는 각각 1~26의 숫자들로 대응이 된다.
    오로지 숫자만 포함한 문자열 s가 주어지면, 이것을 해석할 가짓수를 구하여라.
    testcase는 32-bit integer에 맞는 답만 주어진다.
    
    제한:
    
    해결방법:
    1.이전 문제 90번 스크램블링과 비슷하다.
    -> 랜덤하게 인덱싱하기. 
    -> "1111"같은경우, 1, 1, 11 또는 11, 1, 1로 나눠질 수도 있다. 그래도 결과는 똑같네. 중복은 없을까?
    " 11011"에서 사전에 첫 문자가 0이거나, 문자열이 26을 넘어간다거나 하면 return 0;
    -> 가짓수를 return하는 것이므로, int help(string s) = help(s.substr(0, i)) * help(s.substr(i, s.size()-i-1))
    
    한계: 226같은 경우 2, 26과 22, 6에서 발생되는 2, 2, 6중복을 제거하지 못함.
    생각해주다가 시간부족해서 못풀음.
    
    또한 DP로 풀어야함.
    */
    
    
    //이건 재귀 풀이. 시간초과남
    int numDecodings(string s) {
        return s.empty() ? 0 : numDecodings(0, s);
    }
    int numDecodings(int p, string& s){
        int n = s.size();
        if(p == n) return 1;
        if(s[p] == '0') return 0;
        int res = numDecodings(p+1, s);//p+1과 s를 넘긴것을 보자! s.substr(1)이 아니다!
        if(p < n-1 && (s[p] == '1' || (s[p] == '2' && s[p+1] < '7'))) res += numDecodings(p+2, s);
        return res;
    }
    
    //재귀를 DP로 바꿈.
     int cache[101];
    int numDecodings(string s) {
        memset(cache, -1 ,sizeof(cache));
        cache[s.size()]=1;
        return s.empty() ? 0: numDecodings(0,s);    
    }
    int numDecodings(int p, string& s) {
        int n = s.size();
        if(p == n) return 1;
        if(s[p] == '0') return 0; // sub string starting with 0 is not a valid encoding
        int& ret = cache[p];
        if(ret != -1)
            return ret;
        
        ret = numDecodings(p+1,s);
        if( p < n-1 && (s[p]=='1'|| (s[p]=='2'&& s[p+1]<'7'))) ret += numDecodings(p+2,s);
        return ret;
    }
    
    
};
