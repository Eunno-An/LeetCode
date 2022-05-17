1차 22-05-17 Fail
회고
브루트 포스로는 해결하였으나, 좋은 방법을 떠올리지 못함.
뭔가 Circular라고해서 이어붙여서 푸는 풀이를 했으나.. 딱히 배열을 어떻게 설정해야 할지 모르겠음.
풀이 참고함.

//이 문제는 시뮬레이션 보다는
//먼저 답이 아닌 경우를 제외하고,
//순차탐색을 통해 답이 결국엔 나올것이라는 보장이 있다는 식으로 문제를 푼 느낌이다.
class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        // first of all we need to check whether we've sfficient fuel or not. 
        int total_cost=0,total_fuel=0,n=cost.size();
        for(int i=0;i<n;i++)
        {
            total_cost+=cost[i];
            total_fuel+=gas[i];
        }
        //일단 어떤 경우든 총 용량보다 총 비용이 더 비싸면 못갈 수 밖에 없다.
        if(total_fuel<total_cost)
        {
            return -1;
        }
        
        
        // If the total fuel is sufficient enough to cover the circular tour then definitely an answer exists
        int curr_fuel=0,start=0;  // start with zero fuel.
        for(int i=0;i<n;i++)
        {
            // If at any point our balance/ current fuel is negative that means we can't come to the i'th petrol pump from the previous pump beacuse our fuel won't allow us to cover such distance. 
            //So we'll make the i'th pump as the start point ans proceed. Simultaneously we'll make the current fuel to be 0 as we're starting freshly.
            if(curr_fuel<0)
            {
                start=i;
                curr_fuel=0;
            }
            // at any station we'll fill petrol and pay the cost to go to the next station . so current fuel would be the following.
            curr_fuel+=(gas[i]-cost[i]);
        }
        return start;
    }
};
