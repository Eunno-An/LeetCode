Success
Runtime: 4 ms, faster than 80.03% of C++ online submissions for Search Insert Position.
Memory Usage: 9.8 MB, less than 21.60% of C++ online submissions for Search Insert Position.
  
2차
Time: 08분 44초
Runtime: 3 ms, faster than 90.18% of C++ online submissions for Search Insert Position.
Memory Usage: 9.6 MB, less than 73.72% of C++ online submissions for Search Insert Position.

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

2차코드첨부
class Solution {
public:
    /*
    문제:
    각기 다른 정수들이 정렬된 배열과 target value가 주어지면
    target이 찾아지면 그 인덱스를 반환해라.
    그렇지 않으면 그게 있을만한 곳을 리턴해라.
    
    
    */
    int searchInsert(vector<int>& nums, int target) {
        int start =0, end = nums.size()-1;
        int mid;
        while(start < end){
            mid = (start + end)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        return nums[start] < target ? start+1 : start;
    }
};
