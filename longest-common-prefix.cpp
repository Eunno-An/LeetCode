//Success
//이 부분은 공부할게 많은 부분임. 전체 문자열들의 공통 접두사를 찾는 문젠데, 해결방법이 정말 다양하다.
//기존 것도 BadCodes에 옮겨놨음.
//Runtime: 104 ms, faster than 5.10% of C++ online submissions for Longest Common Prefix.

//2021-12-13 추가.
//두번째 해결 방법
//기존 해결 방법: N^2번 for문을 돌았음. 
//근데 이럴 필요가 없이 그냥 N번만 돌면 됨.
//prefix(S1, S2, S3, ..., Sn) = prefix(...prefix(S1, S2), S3), S4), ... , Sn)

//2022-01-20 두번째 풀이. 성공
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string comp = strs[0];
        
        for(int i=1; i<strs.size(); i++){
            string now = strs[i];
            int lastIdx = 0;
            for(int j=0; comp.size() > j && j<now.size(); j++){
                if(comp[j] == now[j])
                    lastIdx = j+1;
                
                else if(comp[j] != now[j])
                    break;
            }
            comp = now.substr(0, lastIdx);
        }
        return comp;
    }
};

//아래의 방법들 외에도, 이분탐색, Trie 들로 푸는 방법이 있으니 더 참고해보자.
//https://leetcode.com/problems/longest-common-prefix/solution/
/*
Runtime: 4 ms, faster than 71.16% of C++ online submissions for Longest Common Prefix.
Memory Usage: 9.6 MB, less than 13.41% of C++ online submissions for Longest Common Prefix.
*/
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
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1)
            return strs[0];
        
        string prefix = getPrefix(strs[0], strs[1]);
        for(int i=2; i<strs.size(); i++)
            prefix = getPrefix(prefix, strs[i]);
        return prefix;
    }
};

//위 코드를 좀 더 수정하자면, 
//string의 find함수를 이용하여 더 쉽게 만들 수 있음.
/*
Runtime: 4 ms, faster than 71.16% of C++ online submissions for Longest Common Prefix.
Memory Usage: 9.2 MB, less than 43.74% of C++ online submissions for Longest Common Prefix.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        
        for(int i=1; i<strs.size(); i++)
            while(strs[i].find(prefix) != 0){//flow.find(flower) = 큰 양수 리턴함.
              //prefix를 찾을떄 까지 확인한다.
                prefix = prefix.substr(0, prefix.size() - 1);
                if(prefix == "") return "";
            }
        return prefix;
    }
};
//세번째 해결 방법
//위 방법과 비슷한 방법이지만, 조금은 다른 방법
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0) return "";
    for (int i = 0; i < strs[0].length() ; i++){
        char c = strs[0].charAt(i);
        for (int j = 1; j < strs.length; j ++) {
            if (i == strs[j].length() || strs[j].charAt(i) != c)//i번째 문자열이 만약 c가 아니라면 바로 종료. 또는 i가 strs[j]의 size를 넘어간 경우!
                return strs[0].substring(0, i);             
        }
    }
    return strs[0];//전체 문자열이 다 같을 경우!
}


//네번째 해결 방법: BadCodes
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
