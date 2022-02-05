Success
Time: 40분
Runtime: 7 ms, faster than 19.23% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 13.1 MB, less than 26.74% of C++ online submissions for Search in Rotated Sorted Array.

2차시도: Fail
회고: nums[left]<=nums[mid]가 아니라 nums[left]<=nums[right]라고 하였음. 
사사로운 if조건.. 이분탐색은 조건이 너무 까다로운 문제같다.
  
 

/*
회고
아래처럼 굳이 복잡하게 풀 필요가 없다.
더 쉽게 풀 수 있는데 굳이 어렵게 풀 이유가 없ㄱ는데..
아래 좋은 코드 첨부하였음.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        int k = findTarget(nums, start, end, target);
        return k;
    }

    //findTarget(vector<int> nums, int target, int start, int end)//start와 end가 주어지면 nums[start ]~ nums[end]까지 이분탐색으로 target을 찾는다.
    int findTarget(vector<int> nums, int start, int end, int target) {
        if (start == end) {
            if (nums[start] == target)
                return start;
            return -1;
        }
        int mid = (start + end) / 2;
        if (nums[start] > nums[end]) {
            int left = findTarget(nums, start, mid, target);
       
            if (left != -1 && nums[left] == target)
                return left;
            int right = findTarget(nums, mid + 1, end, target);
            if (right != -1 &&  nums[right] == target)
                return right;
            return -1;
        }
        else {
            while (start < end) {
                mid = (start + end) / 2;
                if (nums[mid] < target)
                    start = mid + 1;
                else if (nums[mid] > target)
                    end = mid - 1;
                else
                    return mid;
            }
            if (nums[start] == target)
                return start;
            else
                return -1;
        }
        return 123456789;//"OOPS"
    }
};

int beg=0,end=nums.size()-1,mid;
        while(beg<=end)
        {
            mid=(beg+end)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[beg]<=nums[mid])
            {
                if(target<=nums[mid] && target>=nums[beg])
                    end=mid-1;
                else
                    beg=mid+1;
            }
            
            else
            {
                if(target>=nums[mid] && target<=nums[end])
                   beg=mid+1;
                else
                    end=mid-1;
            }
            
        }
        return -1;
    }
