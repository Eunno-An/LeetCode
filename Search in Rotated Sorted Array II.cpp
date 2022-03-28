1차 Fail

class Solution {
public:
    /*
    문제:
    오름차순 정렬된 nums 배열이 있다.
    nums는 어떤 pivot k에 대해 rotated.
    target이 nums에 있으면 true, 아니면 false를 리턴해라.
    반드시 전반적인 연산의 단계를 가능한 많이 줄여야 한다.
    
    Follow-up:
    This problem is similar to Search in Rotated Sorted Array, 
    but nums may contain duplicates. 
    Would this affect the runtime complexity? How and why?
    
    제한:
    
    해결방법:
    1)단순하게 순차탐색. 하지만 이건 문제가 원하는 바가 아님.
    2)left, right two-pointer.
    ->하지만 left와 mid값이 같을 경우 골치가 아프다. 어떻게 해야할까?
    
    회고:
    1)우리가 이전 문제와 다른 점?
    ->이 문제에서는 중복이 허용이 된다. 즉, nums[mid] == nums[left]와 같은 상황이 나올 수 있다.
    ->조금만 더 생각해보면, 이런 상황은 nums[mid] == nums[left] 임과 동시에 nums[right]와 같다!!! (pivot에 대한 회전이 가정이므로, nums[mid]의 오른쪽부터 nums[left]까지 돌아오기위해서는 그 수들이 같아야 한다.)
    */
    bool search(vector<int>& nums, int target) {
        int left=0, right = nums.size()-1;
        int mid;
        while(left<=right){
            mid = left + (right-left)/2;
            if(nums[mid] == target)
                return true;
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){//이런 상황!
                left++;
                right--;
                
            }
            else if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target <= nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
            else if(nums[mid] <= nums[left]){
                if(nums[mid]<=target && target <= nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
            
        }
        return  false;
    }
};
