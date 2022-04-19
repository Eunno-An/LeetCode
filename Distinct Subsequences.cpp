1차 22-04-19 Fail
회고:
-> 재귀에서 코드 반복문 쓰는거..
        이건 정말 내가 실수많이하는거. 굳이 반복문을 돌릴 필요가 없다.
        케이스 별로 나눠서 이걸 선택하는지 안선택하는지만 생각하면된다! 
        뒤에 있는건 알아서 재귀가 해줄꺼임.
        for(int i=is; i<s.size(); i++)
            if(s[i] == t[ie])
                ret += numDistinct(s, t, i+1, ie+1);    
-> 그리고 반드시 매개변수는 레퍼런스로 하자!!!!!!! shallow copy에 시간이 너무 걸린다. 계속 time limit 걸림!!
class Solution {
public:
    /*
    문제:
    string s와 t가 주어진다. 
    t와 같은 s의 distinct subsequences의 개수를 나타내라.
    여기서 subsequences란? s 중에서 무작위로 몇개 뺐을 때 남아있는 문자들을 합친 것이다.
    
    제한:
    답은 항상 int 범위에 있는 것만 주어진다.
    
    해결방법:
    종료조건 설정. 그리고 재귀 설정. 그리고 나머지는 DP.
    
    */
    int cache[1001][1001];
    int numDistinct(string& s, string& t, int is, int ie) {
        //cout << is << ' ' <<ie << endl;
        //종료조건
        if(ie == t.size()) return 1;
        if(is == s.size()) return 0;
        
        int& ret = cache[is][ie];
        if(ret != -1)
            return ret;
        ret = 0;
        
        //여기서 왜 numDistinct(s, t, is+1, ie+1) + numDistinct(s, t, is+1, ie)로 할까?
        //그냥 numDistinct(s, t, is+1, ie+1)만 하면 안되나?
        //아니다! 왜냐하면 s[is] == t[ie]여도 s[is]를 사용 안 할수도 있기 때문이다.
        
        if(s[is] == t[ie])
            return ret = numDistinct(s, t, is+1, ie+1) + numDistinct(s, t, is+1, ie);
        
        
        return ret = numDistinct(s, t, is+1, ie);
    }
    int numDistinct(string s, string t){
        memset(cache, -1, sizeof(cache));
        return numDistinct(s, t, 0, 0);
    }
};
