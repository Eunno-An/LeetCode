//Fail
//2차 Fail. 22-03-02
//2차 실패 이유? 홀수랑 짝수는 따로 짤 필요 없다는 것을 인지했으나, 구현 능력 부족.
class Solution {
public:
    /*
    문제:
    90도 이미지 돌리는 문제
    해결방법:
    1)단순 구현.
    2)90도 회전은 transposed + reverse와 같다. 코드가 더 1번에 비해 심플하다. 
    
    회고:
    1)시계 방향으로 회전이면, 대입을 반시계로 하면 더 간단하다! 실수를 한건 시계방향으로 대입하려다 보니 변수를 두개를 썼고, 구현이 복잡해졌음.
    2)이전 코드에서는 홀수와 짝수로 나눠서 했었음. 근데 그럴 필요가 없음.
    3)홀수와 짝수를 둘 다 처리해주려다 보니 코드가 길어졌는데, 그럴 필요가 없고 길이 만큼 수행해주면 됨.(len = n-2*i-1)
    */
    //1)단순구현
    void rotate(vector<vector<int>>& M) {
        int n = M.size(), depth = n / 2;
        for (int i = 0; i < depth; i++) {
            int len = n - 2 * i - 1, opp = n - 1 - i;//변의 길이는 2씩 짧아지고, opp은 i의 반대쪽 값임.
            for (int j = 0; j < len; j++) {
                int temp = M[i][i+j];
                M[i][i+j] = M[opp-j][i];
                M[opp-j][i] = M[opp][opp-j];
                M[opp][opp-j] = M[i+j][opp];
                M[i+j][opp] = temp;
            }
        }
    }
    //2)transpose + reverse
    void rotate(vector<vector<int>>& matrix) {
		// complement of matrix 
        int n = matrix.size();
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; ++i) {
		// 2 Pointer approach :  just like we do in 1D array we take left and right pointers
		// and swap the values and then make those pointers intersect at some point.
            int left = 0, right = n-1;
            while(left < right) {
                swap(matrix[i][left], matrix[i][right]);
                ++left;
                --right;
            }
        }
    }
      
};
