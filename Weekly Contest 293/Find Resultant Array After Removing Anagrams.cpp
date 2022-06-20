1.
6분
문제:

words라는 배열이 주어진다. words[i]는 영어 소문자이다.
한번의 동작에서 i라는 인덱스를 선택하는데, words[i-1]과 words[i]는 anagram인 words[i]를 words에서 지워버린다.
이러한 조건을 만족하는 인덱스를 선택할 수 있는 한 계속 수행한다.
모든 동작들을 수행한 뒤의 words를 리턴해라.
Anagram = 구성 요소가 같은 문자열

제한:
words의 길이는 100이하, words[i]의 길이는 10 이하.

해결방법:
1) 문자열을 이용한 단순 구현
2) 🎃문자열을 사용하지 않고, two-pointer를 이용한 풀이 (Discussion 참고: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/discuss/2039931/2-Pointers-oror-Without-sorting)


나의 풀이:

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ret;
        int n = words.size();
        for(int i=0; i<n; i++){
            string temp = words[i];
            sort(temp.begin(), temp.end());
            
            if(ret.empty()){
                ret.push_back(words[i]);
                continue;
            }
            string last = ret.back();
            sort(last.begin(), last.end());
            if(last != temp)
                ret.push_back(words[i]);
        }
        return ret;
    }
};

//Discussion 풀이
vector<string> removeAnagrams(vector<string>& A) {
    vector<string> ans;
    int n= size(A);
    for(int i=0;i<n;){
        int j=i+1;
        while( j<n and isang(A[i],A[j]) ) j++;
        ans.push_back(A[i]);
        i=j;
    }
    return ans;
}
//function for checking if two string are anagrams or not
bool isang(string p,string q){
    vector<int> cnt(26);
    int res=0;
    for(auto i:p) cnt[i-'a']++;
    for(auto i:q) cnt[i-'a']--;         
    for(auto i:cnt) if(i!=0) return false;
    return true;
}
