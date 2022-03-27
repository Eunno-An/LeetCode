1차시도: Fail

Details 
Runtime: 750 ms, faster than 33.16% of C++ online submissions for Word Search.
Memory Usage: 8 MB, less than 36.36% of C++ online submissions for Word Search.
class Solution {
public:
    /*
    문제:
    m*n 사이즈의 board가 있고, string word가 있다.
    만약 grid에 word가 존재하면 true를 리턴해라!
    
    제한:
    m, n <= 6
    word의 길이는 15 이하.
    
    해결방법:
    쉬운 방법부터!
    전체 칸을 탐색한다.
        DFS로 각 칸마다 수행하여 만약 더이상 탐색할 수 없는 경우, return ""; 만약 발견했을 경우 그 문자열을 리턴한다.
    
    Follow-up:
    Could you use search pruning to make your solution faster with a larger board?
    (더 큰 보드에 대해서 search 가지치기를 할 수 있는지?)
    
    회고:
    1.Discussion에서 알게된 사실
    -> 함수 parameter는 reference로 전달해야 시간초과가 안난다!
    2.메모리를 절약하기 위한 Tip
    -> Visit을 쓸 필요보다는, 이미 지나온 점을 어떤 "숫자"로 바꿔주면 된다. 왜냐하면 board에는 초기 조건이 only lowercase, uppercase이기 때문이다!
    -> 그 외엔 대체적으로 비슷하다.
    */
    const int dy[4] = {1, 0, -1, 0};
    const int dx[4] = {0, 1, 0, -1};
    bool ok(int n, int m, int y, int x){
        return (y >= 0 && y < n && x >=0 && x < m ? true : false); 
    }
    
    bool help(vector<vector<char>>& board, vector<vector<bool>>& visit, int y, int x, string now){
        /*두번째 예외처리를 해주면 사실 이 코드는 필요가 없음.
        if(now.empty()){
            cout << "1:" <<  now << endl;
            return true;
        }
        */
        if(now.size() == 1 && board[y][x] == now[0]){//하나만 남은 경우, 또는 board가 [["a"]]이고 word가 "a"인 경우에 대한 예외처리
            cout << "2:" << now << endl;
            return true;
        }
        if(now[0] != board[y][x])//다른 경우
            return false;
        
        
        bool ret = false;
        visit[y][x] = true;
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ok(board.size(), board[0].size(), ny, nx) && !visit[ny][nx]){
                ret = help(board, visit, ny, nx, now.substr(1)); 
                if(ret)
                    return true;
            }
        }
        visit[y][x] = false;
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[i].size(); j++)
                if(help(board, visit, i, j, word))
                    return true;
            
        return false;
    }
};
