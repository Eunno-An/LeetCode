//fail
//중복된 조합이 나타나면 안됨. 또한 모든 수들은 한번 만 써야 함.
//i!= curInd && candidates[i] == candidates[i-1] 같은 조건을 통해 중복된 조합을 피할 수 있음.

//내가 실수했던 부분. 똑같은 실수를 했던 적이 있음.
//모든 경우의 수를 백트랙으로 다 구한다음에 set<multiset<int>>같은 자료구조를 이용해서 중복을 제거하려했으나,
//너무 시간이 오래걸리는 방법임. 이건 예전 프로그래머스 문제에서도 같은 실수를 한 적이 있음.
class Solution {
public:
    vector<vector<int>> result;
    void comsum(vector<int>& curr, int target, int sum, vector<int>& candidates, int curInd, int n){
        if(target == sum){
            result.push_back(curr);
            return;
        }else if(sum > target)
            return;
        
        for(int i=curInd; i<n; i++){
            if(i!=curInd && candidates[i] == candidates[i-1])//to avoid picking up the same combinations i.e we don`t pick same element for certain kth position of a combination
                continue;
            
            sum += candidates[i];
            curr.push_back(candidates[i]);
            comsum(curr, target, sum, candidates, i+1, n);
            sum -= candidates[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        comsum(curr, target, 0, candidates, 0, n);
        return result;
    }
};
