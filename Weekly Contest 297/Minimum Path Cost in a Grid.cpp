2.
30분
m*n 정수 행렬 grid는 
0부터 m*n-1까지의 distinct한 정수로 구성되어 있다.
이 행렬에서 어떤 셀에서 다음 행의 다른 셀로 이동할 수 있다.

단, 마지막 행은 이동이 불가능 하다.

각각의 가능한 move는 2차원 배열의 moveCost로, 비용이 주어진다.
moveCost는 (m*n) * n으로 되어있는데
moveCost[i][j]는 value i 를 가진 셀에서 다음 행의 j열을 가진 cell로의 비용을 의미한다.

grid의 경로 비용은 방문한 모든 셀 값의 합계에 모든 이동 비용의 합계를 더한 값이다.
첫번재 행의 셀에서 시작하여 마지막 행의 셀에서 끝나는 경로의 최소 비용을 반환하여라.

제한:
1) m, n은 2 이상 50 이하.
2) grid는 0부터 m*n-1까지의 정수로 이루어져 있다.
3) moveCost[i][j] 는 100 이하.

해결방법:
1)재귀로 풀어도 될 듯 하다. -> 시간초과./ 🎈이유? O(50^50) 이므로 안됨!
2)DP

회고:
문제를 잘 못 봐서, minElem을 구해야 하는데 max를 구하고 있었으니..

class Solution {
public:
    int cache[51][51];
    int help(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int r, int c){
        //cout << r << ' ' << c << ' ' << nowCost << endl;
        if(r == grid.size()-1)
            return grid[r][c];
        
        int& ret = cache[r][c];
        if(ret != INT_MAX)
            return ret;
        for(int col=0; col < grid[0].size(); col ++){
            ret = min(ret, help(grid, moveCost, r+1, col) + grid[r][c] + moveCost[grid[r][c]][col]);
        }
        return ret;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ret = INT_MAX;
        for(int i=0; i<51; i++)
            for(int j=0; j<51; j++)
                cache[i][j] = INT_MAX;
        
        for(int i=0; i<grid[0].size(); i++){
            ret = min(ret, help(grid, moveCost, 0, i));
        }
        return ret;
    }
};

//Discussion 코드
int minPathCost(vector<vector<int>>& g, vector<vector<int>>& moveCost) {
    int m = g.size(), n = g[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[0] = g[0];
    for (int i = 1; i < m; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                dp[i][k] = min(dp[i][k], g[i][k] + dp[i - 1][j] + moveCost[g[i - 1][j]][k]);
    return *min_element(begin(dp[m - 1]), end(dp[m - 1]));
}
