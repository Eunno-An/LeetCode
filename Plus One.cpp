22-02-24
Success
2차
22-04-05
Success
Time:1분미만
Details 
Runtime: 3 ms, faster than 61.06% of C++ online submissions for Plus One.
Memory Usage: 8.8 MB, less than 12.83% of C++ online submissions for Plus One.
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1;
        int upper = 0;
        digits[n]++;
        for(int i=n; i>=0; i--){
            digits[i]+=upper;
            if(digits[i]>=10){
                digits[i]-=10;
                upper=1;
            }
            else{
                upper=0;
            }
        }
        if(upper==1)
            digits.insert(digits.begin(), upper);
        return digits;
    }
};
