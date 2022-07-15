1. 
class Solution {
public:
    string decodeMessage(string key, string message) {
        char start = 'a';
        unordered_map<char, char> bucket;
        for(int i=0; i<key.size(); i++){
            if(start == 'A')
                break;
            if(key[i] == ' ')
                continue;
                
            if(bucket.find(key[i]) == bucket.end()){
                bucket[key[i]] = start++;
            }
        }
        string ret = "";
        for(int i=0; i<message.size(); i++){
            if(message[i] == ' ')
                ret += ' ';
            else
                ret += bucket[message[i]];
        }
        return ret;
    }
};
2. 깔금하게 잘 짠듯.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    const int dy[4] = {0, 1, 0, -1};
    const int dx[4] = {1, 0, -1, 0};
    bool ok(int y, int x, int m, int n){
        return (y >=0 && y < m && x >=0 && x < n);
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ret(m, vector<int>(n, -1));
        int dir = 0; // 0 : right, 1 : down, 2 : left, 3 : up
        int y = 0 , x = 0;
        while(head!=NULL){
            int val = head->val; head = head->next;
            
            if(!ok(y, x, m, n) || ret[y][x] != -1){
                y -= dy[dir];
                x -= dx[dir];
                dir = (dir + 1) % 4;
                y += dy[dir];
                x += dx[dir];
            }
            
            ret[y][x] = val;
            
            y += dy[dir];
            x += dx[dir];
        }
        return ret;
    }
};  
3.Fail 사유 : 시간초과.
  dp[i]는 i번째 날에 비밀을 찾은 사람의 수를 의미합니다.
share는 비밀을 공유할 사람들의 수입니다.
i번째 날,
dp[i - delay] 사람들은 며칠 전에 secret 찾음.
비밀을 나누기 시작합니다.
그래서 share += dp[i - delay]

dp[i - forget] 사람들은 며칠 전에 잊어버린 비밀을 찾았고,
그리고 오늘 그 비밀을 잊었다.
그래서 share -= dp[i - forget]
그리고 우리는 dp[i] = share 할당합니다.
  int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp(n + 1);
        dp[1] = 1;
        int share = 0, mod = 1e9 + 7, res = 0 ;
        for (int i = 2; i <= n; ++i)
            dp[i] = share = (share + dp[max(i - delay, 0)] - dp[max(i - forget, 0)] + mod) % mod;
        for (int i = n - forget + 1; i <= n; ++i)
            res = (res + dp[i]) % mod;
        return res;
    }

4. 7/15 다시 풀어봄. 
cache 배열과 visit 배열을 동시에 사용하여 DP + DFS로 해결
브루트 포스 해결방법으로 시도, 시간초과 났음.
cache[i][j] = i, j번째에서 시작하여 갈 수 있는 increasing Path의 개수.
cache[i][j] = for i in 0..4 cache[i][j] += cache[i+dx[i]][j+dy[i]]
또한 MOD도 신경써 주어야 한다.
class Solution {
public:
    
    int cache[1001][1001];
    const int MOD = 1000000007;
    const int dy[4] = {-1, 0, 1, 0};
    const int dx[4] = {0, 1, 0, -1};
    bool canGo(vector<vector<int>>& grid, vector<vector<bool>>& visit, int y, int x){
        return (y>=0 && y < grid.size() && x >= 0 && x < grid[0].size() && visit[y][x] == false) ? true : false;
    }
    int getPath(vector<vector<int>>& grid, vector<vector<bool>>& visit, int y, int x){
        if(!canGo(grid, visit, y, x))
            return 0;
        int& ret = cache[y][x];
        if(ret != 0)
            return ret % MOD;
        visit[y][x] = true;
        for(int i=0; i<4; i++){
            if(canGo(grid,visit, y+dy[i], x + dx[i]) && grid[y][x] < grid[y+dy[i]][x+dx[i]]){
                ret += (getPath(grid, visit, y+dy[i], x+dx[i]) % MOD + 1) % MOD; 
                //cout << ret << endl;
            }
        }
        visit[y][x] = false;
        return ret;
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
        int ret = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                cache[i][j] = getPath(grid, visit, i, j) % MOD;
                ret %= MOD;
                ret += cache[i][j] % MOD;
                //cout << cache[i][j] << endl;
            }
            ret += grid[i].size() % MOD;
        }
        return ret;
    }
};
