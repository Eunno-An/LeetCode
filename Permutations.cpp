/*
반드시 sort하는거 잊지 말기.
한번 구현해보기 permutations
*/
class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do{
            ret.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return ret;
    }
};
