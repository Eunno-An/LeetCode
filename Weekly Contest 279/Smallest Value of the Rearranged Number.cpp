class Solution {
public:
    long long smallestNumber(long long num) {
        bool isMinus = (num < 0 ? true : false);
        vector<int> nums;
        
        long long ret = 0;
        if(isMinus)
            num*=-1;
        long long temp = num;
        while(temp != 0){
            nums.push_back(temp%10);
            temp /= 10;
        }
        sort(nums.begin(), nums.end());
        if(isMinus){//num으로 최대 만들기
            for(int i=nums.size()-1; i>=0; i--){
                ret *= 10;
                ret += nums[i];
            }
            ret *= -1;
        }else{//num으로 최소 만들기
                for(int i=0; i<nums.size(); i++){
                    if(nums[i] != 0){
                        ret += nums[i];
                        nums.erase(nums.begin() + i);
                        break;
                    }
                }
                for(int i=0; i<nums.size(); i++){
                    ret *= 10;
                    ret += nums[i];
                }
            
        }
        return ret;
    }
};
