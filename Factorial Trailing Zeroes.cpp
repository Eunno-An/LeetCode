1차 22-06-16
Success
Time: 20분
Details 
Runtime: 88 ms, faster than 5.17% of C++ online submissions for Factorial Trailing Zeroes.
Memory Usage: 47.1 MB, less than 5.89% of C++ online submissions for Factorial Trailing Zeroes.
회고:
🎈Follow-up은 도무지 방법이 생각나지 않음.
그리고 n은 최대 10000임. 아래 풀이처럼 후행하는 0을 제외한 앞 자리 수만 따로 저장했음.
근데 fact[i].first를 나머지 하는 과정에서 10000(만)이 아니라 100000(십만)으로 해야함.
왜냐하면 예외가 걸림. 3125인가? 암튼 앞자리가 99250000이 되는데, 10000으로 나누면 next가 0이 되어버림. 이러면 ... 그냥 쥐쥐임.
그래서 최소한 10만은 잡아야함. 그렇게 되면 당연히 first도 자료형을 long long으로 해주어야 하지 않나? 그냥 int로 해도 답이 나온다.

class Solution {
public:
    /*
    문제:
    정수 n이 주어지면, n의 팩토리얼을 구하고 그 수의 뒤 0의 개수를 구한다.
    
    제한:
    n은 0이상 만 이하.
    
    Follow-up:
    logarithmic time complexity에 해결할 수 있나?
    
    해결방법:
    n이 생각보다 크다.
    1) 팩토리얼을 정확히 저장해야 하나? 아니다. 
    후행하는 0의 개수와, 그 0을 제외한 나머지 수들을 저장하면 된다.
    순차적으로 하면 당연히 O(n)에 해결할 수 있다.
    
    
    2)🎈Follow-up: O(logN)에 해결하는 방법
    -> 95000이 있다. 이건 답이 3이다. 왜냐하면 10의 거듭제곱 중에서 95000을 나눠서 딱 떨어지는 가장 큰 수는 1000이다.
    그래서 답이 3인거임. ?? 이게 뭔솔?? 왜 이렇게 가정하지
    -> Hence, 정수가 10^k로 나눠지면, k개의 trailing zeroes가 있다고 할 수 있다. 라고 하네
    -> 더 많은 예시:
    Now let a number be 2^5 * 5^4. Here 2^4 * 5^4 is the highest power of 10 which is 10^4. So, The number has 4 trailing powers.
Another example, 2^3 * 3^1 * 5^4 * 7^2 gives us 2^3 * 5^3 to make the max power of 10 hence 3 trailing zeroes.
    -> 다른 예시들을 통해서 2와 5의 거듭제곱 중 작은 거듭제곱이 후행하는 k의 개수임을 알 수 있다.
    -> 또한 2의 거듭제곱은 항상 5의 거듭제곱보다 작거나 같음을 알 수 있다. 결론은 5의 거듭제곱으로만 계산해도 괜찮대
    -> 그니까 주어진 n!을 5와 연관시키는것이지!
    -> 예로 들어 37!에는 37 * 36 * (35) * ... * (30) * ... * (25) * ... * (5) * ... * 1
    -> 아 똥마려
예시참고
https://leetcode.com/problems/factorial-trailing-zeroes/discuss/52373/Simple-CC++-Solution-(with-detailed-explaination)

    */
    int trailingZeroes(int n) {
        vector<pair<long long int, int>> fact(n+2, {0, 0});//pair<int, int> p->p.first = 0을 제외한 나머지 수, p.second = 0의 개수
        fact[1].first = 1;
        fact[1].second = 0;
        
        for(int i=2; i<=n; i++){
            long long int next = fact[i-1].first * i;
            if(next % 10 != 0){
                fact[i].first = next;
                fact[i].second = fact[i-1].second;
            }
            else{//0일 경우, next에 0이 몇개가 있는지 확인한다.
                int zeroCount = 0;
                while(next % 10 == 0){
                    zeroCount++;
                    next /= 10;
                }
                fact[i].first = next;
                fact[i].second = fact[i-1].second + zeroCount;
            }
            if(fact[i].first > 100000)
                fact[i].first %= 100000;
            //cout << i << ' ' << fact[i].first << ' ' << fact[i].second << '\n';
        }
        //cout << fact[3124].first;
        return fact[n].second;
    }
};
