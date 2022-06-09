1차 22-06-09 
Success
Time: 8분
Runtime: 24 ms, faster than 26.00% of C++ online submissions for Two Sum II - Input Array Is Sorted.
Memory Usage: 15.5 MB, less than 93.11% of C++ online submissions for Two Sum II - Input Array Is Sorted.
class Solution {
public:
    /*
    문제:
    처음 시작 인덱스가 1인 정수 배열 numbers가 주어진다.
    오름차순으로 정렬되어 있다.
    합쳐서 target number가 되는 두개의 숫자를 찾아라.
    1 <= index1 < index2 <= numbers.length이다 .
    🎈반드시 상수 추가 메모리만 사용해야 한다.    

    
    제한:
    numbers의 길이는 1 이상 3만이하.
    numbers[i]는 -1000이상 1000이하
    target은 -1000이상 1000이하
    반드시 답은 하나밖에 존재하지 않도록 입력이 주어진다.
    
    
    
    해결방법:
    target이 되려면 어쨌든 두가지 요소를 다 봐야한다.
    1) 브루트 포스
    -> numbers를 2중 포문으로 순회한다.
    
    2)그거 말고 어짜피 오름차순이니까, 이분탐색으로 한다. O(nlogn)
    
    3)🎈Discussion의 풀이 O(n)
    ->그리디 풀이. 정당성에 대한 증명은 아직 어렵다.
    
    4)이거 해시맵으로도 풀었던 것 같은데..
    
    
    */
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        for(int i=0; i<numbers.size(); i++){
            int now = numbers[i];
            int find = target - now;
            
            int start = i+1;
            int end = numbers.size()-1;
            int mid;
            while(start <= end){
                mid = (start + end)/2;
                if(numbers[mid] == find){
                    ret.push_back(i+1);
                    ret.push_back(mid+1);
                    return ret;
                }else if(numbers[mid] < find){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }
        return ret;//"oops"
    }
  
  //Discussion 풀이
  vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum==target) return {i+1,j+1};
            else if(sum>target) j--;
            else i++;
        }
        return {}; // not found
    }
};
