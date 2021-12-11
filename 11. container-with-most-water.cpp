//fail
//히스토그램 최대 넓이랑 비슷한 문제였으나, 거의 다르다고 볼 수도 있음.
//Two-pointer를 이용한 문제.

//왜 높이가 작은것을 이동할까?
//쉽게 설명하면, 우리는 h[l]과 h[r]중 작은 것을 높이로 이용하게 되는데,
//처음 상황에서
//만약 h[l] <h[r]이라고 하자. h[r]을 움직이면 너비는 1 줄고, h[r]에 따라 결정되게 될 것이다.
//h[r]이 h[l]보다 크면 h[l]을 높이로 이용하게 될 것이고, 이는 무조건 처음 넓이보다 작다.
//만약 h[r]이 h[l]보다 작다면 h[r]을 높이로 이용하게 될 것이고, 이는 무조건 처음 넓이보다 작다!. 
//따라서 두 상황 다 모순이 발생하므로, 안된다.

//h[l] < h[r]일 때, h[l]을 움직이면?
//h[l] < h[r]일 때, h[l]을 사용하게 될 것이다. 결과는 알 수 없다. 왜냐면 바뀐 h[l]이 h[r]보다 클 수도 있으니까!
//h[l] > h[r]일 때, h[r]을 사용하게 될 것이다. 이건 h[r]을 사용하겠지. 그럼 또 결과가 바뀔 수 있다.

//따라서 작은걸 옮겨야 한다.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0, l = 0, r = height.size()-1;
        while(l < r){
            maxarea = max(maxarea, min(height[l], height[r]) * (r-l));
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
};
