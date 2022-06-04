1차
Success
Time: 12분 13초
Details 
Runtime: 20 ms, faster than 26.35% of C++ online submissions for Evaluate Reverse Polish Notation.
Memory Usage: 12.8 MB, less than 10.95% of C++ online submissions for Evaluate Reverse Polish Notation.
class Solution {
public:
    /*
    문제:
    후위 연산을 하라는 것 같다.
    
    제한:
    ->tokens의 length가 10000
    ->근데 각각 수는 200까지. 그러면 오버플로우가 발생할수도 있다는 생각이 들었음. 5001개의 숫자, 5000개의 곱하기. 
    ->200 * 200 * 200 * 이러면 ? 안될수도 있겠다 라는 생각이 들었음. 설명이 부족함.
    ->근데 함수에서는 int로 명시되어 있으니 int형을 무조건 리턴할거 같다는 생각을 함.
    ->근데 연산 과정에서 long long으로 넘어갈 수 있으니 long long으로 연산하자잉.
    
    해결방법:
    단순히 stack을 이용하면 된다!
    */
    int evalRPN(vector<string>& tokens) {
        stack<string> bucket;
        int n = tokens.size();
        for(int i=0; i<n; i++){
            if(tokens[i] == "+"){
                long long n1 = stol(bucket.top()); bucket.pop();
                long long n2 = stol(bucket.top()); bucket.pop();
                bucket.push(to_string(n1 + n2));
            }else if(tokens[i] == "-"){
                long long n1 = stol(bucket.top()); bucket.pop();
                long long n2 = stol(bucket.top()); bucket.pop();
                bucket.push(to_string(n2 - n1));
            }else if(tokens[i] == "*"){
                long long n1 = stol(bucket.top()); bucket.pop();
                long long n2 = stol(bucket.top()); bucket.pop();
                bucket.push(to_string(n1 * n2));
            }else if(tokens[i] == "/"){
                long long n1 = stol(bucket.top()); bucket.pop();
                long long n2 = stol(bucket.top()); bucket.pop();
                bucket.push(to_string(n2 / n1));
            }else{
                bucket.push(tokens[i]);
            }
        }
        int ret = stoi(bucket.top());
        return ret;
    }
};
