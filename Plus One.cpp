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
