//Success 23:25분
//2차: 03-04 Fail. 집중해서 풀지 않았음. 코드 첨부함.
//2차는 int형을 통해 재귀 부담을 줄이고, main에서 한번에 처리했음.
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


//2차코드 첨부
class Solution {
public:
    /*
    문제:
    N-queens문제.
    
    제한:
    
    해결방법:
    
    */
    vector<vector<int>> ret_int;
    void getQueensPos(int n, vector<int> now, int idx){//idx = 현재 몇번째 열인지
        if(n == idx){
            ret_int.push_back(now);
            return;
        }
        
        for(int i=0; i<n; i++){//0번째 행부터 n-1번째 행까지 한번씩 다 놓아볼꺼얌
            bool able = true;
            for(int j=0; j<idx; j++){//현재 idx열에 위치해있으니까 우리는 0번부터 idx-1번째 위치에 있는 말들과 idx번에 있는 말의 상관관계를 볼꺼야.
                if(now[j] == i) {able = false; break;};
                if(i - (idx-j) == now[j]) {able = false; break;};//now[j]가 idx번쨰 열의 i행에 위치한 말보다 왼쪽 위 대각선에 있는 경우
                if(i + (idx-j) == now[j]) {able = false; break;};
            }
            if(able){
                now.push_back(i);
                getQueensPos(n, now, idx+1);
                now.pop_back();
            }
            
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        
        getQueensPos(n, vector<int>(), 0);
        vector<vector<string>> ret;
        string base(n, '.');
        for(int i=0; i<ret_int.size(); i++){
            
            vector<string> temp(n, base);
            for(int j=0; j<ret_int[i].size(); j++){
                temp[ret_int[i][j]][j] = 'Q';
            }
            ret.push_back(temp);
        }
        return ret;
    }
};
