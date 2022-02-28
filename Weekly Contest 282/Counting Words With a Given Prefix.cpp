Success
Details 
Runtime: 11 ms, faster than 77.78% of C++ online submissions for Counting Words With a Given Prefix.
Memory Usage: 9.8 MB, less than 77.78% of C++ online submissions for Counting Words With a Given Prefix.
class Solution {
    /*
    문제:
    pref와 문자열 배열 words가 주어진다.
    prefix로써 pref를 갖고 있는 words안의 단어들의 개수를 리턴해라.
    
    제한:
    
    해결방법:
    */
public:
    int prefixCount(vector<string>& words, string pref) {
        int ret = 0;
        for(int i=0; i<words.size(); i++){
            int matchCount = 0;
            for(int j=0; j<words[i].size() && j<pref.size(); j++){
                if(words[i][j]!=pref[j])
                    break;
                matchCount++;
            }
            if(matchCount == pref.size())
                ret++;
        }    
        return ret;
    }
};
