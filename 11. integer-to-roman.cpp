//fail
//for문의 조건을 잘 봐라. i<num이 아니라 num 자체가 0이 되면 종료가 되게끔 하였다.
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
