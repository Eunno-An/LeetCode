1차 22-04-02 Fail

class Solution {
public:
    /*
    문제:
    nums가 주어지는데 중복을 포함한다. 정수배열이다.
    모든 가능한 subsets들을 구해라.
    단, subset들은 중복이 되면 안된다. 순서는 상관없이 리턴해라.
    공집합 포함임.
    
    
    제한:
    nums의 길이는 1 이상 10 이하
    nums[i]는 -10이상 10이하
    
    해결방법:
    기존에 풀어본 적이 있는 문제이다.
    저번에는 set<set<int>>이런식으로 해서 시간초과도 나고 복잡하게 풀었던 걸로 기억하는데
    그렇게 하지말고, 현재 idx의 요소와 이전의 idx를 비교해서
    만약에 같으면 그냥 넘어가는 식으로 구현했던 것으로 기억한다.
    
    회고:
    해봤던 문젠데 정확한 구현이 헷갈려서 틀렸다.
    for문이 안에 들어갔으야 했는디..
    
    */
    void help(vector<vector<int>>& ret, vector<int>& nums, vector<int>& now, int nowIdx){
        
        ret.push_back(now);//현재 상태 삽입.
        for(int i=nowIdx; i<nums.size(); i++)
            if(i == nowIdx || nums[i] != nums[i-1]){
                now.push_back(nums[i]);
                help(ret, nums, now, i+1);
                now.pop_back();
            }
        
        
        
        return;
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> now;
        help(ret, nums, now, 0);
        return ret;
    }
};
