Success
Time:19:00
Details 
Runtime: 8 ms, faster than 89.32% of C++ online submissions for Minimum Path Sum.
Memory Usage: 9.8 MB, less than 59.96% of C++ online submissions for Minimum Path Sum.
회고:
memset으로 최댓값 초기화는 지양!!!!!!!!!!!!!!!!! memset은 0이나 1만 가능하다구...
2차 Success. 22-04-03
Time: 07:00
Runtime: 19 ms, faster than 21.25% of C++ online submissions for Minimum Path Sum.
Memory Usage: 9.8 MB, less than 64.16% of C++ online submissions for Minimum Path Sum.
class Solution {
public:
    /*
    문제:
    양수로 차 있는 격자가 주어지면, 경로에 써져있는 숫자들의 합을 최소화 하는 경로를 구하여라.
    단 넌 항상 아래 또는 오른쪽으로 움직일 수 있다.
    
    제한:
    
    해결방법:
    그리드하게 고르면 될 거 같음? ㄴㄴ 만약 내가 지금 최소라고 정한게 local min에 빠질 수 있다.
    
    양수라는 점을 이용한 DP가 가능한가?
    ㅇㅇ 가능하다.
    cache[y][x] = y, x부터 endpoint까지 이동하는데 최소 비용이라고 가정한다.
    
    */
    int cache[201][201];
    int getMinPath(vector<vector<int>> & grid, int m, int n, int y, int x){
        
        if(y == m || x == n)
            return 40000000;
        
        if(y == m-1 && x == n-1)
            return grid[y][x];
        
        int& ret = cache[y][x];
        if(ret != 40000000)
            return ret;
        
        ret = min(getMinPath(grid, m, n, y+1, x), getMinPath(grid, m, n, y, x+1)) + grid[y][x];
        return ret;
    }
    int minPathSum(vector<vector<int>>& grid) {
        //memset은 0이나 1만된다!!! 이거 인지하자
        for(int i=0; i<201; i++)
            for(int j=0; j<201; j++)
                cache[i][j] = 40000000;
        
        int m = grid.size(), n = grid[0].size();
        cache[m-1][n-1] = grid[m-1][n-1];
        return getMinPath(grid, m, n, 0, 0);
    }
};
