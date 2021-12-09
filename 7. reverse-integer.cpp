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
