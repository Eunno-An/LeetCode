class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ret;
        queue<int> front;
        queue<int> end;
        int pivotCount=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == pivot)
                pivotCount++;
            else if(nums[i] > pivot)
                end.push(nums[i]);
            else
                front.push(nums[i]);
        }
        
        while(!front.empty()){
            ret.push_back(front.front());
            front.pop();
        }
        while(pivotCount--){
            ret.push_back(pivot);
        }
        while(!end.empty()){
            ret.push_back(end.front());
            end.pop();
        }
        return ret;
    }
};
