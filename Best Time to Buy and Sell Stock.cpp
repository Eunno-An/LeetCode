1차 22-04-20
Success
Time: 33분
Details 
Runtime: 207 ms, faster than 22.75% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 94.9 MB, less than 8.14% of C++ online submissions for Best Time to Buy and Sell Stock.
회고:
은근 쉬우면서도 어렵다... Discussion에서 깔끔한 코드 첨부했다.
  
2022-05-14 내용 추가
Recursion풀이 추가하였음.
  Best Time to Buy and Sell Stock2.cpp
  Best Time to Buy and Sell Stock3.cpp
  풀이에 도움이 되는 코드 첨부함.
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
}
//recursion
int find(vector<int>& prices, int idx, int trx_num, bool buy, vector<vector<int>> & v){
        //만약 더이상 거래를 할 수 없고, prices에 있는걸 다 썼을 때
        if(idx >= prices.size() || trx_num <= 0) return 0;
        
        //caching
        if(v[idx][buy] != -1) return v[idx][buy];
        
        
        if(buy){//무언가 stock을 사야할 때
            //다음번에는 이 주식을 팔아야 겠지. 현재 prices[idx]가격의 주식을 산거니까. 이게 -prices[i]+find(prices,idx+1, k, !buy, v)
            //근데 바로 다음에 안팔고 그냥 넘어가! 이게 find(prices, idx+1, k, buy, v)이고.
            return v[idx][buy] = max(-prices[i] + find(prices, idx+1, trx_num, !buy, v), find(prices, idx+1, trx_num, buy, v));
            
        }
        else{
            //이제 팔 시간이야. trx_num을 감소시켜야겠지 이게 prices[idx] + find(prices, idx+1, trx_num-1, !buy, v)이고
            //find(prices, idx+1, k, buy, v)는 안팔고 그냥 다음으로 넘어간거지.
            return v[idx][buy] = max(prices[idx] + find(prices,idx+1, trx_num-1, !buy, v), find(prices, idx+1, k, buy, v));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> v(n, vector<int>(2, -1));
        return find(prices, 0, 1, 1, v);
    }
