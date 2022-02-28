//Fail
class Solution {
public:
    /*
    문제:
    time[i] = i번째 버스가 one trip을 완료하기 위해 걸리는 시간
    totalTrips = 총 모든 버스가 한 여행의 횟수
    
    문제는 적어도 totalTrips번 만큼의 trips를 하기 위한 최소 시간을 구하여라.
    
    제한:
    time의 길이는 십만
    time[i]와 totalTrips는 천만 이하
    
    해결방법:
    
    시뮬레이션이다. 근데 시뮬레이션인데 이게 시간이 너무 걸린다.
    그럼 어떻게 줄일 방법이 없을까?
    이분탐색으로 시간을 찾아보면 된다.
    
    회고:
    브루트포스는 세웠으나... 이분탐색으로까지 생각을 못한게 조금은 아쉽다.
    
    maxTripTime설정하기
    ->실수:가장 작은 시간으로 totalTrips번 만큼 여행한게 최대 시간인데 이상하게 설정했다.
        
    */
    
    //tripTime만큼의 초 안에 버스들이 totalTrips 이상의 trip이 가능한지 여부를 리턴한다.
    bool checkAllBusCanTrip(vector<int>& time, int tripTime, int totalTrips){
        long long tempTrips = 0;
        for(int i=0; i<time.size(); i++){
            tempTrips += tripTime / time[i];
            if(tempTrips >= totalTrips)
                return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        int minTime = time[0];
        long long maxTripTime = (long long)time[0] * totalTrips;
        
        long long lo = minTime, hi = maxTripTime;
        long long mid;
        while(lo != hi){
            mid = (lo + hi)/2;
            //mid time에 모든 버스가 totalTrips만큼 이상을 할 수 있는지를 check 한다.
            //만약 totalTrips만큼을 못한다면? midTime은 부족하다. 그래서 lo를 mid+1 늘린다.
            if(!checkAllBusCanTrip(time, mid, totalTrips)){
                lo = mid+1;
            }else{
                hi = mid;
            }
        }
        return lo;
    }
};
