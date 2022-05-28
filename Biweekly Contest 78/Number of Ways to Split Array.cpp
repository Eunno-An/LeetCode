1차 22-05-28
Success
Time: 5분
class Solution {
public:
/*
문제:
길이가 n인 정수 배열 nums가 주어진다.
nums는 인덱스 i에 대해 valid split을 포함한다.

1)첫 i+1개의 요소들의 합은 나머지 n-i-1개의 elements들의 합보다 크거나 같다.
2) i의 오른쪽에 대해 적어도 하나의 요소가 있다.

제한:
nums의 길이는 십만, nums[i]들은 -십만에서 +십만

해결방법:
1) 브루트포스로 하기에는 너무 시간 오래걸림.
따라서 sum 배열 이용.
자료형도 주의하기.
*/
    int waysToSplitArray(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();
        
        
        vector<long long> sums(n, 0);
        sums[0] = nums[0];
        
        for(int i=1; i<n; i++)
            sums[i] = (long long)nums[i] + sums[i-1];
        
        for(int i=0; i<n-1; i++){
            long long left = sums[i];
            long long right = sums[n-1] - left;
            if(left >= right)
                ret++;
        }
        return ret;
    }
};
