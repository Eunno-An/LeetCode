//fail
class Solution {
public:
    //정렬된 배열에서 숫자 하나를 고정하고 그 뒤에 있는 나머지 두 숫자를 찾습니다. 나머지 두 숫자는 두 포인터를 사용하여 쉽게 찾을 수 있으며 두 숫자는 합 = -1*(고정수)을 가져야 합니다.
    //굳이 set<multiset<>>으로 해 줄 필요가 없고, 이전에 이 숫자를 본 적 이 있다면 건너뛰는 작업을 통해 바로 구할 수 있음. 16번째 줄이나, 30,31번째 줄 같은 경우!
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.empty())
            return ret;
        
        int n_size = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n_size; i++){
            //i부터 모든 숫자가 0보다 크다면 안센다.
            if(nums[i] > 0) break;
            
            //이전에 이 숫자를 본 적이 있다면 건너뛴다.
            if(i > 0 and nums[i] == nums[i-1]) continue;
            
            int left = i+1, right = n_size - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0)
                    ++left;
                else if(sum > 0)
                    --right;
                else{
                    ret.push_back({nums[i], nums[left], nums[right]});
                    int last_left = nums[left], last_right = nums[right];
                    //이전에 이 숫자를 본 적이 있다면 건너뛴다.
                    while(left < right && nums[left] == last_left) ++ left;
                    while(left < right && nums[right] == last_right) --right;
                }
            }
        }
        return ret;
    }
};
