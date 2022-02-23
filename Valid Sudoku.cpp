1차
Success
Time: 20분
Runtime: 24 ms, faster than 56.58% of C++ online submissions for Valid Sudoku.
Memory Usage: 18.6 MB, less than 58.38% of C++ online submissions for Valid Sudoku.

2차 2022-02-23
Success
Time: 11
Details 
Runtime: 25 ms, faster than 71.45% of C++ online submissions for Valid Sudoku.
Memory Usage: 18.6 MB, less than 60.98% of C++ online submissions for Valid Sudoku.
2차 풀이도 참고하기.

//이것도 좋은 풀이가 있다. 아래에 참조하였음.
//모범 풀이 아이디어: row와 col, 그리고 3by3 정사각형도 하나의 set이라고 생각하자!. 
//그럼 bloack[(i/3 * 3 + j/3]으로 큰 스도쿠판을 작은 스도쿠판 9개로 매핑할 수 있다. 
//큰 실수한 점. board[i][j] 는 char형이다. int num = board[i][j] - '0'; 해줘야함.
    
    
class Solution {
public:
    bool Rule_1(vector<vector<char>>& board){
        int num;
        for(int i=0; i<9; i++){
            vector<bool> check(10, false);
            for(int j=0; j<9; j++){
                if(isdigit(board[i][j]) == false)
                    continue;
                num = board[i][j];
                if(check[num] == true)
                    return false;
                check[num]=true;
            }
        }
        return true;
    }
    bool Rule_2(vector<vector<char>>& board){
        int num;
        for(int i=0; i<9; i++){
            vector<bool> check(10, false);
            for(int j=0; j<9; j++){
                if(isdigit(board[j][i]) == false)
                    continue;
                num = board[j][i]; 
                if(check[num] == true)
                    return false;
                check[num] = true;
            }
        }
        return true;
    }
    bool Rule_3(vector<vector<char>>& board){
        int num;
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                vector<bool> check(10, false);
                for(int k=i; k<i+3; k++){
                    for(int l=j; l<j+3; l++){
                        if(isdigit(board[k][l]) == false)
                            continue;
                        num = board[k][l];
                        if(check[num] == true)
                            return false;
                        check[num]=true;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool res1 = Rule_1(board);
        bool res2 = Rule_2(board);
        bool res3 = Rule_3(board);
        cout << res1 << ' ' << res2 << ' ' << res3 << '\n';
        return res1 && res2 && res3;
    }
};

//모범풀이
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9), cols(9), blocks(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] == '.') continue;
                
                int curr = board[i][j] - '0';
                if (rows[i].count(curr) || cols[j].count(curr) || blocks[(i/3)*3+j/3].count(curr)) 
                    return false;
                
                rows[i].insert(curr);
                cols[j].insert(curr);
                blocks[(i/3)*3+j/3].insert(curr);
            }
        }
        
        return true;
    }
};

//2차풀이
class Solution {
public:
    /*
    문제:
    
    미완성 스도쿠 보드가 주어지면
    이게 타당한지 아닌지를 나타내라.
    
    회고:
    더 깔끔하게 했다고 생각했는데 역시 잘짜는 사람은 많구나.
    시간을 그래도 1/2로 줄였다.
    
    */
    bool isValidRow(vector<vector<char>>& board, int row){
        vector<int> one2nine(10, 0);
        for(int i=0; i<board.size(); i++)
            if(board[row][i] != '.' && one2nine[board[row][i]-'0']++)
                return false;
        return true;
    }
    bool isValidCol(vector<vector<char>>& board, int col){
        vector<int> one2nine(10, 0);
        for(int i=0; i<board.size(); i++)
            if(board[i][col] != '.' && one2nine[board[i][col]-'0']++)
                return false;
        return true;
    }
    bool isValidBox(vector<vector<char>>& board, int row, int col){
        vector<int> one2nine(10, 0);
        for(int i=row; i<row+3; i++){
            for(int j=col; j<col+3; j++){
                if(board[i][j] != '.' && one2nine[board[i][j]-'0']++)
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int row =0 , col = 0;
        for(int i=0; i<board.size(); i++){
            if(!isValidRow(board, i))
                return false;
            if(!isValidCol(board, i))
                return false;
            if(!isValidBox(board, row, col))
                return false;
            col+=3;
            if(col == 9){
                row+=3;
                col = 0;
            }
        }
        return true;
    }
};
