1차 22-06-14 Success
Time: 10분
Details 
Runtime: 52 ms, faster than 5.09% of C++ online submissions for Majority Element.
Memory Usage: 19.5 MB, less than 92.23% of C++ online submissions for Majority Element.
class Solution {
public:
    /*
    문제:
    n size의 nums 배열이 주어진다.
    majority element를 리턴해라.
    
    majority element란 n/2번보다 더 많이 나타나는 요소를 말한다.
    이 문제에서는 majority element가 항상 나타난다고 가정해도 좋다.
    
    제한:
    
    Follow-up:
    추가 공간이 O(1)에 되도록 할 수 있음?
    
    해결방법:
    1) 메모리 상관없이 unordered_map 사용
    -> follow-up에 어긋남.
    2) sorting 한 다음에 mid와 start, end를 각각 비교함.
    -> 한계점: majority element가 배열의 중간에 있을 경우 안됨
    3) sorting 한 다음에 요소를 일일히 하나하나씩 세기
    -> 풀리긴 하는데 좋은 풀이는 아님. 너무 느림./
    4) 🎈어짜피 n/2개 이상이니까, sorting 한다음에 중간 요소 뽑기
    -> 3번 풀이의 상위 호환 버전. 좋다.
    5) 🎃Boyre-Moore 투표알고리즘
    -> 정당에 대한 투표라고 생각해 보자. 반드시 정답은 하나 있다고 가정하므로, 쉽게 생각하면 마지막에 끝까지 살아남는 놈이 이기는거다.
    */
    
    //3번 풀이
    int majorityElement(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums[0];
            
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int major = n/2;
        int elem = nums[0];
        int count = 1;
        for(int i=1; i<n; i++){
            if(elem != nums[i]){
                count = 1;
                elem = nums[i];
            }else{
                count++;
                if(count > major)
                    return elem;
            }
        }
        return 1000000001;//"oops"
    }
    
    //5번 풀이
    int majorityElement(vector<int>& nums) {
        int majority,count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count)
            {
                count+=(nums[i]==majority ? 1 : -1);
            }
            else
            {
                majority=nums[i];
                count=1;
            }
        }
        return majority;
    }
};
