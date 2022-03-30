1차 22-03-30Fail


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
    int largestArea(vector<int>& histogram){
        int n=histogram.size(), area=0;
        stack<int> s;
        
        for(int i=0; i<n; i++){
            while(!s.empty() && histogram[s.top()]>=histogram[i]){
                int top = s.top();
                s.pop();
                
                int start;
                if(s.empty())
                    start = -1;
                else
                    start = s.top();
                    
                
                int curr_area = histogram[top] * (i - start -1);
                area = max(area, curr_area);
            }
            s.push(i);
        }
        
        while(!s.empty()){
            int top = s.top();
            s.pop();

            int start;
            if(s.empty())
                start = -1;
            else
                start = s.top();
            
            int curr_area = histogram[top] * (n - start -1);
            area = max(area, curr_area);
        }
        
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size(), result=0;
        vector<int> histogram(n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    histogram[j]+=1;
                else
                    histogram[j]=0;
            }
            
            result = max(result, largestArea(histogram));
            cout<<result<<" ";
        }
        return result;
    }
};
