1차 Fail 22-05-16
회고: 
1) 알고리즘 자체 설계를 잘못함. 이상하게 코드를 짰음. 잘 풀었다고 생각했지만 논리적으로 오류난 곳을 찾지 못함.
2) 좋은 풀이 발견. 테두리에 붙어있는 O부터 시작해서 DFS를 돌려서 'O','X'가 아닌 'P'로 만들음. 추후에 매트릭스 순회를 하면서 'P'만 'X'로 만들어 주면 됨..
class Solution {
public:
    void DFS(vector<vector<char>>& board,int r,int c,int rsize,int csize){
        if(r<0||c<0||r==rsize||c==csize||board[r][c]!='O')return;
        board[r][c] = 'P';
        DFS(board,r+1,c,rsize,csize);
        DFS(board,r,c+1,rsize,csize);
        DFS(board,r-1,c,rsize,csize);
        DFS(board,r,c-1,rsize,csize);
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty())return;
        int row = board.size(),col = board[0].size();
        for(int i=0;i<col;i++)DFS(board,0,i,row,col),DFS(board,row-1,i,row,col);
        for(int i=0;i<row;i++)DFS(board,i,0,row,col),DFS(board,i,col-1,row,col);
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='P')board[i][j]='O';
    }
};
