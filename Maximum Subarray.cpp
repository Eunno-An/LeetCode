1차 Fail
2차 Fail 2022-03-25. 
    
/*
    Fail. 

    2022-01-31
    문제:
    정수 배열 nums가 주어지면, 연속된 부분배열 중에 가장 큰 sum을 가지는 부분배열의 sum을 리턴해라.
    
    제한:
    nums의 길이는 최대 십만
    
    해결방법:
    1)BruteForce
    i부터 j까지 합을 구한다. 그럼 O(십만 * 십만 * 십만) = 타임리밋
    
    2)Optimize Sum
    이건 안될줄 알았는데 되네
    문제가 시간제한이 널널해서 되나봄.
    
    3)Kadane Algorithm
    
    회고:
    N^2 솔루션 까지는 생각했음.
    Kadane 알고리즘 정말 유용할 것 같다. 잘 기억해 두자.
    
    2차회고:
    양수일때만 생각해줌. 음수일때도 생각해주기. 종만북에는 양수일 때만 가능한 코드가 있음.
*/
class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        int MAX = INT_MIN;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            MAX = max(sum, MAX);
            if(sum < 0) sum = 0; 
            //cout << sum << endl;
        }
        return MAX;
    }
};
