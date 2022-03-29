1차 Success
2차 Success 22-03-29 
class Solution {
public:
    /*
    문제:
    
    해결방법:
    stringstream으로 쓰기에는 공백이 너무 많다.
    그래서 그냥 순회하는 방법으로.
    마지막에 temp가 안비었을 경우도 생각해주어야한다.
    굳이 bucket으로 안하고 maxLength만 구하는 것이므로 메모리는 안써도 될 것 같다.
    
    회고:
        ->2차는 s를 연속된 공백을 공백 하나로 만드는 코드로 수정하였ㅇ므.
    */
    int lengthOfLastWord(string s) {
        string temp="";
        vector<string> bucket;
        for(int i=0; i<s.size(); i++){
            if(s[i] != ' '){
                temp+=s[i];
            }else{
                if(temp.empty())
                    continue;
                bucket.push_back(temp);
                temp.clear();
            }
        }
        if(!temp.empty())
            bucket.push_back(temp);
        return bucket.back().length();
    }
};
