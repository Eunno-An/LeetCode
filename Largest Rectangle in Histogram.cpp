1차 Fail
이유?
  아얘 풀지를 못함. 많이 본 문젠데 확실히 어렵다. 15~18번째줄이 진짜 중요하다.
  stack에 인덱스를 넣은것과
  heights의 마지막에 0을 넣어줌으로써 stack이 비어있지 않은 경우를 처리해준 점
 2차 22-04-15 Fail
회고:
 -> [3, 2, 7, 4]에서 4가 들어왔을 때, 2, 7이 stack에 있고 우리는 7까지만 뺀다!(while조건때문에!)
   예시를 통해서 확실히 이해했다. 거의 다 풀이에 근접했었는데.. 아쉽다
   while문의 등호도 자세히 봐야한다.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        
        for(int i = 0; i <= n; i++){
            int currHeight = i == n ? 0 : heights[i];
            // check if currHeight becomes greater then height[top] element of stack. we do a push because it's an increasing sequence
            // otherwise we do pop and find area, so for that we write a while loop
            while(!st.empty() && currHeight < heights[st.top()]){
                int top = st.top(); st.pop(); // current element on which we are working
                // now we need width & area
                int width = st.empty() ? i : i - st.top() - 1; // width differ if we stack is empty or not empty after we pop the element
                int area = heights[top] * width; // current height * width
                maxArea = max(area, maxArea);
            }
            // if it doesn't enter in while loop, it means it's an increasing sequence & we need to push index
            st.push(i);
        }
        return maxArea;
    }
  //2차 풀이
  int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> s;
        int maxArea = 0;
        for(int i=0; i<heights.size(); i++){
            int h = heights[i];
            cout << h << '\n';
            while(!s.empty() && h < heights[s.top()]){
                int t = s.top(); s.pop();
                int w = s.empty() ? i : i-s.top()-1;
                int area = heights[t]*w;
                maxArea = max(area, maxArea);
                cout << t << ' ' << w << ' ' << area << ' ' << maxArea << '\n';
            }
            s.push(i);
        }
        return maxArea;
    }
};
