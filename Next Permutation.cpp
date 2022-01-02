//이건 진짜 어려움.. 
//그냥 next_permutation(nums.begin(), nums.end()) 임.
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        //첫번째 단계.
        //주어진 배열을 끝에서부터 선형적으로 탐색해라, 그리고 num[i] > num[i-1]인 지점을 찾아라. i-1 인덱스를 breakPoint라는 변수에 저장해라. 더이상 그런 요소가 없다면, 배열 전체를 뒤집고 리턴해라
        //두번째 단계
        //주어진 배열을 끝에서부터 탐색하고, nums[breakPoint]보다 큰 수를 찾아라. 이걸 nums[i]라고 불러보자.
        //세번째 단계
        //nums[i]와 nums[breakPoint]를 swap한다.
        //breakPoint+1부터 nums.size()까지 배열을 뒤집는다.
        
        int breakPoint = -1;
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                breakPoint = i-1;
                break;
            }
        }
        if(breakPoint == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] > nums[breakPoint]){
                swap(nums[i], nums[breakPoint]);
                reverse(nums.begin() + breakPoint+1, nums.end());
                break;
            }
        }
        return;
    }
};
