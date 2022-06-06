1차 22-06-06 Fail
 /*
    문제:
    정수 배열 nums가 주어지면, 가장 큰 곱을 갖고 있는 연속적인 subarray의 곱을 리턴해라..
    항상 int 형 안에서만 해결되는 답만 주어진다. 자료형 신경 안써도 됨.
    
    제한:
    nums의 길이는 2만
    🎈nums[i]는 0일수도 있다는 것을 인지하자!!!
    
    해결방법:
    1) 🎃브루트 포스
    -> product[i] = 0부터 i까지의 곱
    -> (🧨함정!!!!!)i와 j 두 가지 인덱스를 초이스 하여 product[j] / product[i]를 하면 max를 찾을 수 있을까? NONO!
    -> 중간에 0이 껴서 불가함... 아얘 하려면 N^3풀이로 가야함.
    
    
    2) 조금 더 시간 단축하려면?
    -> 최대 연속합 부분배열 문제의 변형이라는 것을 인지하자.
    -> 배열의 음수 요소를 처리하는 것이 중요하다!
    -> 🎈핵심 아이디어는, 마이너스 요소에 현재 최대 곱을 곱하면 최소 곱이 되고, 그 반대도 마찬가지라는 것이다.
    -> 모든 인덱스 i에 대해 현재 최대값과 최소값을 모두 찾을 수 있다.
    -> 음수를 마주칠 경우 최대와 최소를 바꾸면 된다.
    -> 🎈0을 마주치면? 0이 있으면 어쨌든 결과는 한번 끊기게 되어있음!!
*/
    
class Solution {
public:
    // TIME COMPLEXITY:- O(N)
    // SPACE COMPLEXIY:- O(1)
    int maxProduct(vector<int>& nums) {
        int ans = nums[0],max_prod = nums[0],min_prod = nums[0]; // initialize max product,min product and answer
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) // if number is negative, we will swap max prod and min prod
                swap(max_prod,min_prod);
            max_prod = max(nums[i],max_prod*nums[i]); // find current max prod each time
            min_prod = min(nums[i],min_prod*nums[i]); // find current min prod each time
            ans = max(ans,max_prod); // store the maximum product each time
        }
        return ans;
    }
};
