3. 28분
정수 배열 cookies가 주어진다. cookies[i]는 i번째 가방에 들어있는 쿠키의 수를 의미한다.
정수 k도 주어지는데, 이는 모든 쿠키 봉지를 배포할 자식 수를 나타낸다.
같은 가방에 들어있는 모든 쿠키는 반드시 같은 아이에게 가야하고, 나눠져서도 안된다.

배표의 부당성은 배포에서 한 아이가 얻은 최대 총 쿠키로 정의된다.

배포의 부당성의 최소를 리턴해라.

제한:
cookies의 길이는 8 이하
cookies[i]는 십만 이하
k는 2 이상 8 이하.

해결방법:

1)파티셔닝 문제. k가 8 이하이므로 직접 일일히 세어 보는 수 밖에 없나?
-> 구간 합은 정렬한 뒤에 Sum배열을 만들면 O(1)에 리턴할 수 있다.
-> cookies도 2 이상 8 이하이다.
-> 해볼 만 하다.
-> 그럼 파티셔닝의 기준을 명확히 세워야 한다.
-> partition [i] = 0부터 i번쨰, i+1번쨰와 마지막을 나눈다는 의미이다.
-> 파티셔닝은 그럼 0부터 cookies.length-2까지 가능하다.
-> 한가지 유의할 점!! sorting 해도 반드시 순열을 통해 구해야 한다!! 순열을 하지 않으면 빼먹는 케이스가 반드시 있다!!

회고:
상당히 까다로운 문제. partition할 때  beforeIdx에 대한 예외처리 중요 
그리고 부당성은 최대로 정의되지만, 우리가 구하는건 최소 부당성이므로, 최대의 최소 문제로 볼 수 있다.
https://leetcode.com/problems/fair-distribution-of-cookies/discuss/2140937/DFS-with-Mask-0-ms
우리는 k가 8 이하이기 때문에 이런 방법을 적용할 수 있었다.
이는 knapsack문제이며, np-complete이기 때문에 모든 방법을 search해야 한다.
class Solution {
public:
    int help(vector<int>& cookies, vector<int>& Sum, vector<int>& partition, int nowIdx, int remain){//nowIdx = 현재 cookies의 인덱스, remain = 남은 파티션 개수
        if(remain == 0){
            int temp = -1;
            int partIdx = -1, beforeIdx = -1;
            for(int i=0; i<partition.size(); i++){
                partIdx = partition[i];
                beforeIdx = (i == 0 ? 0 : partition[i-1]);
                temp = max(temp, Sum[partIdx] - (beforeIdx == 0 ? 0 : Sum[beforeIdx]));
                //cout << temp << ' ' ;
            }
            //cout << endl;
            //끝 요소도 넣어주어야 한다.
            temp = max(temp, Sum.back() - Sum[partition.back()]);
            return temp;
        }
        if(nowIdx == cookies.size())
            return 100000000;
        int ret = 100000000;
        
        partition.push_back(nowIdx);
        ret = min(ret, help(cookies, Sum, partition, nowIdx+1, remain - 1));
        partition.pop_back();
        ret = min(ret, help(cookies, Sum, partition, nowIdx+1, remain));
        return ret;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        //정렬
        sort(cookies.begin(), cookies.end());
        
        int n = cookies.size();
        
        
        int ret = 100000000;
        do{
            vector<int> Sum(cookies.size(), 0);
            for(int i=0; i<n; i++){
                if(i == 0){
                    Sum[0] = cookies[0];
                    continue;
                }
                Sum[i] = Sum[i-1] + cookies[i];
            }
            vector<int> partition;
            ret = min(ret, help(cookies, Sum, partition, 0, k-1));
        }while(next_permutation(cookies.begin(), cookies.end()));
        return ret;
        
    }
};
