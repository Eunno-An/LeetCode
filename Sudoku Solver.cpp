//fail
//전형적인 백트랙킹문제. 시간복잡도는 O(9^m)이다. (m = 빈칸의 개수).
//np-complete 문제.
//꼭 다시 봐야할 문제이다.

//2차 Fail
//아이디어: 한칸씩 보면서 이 row, col에 있는 숫자가 각각 세로와 가로, box안에서 valid 한지를 봐야한다.
//생각보다 쉽지만 구현은 그렇게 떠오르지 않았던 문제.
class Solution {
public:
    //리터닝이 요구된다. 이러한 유형의 질문에서는 벡터안에 답을 담는다.
    //하지만 백트래킹 솔루션에서는 보드의 처음 스테이트와 끝 스테이트가 같으므로
    //반환을 피하고 솔루션이 만들어진 후 역추적하지 않도록 한다.
    
    bool isValid(vector<vector<char>> & board, int row, int col, char c){
        //row check
        for(int i=0; i<9; i++)
            if(board[i][col] == c)
                return false;
        
        //col check
        for(int i=0; i<9; i++)
            if(board[row][i] == c)
                return false;
        
        //box check
        int x0=(row/3)*3, y0 = (col/3)*3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[x0+i][y0+j] == c) return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board, int row, int col){
        //done
        if(row == 9)
            return true;
        //time for next row
        if(col == 9)
            return helper(board, row+1, 0);
        //already marked
        if(board[row][col]!='.')
            return helper(board, row, col+1);
        
        for(char c = '1'; c <= '9'; c++){
            if(isValid(board, row, col, c)){
                board[row][col]=c;
                //without return here, the board reverts to initial state
                if(helper(board, row, col+1))
                    return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};
