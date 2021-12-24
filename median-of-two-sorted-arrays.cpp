//두개의 정렬된 배열이 주어질 때, 중앙값을 찾는 문제.
//단순히 BruteForce로 하면 O(m+n)에 수행할 수 있지만,
//문제의 질이는 O(log(m+n))으로 하는 거였다..슈발..

//총 두가지 풀이가 있다.
//하나는 이분탐색. 

//그리고 하나는 kth smallest number를 이용한다.

//1. 이분탐색
class Solution {
public:
    double mediann(vector<int>& a, vector<int>& b){
        int m = a.size();
        int n = b.size();
        
        //항상 m <= n 임을 보증
        if(m > n)
            return mediann(b, a);
        int l=0, r=m;
        
        //문제의 아이디어:
        //각각의 어레이를 파티션으로 나눈다.
        //x라는 어레이를 파티션으로 나눴을 때, 파티션 기준 leftX, rightX
        //y라는 어레이를 파티션으로 나눴을 때, 파티션 기준 leftY, rightY
        
        //leftX에서 가장 큰 값을 maxlx, rightX에서 가장 작은 값을 minrx
        //leftY에서 가장 큰 값을 maxly, rightY에서 가장 작은 값을 minry
        
        //leftX <= minry && maxly <= minrx일 때까지 반복한다
        
        while(l <= r){
            int partx = l + (r-l)/2;
            int party = (m+n+1)/2 - partx;
            int maxlx = (partx == 0) ? INT_MIN:a[partx-1];
            int minrx = (partx == m) ? INT_MAX:a[partx];
            int maxly = (party == 0) ? INT_MIN:b[party-1];
            int minry = (party == n) ? INT_MAX:b[party];
            if(maxlx<=minry && maxly<=minrx){
                if((m+n)%2 == 0)
                    return (double)(max(maxlx, maxly) + min(minrx, minry))/2;
                else
                    return (double)(max(maxlx, maxly));
            }else if(maxlx > minry)
                r = partx - 1;
            else
                l = partx+1;
        }
        return -1.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        ans = mediann(nums1, nums2);
        return ans;
    }
};
//kth smallest number
class Solution {
public:
    int kth(int a[], int m, int b[], int n, int k) {
        if (m < n) return kth(b,n,a,m,k);
        if (n==0) return a[k-1];
        if (k==1) return min(a[0],b[0]);

        int j = min(n,k/2);
        int i = k-j;
        if (a[i-1] > b[j-1]) return kth(a,i,b+j,n-j,k-j);
        return kth(a+i,m-i,b,j,k-i);
    }

    double findMedianSortedArrays(int a[], int m, int b[], int n) {
        int k = (m+n)/2;
        int m1 = kth(a,m,b,n,k+1);
        if ((m+n)%2==0) {
            int m2 = kth(a,m,b,n,k);
            return ((double)m1+m2)/2.0;
        }
        return m1;
    }
};
/*
1 7 24 52 36

2 8 23 

merging: 1 2 7 8 23 24 52 36
k를 4라고 하면 num[k-1] = 8

j = min(3, 2) = 2
i = 4-2 = 2
if(a[2-1] = 7 > b[2-1] = 8)
return kth([24, 52, 36], 3, [2, 8, 23], 6) 
*/
