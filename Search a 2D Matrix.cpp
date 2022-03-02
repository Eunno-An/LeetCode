Success
Details 
Runtime: 15 ms, faster than 6.09% of C++ online submissions for Search a 2D Matrix.
Memory Usage: 9.4 MB, less than 78.63% of C++ online submissions for Search a 2D Matrix.

class Solution {
public:
    /*
    문제:
    m*n 매트릭스에서 target을 찾는 효율적인 알고리즘을 찾아라.
    각 row에서는 오름차순으로 정렬됨.
    각 row의 첫번째 숫자는 이전 row의 첫번재 숫자보다 크다.
    
    제한:
    
    해결방법:
    matrix안에 있는걸 vector에 옮겨서 이분탐색하면 될거같기도 하다.
    아니면 메모리 아낄려면? 
    matrix전체의 개수는 m*n개이다. 중간 요소는 m*n/2이다.
    중간 요소가 6번째 요소니까6번째 요소와 target을 비교해서, target이 작으면 high를 5로 하면된다.
    
    회고:
    일단 행을 먼저 찾고,
    그 행에서 이분탐색을 하는 방법도 있다....
    그게 더 훨씬 구현도 쉬운거 같다.
    근데 조금 더 빠른 이유는 잘 모르겠다.
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lo = 0, hi = m * n - 1;
        int mid = (lo + hi) / 2;
        int y=0, x=0;
        int temp = 0;
        while(temp + n< mid){
            temp += n;
            y++;
        }
        x = (mid % n);
        
        while(lo <= hi){
            
            mid = (lo + hi) / 2;
            while(temp + n<= mid){//<=으로 해줘야함.
                temp += n;
                y++;
            }
            x = (mid % n);
            //cout << y << ' ' << x << endl;
            if(matrix[y][x] < target){
                lo = mid + 1;
            }
            else if(matrix[y][x] > target){
                hi = mid - 1;
            }
            else
                return true;
            y = 0;
            x = 0;
            temp = 0;
        }
        
        return false;
    }
};
