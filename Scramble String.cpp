//1차 22-04-02 Fail
//2차 22-04-18 Fail
회고: 
너무나 ...어려운 ...문제다... 이해는 쉽지만 
그냥 쉽게 푸는 방법 떠올리기도 어렵다.
class Solution {
public:
    /*
    문제:
    s라는 문자열을 scramble해서 t를 얻으려고 한다. 다음과 같은 과정을 통해서이다.
    1.string의 길이가 1이면 멈춘다.
    2.만약 string의 길이가 1보다 크면?
        2-1. 두개의 비어있지 않은 substring으로 쪼갠다. index는 랜덤이다. 
        2-2. s=x+y로 하든 s=y+x로 하든 상관없다.
        2-3. step 1을 각각 x와 y에 대해 재귀적으로 호출한다.
    
    길이가 같은 문자열 s1와 s2가 주어지면, 
    s2가 s1의 scrambled string이면 true를 리턴하고, 아니면 false를 리턴해라.
    
    제한:
    s1과 s2의 길이는 같다.
    s1의 길이는 1 이상 30이하이다.
    s1과 s2는 영어 소문자로만 이루어져있다.
    
    
    해결방법:
    
    회고:
    좋은 풀이다... DP + 함수 짜는데 좋은 풀이인듯 싶다.
    */
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2) {
        //base cases
        int n = s1.size();
        if(s2.size() != n)//두 문자열의 사이즈가 같지 않을경우
            return false;
        if(s1 == s2)//두 문자열이 같은 경우
            return true;
        
        if(n == 1)//길이가 같고 한글자밖에 없는데 두문자열이 같지가 않으니까!
            return false;
        
        //기존에 풀었던 문제인 경우
        string key = s1 + " " + s2;
        if(mp.find(key) != mp.end())
            return mp[key];
        
        for(int i=1; i<n; i++){
            //ex of without swap: gr|eat and rg|eat
            bool withoutswap = (
                //left part of first and second string
                //각 문자열의 왼쪽 부분을 스크램블 한것. 
                isScramble(s1.substr(0, i), s2.substr(0, i))
                &&
                //right part of first and second string
                //각 문자열의 오른쪽 부분을 스크램블 한것.
                isScramble(s1.substr(i), s2.substr(i))
            );
            
            //if without swap give us right answer then we do not need to call the recursion withswap
            if(withoutswap)
                return true;
            
            //ex of withswap: gr|eat  rge|at
			//here we compare "gr" with "at" and "eat" with "rge"
            bool withswap = (
                //left part of first and right part of second
                isScramble(s1.substr(0, i), s2.substr(n-i))
                &&
                
                isScramble(s1.substr(i), s2.substr(0, n-i))                           );
            
            if(withswap)
                return true;
            
            
        }
        return mp[key] = false;
        
    }
};
