Success
Time: 28분
Runtime: 388 ms, faster than 11.11% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram II.
Memory Usage: 29.2 MB, less than 11.11% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram II.

class Solution {
public:
  /*
  문제:
  두 문자열을 anagram으로 만들기 위한 각각의 횟수를 더해라!
  anagram : 순서는 달라도 각각 문자열에 들어가 있는 문자가 같음.
  
  해결방법:
  처음엔 unordered_multiset을 이용했지만
  시간초과가 계속 났음.
  생각해보니, multiset.erase는 해당되는 key들을 다 지우는 것으로 기억함.
  
  그렇다보니 같은 요소가 n개 있으면 
  지워야 할 요소의 개수에 선형에 비례하는 time도 추가로 걸린다는 것이다. 그래서 적절치 못하다.
  For the second version (erase(val)), logarithmic in container size, plus linear in the number of elements removed.
  
  */

    int minSteps(string s, string t) {
        unordered_map<char, int> ms, mt;
        for(int i=0; i<s.size(); i++){
            ms[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            mt[t[i]]++;
        }
        
        for(int i=0; i<t.size(); i++){
            if(ms.find(t[i]) != ms.end() && ms[t[i]]>0)
                ms[t[i]]--;
        }
        for(int i=0; i<s.size(); i++){
            if(mt.find(s[i]) != mt.end() && mt[s[i]]>0)
                mt[s[i]]--;
        }
        int ret=0;
        for(auto it : ms){
            ret += it.second;
        }
        for(auto it : mt){
            ret += it.second;
        }
        return ret;
    }
};
