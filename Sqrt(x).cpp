//이게 이렇게도 풀 수 있구나...신기하다
class Solution {
public:
    int mySqrt(int x) {
        return (int)sqrt(x);
    }
};

class Solution {
public:
 int mySqrt(int x) {
     if(x==0) return 0;
int l=0, r=x;
int res, mid;  
     while(l<=r){             
            mid=(l+r)/2;
         if(mid == 0) return 1;
            if(mid==x/mid) return mid;    
            else if(mid<x/mid){             
                l=mid+1;       
                res = mid;      
            }
            else r=mid-1;       
        }
        return res;  
    }
};
