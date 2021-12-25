//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
//Memory Usage: 6.2 MB, less than 96.02% of C++ online submissions for Valid Parentheses.
class Solution {
public:
    bool isValid(string s) {
        stack<char> box;
        for(int i=0; i<s.size(); i++){
            if(box.empty())
                box.push(s[i]);
            else{
                if((box.top() == '(' && s[i] == ')') || (box.top() == '[' && s[i] == ']') || (box.top() == '{' && s[i] == '}') )
                    box.pop();
                else
                    box.push(s[i]);
            }
        }
        return box.empty() ? true : false;
    }
};
