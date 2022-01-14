//Success.

//예외처리가 중요한 구현 문제.
//Runtime: 4 ms, faster than 97.86% of C++ online submissions for Zigzag Conversion.

//잘 구현했지만 시간이 너무 오래걸렸음. 40~50분 정도.
//그것보다 직관적인 구현들을 아래에 적어놨으니 볼것.
class Solution {
public:
    string convert(string s, int numRows) {
    int n = s.size();
    if (n == 1 || numRows == 1 || n <= numRows)
        return s;

    string ret = "";
    int jump = 2 * numRows - 2;
    for (int i = 0; i < n; i += jump)
        ret += s[i];

    int startIdx = 1;
    int jump2;
    while (ret.size() < n) {
        numRows--;

        jump = 2 * numRows - 2;
        jump2 = startIdx * 2;


        for (int i = startIdx; i < n; i += jump2) {
            ret += s[i];
            if (jump == 0)
                continue;
            else if (i + jump < n) {
                ret += s[i + jump];
                i += jump;
            }
            else if (i + jump >= n)
                break;
        }
        startIdx++;
    }
    return ret;
}
};

//진짜 지그재그로 가는것을 구현함.
class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        vector <string> tmp(numRows);                                                         //create strings for each row
        int i=0, n=s.size();
        while(i<n){                                      
            for(int j=0;j<numRows && i<n; j++, i++) tmp[j] += s[i];               //add for our strings character when we move down
            for(int j=numRows - 2;j>0 && i<n; j--, i++) tmp[j] += s[i];            //add for our strings character when we move up exept first and last string
        }
        for(int j=0;j<numRows; j++) ans += tmp[j];                                       //combain together our strings
        return ans;
    }
};
