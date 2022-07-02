
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ret = 10000;
        for(int i=0; i<nums.size(); i++){
            if(target == nums[i]){
                if(ret > abs(i - start))
                    ret = abs(i-start);
            }
        }
        return ret;
    }
};
