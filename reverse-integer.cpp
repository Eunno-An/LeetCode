//2022.01.15 두번째 풀이 완료. 시간 13분.
/*
문제:
    x라는 32비트 부호있는 정수가 주어질때, 그 숫자들을 뒤집은 x를 리턴해라.
    만약 뒤집은 x가 부호있는32비트 정수 표현을 넘어갈 때, 0을 리턴해라.
    (가정: 64비트 정수가 허용되지 않는 환경이라고 가정한다.)
*/
//첫 풀이 코드
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
    /*
    해결 방법:
    max_int와 min_int를 지정해주고,
    string의 reverse함수를 사용한다.
    여기서 중요한 점. custom 함수가 reverse고, 우리가 원하는 함수인 string::reverse함수가 이름이 같다.
    string::reverse함수를 사용하기 위해서는 ::reverse라고 써야 한다!!
    중요하다.
    
    실수한 점:
    1)max_int와 min_int를 할 때, 1<<31은 오버플로우가 발생한다. 1<<31은 -212312...8임. 즉 오버플로우 발생함. 따라서 long형으로 변환시켰음.
    2)x가 만약 min_int 보다 작은 값일 경우 오버플로우가 발생하게 된다.
    
    보완할 점:
    INT_MAX, INT_MIN을 그냥 지정해줘도 될뻔했다. 이 문제 자체에서의 
    */
    int reverse(int x) {
        //mistake 1)
        int max_int = ((long)1<<31)-1;
        int min_int = ((long)1<<31)*-1;
        
        bool isMinus = false;
        if(x < 0){
            if(x < min_int+1)
                return 0;
            x *= -1;//mistake 2)
            isMinus = true;
        }
        string strX = to_string(x);
        ::reverse(strX.begin(), strX.end());
        
        long lX = stol(strX);
        if(isMinus)
            lX *= -1;
        
        int ret;
        if(lX > max_int || lX < min_int)
            ret = 0;
        else
            ret = (int)lX;
        return ret;
    }
};

//push와 pop연산을 통해 구현함. 예외처리 반드시 필요함.
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
