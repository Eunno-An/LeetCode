class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_set<string> bucket;
        int n = s.size();
        string temp = "";
        for(int i=0; i<n; i++){
            temp += s[i];
            bucket.insert(temp);
        }
        int m = words.size();
        int ret = 0;
        for(int i=0; i<m; i++){
            if(bucket.find(words[i]) != bucket.end())
                ret++;
        }
        return ret;
    }
};
