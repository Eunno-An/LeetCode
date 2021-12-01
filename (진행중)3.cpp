class Solution {
    //dvdf
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> dummy;
        int maxSize = 0;
        int checkLength = 0;
        for(int i=0; i<s.size(); i++){
            char one = s[i];
            if(dummy.find(one) == dummy.end()){
                dummy.insert(make_pair(one, i));
                checkLength++;
                if(checkLength > maxSize)
                    maxSize = checkLength;
            }
            else{
                int before_idx = dummy[one];
                checkLength = i - before_idx;
                if(maxSize < checkLength)
                    maxSize = checkLength;
                
                dummy[one] = i;
                
                
            }
                
        }
       
        return maxSize;
    }
};
