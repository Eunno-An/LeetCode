//미완성 코드
//진행중이나, 어떤 부분이 잘못됐는지 모르겠다.
class Solution {
public:
    /*
    문제:
    matrix에 0과 1이 있는데, 1만으로 차있는 직사각형의 최대 넓이를 찾아봐!
    
    제한:
    
    해결방법:
    1)BruteForce
    -> 어떤 두 점을 골라서, 그 안의 사각형이 1로 차있는지 본다.
    
    2)쉬운 문제 유형으로 바꿔보자
    -> 만약 정사각형의 최대 넓이라면? 어떤 점 1 을 기준으로 확대시키면 됨.
    -> 확대는 길이를 증가시키는 것임. 
    -> 각각의 길이를 한번에 증가시켜서, 그 테두리를 보겠지. i, j부터 시작했고, 길이가 n이면 matrix[i+n-1][0 to j+n-1]이 다 1이여야 하고, matrix[j+n-1][0 to i+n-1]이 다 1이여야 하겠지
    
    -> 그렇다면, 직사각형은 매개변수 n을 가로와 세로를 따로 두어야겠어. 가로를 1 증가시킨거 한번 호출하고, 세로를 1 증가시킨거 한번 호출하고, 둘다 1 증가시킨거 한번 호출하면 되겠지!
    -> 종료 조건은? 이건 따로 없는듯 하다.
    
    */
    
    bool check_all_1(vector<vector<char>>& matrix, int y, int x, int n, int m){
        //사각형의 밑부분이 모두 다 1 인지를 check
        for(int i=x; i<m; i++)
            if(matrix[n][i] == '0')
                return false;
        //사각형의 오른쪽변 부분이 모두 다 1인지를 check
        for(int i=y; i<n; i++)
            if(matrix[i][m] == '0')
                return false;
        return true;
    }
    int getMaxArea(vector<vector<char>>& matrix, int y, int x, int n, int m){//n이랑 m은 각각 어떤 area의 바닥 y좌표와 오른쪽 x좌표
        if(check_all_1(matrix, y, x, n, m))
            return (n-y+1)*(m-x+1);
        int ret = 0;
        if(y+1 < matrix.size() && matrix[y+1][x] == '1')
            ret = max(ret, getMaxArea(matrix, y, x, n+1, m));
        if(x+1 < matrix[0].size() && matrix[y][x+1] == '1')
            ret = max(ret, getMaxArea(matrix, y, x, n, m+1));
        
        return ret;
        
                
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ret = 0;
        for(int i=0; i<matrix.size(); i++)
            for(int j=0; j<matrix[i].size(); j++)
                if(matrix[i][j] == '1')
                    ret = max(ret, getMaxArea(matrix, i, j, i, j));
        return ret;
    }
};
