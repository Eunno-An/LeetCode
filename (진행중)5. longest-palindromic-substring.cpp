class Solution {
public:
    //palindromic string: 뒤집어도 같은 문자열
    //투포인터로 접근. 근데 양끝에서부터 시작하지 말고, 가운데서 시작해서 바깥으로 나가는 형태로 짜자.
    
    //O((s.size()-1)/2 * 2): 점 (s.size()-1)/2 를 기준으로 왼쪽과 오른쪽 두번 다
    //O(s.size()): string이 palindrome인지 확인
    //O(s.size()): palindromic string인지 확인
    //대략 10억으로 T.C 예상.
    string longestPalindrome(string s) {
        int ret = 0;
        string retStr = "";
        int mid = s.size()/2;
        
        for(int i=0; i<s.size(); i++){
            for(int j = i; j<s.size(); j++){
                string subStr = s.substr(i, j-i+1);
                if(check_String(s.substr(i, j-i+1))){
                    if(ret < subStr.size()){
                        ret = subStr.size();
                        retStr = subStr;
                    }
                }
                
            }
        }
        return retStr;
    }
    bool check_String(string s){
        string origin = s;
        reverse(s.begin(), s.end());
        return origin == s ? true : false;
    }
    
};
