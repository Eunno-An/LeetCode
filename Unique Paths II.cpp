1차 22-02-23
Success
Time: 13:37
Details 
Runtime: 19 ms, faster than 5.01% of C++ online submissions for Unique Paths II.
Memory Usage: 7.5 MB, less than 87.05% of C++ online submissions for Unique Paths II.
  회고:
    1)예외처리:
      시작점이 장애물일때
      끝점이 장애물일때
    2)Bottom-up 풀이방법 첨부함.
class Solution {
public:
    /*
    문제:
    unique pathes의 개수를 구하라.
    근데 중간에 장애물이 껴있다.
    유니크 패스 1문제랑 전체 틀은 아얘 같음.
    
    제한:
    
    해결방법:
    1)DP
    
    
    */
    
    int cache[101][101];
    int getUniquePathNumbers(vector<vector<int>>& obstacleGrid, int m, int n, int y, int x){
        if(obstacleGrid[y][x] == 1)
            return 0;
        if(y == m-1 && x == n-1)
            return obstacleGrid[y][x] == 0 ? 1 : 0;
        int & ret = cache[y][x];
        if(ret != 0) //y,x에서 endpoint로 가는 길의 개수가 1개 이상이면
            return ret;
        if(y+1 < m && obstacleGrid[y+1][x] == 0)
            ret += getUniquePathNumbers(obstacleGrid, m, n, y+1, x);
        if(x+1 < n && obstacleGrid[y][x+1] == 0)
            ret += getUniquePathNumbers(obstacleGrid, m, n, y, x+1);
        return ret;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return getUniquePathNumbers(obstacleGrid, obstacleGrid.size(), obstacleGrid[0].size(), 0, 0);    
    }
};
/*
Bottom-Up
*/
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
	int m = size(grid), n = size(grid[0]);
	vector<vector<int> > dp (m + 1, vector<int>(n + 1));
    dp[0][1] = 1;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)            
			// dp[i][j] = sum of unique paths for top and left cell (cells from which we reach current one)
            dp[i][j] = !grid[i - 1][j - 1] ? dp[i - 1][j] + dp[i][j - 1] : 0;
    return dp[m][n];
}
