/*
Fail
문제:
    오버래핑되지않은 구간들이 주어진다. 이걸 intervals라고 한다.
    1) intervals들은 start_i로 오름차순 정렬되어 있다.
    2) 서로 겹치지 않는다.
    newInterval이 주어지면
    그걸 intervals에 넣고
    intervals의 조건을 만족하도록 intervals들을 수정해라
    
    제한:
    intervals의 길이는 최소 0, 최대 만
    start_i와 end_i의 최소 0, 최대 십만
    
    해결방법:
    단순한 구현.. 근데 이사람 진짜 개 깔끔하게 했네
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> result;
        
        for (size_t i = 0; i < intervals.size(); i++)
        {
			//  the new interval is after the range of other interval, so we can leave the current interval baecause the new one does not overlap with it
            if (intervals[i][1] < newInterval[0])
            {
                result.push_back(intervals[i]);
            }
			// the new interval's range is before the other, so we can add the new interval and update it to the current one
            else if (intervals[i][0] > newInterval[1])
            {
                result.push_back(newInterval);
                newInterval = intervals[i]; 
            }
			// the new interval is in the range of the other interval, we have an overlap, so we must choose the min for start and max for end of interval 
            else if(intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1])
            {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);

            }
        }
        
        result.push_back(newInterval); 
        return result;
    }
};
