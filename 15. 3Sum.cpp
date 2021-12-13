//Fail.
//이분탐색으로 해 보려고 해도 시간초과가 난다잉..
class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        //negatives: (-4, 5) (-1, 0) (-1, 4)
        //positives: (1, 2) (2, 3)
        //zeros: (0, 1)
        
        //nums[i] + nums[j] = -nums[k];
        //if(nums[i] > 0 && nums[j] > 0) -> nums[k] < 0
        //if(nums[i] > 0 && nums[j] < 0) -> ?
        //if(nums[i] < 0 && nums[j] < 0) -> nums[k] > 0
        set<multiset<int>> triplets;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int A = nums[i] + nums[j];
                int idx = lower_bound(nums.begin(), nums.end(), A*-1) - nums.begin();
                if(idx != i && idx != j && idx < nums.size() && nums[idx] == (A * -1)){
                    multiset<int> temp = {nums[i], nums[j], nums[idx]};
                    triplets.insert(temp);
                }
            }
        }
        vector<vector<int>> ret;
        for(auto it : triplets){
            multiset<int> ms_temp = it;
            vector<int> vec_temp;
            for(auto it2 : it)
                vec_temp.push_back(it2);
            ret.push_back(vec_temp);
        }
        return ret;
    }
    
};
