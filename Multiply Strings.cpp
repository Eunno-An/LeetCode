/*
Fail
문제:
문자열로 표시된 nums1, nums2가 있다. 각각은 음이 아닌 정수이고
nums1와 nums2의 곱을 구하여라. 단, string으로 리턴해야 한다.


해결 방법
1) 간단한 방법.
stoi(num1)*stoi(num2).
하지만 num1과 num2의 자릿수가 매우 길다.
이건 안되는 방법

2) 각각의 숫자를 한 자리씩 곱하는 것.
핵심 아이디어?
->num1과 num2를 reverse 한다. for문을 구현하기 편해진다.
->단순히 십의 자리 수까지 밖에 안나오니 결과를 처리하기도 쉽다.


회고
실수한 점?
1)반드시 upper는 inner for문 안에서 처리해주어야 한다. 즉, i와 j의 연산 결과 carry가 발생되면 그 for문 안에서 i+j+1번째에 carry를 더해주어야 한다.
그렇지 않으면 이상한 곳에 carry를 더해주게 되는 실수를 하게 된다.
2)기존에 save[i+j]가 있으면 더해주어야 한다.
3)vector<char> save(num1.size() * num2.size() + 1, '\0'); 이런 식으로 답을 구현했었는데, 그러기보단
string ret(num1.size() + num2.size())로 하면 됐을 것이다. 그리고 NULL 문자가 아닌 '0'으로 초기화 해주면 예외처리할 것도 줄어들 것이고!
사소한 하나하나에서 좋은 코딩 나쁜 코딩이 차이나는 것 같다.


*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        // Reverse num1 and num2.
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        // Initialize answer as a string of zeros of length N.
        int N = num1.size() + num2.size();
        string answer(N, '0');
        
        for (int place2 = 0; place2 < num2.size(); place2++) {
            int digit2 = num2[place2] - '0';
            
            // For each digit in num2 multiply the digit by all digits in num1.
            for (int place1 = 0; place1 < num1.size(); place1++) {
                int digit1 = num1[place1] - '0';
                
                // The number of zeros from multiplying to digits depends on the 
                // place of digit2 in num2 and the place of the digit1 in num1.
                int numZeros = place1 + place2;
                
                // The digit currently at position numZeros in the answer string
                // is carried over and summed with the current result.
                int carry = answer[numZeros] - '0';
                int multiplication = digit1 * digit2 + carry;
                
                // Set the ones place of the multiplication result.
                answer[numZeros] = (multiplication % 10) + '0';
                
                // Carry the tens place of the multiplication result by 
                // adding it to the next position in the answer array.
                answer[numZeros + 1] += (multiplication / 10);
            }
        }
        
        if (answer.back() == '0') {
            answer.pop_back();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
