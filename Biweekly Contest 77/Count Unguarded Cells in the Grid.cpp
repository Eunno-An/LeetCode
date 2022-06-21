class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        int ret = 0;
        
        for(int i=0; i<guards.size(); i++){
            int y = guards[i][0];
            int x = guards[i][1];
            mat[y][x] = 1;
        }
        for(int i=0; i<walls.size(); i++){
            int y = walls[i][0];
            int x = walls[i][1];
            mat[y][x] = 2;
        }
        
        for(int i=0; i<guards.size(); i++){
            int y = guards[i][0];
            int x = guards[i][1];
            
            int upY = y - 1, downY = y + 1;
            while(upY >= 0 && mat[upY][x] != 2 && mat[upY][x] != 1)
                mat[upY--][x] = 3;
            
            while(downY < m && mat[downY][x] != 2 && mat[downY][x] != 1)
                mat[downY++][x] = 3;
            
            int leftX = x - 1, rightX = x + 1;
            while(leftX >= 0 && mat[y][leftX] != 2 && mat[y][leftX] != 1)
                mat[y][leftX--] = 3;
            
            while(rightX < n && mat[y][rightX] != 2 && mat[y][rightX] != 1)
                mat[y][rightX++] = 3;
            
        }
        for(int i=0;i < m; i++)
            for(int j=0; j<n; j++)
                if(mat[i][j] == 0)
                    ret++;
        return ret;
    }
};
