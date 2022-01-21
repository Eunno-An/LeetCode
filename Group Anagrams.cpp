class Solution {
public:
    /*
    Success 35분
Details 
Runtime: 58 ms, faster than 34.96% of C++ online submissions for Group Anagrams.
Memory Usage: 21.7 MB, less than 22.64% of C++ online submissions for Group Anagrams.
    
    문제:
    string 배열 strs가 주어지면, anagrams끼리 그룹을 지어라. 순서는 상관없다.
    anagram이란 ? 서로 다른 구나, 절들을 재배열하면 같은게 되는 것이다.
    
    해결방법:
    strs[i]들을 해싱하는 것이다.
    strs[i]들의 문자 하나하나의 아스키값을더한 pair를 키로 한다.
    ->근데 이러면 문자열은 다른데, 키값은 같은 경우가 발생한다.예시: ["aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzztttttttttt"]
    ->따라서 문자열을 키값으로 잡아야 한다.
    
    회고:
    unordered_map은 key로 pair값을 사용하지 못한다!!!!!!!!!!
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> ret;
        for(int i=0; i<strs.size(); i++){
            string nowStr = strs[i];
            string original = strs[i];
            sort(nowStr.begin(), nowStr.end());
            
            if(hash.find(nowStr) == hash.end())
                hash.insert({nowStr, {original}});
            else
                hash[nowStr].push_back(original);
            
        }
        
        for(auto it : hash)
            ret.push_back(it.second);
        return ret;
    }
};
