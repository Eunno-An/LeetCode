Success
Time: 38분
Runtime: 14 ms, faster than 9.89% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 14 MB, less than 5.56% of C++ online submissions for Find First and Last Position of Element in Sorted Array.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret = {-1, -1};
        if(nums.empty())
            return ret;
        
        int s = findStartIdx(nums, target);
        if(s == -1)
            return ret;
        int e = findEndIdx(nums, target, s);
        ret[0] = s;
        ret[1] = e;
        return ret;
        
    }
    //findStartIdx(vector<int> nums, int target): nums에서 target이 존재하는 첫 번째 위치를 리턴한다
    int findStartIdx(vector<int> nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int count = 0;
        while(start < end && count != 100){
            int mid = (start + end) / 2;
            if(nums[mid] < target)
                start = mid+1;
            else
                end = mid;
            count++;
        }
        if(nums[start] == target)
            return start;
        else
            return -1; 
    }
    int findEndIdx(vector<int> nums, int target, int s){
        int mid;
        
        int start = s;
        
        int end = nums.size()-1;
        int count = 0;
        while(start < end && count != 100){
            mid = (start + end)/2;
            if(nums[mid] <= target ){
                start = mid + 1;
                if(start < nums.size() && nums[mid] == target && nums[start] != target)
                    return mid;
            }else{
                end = mid - 1;
            }
            count++;
        }
        if(nums[start] == target)
            return start;
        else
            return -1;
        
    }
};
