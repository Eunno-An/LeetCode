1차 22-06-06 Success
Success
Details 
Runtime: 6 ms, faster than 43.94% of C++ online submissions for Find Minimum in Rotated Sorted Array.
Memory Usage: 10.1 MB, less than 72.37% of C++ online submissions for Find Minimum in Rotated Sorted Array.
class Solution {
public:
    /*
    문제:
    오름차순으로 정렬된 길이 n의 배열이 1부터 n번까지 회전되었다고 가정하자.
    회전은 예를들어
    1번 회전되면 오른쪽으로 한칸 미는것임.
    
    몇번 회전된 nums가 주어진다. 이때 minimum element를 리턴해라.
    
    Time Complexity O(n)풀이 말고 O(log n)풀이로 해봐
    제한:
    
    해결방법:
    1) 비슷한 문제
    -> 되게 초기 번호에 이런 문제가 있었다. two-pointer로 풀었던 느낌이다.
    -> arr[i] > arr[i+1]인 arr[i+1]을 찾으면 된다. 만약 만족하는 요소가 없으면 arr[0]리턴하면 된다.
    -> two-pointer로 이용해서 찾아보자.
    */
    int findMin(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int left = 0, right = nums.size()-1;
        int mid = -1;
        
        if(nums[0] > nums[1])
            return nums[1];
        if(nums.size() == 2){
            if(nums[0] < nums[1])
                return nums[0];
            else
                return nums[1];
        }
        while(left < right){
            mid = (left + right)/2;
            if(mid+1 < nums.size() && nums[mid] > nums[mid+1])
                return nums[mid+1];
            if(nums[left] < nums[mid])
                left = mid;
            else if(nums[mid] < nums[right])
                right = mid;
        }
        return nums[0];
    }
};

//쫌 더 깔끔한 코드
class Solution {
public:
    int findMin(vector<int>& nums) {
        int r = nums.size()-1, l = 0, mid;
        if (!r) return nums[0]; // only one element

        while (l < r)
        {
            mid = l + (r - l) / 2;

            // got a part that is not rotated
            if (nums[l] < nums[r]) return nums[l]; 

            // mid is larger than right - min is in right side
            else if (nums[mid] > nums[r]) l = mid + 1;

            // mid is smaller than right - min is in left side (including mid)
            else r = mid;
        }
        return nums[l];
    }
};
