1차 22-06-08 Fail
아이디어는 정말 잘 떠올렸으나, 세부적인 구현도 했음.
근데 이분탐색은 정말 제대로 구현하기가 너무나 어렵다. 정말 꼼꼼한거 다 생각해줘야하는게 ...
class Solution {
public:
    /*
    문제:
    peak 요소는 그것의 이웃보다 큰 요소이다.
    nums 정수 배열이 주어지면, peak element를 찾고, 그것의 "인덱스"를 리턴한다.
    만약 peak element가 여러개라면, 그것들 중 아무거나 리턴해라.
    
    nums[-1] = nums[n] = -무한대 라고 생각해도 좋다.
    
    O(logN) time에 실행하도록 알고리즘을 설계하라.
    
    
    제한:
    이 문제를 풀 때 씹 핵심은 어떻게든 답이 존재한다는 것이다.
    peak 요소는 어떻게든 존재할 수 밖에 없다.(nums[i] != nums[i+1]이고 맨끝이 -무한대 이므로)
    해결방법:
    1)O(n) 해결방법
    -> peak 요소 인 것들을 순차 탐색으로 찾는다.
    
    2)O(logN) 해결방법
    -> 무슨 특성이 있길래 이걸 로그로 줄였을까 생각해보자.
    -> 로그는 보통 이분탐색과 관련이 있다.
    -> 아무리 생각해도 이분탐색은 아닌거 같다.
    -> 그럼 다른 걸 생각해보면 heap이 떠오른다. 근데 이것도 아니다. 만약 peak element가 배열의 끝에 있으면 또 안되는데
    -> 그럼 이분탐색으로 다시 돌아가보면 이분탐색이 맞는데?
    
    */
   
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, mid;
        
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[mid + 1]) 
                lo = mid + 1;
            else hi = mid;
        }
        
        return lo;
    }
};
