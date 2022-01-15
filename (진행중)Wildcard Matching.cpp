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
