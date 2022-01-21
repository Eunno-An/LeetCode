//fail
//2번재 복습 2022-01-21: Success 34분
/*
문제:
    target과 정수 배열 nums가 주어지면, 
    세개의 수 합이 target과 가장 근접한 세개 수의 합을 구하여라.
    
해결방법:
    3Sum Closet과 상당히 유사하다.
회고:
    2차 풀이때 실수한 부분: 
    1) 처음에 ret값을 0으로 두었음.
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = nums[0] + nums[1] + nums[2];//initial sum
        for(int i=0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            while(j < k){
                int temp = nums[i] + nums[j] + nums[k];
                if(abs(temp-target) < abs(sum-target)) sum = temp;//거리가 적으면 이 sum으로 교체
                if(temp>target)
                    k--;
                else if(temp<target)
                    j++;
                else
                    return target;
            }
        }
        return sum;
    }
};

//2차 풀이
int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        bool isMinus = false;
        int ret = 100000000;//실수 1: ret초기값 잘못 잡음.
        for(int i=0; i<n; i++){
            int left = i+1;
            int right = n-1;
            
            while(left<right){
                int threeSum = nums[i] + nums[left]+nums[right];
                
                if(threeSum == target){
                    return threeSum;
                }else if(threeSum > target){
                    right--;//right를 감소시키면 threeSum이 감소하고, 즉 abs(threeSum-target)은 감소한다. ㅇㅇ 혹시나 nums = -5 -3 -2 -1, target = -6일 때를 해봤는데 성립함.
                }else{
                    left++;
                }
                if(abs(ret-target) > abs(threeSum-target))
                    ret = threeSum;
            }
        }
        //return minAbs; minAbs를 리턴하는게 아니라, ret 리턴하자
        return ret;
        //-4 -1 1 2
    }
