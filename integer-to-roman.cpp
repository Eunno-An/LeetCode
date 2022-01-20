//fail
//for문의 조건을 잘 봐라. i<num이 아니라 num 자체가 0이 되면 종료가 되게끔 하였다.
//2차 복습 22-01-20. 좋은 문제는 아니였기 때문에 구현만 보고 넘김. 19번째 줄 잘보기.
/*
    문제:
    num이 주어지면 이걸 roman 표기법으로 바꿔라.
    단 num은 3999 이하.
    
    해결방법:
    어짜피 1, 4,5,9,10,40,50,90, ... , 1000까지 존재함. 이걸 큰 수부터 빼면 됨.
    */
*/
class Solution {
public:
    const int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string rom[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int num) {
        string ans = "";
        for(int i=0; num; i++)
            while(num>=val[i]) ans += rom[i], num -= val[i];
        return ans;
    }
};
