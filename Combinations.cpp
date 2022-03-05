Success 2022-03-05
Time: 6분
Runtime: 752 ms, faster than 10.10% of C++ online submissions for Combinations.
Memory Usage: 165 MB, less than 9.44% of C++ online submissions for Combinations.
class Solution {
public:
    /*
    문제:
    n과 k가 주어진다.
    k의 가능한 조합들을 다 내놔!
    
    제한:
    
    해결방법:
    조합 구현
    
    회고:
    n이 20 미만이여서 가능했던 풀이 방법.
    */
    vector<vector<int>> ret;
    void help(vector<int>& numbers, vector<int> comb, int choice, int idx, int k){
        if(choice == k){
            ret.push_back(comb);
            return;
        }
        for(int i=idx; i<numbers.size(); i++){
            comb.push_back(numbers[i]);
            help(numbers, comb, choice+1, i+1, k);
            comb.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> numbers;
        for(int i=0; i<n; i++)
            numbers.push_back(i+1);
        help(numbers, vector<int>(), 0, 0, k);
        return ret;
    }
};
