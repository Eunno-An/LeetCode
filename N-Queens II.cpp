class Solution {
public:
    /*
    Fail.
    오랜만에 구현하니까 실력이 줄은게 느껴짐. 맨날 공부해야 하는구나 이래서 ..
    
    2022-01-31
    문제:
    n-queens를 해결할 수 있는 보드의 개수를 리턴해라.
    
    해결방법:
    n-queens 해결하는 방법의 벡터 수를 세면 됨.
    board를 vector<int>로 표시하면? board[i][j]가 무엇인지 O(1)에 접근이 안된다.
    따라서 vector<string>으로 표시하면 훨씬 편하다.
    
    실수:
    모든 열에 대해 검사한 후 재귀를 돌렸어야 했는데
    그렇지 않았음
    */
    int ret = 0;
    void help(int n, int nowCol, vector<string> nowBoard){ 
        if(nowCol == n){//끝 열에 다다랐을 경우
            ret++;
            return;
        }
        for(int i=0; i<n; i++){
            bool able = true;
            for(int j=0; j<nowCol; j++){
                int distance = nowCol - j;
                if(nowBoard[i][j] == 'q'){//현재 퀸의 위치와 같은 행에 퀸이 놓여져 있는 경우
                    able = false;
                    break;
                }
                if(i-distance >=0 && nowBoard[i - distance][j] == 'q'){//현재 퀸의 위치에서 좌측 위 대각선에 퀸이 놓여져 있는 경우
                    able = false;
                    break;
                }
                if(i+distance < n && nowBoard[i + distance][j] == 'q'){
                    able = false;
                    break;
                }
                
            }
            if(able){
                nowBoard[i][nowCol]='q';
                help(n, nowCol+1, nowBoard);
                nowBoard[i][nowCol]='.';
            }
        }
        return;
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        
        help(n, 0, board);
        return ret;
    }
};
