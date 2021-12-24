//위에건 내가 푼 거고
//아래꺼는 Discussion의 맨 위의 코드를 참조.
//정말 와...라는 소리밖에 안나온다. ㅋㅋ
class Solution {
public:
    //26분 36초.
    //4 ms, faster than 41.06%
    /*
    1. double을 이용.
    -> double 변수를 to_string() 하면 밑에 있는 소수점까지 모두 다 string으로 변환되니 주의할것.!!!!!
    */
    int reverse(int x) {
        if(x == 0)
            return 0;
        
        double dx = (double)x;
        bool isMinus = (dx < 0 ? true: false);
        
        string str_x = to_string((int)dx);
        string reverse_x = "";
        for(int i=str_x.size()-1; i>=0; i--)
            reverse_x.push_back(str_x[i]);
        
        cout << str_x << ' '  << reverse_x << '\n';
        double rev_dx = stod(reverse_x);
        int ret = 0;
        if(isMinus)
            rev_dx *= -1;
        
        if(INT_MIN <= rev_dx && rev_dx <= INT_MAX)
            ret = (int)rev_dx;
        
        return ret;
            
        
    }
};

class Solution {
public:
    int reverse(int x) {
        int y=0;
        while(x){
            if(y>INT_MAX/10 || y<INT_MIN/10){
                return 0;
            }else{
                y=y*10 +x%10;
                x=x/10;
            }
        }
        return y;
    }
};

/*
y = 3, x = 12
y = 32, x = 1
y = 321, x = 0

x = -123

y = -123 mod 10 = -3, x = -12
y = -32, x = -1

x = 1,234,567,899

y = 998, 765, 432, x = 1


*/
