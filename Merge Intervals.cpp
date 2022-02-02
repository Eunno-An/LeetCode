Success
시간: 19분 42초
Details 
Runtime: 96 ms, faster than 7.34% of C++ online submissions for Merge Intervals.
Memory Usage: 18.9 MB, less than 45.28% of C++ online submissions for Merge Intervals.

class Solution {
public:
    /*
    문제:
    intervals의 배열이 주어진다. intervals[i] = [start_i, end_i]
    모든 intervals들을 합치고, 최종 intervals들의 결과를 도출해라.
    
    제한:
    intervals의 길이는 10000
    
    해결방법:
    1)start_i와 end_i가 최대 만이므로, 구간을 실제로 색칠한다. 
    구간을 받을때 마다 end_i - start_i번 만큼 루프를 돌고, 구간 받는건 만번이니까 최대 일억번에 수행이 가능하다.
    2)sorting을 통해 점차 늘려주는 방법.(Solution 참고)
    
    회고:
    ★★★ 비슷한 문제를 본 적이 있었음. 항상 좌표와 구간 관련한 문제가 나올때는, [1,3], [4, 6]라는 구간이 있을 때
    좌표상에서 순회를 하면 3이랑 4가 붙어있어서 얘네가 따로 떨어져있다는 것을 인식하지 못함.
    그래서 좌표를 확장시켜줘서 공간을 두게 하는 방법이 있음. 대표적으로 *2를 하는 방법.
    
    그러나 이 문제에서는 이상하게 시간초과가 안나는데
    보통 시간초과가 날 거 같음 왜냐면 배열의 크기를 1만에서 2만으로 늘리면 총 코스트는 2억이 되서, 
    만약 타임이 1초였다면 시간이 넘칠것임.
    
    결론은 내 풀이는 좋은 풀이가 아니엿음.
    */
  //1)번 풀이
    bool line[20002];
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        for(int i=0; i<intervals.size(); i++)
            intervals[i][0]*=2, intervals[i][1] *= 2;
        memset(line, false, sizeof(line));
        sort(intervals.begin(), intervals.end());
        int minPos = intervals[0][0];
        //maxPos로 하면 안된다!
        for(int i=0; i<intervals.size(); i++)
            for(int j = intervals[i][0]; j<=intervals[i][1]; j++)
                line[j] = true;
        int startPos = minPos;
        bool startRange = true;
        
        for(int i=minPos; i<=20001; i++){
            if(line[i] == false && startRange == true){
                ret.push_back({startPos/2, (i-1)/2});
                startRange = false;
            }
            else if(line[i] == true && startRange == false){
                startPos = i;
                startRange = true;
            }
        }
        return ret;
    }
  //2번 풀이
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        for(auto interval:intervals){
            //만약 리스트가 비어있거나, 현재 구간이 이전 구간을 덮지 못할 때 그냥 더해주라.
            if(ret.empty() || ret.back()[1] < interval[0])
                ret.push_back(interval);
            //그렇지 않으면, 오버랩이 발생한다. 따라서 현재와 이전 구간을 합친다.
            else
                ret.back()[1] = max(ret.back()[1], interval[1]);
        }
        return ret;
    }
};
