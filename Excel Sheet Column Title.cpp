1차 22-06-12 Fail
이유? 쉬운 문젠데 구현을 못했음... 왜일까??
  외박 갔다와서 너무 피곤하다..
class Solution {
public:
    /*
    문제:
    columnNumber라는 정수가 주어지면, 상응하는 column title을 나타내라.
    
    제한:
    
    해결방법:
    columnNumber를 26으로 나눈다. 
    */
    string convertToTitle(int columnNumber) {
        string s = "";
        columnNumber--;
        while(columnNumber >=0 ){
            s += ('A' + columnNumber % 26);
            columnNumber /= 26;
            columnNumber--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
//div = 22 
//4561 FSK

//
