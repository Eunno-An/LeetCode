1차 2022-03-04

Runtime: 9 ms, faster than 5.54% of C++ online submissions for Sort Colors.
Memory Usage: 8.3 MB, less than 70.58% of C++ online submissions for Sort Colors. 
2차 2022-04-08
Success. 풀이는 선택정렬.
Time: 17분..
Runtime: 3 ms, faster than 58.37% of C++ online submissions for Sort Colors.
Memory Usage: 8.3 MB, less than 24.35% of C++ online submissions for Sort Colors.
    /*
문제: 정렬을 sort를 쓰지 말고 in-place알고리즘으로 정렬 직접 구현해봐라.

회고:
1. 내 풀이 방법.
mergesort구현하다가 실패함. 왜냐하면 mergesort는 추가적인 메모리가 필요한데, in-place로 구현하는 것은 따로 방법이 있음.
그래서 그냥 선택정렬 했음.

2.🤬O(n) 방법
low, mid, high pointer를 이용한다.
처음엔 mid =0, low = 0, hight = nums.size()-1
만약 
nums[mid]가 1인 경우: mid++
nums[mid]가 2인 경우: swap(nums[mid], nums[high]), high--;
nums[mid]가 0인 경우: swap(nums[mid], nums[low]), low++, mid++;

The algorithm ensures that at any point, every element before low is 0, every element after high is 2, every element in between are either 0, 1 or 2 i.e. unprocessed.
*/
class Solution {
public:
    //선택정렬
    int findMinIdx(vector<int>& nums, int nowIdx){
        int Idx = -1;
        int maxVal = 301;
        for(int i=nowIdx; i<nums.size(); i++){
            if(maxVal > nums[i]){
                maxVal = nums[i];
                Idx = i;
            }
        }
        return Idx;
    }
    void sortColors(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int minIdx = findMinIdx(nums, i);
            swap(nums[i], nums[minIdx]);
        }
    }
};
//두번째 방법
void sortColors(vector<int>& nums) {
        
        // initialize variables:
        int low = 0, mid = 0, high = nums.size() - 1;
        
        // logic:
        while(mid <= high)
        {
            switch(nums[mid])
            {
                case 0: swap(nums[low++], nums[mid++]); break;
                
                case 1: mid++; break;
                
                case 2: swap(nums[mid], nums[high--]); break;
            }
        }
    }
