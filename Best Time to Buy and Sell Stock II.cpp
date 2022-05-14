22-05-14 Fail
회고
코로나 걸리고 오랜만에 풀어서 그런지 .. 어려웠음
recursion을 통한 재귀 풀이로 해야 할듯.
class Solution {
public:
    /*
    문제:
    여러번 거래를 할 수 있다.
    121번 문제는 한번 트랜잭션 할 수 있었는데
    이건 여러번 트랜잭션 하는 거임.
    
    제한:
    
    해결방법:
    
    */
    int find(vector<int>& prices, int idx, bool buy, vector<vector<int>> & v){
        // prices에 있는걸 다 썼을 때
        if(idx >= prices.size() ) return 0;
        
        //caching
        if(v[idx][buy] != -1) return v[idx][buy];
        
        
        if(buy){
            return v[idx][buy] = max(-prices[idx] + find(prices, idx+1,  !buy, v), find(prices, idx+1,  buy, v));
            
        }
        else{
            
            return v[idx][buy] = max(prices[idx] + find(prices,idx+1,  !buy, v), find(prices, idx+1, buy, v));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> v(n, vector<int>(2, -1));
        return find(prices, 0, 1, v);
    }
};
