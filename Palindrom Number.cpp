//아래가 더 간결함.

class Solution {//runtime 8ms
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x <= 9) return true;
        
        string s = to_string(x);
        int start = 0, end = s.size()-1;
        while(start <= end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};


class Solution {//runtime 4ms
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string s2 = s;
        reverse(s.begin(), s.end());
        return s == s2;
    }
};
