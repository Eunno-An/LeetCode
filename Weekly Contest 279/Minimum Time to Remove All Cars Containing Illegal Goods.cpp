1과 0이 있는 문자열에서 1을 제거하기 위한 최소 비용 구하기.
 처음에 재귀로 풀었고, 시간초과가 나서 디피로 바꿨으나 시간초과 문제를 해결하지 못함
 근데 해결방법 보니까 엄청난 풀이가 이썽ㅆ음.
  int minimumTime(string s) {
        // "left" is the minimum cost to move all the illegal cars from s[0] to s[i] (i + 1 cars in total), this can be done by 
        // either removing all of the cars in this range consecutively starting from the left OR 
        // removing some of them from the left and some of them in the middle. 
        // "res" stands for the minimum cost of moving all the illegal cars, and it is important to understand that it has an upper bound of n, 
        // which equals to the total cost if we remove all the cars consecutively from one end. 
        // The reason we initialize it with n is that we seek to minimize it with other possible ways of removing cars. 
        int n = s.size(), left = 0, res = n;
        for (int i = 0; i < n; ++i) {   
            // As explained in the original post, each time when s[i] is illegal, we have the option to either 
            // remove it in a consecutive fashion starting from the left OR to remove it as if it is picked from the middle. 
            left = min(left + (s[i] - '0') * 2, i + 1);
            // Here is the key part. "left + n - 1 - i" means the total cost with the cars from s[i + 1] to s[n - 1] to be removed 
            // starting from the right consecutively, and we compare it with the current minimum res. 
            // An alternative way to look at it is: imagine if we have maintained a dp array,
            // where dp[i] := cost of removing illegal cars from s[0] to s[i] in the optimal fasion + 
            // cost of removing illegal cars from s[i + 1] to s[n - 1] consecutively from the right.
            // As the dp array is filled from 0 to n - 1 using the rules defined above, it covers all possible min cost at each index, 
            // while avoids optimizing the costs associated with the right portion of the input array. 
            // And then we find the minimum cost in the dp array, which is the answer we are looking for. 
            res = min(res, left + n - 1 - i);
        }
        return res;
    }


//이건 내가 재귀로 했던거
class Solution {
public:
    unordered_map<string, int> bucket;
    int solve(string& s, int nowCost, int oneCount){
        if(s.empty() || oneCount == 0)
            return nowCost;
        
        int ret = 400001;
        if(s[0] == '1'){
            string t = s.substr(1);
            ret = min(ret, solve(t, nowCost + 1, oneCount - 1));
        }else{
            string t = s.substr(1);
            ret = min(ret, solve(t, nowCost + 1, oneCount));
        }
        if(s.back() == '1'){
            string t = s.substr(0, s.size()-1);
            ret = min(ret, solve(t, nowCost + 1, oneCount - 1));
        }else{
            string t = s.substr(0, s.size()-1);
            ret = min(ret, solve(t, nowCost + 1, oneCount));
        }
        for(int i=1; i<s.size()-1; i++)
            if(s[i] == '1'){
                int idx = i;
                s.erase(s.begin() + i);
                ret = min(ret, solve(s, nowCost + 2, oneCount - 1));
                s.insert(s.begin() + i, '1');
            }
        
        return ret;
    }
    int minimumTime(string s) {
        int oneCount = 0;
        for(int i=0; i<s.size() ;i++)
            if(s[i] == '1')
                oneCount++;
        return solve(s, 0, oneCount);
    }
};
