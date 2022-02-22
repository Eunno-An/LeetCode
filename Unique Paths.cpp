1차 2022-02-22
Time:12분49초
Success
Details 
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
Memory Usage: 6 MB, less than 57.30% of C++ online submissions for Unique Paths.
class Solution {
public:
    /*
    문제:
    m*n 격자가 있는데, m-1, n-1(오른쪽 아래 끝)으로 가고싶어 한다.
    m, n이 주어지면 도착할수 있는 가능한 unique path들의 개수를 구하여라.
    답은 항상 20억과 같거나 아래이다.
    
    제한:
    m과 n이 100 이하인 자연수
    
    해결방법:
    단순히 visit을 bool 배열로 하면, 지그재그로 가는걸 저장못함.
    따라서 int 배열을 통한 DP로 해야한다.
    
    */
    int visit[101][101];
    bool ok(int y, int x, int m, int n){
        if(y >=0 && y < m && x >=0 && x < n) return true;
        return false;
    }
    int getUniquePathNumber(int y, int x, int m, int n){
        if(y == m-1 && x == n-1){
            return 1;
        }
        
        int& ret = visit[y][x];
        if(ret != 0)
            return ret;
        
        if(ok(y+1, x, m, n))
            ret+=getUniquePathNumber(y+1, x, m, n);
        if(ok(y, x+1, m, n))
            ret+=getUniquePathNumber(y, x+1, m, n);
        return ret;
        
    }
    int uniquePaths(int m, int n) {
        return getUniquePathNumber(0, 0, m, n);  
    }
};
