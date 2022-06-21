class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int ret = -1;
        long long minAvgDiff = LLONG_MAX;
        int n = nums.size();
        vector<long long> Sum(n, 0);
        for(int i=0; i<n; i++){
            if(i == 0){
                Sum[0] = nums[0];
                continue;
            }
            Sum[i] = Sum[i-1] + nums[i];
        }
        long long a, b;
        long long tempAvgDiff;
        for(int i=0; i<n; i++){
            a = Sum[i] / (i+1);
            b = (i == n-1 ? 0 : (Sum.back() - Sum[i]) / (n-i-1));
            tempAvgDiff = abs(a-b);
            if(minAvgDiff > tempAvgDiff){
                ret = i;
                minAvgDiff = tempAvgDiff;
            }
            
            
        }
        return ret;
    }
};
