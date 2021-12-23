//13분 40초
//단순 구현 문제.
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        map<char, string> number;
        number['2']="abc";
        number['3']="def";
        number['4']="ghi";
        number['5']="jkl";
        number['6']="mno";
        number['7']="pqrs";
        number['8']="tuv";
        number['9']="wxyz";
        vector<string> ret;
        
        for(int i=0; i<digits.size(); i++){
            string str_i = number[digits[i]];
            vector<string> temp;
            
            if(i == 0){
                
                for(int j=0; j<str_i.size(); j++){
                    temp.push_back(string(1, str_i[j]));
                }
                ret = temp;
                continue;
            }
            for(int j=0; j<ret.size(); j++){
                for(int k=0; k<str_i.size(); k++){
                    temp.push_back(ret[j] + string(1, str_i[k]));
                }
            }
            ret = temp;
            
        }
        return ret;
    }
};
