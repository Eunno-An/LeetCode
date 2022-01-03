Success
Runtime: 4 ms, faster than 80.03% of C++ online submissions for Search Insert Position.
Memory Usage: 9.8 MB, less than 21.60% of C++ online submissions for Search Insert Position.
  
class Solution {
public:
  //return distance(nums.begin() , lower_bound(nums.begin(), nums.end(), target))
    int searchInsert(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size()-1;
        int mid;
        while(start < end){
            mid = start + (end-start)/2;
            if(nums[mid] <target){
                start = mid+1;
            }else if(nums[mid] > target){
                end = mid-1;
            }else{
                return mid;
            }
        }
        if(nums[start] >= target)
            return start;
        else 
            return start+1;
    }
};
