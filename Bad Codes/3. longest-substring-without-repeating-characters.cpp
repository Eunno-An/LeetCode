class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //나이브한 구현은 너무 느리다. 이걸 어떻게 해볼방법은 없을까?
        //슬라이딩 윈도우!
        int start_idx = 0, end_idx = 0;
        int ret = 0;
        set<char> dummy;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(dummy.find(c) == dummy.end()){
                dummy.insert(c);
                end_idx++;
            }
            else{
                if(ret < end_idx-start_idx)
                    ret = end_idx - start_idx;
                
                while(1){
                    if(start_idx == end_idx)
                        break;
                    if(s[start_idx] == c)
                        break;
                    dummy.erase(s[start_idx]);
                    start_idx++;
                }
                
                
            }
        }
        return ret == 0 ? dummy.size() : ret;
    }
};
