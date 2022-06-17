1차 22-06-17
Success
(8분 24초, 단순 구현)
class Solution {
public:
    /*
    문제:
    아래의 조건들을 만족하면 password가 strong하다고 말할 수 있다
-> 적어도 8개의 캐릭터를 갖고 있어야 한다
-> 적어도 하나의 lowercase를 갖고 있어야 한다
-> 적어도 하나의 uppercase를 갖고 있어야 한다
-> 적어도 하나의 숫자를 갖고 있어야 한다
-> 적어도 특수 문자 하나를 갖고 있어야 한다. !@#$%^&*()-+ 안에 들어가는 문자들만
-> 같은 문자가 인접해 있으면 안된다.

    제한:
    
    해결방법:
    
    */
    set<char> special;
    bool check1(string& p){
        return p.size() >= 8 ? true : false;
    }
    bool check2(string& p){
        for(int i=0; i<p.size(); i++)
            if(islower(p[i]))
                return true;
        return false;
    }
    bool check3(string& p){
        for(int i=0;i <p.size(); i++)
            if(isupper(p[i]))
                return true;
        return false;
    }
    bool check4(string& p){
        for(int i=0; i<p.size(); i++)
            if(isdigit(p[i]))
                return true;
        return false;
    }
    bool check5(string& p){
        for(int i=0; i<p.size(); i++)
            if(special.find(p[i]) != special.end())
                return true;
        return false;
    }
    bool check6(string& p){
        for(int i=1; i<p.size(); i++)
            if(p[i-1] == p[i])
                return false;
        return true;
    }
    bool strongPasswordCheckerII(string p) {
        if(check1(p) and check2(p) and check3(p) and check4(p)){
            string specialChar = "!@#$%^&*()-+";
            for(int i=0; i<specialChar.size(); i++)
                special.insert(specialChar[i]);
            
            return check5(p) and check6(p);
        }
        else
            return false;
    }
};
