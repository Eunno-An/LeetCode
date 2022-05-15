1차 22-05-15 Success
Time: 31분 44초
Success
Details 
Runtime: 577 ms, faster than 28.29% of C++ online submissions for Longest Consecutive Sequence.
Memory Usage: 53.7 MB, less than 5.23% of C++ online submissions for Longest Consecutive Sequence.
회고:
O(n)에 푸는게 핵심임. 그래서 map을 이용해볼까 했는데 unordered_map을 통해 요소 접근을 O(1)에 하였음.
class Solution {
public:
    /*
    문제:
    정수 배열 nums가 주어진다. unsorted이다.
    가장 긴 연속요소시퀀스의 길이를 반환해라.
    알고리즘을 O(n)에 작동하도록 하여라.
    
    
    
    제한:
    
    해결방법:
    1)쉬운 방법
    정렬한 다음에 순차탐색하면서 연속요소의 최대길이를 갱신하면됨.
    ㅋㅋ 근데 정렬이 O(logN)임.
    
    nums[i]가 최소 마이너스 십억에서 최대 십억이네? 그럼 bool 배열을 통해서 인덱싱을 해보자.
    이러면 2천 메가바이트가 소요가 되는디?...
    뭐 용량은 많으니까 할 수 는 있겠다만
    이러면 만약 1, 3, 4, 2 순서대로 들어왔는데 이러면 길이를 알 수가 없지.
    
    그럼 unordered_map으로 해보자.
    */
    //key: number, value: number가 속한 range의 시작과 끝점.
    unordered_map<int, pair<int, int>> bucket;
    
    int longestConsecutive(vector<int>& nums) {
        int maxLength = 0;
        for(int i=0; i<nums.size(); i++){
            
            int num = nums[i];
            cout << "num: " << num << " maxLength: ";
            //num이 없을 때 추가.
            if(bucket.find(num) == bucket.end())
                bucket.insert(make_pair(num, make_pair(num, num)));
            else //그렇지 않고 기존에 본 수면 그냥 pass한다.
                continue;
            
            //num-1이 있는 경우
            //num+1이 있는 경우
            int left =num, right = num;
            if(bucket.find(num-1) != bucket.end())
                left = bucket[num-1].first;
            
            if(bucket.find(num+1) != bucket.end())
                right = bucket[num+1].second;
            
            bucket[left].second = right;
            bucket[right].first = left;
            bucket[num].first = left;
            bucket[num].second = right;
            
            maxLength = max(maxLength, bucket[num].second - bucket[num].first + 1);
            cout << maxLength << endl;
        }
        return maxLength;
        
        
        
    }
};
