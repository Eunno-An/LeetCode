1차 22-06-16
Success
Details 
Runtime: 4 ms, faster than 42.66% of C++ online submissions for Excel Sheet Column Number.
Memory Usage: 6.1 MB, less than 32.84% of C++ online submissions for Excel Sheet Column Number.
class Solution {
public:
    /*
    문제:
    columnTitle이 주어지면, 해당하는 열 넘버를 리턴해라.
    
    제한:
    
    해결방법:
    
    */
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int ret = 0;
        for(int i=0; i<n; i++){
            ret *= 26;
            ret += (columnTitle[i] - 'A' + 1);
        }
        return ret;
    }
};
