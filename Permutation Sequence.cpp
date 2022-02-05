2022-02-05
Success
소요시간:1번 풀이방법으로는 7분
Details 
Runtime: 176 ms, faster than 14.36% of C++ online submissions for Permutation Sequence.
Memory Usage: 6 MB, less than 80.21% of C++ online submissions for Permutation Sequence.
class Solution {
public:
    /*
    문제:
    1부터 n까지 정수가 들어가 있는 set이 있는데
    그 set에는 n!개의 unique한 수열들이 포함되어 있다.
    
    n과 k가 주어지면 k번째의 수열을 리턴해라!
    
    해결방법:
    1)가장 쉽게:
    next_permutation, string 사용.
    
    
    2)비슷한 문제를 종만북에서 본 적이 있다.
    ->건너뛰기!
    ->n개의 문자들로 만들수 있는 수열은 n!개.
    ->n-1개의 문자들로 만들 수 있는 수열은 n-1의 팩토리얼개
    ->만약 k가 n-1팩토리얼보다 크고 n!보다 작으면? 그 수는 정해져 있다.
    */
    //1번풀이
    string getPermutation(int n, int k) {
        string permu;
        for(int i=1; i<=n; i++)
            permu.push_back(i+'0');
        do{
            if(k-- == 1)
                return permu;
        }while(next_permutation(permu.begin(), permu.end()));
        return "OOPS!";
    }
  //2번풀이(Discussion 참고)
  vector<int> fact;
    
    void findfact(int n)
    {
        fact = vector<int>(n);
        
        fact[0] = 1;
        
        if(n==1) return;
        
        fact[1] = 1;
        for(int i=2; i<n; i++)
            fact[i] = i*fact[i-1];
    }
    
    string getPermutation(int N, int K) {
        int n = N-1, k = K-1, nt, kt;
        
        findfact(N);
        vector<int> num(N);
        for(int i=0; i<N; i++)
            num[i] = i+1;
        vector<int>::iterator it; 
        
        string ans = "";
        
        while(n>=0)
        {
            nt = k/fact[n];
            kt = k%fact[n];

            ans += (num[nt]+'0');
            it = num.begin(); 
            num.erase(it+nt);
            n--;
            k = kt;   
        }

        return ans;
    }
};
