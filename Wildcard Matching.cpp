1차:Fail
2차:Fail 2022-02-28
/*
Fail
문제: s와 p가 주어지면, p 정규식으로 s 표현이 가능한지 여부를 물어보는 문제

해결 아이디어:


회고:
1) Regular Expression Matching과 매우 유사하다. 그러나 단 하나의 차이는 
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
이 문제에서는 위 조건이 명시되어 있지 않다.
그래도 문제 해석만 잘 하면 어렵지 않다.
하지만 이 문제에서는 문자열들이 훨씬 길다. 즉, 브루트 포스로는 할 수가 없는 문제이다.

2) DP
이것도 똑같이 DP로 해결이 가능하다.
매우 유사하다.

3)Backtracking
무슨 start로 하는게 있다는데 잘 모르겠다.. 이건 좀 더 이해해야겠다.


*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p == s)
            return true;
        if(p == "")
            return (s == "" ? true: false);
        if(p.size() == 1){
            if(p == "*") return true;
        }
        
        //여기서부터는 p의 size가 2 이상인 것은 보장된다.
        if(p[0] == '*'){
            //'*'은 걍 다된다. 그냥 스킵도 가능하다.
            bool flag1 = isMatch(s, p.substr(1, p.size()-1));
            bool flag2 = s.size() > 1 ? isMatch(s.substr(1, s.size()-1), p) : false;
            bool flag3 = s.size() > 1 ? isMatch(s.substr(1, s.size()-1), p.substr(1, p.size()-1)) : false;
            return flag1 || flag2 || flag3;
        }else if(p[0] == '?'){
            bool flag = s.size() > 1 ? isMatch(s.substr(1, s.size()-1), p.substr(1, p.size()-1)) : false;
            return flag;
        }else{//실수: sdas s* 같은 경우, 단순히 return s == p라고 하면 안된다. 뒤에 *가 있을 수 있으니까!
            if(s.empty())
                return false;
            if(s.size() == 1)
                return s == p;
            bool flag = isMatch(s.substr(1, s.size()-1), p.substr(1, p.size()-1));
            return flag;
        }
    }
};

/*

""
"*?*"

*/


class Solution {
public:
    /*
    문제:
    s라는 문자열과 p라는 패턴이 주어지면, 
    wildcard 패턴 매칭을 구현하라
    ?: 어떤 문자도 가능하다.(문자 단순히 하나만!)
    *: 어떤 문자열도 가능하다. 빈 문자열도 가능하다.
    매칭은 반드시 전체 string을 커버해야 한다.
    
    
    제한:
    s와 p의 길이는 2000이하이다.
    
    해결방법:
    
    회고:
    s가 p보다 길이가 작은 경우
    
    
    
    */
    char cache[2001][2001];
    bool help(int si, int pi, string s, string p){
        if(pi == p.size())
            return si == s.size();
        char& ret = cache[si][pi];
        if(ret != -1)
            return ret;
        
        if(si == s.size()){
            if(p[pi] == '*')
                return help(si, pi+1, s, p);
            else
                return ret = false;
        }
        
        if(p[pi]=='?' || s[si] == p[pi])
            return ret = help(si+1, pi+1, s, p);
        if(p[pi]=='*')
            return ret = help(si, pi+1, s, p) || help(si+1, pi, s, p);
        return ret = false;
    }
    
    bool isMatch(string s, string p) {
        memset(cache, -1, sizeof(cache));
        return help(0, 0, s, p);
    }
};
