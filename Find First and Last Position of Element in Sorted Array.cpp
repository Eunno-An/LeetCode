Success
1차
Time: 38분
Runtime: 14 ms, faster than 9.89% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 14 MB, less than 5.56% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
아래 좋은 코드 첨부했음. 내가 짠거는 너무 꼼수 부려서했음. 로직으로는 별로 좋은 로직이 아님.

2차 2022-02-22
Time: 18분 30초
Runtime: 16 ms, faster than 26.03% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 13.8 MB, less than 19.17% of C++ online submissions for Find First and Last Position of Element in Sorted Array 

2차 회고:
이분탐색 푸는데 아직 유연하지 않은것같음. 코드 보면서 감 익히기. 그래도 깔끔하게 짜긴 짰음.
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
//이게 좋은 코드
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0, end = nums.size()-1;
        vector<int> ret(2, -1);
        if(nums.empty())
            return ret;
        
        while(start < end){
            int mid = (start + end)/2;
            if(nums[mid] < target) start = mid + 1;
            else end = mid;
        }
        if(nums[start] != target) return ret;
        else ret[0] = start;
        
        end = nums.size()-1;
        while(start < end){
            int mid = (start + end)/2 + 1; // 이거 중요. 우린 가장 오른쪽에 있는 target을 찾아야 하니까 오른쪽으로 이동해야함.
            if(nums[mid]>target) end = mid - 1;
            else start = mid;
        }
        ret[1] = end;
        return ret;
    }
};
