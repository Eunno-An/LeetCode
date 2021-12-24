//Success. 기존 코드는 Bad Codes에 갖다 놓겠음.
//처음 해결 방법: Runtime: 40 ms, faster than 5.45% of C++ online submissions for Roman to Integer.
//반드시 주의해야 할 사항. string s 의 i번째 요소 s[i]는
//string one = s[i] 이렇게 하면 one은 기대한 값과 다를 수 있다.

//아래 코드는 잘 푼 사람꺼 갖다놓음. 되게 직관적임.
//왜 if(4 * num < ans) ans -= num인가? 
//왜 S.size()-1부터 앞으로 탐색하는가?
//~i의 의미는 무엇인지?

class Solution {
public:
    int romanToInt(string S) {
        int ans = 0, num = 0;
        for (int i = S.size()-1; ~i; i--) {
            switch(S[i]) {
                case 'I': num = 1; break;
                case 'V': num = 5; break;
                case 'X': num = 10; break;
                case 'L': num = 50; break;
                case 'C': num = 100; break;
                case 'D': num = 500; break;
                case 'M': num = 1000; break;
            }
            if (4 * num < ans) ans -= num;
            else ans += num;
        }
        return ans;        
    }
};
