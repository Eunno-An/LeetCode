//1차풀이: success. 사실상 unique함수를 알고 있었기에 망정이지, 구현은 실패함.
//직접 구현하는 것을 알아보자
//그리고 for문 안에서 왠만하면 i-- 이지랄좀 하지 말자!
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
//2차풀이: Success. unique도 성공하고, 직접 swap하는 방법도 성공하였음.
class Solution {
public:
    /*
    문제:
    정수 배열 nums가 오름차순으로 정렬되어 있다.
    in-place로 중복을 제거하라.
    
    해결방법:
    1) unique 사용
    2) swap 방법이 없나
    */
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int left = 0, right = 0;
        while(right<nums.size()){
            if(nums[left] != nums[right]){
                swap(nums[left+1], nums[right]);
                left++;
            }
            right++;
        }
        return left+1;
        //0 1 0 1 1
    }
};
