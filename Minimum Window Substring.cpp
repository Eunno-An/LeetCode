
Fail 2022-03-05.
/*

회고:
unordered_map 사용하고 그런건 이해했는데
집중해서 풀지 않았음.
대충 비슷하게 어떻게 풀지 느낌은 잡았으나
좀 어려웠음..


https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
위 링크는 어떤 미친놈이 substring template에 대한 것을 정리해 놓은 것이다. ㅈㄴ 좋은 풀이인듯 싶다. 공부해보자.
아래 코드와 설명 첨부하겠음.
*/
class Solution {
public:
    //s = "ADOBECODEBANC", t = "ABC"
    //output = "BANC"
    string minWindow(string s, string t) {
        vector<int> bucket(128, 0);
        for(auto c : t) bucket[c]++;//bucket은 t의 글자가 몇번 쓰였는지를 기록한다.
        //bucket[A] = 1, bucket[B] = 1, bucket[C] = 1
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        //counter = t의 문자들 중 아직 체크 안 한 문자들의 개수.
        //end는 s를 처음부터 끝까지 훑기 위한 포인터.
        while(end < s.size()){
            if(bucket[s[end++]]-- > 0) counter--; 
            while(counter == 0){//만약 count가 0이라면?(t안의 문자들이 begin부터 end라는 window안에 들어가 있다면)
                if(end-begin < d) d = end - (head = begin);//윈도우의 크기가 나온 것들 중 최소라면? head에 begin을 넣고, 창의 크기를 갱신한다.
                if(bucket[s[begin++]]++ == 0) counter++;//window를 갱신하기 위해 counter를 수정한다.
            }
        }
        return d == INT_MAX ? "":s.substr(head, d);
    }
};

/*
substring problem template에 대한 설명
For most substring problem, 
we are given a string and need to find a substring of it which satisfy some restrictions.
(거의 모든 부분문자열 문제에서, string에서 substring을 찾아야 되는데, restrictions까지 같이 주어진다.)
A general way is to use a hashmap assisted with two pointers.
(투포인터와 함께 hashmap을 사용하는게 일반적인 방법이다. c++에서는 unordered_map)


One thing needs to be mentioned is that when asked to find maximum substring,
한가지만 언급해야될게 있다면, "최대"부분문자열을 찾아야 하는 경우
we should update maximum after the inner while loop to guarantee that the substring is valid.
maximum은 부분문자열이 valid한지를 보장하기 위해 inner while loop문 다음에 업데이트 해야 한다.
예시: Longest Substring with At Most Two Distinct Characters

*/
int findSubstring(string s){
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end<s.size()){

            if(map[s[end++]]-- ?){  /* modify counter here */ }

            while(/* counter condition */){ 
                 
                 /* update d here if finding minimum*/

                //increase begin to make it invalid/valid again
                
                if(map[s[begin++]]++ ?){ /*modify counter here*/ }
            }  

            /* update d here if finding maximum*/
        }
        return d;
  }

int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> map(128, 0);
        int counter=0, begin=0, end=0, d=0; 
        while(end<s.size()){
            if(map[s[end++]]++==0) counter++;
            while(counter>2) if(map[s[begin++]]--==1) counter--;
            d=max(d, end-begin);//update maximum after the inner while loop to guarantee that the substring is valid.
        }
        return d;
    }
