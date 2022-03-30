1차 Fail
이유?
  아얘 풀지를 못함. 많이 본 문젠데 확실히 어렵다. 15~18번째줄이 진짜 중요하다.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ret = 0;
        
        heights.push_back(0);
        //0을 넣은 이유는 코드를 좀 쉽게 하기 위해서임.
        
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int top = heights[st.top()];
                st.pop();
                int ran = st.empty()? -1 : st.top();
                ret = max(ret, top * (i-ran-1));
            }
            st.push(i);
        }
        
        return ret;
        
    }
};
