1차 22-05-18 Fail

Bit manipulation에 관한 내용인데, 비트쪽은 거의 다룰줄 몰라서 못푼것 같다.

https://leetcode.com/problems/single-number-ii/discuss/700329/CPP-solution-O(32*n)-easy-to-understand-oror-Fully-Explained

문제: 하나의 요소만 단 하나 등장하고 나머지는 세개씩 등장함. 이때 하나의 요소가 뭔지 알아내는 문제.
풀이방법:
각각의 비트의 등장 횟수를 3으로 나눈다. 그걸 더해줌.
근데 하나의 요소가 음수인 경우도 있을 수 있으니 나중에 꼭 체크하는 과정 필요함.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long int res=0;
        for(int i=0;i<32;i++)
        {   int p=0;
            for(int j=0;j<nums.size();j++)
            {   
			    int k=abs(nums[j]);
                p+=(k&(1<<i))!=0?1:0;    //by shifting 1 to left ith time and taking and with1  will give us 
				                                         //that ith bit of nums[j] is 1 or 0
            } 
           p%=3; 
          res+=pow(2,i)*p;
        } 
		/*
		**To handle if res is -ve**
		 We have calculated our result positive number
		 But there may be chance that single number may be negative
		 Eg.array= [2,2,-4,2]
		 Here after bitwise calculation our res will store 4 
		 but you see that 4 is not present in  our array.
		 So , we will check if res (4) is present in array or not
		 if present , then return it else res must be -ve
		 Hence return -res (-4):
		*/
        cout<<res;
        int c=0;
        for(auto x:nums)   //for negative numbers
          if(x==res) {c++;}   //if our calculates value res is present in array, then increment c
        return c==1?res:-res; //if c=1 return res else res must be -ve
    }
};
