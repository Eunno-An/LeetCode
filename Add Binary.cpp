Success
Details 
Runtime: 3 ms, faster than 73.74% of C++ online submissions for Add Binary.
Memory Usage: 6.3 MB, less than 84.64% of C++ online submissions for Add Binary.
 
 /*
 문제:
 a랑 b를 이진수로 더하는것임.
 
 제한:
 
 해결방법:
 일단 a랑 b 뒤집고, 항상 a의 길이를 더 길게 한다음에
 단순히 구현했음.
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int upper=0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.size() < b.size())
            swap(a, b);
        //항상 a의 길이가 더 길거나 같다.
        string ret;
        for(int i=0; i<b.size(); i++){
            char c_a = a[i];
            char c_b = b[i];
            int add = (c_a - '0') + (c_b-'0') + upper;
            if(add >= 2 ){
                add -= 2;
                upper=1;
            }
            else{
                upper=0;
            }
            ret.push_back(add+'0');
        }
        for(int i=b.size(); i<a.size(); i++){
            char c_a = a[i];
            int add = (c_a - '0') + upper;
            if(add == 2){
                add = 0;
                upper=1;
            }
            else{
                upper=0;
            }
            ret.push_back(add+'0');
        }
        if(upper == 1)
            ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
