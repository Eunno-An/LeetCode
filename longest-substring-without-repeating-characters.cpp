//fail. 
//(2022.01.13)2차 복습 fail
class Solution {
public:
    /*
    문제: 어떤 문자열이 주어질 때, 반복되는 문자가 없는 가장 긴 부분문자열의 길이를 구하여라.
    
    해결 아이디어: 어려운 것부터 시작해보자.
    1)BruteForce
    인덱스 i부터 j까지 2중 for문을 통해 인덱스를 뽑고,
    s[i:j]에 반복된 문자열이 있나 확인한다.
    총 O(n^3)이 든다.
    
    2)Sliding Window
    특정 구간만 보면 된다. 그 구간이 어떤 구간인가? 문자열을 하나씩 보다보면 이 문자열이 두번 등장할 때를 쉽게 알 수 있다. vector<int>chars(128)에 각 문자열의 빈도 횟수를 저장하면 해결할 수 있다.
    그렇다면 거기서 ans = max(ans, r-l+1)을 통해 쉽게 해결할 수 있다.
    
    실수한 점: 
    
    예시가 소문자라고 해서, 
    문제를 잘 읽지 않고 소문자만 있을 것이라고 생각하였음. vector<int> chars(128)을 통해 모든 캐릭터에 대한 배열을 만듬.
    
    해결방법이 쉽게 떠오르지 않을떄는, 쉬운 해결방법부터 생각하기.
    */
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int ret = 0;
        vector<int> chars(128);
        while(right < s.length()){
            char r = s[right];
            chars[r]++;
            while(chars[r]>1){
                char l = s[left];
                chars[l]--;
                left++;
            }
            ret = max(ret, right-left+1);
            right++;
        }
        return ret;
    }
};
