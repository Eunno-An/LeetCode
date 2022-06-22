1.
8분 38초
brackets라는 2차원 정수 배열이 주어진다.
brackets[i] = [upper_i, percent_i]
i번째 tax bracket은 upper_i의 상한을 갖고 있고, percent_i로 부과된다.
brackets는 upper bound에 의해 sorting 된다.

tax 계산은 다음과 같다.
-> 첫 upper_0 dollar는 percent_0의 비율로 세금이 부과된다.
-> 그 다음 upper_1 - upper_0 dollar는 percent_1의 비율로 세금이 부과된다.
-> and so on

income이라는 정수가 주어진다. income은 너가 번 돈의 양을 의미한다.
세금을 부과해야 하는 돈의 양을 리턴해라.
오차는 10^-5까지 허용된다.

제한:
해결방법:
단순 구현
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int n = brackets.size();
        double ret = 0.0;
        for(int i=0; i<n; i++){
            int up = brackets[i][0];
            if(i >= 1)
                up -= brackets[i-1][0];
            int percent = brackets[i][1];
            if(up < income){
                ret += (double)up * (double)percent / 100;
                income -= up;
            }else{
                ret += (double)income * (double)percent / 100;
                break;
            }
        }
        return ret;
    }
};
//Discussion코드. 내가 얼마나 좇밥인지 알 수 있는 겸손해지는 코드이다.
double calculateTax(vector<vector<int>>& b, int income) {
    double res = 0, prev = 0;
    for (int i = 0; i < b.size(); prev = b[i++][0])
        res += max(0.0, (-prev + min(income, b[i][0])) * b[i][1] / 100);
    return res;
}
