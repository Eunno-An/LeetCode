Success 2022-03-05
Time: 6분
Runtime: 752 ms, faster than 10.10% of C++ online submissions for Combinations.
Memory Usage: 165 MB, less than 9.44% of C++ online submissions for Combinations.

Success: 22-04-09
Time: 5분
Details 
Runtime: 32 ms, faster than 61.74% of C++ online submissions for Combinations.
Memory Usage: 19.1 MB, less than 28.15% of C++ online submissions for Combinations.
회고:
parameter들을 단순 int로 변경하니 효율성이 더 좋아짐. 2차 코드 첨부.
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
    
    //choice 값복사 말고 referencing을 통해 해결해야 한다.
    vector<vector<int>> ret;
    void help(int num, int n, vector<int>& choice, int k){
        if(choice.size() == k){
            ret.push_back(choice);
            return;
        }
        if(num == n+1)
            return;
        choice.push_back(num);
        help(num+1, n, choice, k);
        choice.pop_back();
        help(num+1, n, choice, k);
        return;
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> choice;
        help(1, n, choice, k);
        return ret;
    }
};
