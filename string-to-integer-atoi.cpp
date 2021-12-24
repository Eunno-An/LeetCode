//fail
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
