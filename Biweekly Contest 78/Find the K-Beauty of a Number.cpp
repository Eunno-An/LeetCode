1차 22-05-28
Success 
Time 5분
class Solution {
public:
/*
문제:
정수 num의 k뷰티는 
1) k의 길이를 가져야 하고
2) num의 divisor이다. 
그리고 num의 substring이다.

num과 k가 주어지면 num의 k뷰티를 구하여라.

제한:
num은 십억.

해결방법:
정수와 문자열 간의 자료형 전환 및 substr 
*/
    int divisorSubstrings(int num, int k) {
        string num_str = to_string(num);
        int n = num_str.size();
        int ret = 0;
        for(int i=0; i+k <= n; i++){
            int temp = stoi(num_str.substr(i, k));
            if(temp == 0)
                continue;
            if(num % temp == 0)
                ret++;
        }
        return ret;
    }
};
