예외처리가 많았던 문제이다
정규화 할 때와 아닐때
그리고 분이 99를 넘어가거나
시간초가 40 미만, 그리고 60이상일 때
각각 테스트케이스를 나눠서 생각해주어야 하는 문제
class Solution {
public:
    /*
    targetseconds
    1) 이걸 정규화 시킨 경우
    2) 그냥 하는 경우
    */
    int help(string& s, char now, int cost, int moveCost ,int pushCost){
        if(s.empty())
            return cost;
        if(s[0] != now)
            cost += moveCost;
        cost += pushCost;
        string ss = s.substr(1);
        return help(ss, s[0], cost, moveCost, pushCost);
    }
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int min = targetSeconds / 60;
        int sec = targetSeconds % 60;
        int norm = min * 100 + sec;
        string normal = to_string(norm);
        int v1 = 100000000;
        int v2 = 100000000;
        if(min <= 99)
            v1 = help(normal, startAt + '0', 0, moveCost, pushCost);
        
        if(targetSeconds<= 99){
            string denormal = to_string(targetSeconds);
            v2 = help(denormal, startAt + '0', 0, moveCost, pushCost);
        }
        
        int v3 = 100000000;
        int v4 = 100000000;
        if(sec < 40 && min >= 1){
            int norm2 = (min-1)* 100 + (sec + 60);
            string normal2 = to_string(norm2);
            v3 = help(normal2, startAt + '0', 0, moveCost, pushCost);
        }
        
        if(sec >= 60 && min < 99){
            int norm3 = (min+1) * 100 + (sec - 60);
            string normal3 = to_string(norm3);
            v4 = help(normal3, startAt+'0', 0, moveCost, pushCost);
        }
        int min1 = (v1 < v2 ? v1 : v2);
        int min2 = (v3 < v4 ? v3 : v4);
        int minVal = (min1 < min2 ? min1 : min2);
        return minVal;
    }
};
