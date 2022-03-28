1차
Success
시간: 16분 7초
Runtime: 48 ms, faster than 97.82% of C++ online submissions for Jump Game.
Memory Usage: 48.3 MB, less than 52.62% of C++ online submissions for Jump Game.

2차 22-03-28
Fail 
이유?
    1. 해결방법을 recursive dp로 하려 했으나, O(n^2)이 걸림. 왜냐하면 일단 함수 호출을 해버림. 
    2. 반드시 DP가 답은 아니라는 것을 알아야함. 
class Solution {
public:
    /*
    2022-02-02
    문제:
    정수 배열 nums가 주어진다. 현재 첫번째 index에 위치해 있고, 각각의 요소 nums[i]는 내가 최대로 점프할 수 있는 길이를 나타낸다.
    이때 last Index에 도달할 수 있으면 true, 아니면 false를 리턴해라.
    
    제한:
    nums의 길이가 10000
    nums[i]는 십만이다.
    nums[i]는 0도 가능하다.
    해결방법:
    1)BruteForce
    ->재귀로 모든 경우를 다 탐색하는 경우. 각각의 케이스 는 nums[i]번 탐색해야하고, nums의 길이가 만이므로 만 * 십만 = 타임리밋.
    
    2)Two-pointer
    ->left = 0, right = 0
    arr[left]를 보면서 현재 최대 갈 수 있는 곳을 수정한다.
    조건 left < right일 때 동안만임. left == right일 경우 stop.
    
    회고:
    카데인 알고리즘과 굉장히 비슷하다.
    */
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1 && nums[0] == 0)
            return true;
        int left = 0, right = 0;
        int goal = nums.size()-1;
        while(left <= right){
            if(left == right && nums[left] == 0)
                return false;
            right = max(right, left + nums[left]);//왼쪽에서 최대로 점프할 수 있는 칸
            if(left <= goal && goal <= right)
                return true;
            left++;
        }
        return false;
    }
};
