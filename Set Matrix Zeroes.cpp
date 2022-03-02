/*
2022-03-01
Fail.
2차시도 22-03-02
Fail

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
