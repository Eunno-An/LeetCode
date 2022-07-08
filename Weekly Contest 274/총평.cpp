1. 
class Solution {
public:
    bool checkString(string s) {
        bool isA = false;
        if(s[0] == 'a')
            isA = true;
        for(int i=0; i<s.size(); i++){
            if(isA && s[i] == 'a')
                continue;
            else{
                if(isA == true && s[i] == 'b')
                    isA = false;
                else if(isA == false && s[i] == 'a')
                    return false;
            }
        }
        return true;
    }
};
2.
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        string before = bank[0];
        int beforeOneCount = 0;
        int ret = 0;
        for(int i=0; i<before.size(); i++)
            if(before[i] == '1')
                beforeOneCount++;
        for(int i=1; i<bank.size(); i++){
            string now = bank[i];
            int oneCount = 0;
            for(int j=0; j<now.size(); j++){
                if(now[j] == '1')
                    oneCount++;
            }
            if(oneCount == 0)
                continue;
            else{
                if(beforeOneCount == 0){
                    before = now;
                    beforeOneCount = oneCount;
                    continue;
                }else{
                    ret += (oneCount * beforeOneCount);
                    before = now;
                    beforeOneCount = oneCount;
                }
            }
        }
        return ret;
    }
};
3. 
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long l_mass = mass;
        for(int i=0; i<asteroids.size(); i++){
            if(l_mass >= asteroids[i])
                l_mass += (long long)asteroids[i];
            else
                return false;
        }
        return true;
    }
};
4.Fail
Toplogical Sort + Cycle Size check
https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/discuss/1674049/Mutual-Favorites
