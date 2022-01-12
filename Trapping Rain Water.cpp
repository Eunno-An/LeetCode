//FAIL
//문제: 히스토그램의 높이들이 주어질 때, 빗물을 얼마나 담을 수 있는지 생각해보기.
//유사한 문제: Container with most Water

//내가 생각한것:
//비슷하다고 생각함. 투포인터까지 생각함.

//부족헀던 점:
//문제는 항상 쉽게 풀어야 한다. 가장 직관적이고 쉬운 풀이부터 시작하기 반드시. 이걸 안했다.

//해결 아이디어:
//1) Brute Force
//어떤 기준점 i로부터 왼쪽과 오른쪽을 순회하면서, 각각의 maxLeft와 maxRight중 구한다음, min(maxLeft, maxRight)-height[i]를 한다. 이게 i번째 칸에 쌓일 수 있는 물의 높이이다.
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        
        
        for(int i=0; i<height.size(); i++){
            int left_max = 0, right_max = 0;
            for(int j = i; j>=0; j--){
                left_max = max(left_max, height[j]);
            }
            for(int j=i; j<height.size(); j++){
                right_max = max(right_max, height[j]);
            }
            ans += min(left_max, right_max) - height[i];
        }
        return ans;
        //O(N^2)
    }
};

//2) Dynamic Programming
//왼쪽과 오른쪽의 가장 높은 높이를 구하는 과정에서 너무 중복된 계산을 많이 하게 된다. 이는 디피를 통해 시간 개선을 할 수 있다.
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        
        left_max[0] = height[0];
        for(int i=1; i<size; i++)
            left_max[i] = max(height[i], left_max[i-1]);
        
        right_max[size-1] = height[size-1];
        for(int i=size-2; i>=0; i--)
            right_max[i] = max(height[i], right_max[i+1]);
        
        for(int i=1; i<size-1; i++)
            ans += min(left_max[i], right_max[i])-height[i];
        
        return ans;
        //O(N)
    }
};
