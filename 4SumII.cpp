//fail
//T.C = O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hash;
        int n = nums1.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //Increment the hashtable at the sum of the pair
                hash[nums1[i]+nums2[i]]++;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans = ans+hash[-(nums3[i]+nums[j])];
            }
        }
        return ans;
    }
};
