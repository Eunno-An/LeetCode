1차 22-03-30Fail
2차 22-04-17 반은 성공, 반은 맞음.
    회고: 아이디어는 생각했으나..역시나 maximal histo 구하는거에서 자세한 부분에 대한 구현이 생각이 안나스 그만..

class Solution {
public:
    /*
    문제:
    matrix에 0과 1이 있는데, 1만으로 차있는 직사각형의 최대 넓이를 찾아봐!
    
    제한:
    
    해결방법:
    1)BruteForce
    ->엄청나게 시간 오래걸림.
    2)histogram에서 최대넓이문제를 응용한 진짜 멋있는 풀이
    ->각각의 column을 순회하면서, histogram에서 maxArea를 구하는 함수를 호출.
    ->새 column을 볼 때마다 histogram갱신. 1이면 높이 추가. 0이면 0으로 만들어버림.
    */  
    int getMaxRectangle(vector<int>& histo){
        stack<int> s;
        int maxArea = 0;
        for(int i=0; i<histo.size(); i++){
            int h = histo[i];
            while(!s.empty() && histo[s.top()] >= h){
                int idx = s.top(); s.pop();
                int h = histo[idx];
                int w = s.empty()? i:i-s.top()-1;
                int area = h * w;
                if(area > maxArea)
                    maxArea = area;
            }
            s.push(i);
        }
        cout << maxArea << endl;
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> histo(n+1, 0);
        int ret = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1')
                    histo[j]++;
                else
                    histo[j] = 0;
            }
            int area = getMaxRectangle(histo);
            ret = max(ret, area);
        }
        return ret;
    }
};
