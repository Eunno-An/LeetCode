//너무 복잡복잡시려
class Solution {
public:
    /*
    문제:
    n*n 매트릭스가 주어지면, 90도 회전한 이미지를 추천해라.
    단, in-place로 구현해야 한다.

    해결 방법:
    AB
    DC

    AA
    DC, temp = B

    AA
    DB, temp = C

    AA
    CB, temp = D

    DA
    CB, temp = A

    temp = A
    after = B
    after라는 변수 필요. 얘의 역할은  temp를 저장하기 전에 그 위치에 있던 원래 문자를 저장하는 것임.

    matrix[pos(B)]=temp
    temp = after(현재 temp = B)

    matrix[pos(C)]=temp
    temp = after(현재 temp = C)

    matrix[pos(D)]=temp
    temp = after(현재 temp = D)
    */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();//한 변의 길이
        if (n == 1)
            return;
        int startY = 0;
        int startX = 0;
        if (n % 2 == 0) {//한 변의 길이가 짝수일 때
            while (n != 1) {
                int temp = matrix[startY][startX];
                int after = matrix[startY][startX + n - 1];

                for (int i = 0; i < n / 2; i++) {//바깥 테두리는 n/2번만 하면 됨.
                    matrix[startY + i][startX + n - 1] = temp;
                    temp = after;
                    after = matrix[startY + n - 1][startX + n - 1 - i];

                    matrix[startY + n - 1][startX + n - 1 - i] = temp;
                    temp = after;
                    after = matrix[startY + n - 1 - i][startX];

                    matrix[startY + n - 1 - i][startX] = temp;
                    temp = after;
                    after = matrix[startY + i][startX];

                    matrix[startY][startX + i] = temp;
                    
                    temp = matrix[startY][startX + i + 1];
                    after = matrix[startY + i + 1][startX + n - 1];
                    
                }

                n /= 2;//매트릭스 축소
                startY += 1;
                startX += 1;
            }
        }
        else {//한 변의 길이가 홀수일 때, ex = 3
            while (n != 0) {
                int temp = matrix[startY][startX];
                int after = matrix[startY][startX + n - 1];

                for (int i = 0; i < n / 2 + 1; i++) {//홀수일때는 주의하자. 가운데 요소까지 한번 더 해주어야 한다.
                    matrix[startY + i][startX + n - 1] = temp;
                    temp = after;
                    after = matrix[startY + n - 1][startX + n - 1 - i];

                    matrix[startY + n - 1][startX + n - 1 - i] = temp;
                    temp = after;
                    after = matrix[startY + n - 1 - i][startX];

                    matrix[startY + n - 1 - i][startX] = temp;
                    temp = after;
                    after = matrix[startY + i][startX];

                    matrix[startY][startX + i] = temp;
                    
                    temp = matrix[startY][startX + i + 1];
                    after = matrix[startY + i + 1][startX + n - 1];
                }

                n /= 2;
                startY += 1;
                startX += 1;
            }
        }
        return;
    }
};
