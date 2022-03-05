Success
Time: 2022-03-05
Details 
Runtime: 4 ms, faster than 54.23% of C++ online submissions for Subsets.
Memory Usage: 16.1 MB, less than 14.57% of C++ online submissions for Subsets.

class Solution {
public:
    /*
    문제:
    unique nums로 이루어진 배열 nums가 있다.
    가능한 모든 subsets들을 찾아라.
    해답은 중복된 set을 갖고있지는 않다.
    
    제한:
    
    해결방법:
    조합식으로 비슷하게 구하면 될듯
    */
    vector<vector<int>> ret;
    void help(vector<int> now, vector<int>& nums, int idx, int k){
        if(idx == k){
            ret.push_back(now);
            return;
        }
        now.push_back(nums[idx]);
        help(now, nums, idx+1, k);
        now.pop_back();
        help(now, nums, idx+1, k);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        help(vector<int>(), nums, 0, nums.size());
        return ret;
    }
};
