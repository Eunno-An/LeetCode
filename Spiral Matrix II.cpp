2022-02-05
Success
소요시간 18:52
Details 
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
Memory Usage: 6.7 MB, less than 16.68% of C++ online submissions for Spiral Matrix II.

2022-03-30
Success
소요시간 13분
Details 
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
Memory Usage: 6.6 MB, less than 17.68% of C++ online submissions for Spiral Matrix II.
class Solution {
public:
    /*
    문제:
    양수 n이 주어지면, n^2의 spiral matrix를 만들어라.
    
    제한:
    1<=n<=20
    
    해결방법:
    단순 구현.
    
    회고:
    y+dy x+dx를 y+dy y+dx로 써가지고 괜히 시간만 잡아먹었다.
    한 7분?잡아먹은듯...
    */
    const int dir_x[4] = {1, 0, -1, 0};
    const int dir_y[4] = {0, 1, 0, -1};
    
        
    bool ok(int y, int x, int n){
        return (y >=0 && y < n && x >=0 && x < n) ? true : false;
        
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        int count = 1;
        int y=0, x =0;
        vector<vector<int>> ret(n, vector<int>(n, 0));
        while(count <= n*n){
            //cout << count << endl;
            ret[y][x] = count++;
            visit[y][x] = true;
            for(int i=0; i<4; i++){
                int dy = dir_y[i];
                int dx = dir_x[i];
                while(ok(y+dy, x+dx, n) && visit[y+dy][x+dx] == false){
                    //cout << count << endl;
                    ret[y+dy][x+dx] = count++;
                    visit[y+dy][x+dx]=true;
                    y+=dy;
                    x+=dx;
                }
            }
            x+=1;//오른쪽으로 한번 이동.
            
        }
        return ret;
    }
};
