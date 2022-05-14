22-05-14 
class Solution {
public:
    bool isPalindrome(string s) {
        /*
        문제:
        uppercase->lowercase
        removing all non-alphabet character
        이때 문자열이 palindrome인지 판별해라.
        
        제한:
        
        해결방법:
        
        */
        string palin="";
        for(int i=0; i<s.size(); i++){
            if(isupper(s[i]))
                s[i] = tolower(s[i]);
            if(isalpha(s[i]) || isdigit(s[i]))
                palin += s[i];
        }
        
        s = palin;
        reverse(palin.begin(), palin.end());
        
            
        return palin == s;
    }
};
