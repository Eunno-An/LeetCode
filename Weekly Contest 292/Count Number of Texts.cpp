//
class Solution {
public:
    const int mod = 1e9+7;
    int cache[100005];
    int help(string& pressedKeys, int idx){
        if(idx == pressedKeys.size())
            return 1;
        int& ret = cache[idx];
        if(ret != -1) return ret;
        
        int pressCount = 1;
        long long currIdx = idx;
        int maxCount = (pressedKeys[idx] == '7' || pressedKeys[idx] == '9') ? 4 : 3;
        long long ans = 0;
        while(pressCount <= maxCount && pressedKeys[currIdx] == pressedKeys[idx]){
            ++pressCount;
            ++currIdx;
            ans += help(pressedKeys, currIdx) % mod;
        }
        ans %= mod;
        return ret=ans;
    }
    int countTexts(string pressedKeys) {
        memset(cache, -1, sizeof(cache));
        return help(pressedKeys, 0) % mod;
    }
};
