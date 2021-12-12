class Solution {
public:
    string calPrefix(string a, string  b){
        string ret = "";
        for(int i=0; i<min(a.size(), b.size()); i++){
            if(a[i] == b[i])
                ret+=a[i];
            else
                break;
        }
        return ret;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1)
            return strs[0];
        string ret = calPrefix(strs[0], strs[1]);
        for(int i=0; i<strs.size(); i++){
            for(int j=i+1; j<strs.size(); j++){
                string temp = calPrefix(strs[i], strs[j]);
                temp = calPrefix(temp, ret);
                if(ret.size() > temp.size())
                    ret = temp;
            }
        }
        return ret;
    }
};
