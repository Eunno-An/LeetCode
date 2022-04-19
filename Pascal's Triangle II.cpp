1차 22-04-19

Success
Details 
Runtime: 3 ms, faster than 39.24% of C++ online submissions for Pascal's Triangle II.
Memory Usage: 6.6 MB, less than 34.92% of C++ online submissions for Pascal's Triangle II.
  
Follow-up 아직 하지 않았음... O(rowIndex) space 만큼 만 쓰기.
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> now = {1};
        if(rowIndex == 0)
            return now;
        
        vector<int> before = {1, 1};
        if(rowIndex == 1)
            return before;
        now.clear();
        vector<int> ret;
        for(int i=2; i<=rowIndex; i++){
            now.push_back(1);
            
            for(int j=1; j<before.size(); j++)
                now.push_back(before[j-1] + before[j]);
            
            now.push_back(1);
            
            before = now;
            ret = now;
            now.clear();
        }
        return ret;
    }
    
};
