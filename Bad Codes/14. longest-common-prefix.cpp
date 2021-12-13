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


//네번째 해결 방법
//분할 정복!
//Runtime: 4 ms, faster than 71.16% of C++ online submissions for Longest Common Prefix.
//Memory Usage: 12.3 MB, less than 8.48% of C++ online submissions for Longest Common Prefix.
//IF문 실수 했던것 잘 보자!
class Solution {
public:
    string getPrefix(string a, string b){
        string ret = "";
        for(int i=0; i<min(a.size(), b.size()); i++){
            if(a[i] != b[i])
                return ret;
            ret += a[i];
        }
        return ret;
    }
    string divideNConquer(int start, int end, vector<string>& strs){
        
        if(start == end)
            return strs[start];
        //아래 코드는 start == end일 때를 처리할 수 없다.
        //if(start + 1 == end){
        //    return getPrefix(strs[start], strs[end]);
        //}
        
        int mid = (start + end)/2;
        string leftP = divideNConquer(start ,mid, strs);
        string rightP = divideNConquer(mid+1, end, strs);
        return getPrefix(leftP, rightP);
    }
    string longestCommonPrefix(vector<string>& strs) {
        return divideNConquer(0, strs.size()-1, strs);
    }
};
