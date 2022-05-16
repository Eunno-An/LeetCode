1차 Success 22-05-16
Time: 15분 45초
Success
Details 
Runtime: 170 ms, faster than 53.27% of C++ online submissions for Palindrome Partitioning.
Memory Usage: 75.7 MB, less than 41.68% of C++ online submissions for Palindrome Partitioning.
class Solution {
public:
    /*
    문제:
    s가 주어진다. s를 partition하는데, 각 요소들이 palindrom string이 되도록 하라.
    모든 가능한 경우를 다 리턴하라.
    
    제한:
    
    해결방법:
    -> 단순 재귀로 접근.
    -> 최적화 방법: unordered_map을 이용해 기존에 구한 palindrom은 안구해도 될거같음.
    */
    vector<vector<string>> ret;
    unordered_map<string, bool> bucket;
    bool isPalindrom(string s){
        string temp = s;
        reverse(s.begin(), s.end());

        return temp == s;
    }
    void partitioning(string s, vector<string>& temp){
        if(s.empty()){
            ret.push_back(temp);
            return;
        }
        for(int i=1; i<=s.size(); i++){
            string t = s.substr(0, i);
            if((bucket.find(t) != bucket.end() && bucket[t] == true) || isPalindrom(t)){
                bucket[t] = true;
                temp.push_back(t);
                partitioning(s.substr(i, s.size()-i), temp);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        partitioning(s, temp);
        return ret;
    }
};
