//fail
//문제점? 첨부터 너무 편법적으로 풀려고 함. 
//브루트포스 방법부터 생각해 보고, 중복을 어떻게 줄일 수 있는지 체계적으로 생각해 나가자.
//종만북에서도 강조했던 내용.

//그 외 유의깊게 볼점
//문자를 바로 인덱스에 대응시키는 방법을 보자. 굉장히 편하다.

//Time Complexity: O(2 * n)
//O(n)으로 최적화 시키는 방법에 대해 생각해 볼것.



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left = 0, right = 0;
        int ret = 0;
        vector<int> chars(128);
        
        while(right < s.length()){
            char r = s[right];
            chars[r]++;
            
            while(chars[r] > 1){
                char l = s[left];
                chars[l]--;
                left++;
            }
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};

