//Success 23:25분
class Solution {
public:
    /*
    문제:
    n-queen문제.
    모든 solution을 리턴해라. 순서는 상관없다.
    단, solution은 vector<string>이다.
    
    해결방법:
    1)Recursion
    
    회고:
    실수들 체크하기.
    */
    vector<vector<string>> ret;
    
    void help(int col, vector<string> board){
        if(col == board.size()){
            ret.push_back(board);
            return;
        }
        
        for(int i=0; i<board.size(); i++){//모든 row에 대해서 검사한다.
            //지금 설치하려고 하는 애는 (i,col)에 하려고 하는거임.
            bool able = true;
            for(int j=0; j<col; j++){//현재 col 이전까지의 열들을 검사한다.
                //j번째 열과 col번째 열은 차이가 col-j만큼 차이 난다.
                int dist = col-j;
                if(i-dist >= 0 && board[i-dist][j] == 'Q'){//왼쪽 위에 퀸이 이미 있을 경우
                    //return;실수 2: return으로 해버리면 모든 row에 대해 검사하지 못함.
                    able = false;
                    break;
                }
                if(i+dist <board.size() && board[i+dist][j] == 'Q'){//왼쪽 아래에 퀸이 이미 있을 경우
                    able = false;
                    break;
                }
                if(board[i][j] == 'Q'){//실수1: 같은 행에 퀸이 이미 있을 경우를 생각못함.
                    able = false;
                    break;
                }
            }
            if(able){
                board[i][col]='Q';
                help(col+1, board);
                board[i][col]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        help(0, board);
        return ret;
    }
};
