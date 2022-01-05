//Success
//시간: 17분
//굳이 sorting을 안 해도 된다. 애초에 sorting을 하면 시간만 더 잡아먹을 수도 있다.
//실제로 sorting 안하고 푸는게 조금 더 빠름.
//조금 더 최적화를 하려면, sum을 쓰지 말고 target에서 뺴는 식으로 해도 됨.

Runtime: 45 ms, faster than 27.62% of C++ online submissions for Combination Sum.
Memory Usage: 15.5 MB, less than 37.75% of C++ online submissions for Combination Sum.
  
class Solution {
public:
    vector<vector<int>> ret;
    //candidates에 있는 것들을 중복 있이 뽑아서 target이 되는 조합들을 리턴해라.
    void helper(vector<int> candidates, int idx, vector<int> now, int sum, int target){
        for(int i=idx; i<candidates.size(); i++){
            if(sum + candidates[i] < target){
                now.push_back(candidates[i]);
                helper(candidates, i, now, sum + candidates[i], target);
                now.pop_back();
            }else if(sum + candidates[i] > target){
                return;
            }else{
                now.push_back(candidates[i]);
                ret.push_back(now);
                return;
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //if empty
        if(candidates.empty())
            return ret;
        sort(candidates.begin(), candidates.end()); 
        vector<int> now;
        helper(candidates, 0, now, 0, target);
        return ret;
        
    }
};
