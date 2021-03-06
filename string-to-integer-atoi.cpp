//fail
//22.01.15 코드 복습 완료. 풀지는 않고 한번 훑기만 함.
//문제: 조건에 맞게 atoi 함수를 구현하는 것. 
//해결 방법: 정말 문제에 써 있는대로 구현하면 됨. 영어라 좀 어려움
//회고: overflow 체크하는 방법. interview에서 long을 쓰지 말고 오버플로우 체크 하라고 하면 이런식으로 해야함.214748364가 INT_MAX/10이고, 결국 INT_MIN은 =-2147483648이니까, digit이 8 이상이면 
//오버플로우가 난다고 가정해도 되는 것임.

//아래것은 굉장히 깔끔하게 짠 코드 참조함.
//51~53 참조하기. https://leetcode.com/problems/string-to-integer-atoi/discuss/1402936/JAVA-C%2B%2B-%3A-Simple-or-Easy-or-32-bit-int-or-Faster-than-100-or-Explained
//실패요인: 영어 해석 실력이 딸림.
//1. Read in and ignore any leading whitespace. : "선행"공백을 무시하는 것임. s의 모든 공백을 무시하는것이 아님. 문제를 애초에 잘못 접근하였음.


class Solution {
public:
  int myAtoi(string s) {
      
    const int len = s.size();

    if(len == 0){
        return 0;
    }

    int index = 0;

    // skipping white spaces
    while(index < len && s[index] == ' '){
        ++index;
    }

    // to handle sign cases
    bool isNegative = false;

    if(index < len){

      if(s[index] == '-'){
        isNegative = true;
        ++index;
      } else if (s[index] == '+'){
          ++index;
      }

    }

    int result = 0;

    // converting digit(in character form) to integer form
    // iterate until non-digit character is not found or we can say iterate till found character is a digit
    while(index < len && isDigit(s[index])){

      /* s[index] - '0' is to convert the char digit into int digit eg: '5' - '0' --> 5
      or else it will store the ASCII value of 5 i.e. 53,
      so we do 53(ASCII of 5) - 48(ASCII of 0(zero)) to get 5 as int*/
      int digit = s[index] - '0';

      // to avoid integer overflow
      if(result > (INT_MAX / 10) || (result == (INT_MAX / 10) && digit > 7)){
          return isNegative ? INT_MIN : INT_MAX;
      }

      result = (result * 10) + digit; // adding digits at their desired place-value

      ++index;
    }
      
    return isNegative ? -result : result;
  }
    
private:
  bool isDigit(char ch){
    return ch >= '0' && ch <= '9';
  }
};
