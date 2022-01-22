class Solution {
public:
    /*
    문제:
    pow(x, n)을 구현해라.
    해결방법:
    1)return pow(x, n). 만약 custom function과 library function 이 같으면 ::pow(x,n)사용하기.
    2)iterative
    3)recursive
    유의할점:
    
    */
    //iterative
   
    double myPow(double x, int n) {
        double res = 1;
        while (n) {
            if (n % 2) res = n > 0 ? res * x : res / x;
            x = x * x;
            n /= 2;
        }
        return res;
    }

    //recursive
    double myPow(double x, int n, double res = 1) {
        return n? myPow(x*x, n/2, n%2?(n>0?res*x:res/x):res):res;
    }
};
