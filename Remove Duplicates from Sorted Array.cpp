//success. 사실상 unique함수를 알고 있었기에 망정이지, 구현은 실패함.
//직접 구현하는 것을 알아보자
Runtime: 8 ms, faster than 89.94% of C++ online submissions for Remove Duplicates from Sorted Array.
Memory Usage: 18.5 MB, less than 8.37% of C++ online submissions for Remove Duplicates from Sorted Array.
  
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = unique(nums.begin(), nums.end()) - nums.begin();
        return k;
    }
};

//직접 구현하는 방법
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int left = 0;//중복이 일어난 처음 인덱스라고 가정!
        
        for(int right = 1; right < nums.size(); right++){
            if(nums[left] != nums[right]){//서로 다르다면 바꿈! right를 기존의 left의 오른쪽에 놓는것임.
                left++;
                nums[left] = nums[right];
            }
        }
        for(int i=0; i<nums.size(); i++)
            cout << nums[i] << ' ';
        return left + 1;
    }
};
