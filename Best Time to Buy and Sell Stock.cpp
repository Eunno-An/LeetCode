1차 22-04-20
Success
Time: 33분
Details 
Runtime: 207 ms, faster than 22.75% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 94.9 MB, less than 8.14% of C++ online submissions for Best Time to Buy and Sell Stock.
회고:
은근 쉬우면서도 어렵다... Discussion에서 깔끔한 코드 첨부했다.
  class Solution {
public:
    /*
    문제:
    i번째 날에 가격이 prices[i]인 prices 배열이 주어진다.
    나의 이익을 최대화 시킬 수 있는 매수하는 하루만을 선택하고,
    그리고 매도하는 하루를 선택한다.
    이때 가장 maximum profit을 구하라.
    만약 어떠한 이익도 얻지 못하면, 0을 리턴해라.
    
    제한:
    1<=prices.length <= 100000
    0<=prices[i]<=10000
    
    해결방법:
    1)BF
    각 인덱스 두개를 뽑아서 max(0, prices[j] - prices[i])을 갱신한다.
    ->시간 초과
    
    2)stack
    
    while(stack.top() >= prices[i])
        stack.pop();
    
    */
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        deque<int> d;
        for(int i=0; i<prices.size(); i++){
            int price = prices[i];
            while(!d.empty() && d.back() > price)
                d.pop_back();
            d.push_back(price);
            
            int profit = d.empty() ? 0 : d.back()-d.front();
            ret = max(ret, profit);
        }
        return ret;
    }
};

//Discussion 참고
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/1735493/JavaC%2B%2B-best-ever-EXPLANATION-could-possible
{
        int lsf = Integer.MAX_VALUE; // least so far
        int op = 0; // overall profit
        int pist = 0; // profit if sold today
        
        for(int i = 0; i < prices.length; i++){
            if(prices[i] < lsf){ // if we found new buy value which is more smaller then previous one
                lsf = prices[i]; // update our least so far
            }
            pist = prices[i] - lsf; // calculating profit if sold today by, Buy - sell
            if(op < pist){ // if pist is more then our previous overall profit
                op = pist; // update overall profit
            }
        }
        return op; // return op 
