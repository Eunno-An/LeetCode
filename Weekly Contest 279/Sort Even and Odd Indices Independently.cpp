evens가 더 많은 것을 인지하기!
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odds;
        vector<int> evens;
        vector<int> ret;
        for(int i=0; i<nums.size(); i++){
            if(i%2 != 0)
                odds.push_back(nums[i]);
            else
                evens.push_back(nums[i]);
        }
        
        sort(odds.begin(), odds.end(), greater<int>());
        sort(evens.begin(), evens.end());
        
        for(int i=0; i<odds.size() && i < evens.size(); i++){
            ret.push_back(evens[i]), ret.push_back(odds[i]);
        }
        //cout << odds.size() << ' ' << evens.size() << endl;
        if(odds.size() < evens.size())
            ret.push_back(evens.back());
        return ret;
    }
};
