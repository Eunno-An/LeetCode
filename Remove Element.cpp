//fail
//투포인터에 약하다. 굉장히 쉬운 문젠데 구현도 못하고.. 정말 심각하다~~
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int n = nums.size();
        while(i < n){
            if(nums[i] == val){
                nums[i] = nums[n-1];
                n--;
            }else{
                i++;
            }
        }
        return i;
    }
};
