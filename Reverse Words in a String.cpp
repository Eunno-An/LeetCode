1차 22-06-04
Success
Time:10분 30초
Details 
Runtime: 5 ms, faster than 69.19% of C++ online submissions for Reverse Words in a String.
Memory Usage: 7.9 MB, less than 45.65% of C++ online submissions for Reverse Words in a String.
//이건 그냥 푼 풀이.
    string reverseWords(string s) {
        vector<string> temp_vec;
        string ret="";
        string temp = "";
        cout << s.size() << endl;
        for(int i=0; i<s.size(); i++){
            
            if(s[i] == ' ' && temp != ""){
                temp_vec.push_back(temp);
                temp = "";
            }else if(s[i] != ' ')
                temp += s[i];
        }    
        if(temp != "")
            temp_vec.push_back(temp);
        
        reverse(temp_vec.begin(), temp_vec.end());
        for(int i=0; i<temp_vec.size(); i++){
            ret += temp_vec[i];
            ret += " ";
        }
        ret.pop_back();
        return ret;
    }

Success
Details 
Runtime: 15 ms, faster than 27.54% of C++ online submissions for Reverse Words in a String.
Memory Usage: 7.2 MB, less than 79.55% of C++ online submissions for Reverse Words in a String.
//이게 Follow-up을 따라 푼 풀이? 5분 걸렸음.
class Solution {
public:
    /*
    문제:
    단어 단위로 끊어서 순서를 뒤집어라.
    단어 사이사이에 "여러개의 공백"이 있을 수도 있다!
    
    제한:
    
    해결방법:
    
    Follow-up: string data type이 너의 언어에 따라 mutable하다면, in-place로 추가 메모리 O(1)에 가능하겠는가?
    */
    
    
    
    string reverseWords(string s){
        string ret = "";
        string temp = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' ' && temp != ""){
                ret.insert(0, temp);
                ret.insert(0, " ");
                temp = "";
            }else if(s[i] != ' ')
                temp += s[i];
        }
        if(temp != "")
            ret.insert(0, temp);
        if(ret[0] == ' ')
            ret.erase(ret.begin());
        return ret;
    }
};
