1차 22-04-06 Fail
실패이유: 쉽게 생각하면 되는데 너무 졸리기도 하고 집중도 잘 안된다.... Cache배열 설정할 때 의미부여를 아얘 하지 않고 접근함.
  애초에 그래프쪽은 집중도 안되고 지금 컨디션이 너무 안좋은것도 한몫하는거같다.
2차 22-05-16 Fail
내가 실패한 이유는 딱 이거다. 경우의 수만 세면 되는데 굳이 복잡하게 풀려고 함. 그냥 단순하게 노드들은 1부터 n까지니까
개수만 매개변수로 주면 자연스럽게 할 수 있겠지
class Solution {
public:
/*
문제:
Unique BST의 개수를 구하여라
제한:
n이 19 이하!
해결방법:
DP로 해야함. Unique BST 2 문제의 해결방법을 따서 변수 두개로 DP를 설정했는데 왜 안될까??
아무튼 이 방법 말고도 조합을 통해 해결하는 방법이 있다.  
*/
    int cache[20];
    int numTrees(int n) {
        if(n<=1) return 1;
        int& ret = cache[n];
        if(ret != 0)
            return ret;
        for(int i=1; i<=n; i++)
            ret += numTrees(i-1) * numTrees(n-i);
        return ret;
    }
};
