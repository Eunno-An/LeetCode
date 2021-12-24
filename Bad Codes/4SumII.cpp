//굳이 이렇게 안해도 되는데, 4Sum이랑 비슷하게 풀겠다고...
//그치만 대강대강 내가 재귀도 처음부터 짜고, 로직도 어느정도 해결하려고 노력했던 문제라 의미가 깊음.
//졌잘싸
class Solution {
public:
    vector<vector<int>> numArray;
    int kSum(long long now, int start){
        int ret=0;
        //1. 우리가 고려할 배열들을 다 썼을 때, 0을 리턴한다.
        if(start == numArray.size())
            return 0;
        
        //2. 마지막 두개의 배열들만 남았을 때, 두개의 배열을 갖고서 now*-1을 만들 수 있는 경우를 리턴한다. 
        if(start == 2){
            return twoSum(numArray[start], numArray[start+1], now * -1);    
        }
        for(int i=start; i<numArray.size(); i++){
            for(int j=0; j<numArray[start].size(); j++){
                ret += kSum(now + numArray[i][j], i+1);
            }
        }
        return ret;
            
    }

    int twoSum(vector<int> nums3, vector<int> nums4, long long target){
        int ret = 0;
        int left = 0, right = nums4.size()-1;
        while(left < nums3.size() && right >= 0){
            long long add = (long long)nums3[left]+nums4[right];
            if(add > target)
                right--;
            else if(add < target)
                left++;
            else{
                ret++;
                left++; right--;
            }
        }
        return ret;
    }
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        sort(nums4.begin(), nums4.end());
        
        
        numArray.push_back(nums1);
        numArray.push_back(nums2);
        numArray.push_back(nums3);
        numArray.push_back(nums4);
        
        if((long long)nums1[0] + nums2[0] + nums3[0] + nums4[0] > 0)
            return 0;
        if((long long)nums1.back() + nums2.back()+ nums3.back() + nums4.back() < 0)
            return 0;
        
        return kSum(0, 0);
        
    }
    //kSum(): k개의 정수배열이 주어졌을 때, 각각의 정수배열에서 하나씩 뽑아서 그 수들을 더하면 0이 되는 수 조합의 개수를 리턴한다.
    //long long now = 현재까지 더한 값
    //int start = 현재 다루는 배열의 인덱스
    //kSum(long long now, int start)
    //kSum(now, start) = if(numArray[now][0] + kSum(now+numArray[now][0], start+1) == 1

    
};
