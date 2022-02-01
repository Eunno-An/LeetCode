Success
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
Memory Usage: 7 MB, less than 29.96% of C++ online submissions for Spiral Matrix.
  
class Solution {
public:
    /*
    2022-02-01
    
    문제:
    m*n 매트릭스가 주어지면,
    매트릭스의 모든 요소들을 spiral 순서로 리턴해라
    
    해결방법:
    1)단순구현
    m*n에서 처음엔 오른쪽으로 n-1번, 아래로 m-1번 이동한다.
    그리고 왼쪽으로 n-1번 이동하고, 마지막으로는 m-2번 이동한다
    
    그 다음 cycle에서는 가로, 세로의 길이가 2 준 상태로 시작한다.
    
    이동할 수 있는지에 대한 예외처리도 중요하다.
    
    회고:
    두번째 예시에서, loop3를 돌때 현재 위치 7에서 다시 6으로 가는 경우가 발생
    따라서 visit배열을 통해 한번 간 곳을 들를 경우 바로 답을 리턴해주었음.
    
    Discussion에 좀 더 가독성이 쉬운 코드 아래에 첨부하였음. 
    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<bool>> visit(matrix.size(), vector<bool>(matrix[0].size(), false));
        
        int m = matrix.size(), n = matrix[0].size(); // m = 세로의 길이, n = 가로의 길이
        int nowY=0, nowX =0;
        vector<int> ret;
        while(m >= 1 || n>= 1){
            if(n >= 1){
                //cout << "loop1: ";
                for(int i=nowX; i< nowX+n; i++){
                    if(visit[nowY][i] == true){
                        //cout << matrix[nowY][i] << endl;
                        return ret;
                    }
                    ret.push_back(matrix[nowY][i]);
                    visit[nowY][i]=true;
                }
                nowX += n-1;
            }
            //cout << endl;
            if(m >= 1){
                //cout << "loop2: ";
                for(int i=nowY; i<nowY+m; i++){
                    if(i!=nowY){//중복되는것 제외
                        if(visit[i][nowX])
                            return ret;
                        ret.push_back(matrix[i][nowX]);
                        
                        //cout << matrix[i][nowX] << ' ';
                        visit[i][nowX]=true;
                    }
                }
                nowY += m-1;
            }
            //cout << endl;
            if(n >= 1){
                //cout << "loop3: ";
                //cout << nowY << ' ' << nowX << endl;
                for(int i=nowX; i>=nowX-n+1; i--){
                    if(i!=nowX){//
                        //cout << matrix[nowY][i] << ' ';
                        if(visit[nowY][i])
                            return ret;
                        ret.push_back(matrix[nowY][i]);
                        visit[nowY][i] = true;
                    }
                }
                nowX -= n-1;
            }
            //cout << endl;
            if(m > 1){//이미 왼쪽 위 칸은 봤으므로, m은 1과 같으면 볼 필요가 없음.
                //cout << "loop4: ";
                for(int i=nowY; i>nowY-m+1; i--){
                    if(i!=nowY){
                        if(visit[i][nowX])
                            return ret;
                        ret.push_back(matrix[i][nowX]);
                        //cout << matrix[i][nowX] << ' ';
                        visit[i][nowX] = true;
                    }
                }
                nowY -= m-2;
            }
            //cout << endl;
            n-=2;
            m-=2;
            nowX+=1;
            //cout << "m: " << m << " n: " << n << " nowY: " << nowY << " nowX: " << nowX << endl;
        } 
        return ret;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0,right=m-1,bottom=n-1,top=0;
        int direction=1;
        vector<int> v;
        while(left<=right && top<=bottom)
        {
            if(direction==1)
            {
                for(int i=left;i<=right;i++) v.push_back(matrix[top][i]);
                direction=2;
                top++;
            }
            
            else if(direction==2)
            {
                for(int i=top;i<=bottom;i++) v.push_back(matrix[i][right]);
                direction=3;
                right--;
            }
            
            else if(direction==3)
            {
                for(int i=right;i>=left;i--) v.push_back(matrix[bottom][i]);
                direction=4;
                bottom--;
            }
            
            else if(direction==4)
            {
                for(int i=bottom;i>=top;i--) v.push_back(matrix[i][left]);
                direction=1;
                left++;
            }
        }
        return v;
        
    }
};
