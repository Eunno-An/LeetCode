★
//fail
//중복된 조합이 나타나면 안됨. 또한 모든 수들은 한번 만 써야 함.
//i!= curInd && candidates[i] == candidates[i-1] 같은 조건을 통해 중복된 조합을 피할 수 있음.

//내가 실수했던 부분. 똑같은 실수를 했던 적이 있음.
//모든 경우의 수를 백트랙으로 다 구한다음에 set<multiset<int>>같은 자료구조를 이용해서 중복을 제거하려했으나,
//너무 시간이 오래걸리는 방법임. 이건 예전 프로그래머스 문제에서도 같은 실수를 한 적이 있음.

//2차 fail... 이건 진짜 중요하니까 잘 보자.
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


//다음날 다시 짜보니까 이렇게 됨
//실수 한 부분은 i+1 이 아닌 index+1로 해줬음
//이런 실수 자주하는듯!!!
//다시 푸니 16분
class Solution {
public:
    vector<vector<int>> ret;
    void help(vector<int>& candidates, vector<int> now, int index, int target){
        if(target < 0)
            return;
        if(target == 0){
            ret.push_back(now);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i == index || candidates[i-1]!=candidates[i]){
                now.push_back(candidates[i]);
                help(candidates, now, i+1, target-candidates[i]);//index+1이 아니라 i+1로 해줘야함. 이 실수 자주하는듯?
                now.pop_back();  
            }
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //유니크한 조합
        //candidates에 있는 것은 꼭 한번씩 만 쓰여야 한다.
        sort(candidates.begin(), candidates.end());
        help(candidates, vector<int>(), 0, target);
        return ret;
    }
};

//1 1 2 5 6 7 10
//1 
