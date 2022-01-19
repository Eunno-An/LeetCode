class Solution {
public:
    /*
    문제:
    정수 배열 nums가 주어진다. -10<=nums[i]<=10 이고, nums의 길이는 8이며 중복이 존재한다.
    모든 가능한 수열을 구해라. 각 수열은 unique하다. 순서는 상관없다.
    
    해결방법:
    1.next_permutation 이용
    2.직접 구현(https://blog.naver.com/zbqmgldjfh/222557296952)
    3.더 많은 구현들은 여길 참고하기
    https://leetcode.com/problems/permutations-ii/discuss/933190/C%2B%2B-4-different-solutions-with-explanations-and-tips
    
    오름차순으로 시작했던 순열이, 최종적으로 내림차순으로 배열되어 끝나게 된다.
총 N!개의 서로 다른 순열이 있다.(중복되는 요소가 없다는 전제 하에)

1 2 로 시작하는 순열인 1 2 ? ? 의 마지막 순열의 다음 순열을 어떻게 구할까?
1 2 ? ?의 마지막 순열은 1 2 4 3(내림차순), 4 3 이 내림차순으로 끝난다.

앞에 1 2 로 시작하는 마지막 순열 a가 있을 것이다.
이 순열 a의 다음 순열은 앞이 1 3 으로 시작하는 첫 순열 b(오름차순)이 된다.

여기서 핵심!
마지막 순열 다음에 오는 첫 수열은 부분 오름차순이다.


예를 들어,

7 2 3 6 5 4 1같은 순열이 있다고 해보자.

이 순열은 7 2 3 으로 시작하는 마지막 순열이다.
어떻게 알았을까?
7 2 3 다음에 6 5 4 1는 다 내림차순이다.

1)A[i-1]<A[i]를 만족하는 가장 큰 i 찾기
-> 이때 여기서는 A[i]가 6이 되고, i는 3번째가 된다.

2)j>=i이면서 A[j] > A[i-1]를 만족하는 가장 큰 j 찾기
-> 여기서는 4가 된다.

3)A[i-1]과 A[j]의 값을 교환한다.
-> 7 2 4 6 5 3 1

4)A[i]부터 순열을 뒤집는다.
-> 7 2 4 1 3 5 6이 된다.
    */
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> initial_state(nums);//이거 되게 좋은 코드인듯!!! 이건 몰랐네!
        vector<vector<int>> output;
        do{
            output.emplace_back(nums);
            nextPermutation(nums);
        }while(nums!=initial_state);
        return output;
    }
    
private:
    void nextPermutation(vector<int>& nums){
        if(size(nums)<=1) return;//size가 1보다 작거나 같을 때 리턴한다.
        auto pos = 0;
        for(int i=size(nums)-2; i>=0; --i){
            if(nums[i] < nums[i+1]){
                pos = i;
                break;
            }
        }
        for(int i=size(nums)-1; i>=pos; --i){
            if(nums[pos] < nums[i]){
                swap(nums[i], nums[pos]);
                ++pos;
                break;
            }
        }
        reverse(begin(nums)+pos, end(nums));
        
    }    
};
  
