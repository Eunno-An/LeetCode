1차 22-04-05
Success
Time: 48분
Details 
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Restore IP Addresses.
Memory Usage: 7.2 MB, less than 17.16% of C++ online submissions for Restore IP Addresses.
회고:
재귀의 for문을 이중으로 했음. 사실 그럴 필요가 없었는데 함수 틀을 잘못짬.
그리고 idx+j < s.size()로 해서 계속 답이 안나왔음. idx+j<=s.size(), 즉 등호로 바꿔야 함. 왜냐하면 마지막 문자열이 포함되어야 하기 때문!! 
255.255.11.135에서 등호가 안들어가면 11.13까지만 보고 그만두게 됨. 잘 생각해보면 i+j번째도 포함되어야 하므로.. 주의!!

2차 22-05-14
Success
Time: 22분
Success
Details 
Runtime: 4 ms, faster than 50.10% of C++ online submissions for Restore IP Addresses.
Memory Usage: 7.9 MB, less than 10.57% of C++ online submissions for Restore IP Addresses.
회고: 
왠지 모르겠는데 1차보다는 성능은 안좋지만 훨씬 빨리 풀었음.
문제를 잘 읽어야 한다. 029는 valid 숫자가 아니다.
그리고 확실히 오랜만에 짜다보니까 for문에서 매끄럽지 못한게 느껴진다. 2차 코드 첨부하겠음.
class Solution {
public:
    /*
    문제:
    타당한 ip주소는
    single dots에 분리된 정확히 네개의 정수로 되너있다.
    각 숫자는 0부터 255이다. 연속된 0은 없다.

    s가 주어진다. 숫자로만 이루어져있다.
    가능한 ip address들을 모두 리턴해라.
    s의 숫자들을 재배열하거나 지우는건 허용되지 않는다.

    제한:
    s의 길이는 1이상 20이하.

    해결방법:
    1)브루트포스.
    -> string s를 쪼갠다. 점을 각각의 인덱스에 할당한다.
    -> ""부터 시작해서 처음 부분을 넣고, 그다음엔 .을 추가한다.
    void help(string nowIp, string temp, int dotCount)
    */
    vector<string> ret;
    bool ok(string strNum) {
        if (1 <= strNum.size() and strNum.size() <= 3 and 0 <= stoi(strNum) and stoi(strNum) <= 255) {
            if (strNum.size() >= 2 and strNum[0] == '0')
                return false;
            else
                return true;
        }
        return false;
    }
    void help(vector<string>& nowIp, string& s, int idx) {

        if (nowIp.size() == 4 and idx == s.size()) {
            string temp = "";
            for (int i = 0; i < nowIp.size(); i++) {
                temp += nowIp[i];
                temp += ".";
            }
            temp.pop_back();
            ret.push_back(temp);
            return;
        }
        else if (nowIp.size() == 4 and idx != s.size())
            return;

        
        for (int j = 1; j <= 3 && idx + j <= s.size(); j++) {
            string num = s.substr(idx, j);

            if (ok(num)) {
                //cout << num << endl;
                nowIp.push_back(num);
                help(nowIp, s, idx + j);
                nowIp.pop_back();

            }
        }
        
        return;

    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> nowIp;
        help(nowIp, s, 0);
        return ret;
    }
};


//2차 코드
class Solution {
public:
    /*
    문제:
    문자열 s가 주어지면
    가능한 valid ip를 모두 리턴해라.
    
    제한:
    
    해결방법:
    
    */
    vector<string> ret;
    string getIp(vector<string> make){
        string temp = "";
        for(int i=0; i<make.size(); i++){
            temp += make[i];
            temp += '.';
        }
        temp.pop_back();
        return temp;
    }
    void makeIp(vector<string>& make, string s){
        if(make.size() == 4){
            if(s.empty())
                ret.push_back(getIp(make));
            return;
        }
        int num = 0;
        
        if(s.size() >= 1){
            make.push_back(s.substr(0, 1));
            makeIp(make, s.substr(1));
            make.pop_back();
        }
        if(s.size() >= 2){
            num = stoi(s.substr(0, 2));
            if(num >= 10 && num <= 99){
                make.push_back(to_string(num));
                makeIp(make, s.substr(2));
                make.pop_back();
            }
        }
        
        if(s.size() >= 3){
            num = stoi(s.substr(0, 3));
            if(num >= 100 && num <= 255){
                make.push_back(to_string(num));
                makeIp(make, s.substr(3));
                make.pop_back();
            }
        }
        return;
        
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> make;
        makeIp(make, s);
        return ret;
    }
};
