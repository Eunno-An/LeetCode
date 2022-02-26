Success
2022-02-26
Details 
Runtime: 4 ms, faster than 18.88% of C++ online submissions for Climbing Stairs.
Memory Usage: 5.7 MB, less than 96.99% of C++ online submissions for Climbing Stairs.
  
피보나치와 접근이 같다.
class Solution {
public:
    int cache[46];
    int climbStairs(int n) {
        cache[1] = 1;
        cache[2] = 2;
        for(int i=3; i<=n; i++){
            cache[i] = cache[i-2] + cache[i-1];
        }
        return cache[n];
    }
};
