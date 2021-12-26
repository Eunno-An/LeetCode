/*
내 풀이
1. BruteForce
모든 순열을 생성!O(n!) * O(2*n)에 해당하는 시간이 걸림.
Runtime: 16 ms, faster than 9.16% of C++ online submissions for Generate Parentheses.
Memory Usage: 21.5 MB, less than 7.35% of C++ online submissions for Generate Parentheses.
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //if(parentheses[i] == false) '('
        //else ')'
        
        string parentheses(n, '(');
        for(int i=0; i<n; i++)
            parentheses.push_back(')');
        vector<string> ret;
        do{
            stack<char> temp;
            for(int i=0; i<parentheses.size(); i++){
                if(temp.empty())
                    temp.push(parentheses[i]);
                else{
                    if(temp.top() == '(' && parentheses[i] == ')')
                        temp.pop();
                    else
                        temp.push(parentheses[i]);
                }
            }
            if(temp.empty())
                ret.push_back(parentheses);    
        }while(next_permutation(parentheses.begin(), parentheses.end()));
        return ret;
    }
};

/*
2. 백트랙킹
Runtime: 8 ms, faster than 30.49% of C++ online submissions for Generate Parentheses.
Memory Usage: 13.9 MB, less than 36.56% of C++ online submissions for Generate Parentheses.
직관적 풀이로는 모든 brackets에 대해서 순열을 생성하면 된다. 
우리는 백트랙킹에 대해서 해보려고 한다.
모든 백트랙킹 문제는, 우리가 탐색하려고 할 때 두가지 명심해야할게 있다.
1. Base Case: 모든 백트랙킹 문제는 몇개의 '기저 조건'이 있다.
기저 조건이란 재귀 과정에서 멈춰야만 하는 지점이다.
이 문제에서는 string이 최대 길이(n*2)에 도달했을 때, 우리는 멈춰야 하고
이것이 기저 조건이 된다.

2. Conditions: 잘 관찰하다보면 우리는 두개의 조건을 발견할 수 있다.
->adding '(': 만약 여는 괄호의 개수가 n보다 작으면 ')'를 더한다. 그렇지 않으면 더하지 않는다.
->adding ')': 만약 닫는 괄호가 여는 괄호 개수보다 작으면 ')'를 더한다. 그렇지 않으면 not.
*/
class Solution {
public:
    vector<string> ret;
    void helper(int n, int op, int cl, string here){
        if(here.size() == 2 * n){
            ret.push_back(here);
            return;
        }
        if(op < n){
            helper(n, op+1, cl, here + '(');
        }
        if(cl < op){
            helper(n, op, cl+1, here + ')');
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        helper(n, 0, 0, "");
        return ret;
    }
};

