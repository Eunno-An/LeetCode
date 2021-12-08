//Success.
//예외처리가 중요한 구현 문제.
//Runtime: 4 ms, faster than 97.86% of C++ online submissions for Zigzag Conversion.

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
