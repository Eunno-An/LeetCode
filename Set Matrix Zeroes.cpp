2022-03-01 Fail.
2차시도 22-03-02 Fail
3차시도 22-04-07
Success
Time: 40분
Details 
Runtime: 31 ms, faster than 12.76% of C++ online submissions for Set Matrix Zeroes.
Memory Usage: 13.3 MB, less than 19.71% of C++ online submissions for Set Matrix Zeroes.
세번째 풀이 코드 첨부하였음.
	/*


공간을 O(m+n)에 해결하라는 Followup을
시간을 그때 풀으라는 줄 알고 잘못풀었다.
..
ㅅㅂ

2차 회고:
다시 풀어보니 ㅈㄴ 까다로운 문제였음.
잘 생각하지 않으면 삑나기 쉬운 문제임.
EX) [[1,0,3]]
실수한 부분: 
24~33번째 줄 i와 j가 1부터 시작함.
그리고 firstRow, firstCol을 따로따로 체크할 필요가 반드시 있음!!!!!!!! 구현하다 보면 왜 그런지 알거임....

*/
void setZeroes(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        bool firstRow = false;  // do we need to set first row zero
        bool firstCol = false;  // do we need to ser first col zero
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
					if(a[i][j] == 0){   // store rows and cols state in first row and col
                    if(i==0) firstRow = true;
                    if(j==0) firstCol = true;
                    a[i][0] = 0;
                    a[0][j] = 0;
                }
            }
        }
        // cout<<firstRow<<" "<<firstCol<<endl;
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(a[i][0] == 0 || a[0][j] == 0){
                    a[i][j] = 0;
                }
            }
        }
        
        if(firstRow){
            for(int i=0;i<m;i++) a[0][i] = 0;
        }
        
        if(firstCol){
            for(int i=0;i<n;i++) a[i][0] = 0;
        }
    }

//세번째 풀이 코드 첨부
class Solution {
public:
    /*
    문제:
    m*n matrix가 주어진다. 만약 matrix[i][j] == 0이면, 모든 row와 column을 0으로 만든다.
    단 in-place로 해야한다.

    제한:
    
    해결방법:
    1)case를 나눠야 한다.
    -> [0][0]가 0인 경우
    -> 왼쪽 세로줄, 맨 위 가로줄 중에 0이 있는 경우
    -> 그 외 0이 있는 경우
    
    이렇게 나누는 이유는 ?
    -> in-place로 하기 위해서는, [0][0]가 0인 경우, matrix의 왼쪽 세로줄과 위 가로줄을 먼저 0으로 만들어버리면
    나중에 지장이 생긴다.
    -> 왼쪽 세로줄과 맨 위 가로줄 중에 0이 있는 경우도 마찬가지이다. [0][0]에 영향을 주게 된다.
    -> 그 외 0이 있는 경우가 먼저 탐색되어야 한다. matrix[i][j]가 0이면, matrix[i][0] = 0, matrix[0][j] = 0으로 만든다.
    
    회고:
    m과 n을 따로 설정해준 이유? 
    for(int i=1; i<matrix[i].size(); i++)
    이런 코드에서 1*1정사각형인 경우, index에러 날 수 있음!
    
    그리고 [0][0]따로 처리 안해주고 좀 더 코드를 줄일 수 있을것임.
    */
    void setZeroes(vector<vector<int>>& matrix) {
        /**/
        int m = matrix.size();
        int n = matrix[0].size();
        cout << m << ' ' << n << endl;
        bool firstZero = (matrix[0][0] == 0 ? true : false); // matrix[0][0]이 0인 경우!
        
        
        // 왼쪽 세로줄과 맨 위 가로줄을 본다. 0 이 있는 경우, 해당 열과 행을 모두 0으로 만들어 준다.
        //생각해보니 이러면 또 탐색할 때 에러가 생긴다. 
        /*
        1 1 1
        0 1 1
        1 1 1
        이면 matrix[1][0]을 통해서 matrix[2][0]도 0이 될텐데, 이러면 곤란하다. 따라서 그 행만 0으로 죄다 만들어 주어야 한다.
        */
        
        //left와 up에 0이 있을 경우, 훗날에 처리해주기 위해 flag 세우기
        bool leftZero = false, upZero = false;
        for(int i=1; i<m; i++)
            if(matrix[i][0] == 0){
                leftZero = true;
                break;
            }
        
        for(int i=1; i<n; i++)
            if(matrix[0][i] == 0){
                upZero = true;
                break;
            }
        
        //위 가로, 왼쪽 세로 제외한 부분에서 0인 부분 확인하고, 0이면 왼쪽 끝과 위점을 0으로 만들어주기
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        //왼쪽 세로줄에서 0인 부분 확인하고, 그 행을 죄다 0으로 만들기.
        for(int i=1; i<m; i++)
            if(matrix[i][0] == 0)
                for(int j=1; j<n; j++)
                    matrix[i][j] = 0;
            
        //위쪽 가로줄에서 0인 부분 확인하고, 그 열을 0으로 만들기.
        for(int i=1; i<n; i++)
            if(matrix[0][i] == 0)
                for(int j=1; j<m; j++)
                    matrix[j][i] = 0;
        
        //leftZero가 true면 왼쪽 모든걸 0으로 만들기.
        if(leftZero)
            for(int i=0; i<m; i++)
                matrix[i][0] = 0;
        
        //rightZero가 true면 위쪽 모든걸 0으로 만들기.
        if(upZero)
            for(int i=0; i<n; i++)
                matrix[0][i] = 0;
        
        
        
        
        
        
        //3) 만약 matrix[0][0]가 0인 경우를 처리해준다.
        if(firstZero){
            //맨 윗 가로줄 처리
            for(int i=1; i<n; i++)
                matrix[0][i] = 0;
            //맨 왼쪽 세로줄 처리
            for(int i=1; i<m; i++)
                matrix[i][0] = 0;
        }
        return ;
            
    }
};
