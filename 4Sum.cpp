//fail
//2차 시도 Fail
//2차 실패 이유? 단순 조건 문제.. 이 조건 실수 많이하는듯. 정신 차리자.
//2차 풀이는 3Sum을 확장시켜 4Sum에 대해 해결하였다.
//아래 2차 풀이 첨부하였음.
//상당히 많이 배운 문제.
/*
2Sum, 3Sum, 4Sum, ... kSum에 대해서도 물어볼 수 있다.
우리는 일반화된 구현에 대해서 공부하자.

방법 1. 투포인터
-> 투포인터는 항상 정렬된 배열을 요구한다. 따라서 먼저 배열을 정렬할 필요가 있다.
-> 만약 배열이 정렬되어 있으면, 중복된 요소에 대해서도 다루기 쉽다.
-> 3Sum 문제에서는 single loop에 대해서 각각의 값들을 일일히 나열했다.
    그리고 투 포인터를 사용하여 나머지 배열에 대해 훑었다.
-> kSum 문제에서는 k-2개의 값들의 모든 조합들을 열거하기 위해
    k-2개의 nested loop들을 사용해야 된다.
-> 그렇다면 우리는 k-2개의 loop를 recursion을 사용해서 구현할 수 있다.
-> k==2 일 때, 우리는 twoSum()이라는 함수를 구현하여 재귀를 끝낼 수 있다.


*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k){
        vector<vector<int>> res;
        
        //1. 우리가 더할 숫자들을 다 써버렸을 때, res를 리턴한다.
        if(start == nums.size())
            return res;
        
        //2. 여기에는 k개의 더할 숫자들이 남아있다. 이 숫자들의 평균은
        //적어도 target/k만큼은 되어야 한다. -> ??이해가 잘 안감.
        int average_value = target / k;
        
        //쉽게 생각해서 nums[start] * k > target 이거나, nums.back() * k < target이면 무슨 짓을 해도 안된다는거지!
        if(nums[start] > average_value || average_value > nums.back())
            return res;
        
        if(k==2)
            return twoSum(nums, target, start);
        
        for(int i=start ; i <nums.size(); i++){
            if(i == start || nums[i-1] != nums[i]){
                for(vector<int>& subset: kSum(nums, target-nums[i], i+1, k-1)){
                    //i번째 숫자를 선택하고, start는 i+1, k는k-1, target은 target-nums[i]로 바꾼 함수를 호출한 결과가 리턴한 vector<vector<int>>를 순회하면서 값들을 담는다.
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }
         return res;   
    }
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start){
        vector<vector<int>> res;
        int lo = start, hi = nums.size()-1;
        
        while(lo < hi){
            int curr_sum = nums[lo] + nums[hi];
            if(curr_sum < target || (lo > start && nums[lo] == nums[lo-1])){
                ++lo;
            }else if(curr_sum > target || (hi < nums.size()-1 && nums[hi] == nums[hi+1]))
                --hi;
            else{
                res.push_back({nums[lo++], nums[hi--]});
            }
        }
        return res;
    }
};


class Solution {
public:
    /*
    문제:
    n개의 정수로 이루어진 nums가 주어지면,
    nums[a]+nums[b]+nums[c]+nums[d] == target이 되는
    
    모든[nums[a], nums[b], nums[c], nums[d]]의 unique quadruplets를 구하여라.
    
    해결방법:
    "unique" quadruplets라는 것에 유의하자 반드시!
    
    유사한문제:
    3Sum.
    */
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++){
            int a = nums[i];
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                int b = nums[j];
                if(j>i+1&& nums[j] == nums[j-1]) continue;//실수: 조건이 j>1이 아니라 j>i+1; 이여야 한다.. 이 바보
                int left = j+1;
                int right = n-1;
                while(left < right){
                    int c = nums[left];
                    int d = nums[right];
                    
                    long sum = (long)a + b + c + d;//실수2: 오버플로우 생각 안했다.
                    if(sum == target){
                        ret.push_back({a, b, c, d});
                        while(left<right) {
                            if(nums[left] == c) left++;
                            else break;
                        }
                        while(left < right){
                            if(nums[right] == d) right--;
                            else break;
                        }
                    }
                    else if(sum > target)
                        right--;
                    else
                        left++;
                    
                    
                }
            }
        }
        //-8-1122233335
        return ret;
    }
};
