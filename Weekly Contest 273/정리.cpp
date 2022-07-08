1.
class Solution {
public:
    bool isSameAfterReversals(int num) {
        string s_num = to_string(num);
        reverse(s_num.begin(), s_num.end());
        int rev = stoi(s_num);//625
        
        string s_rev = to_string(rev);
        reverse(s_rev.begin(), s_rev.end());
        
        int original = stoi(s_rev);//526
        
        return original == num;
    }
};

2.
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ret(s.size(), 0);
        for(int i=0; i<s.size(); i++){
            int y = startPos[0];
            int x = startPos[1];
            int count = 0;
            for(int j=i; j<s.size(); j++){
                if(s[j] == 'U'){
                    y -= 1;
                }else if(s[j] == 'R'){
                    x += 1;
                }else if(s[j] == 'D'){
                    y += 1;
                }else{
                    x -= 1;
                }
                if(y < 0 || y >= n || x < 0 || x >= n)
                    break;
                count++;
            }
            ret[i] = count;
        }
        return ret;
    }
};

3. Fail
해싱은 잘 했으나, suffix, prefix 아이디어를 떠올리지 못함.
중복되는 요소들에 대한 인덱스 간의 차의 절댓값이
재사용할 수 있다는 것을 확인할 수 있어야 함.(댓글 참조)
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> bucket;
        vector<long long> ret(arr.size(), 0);
        for(int i=0; i<arr.size(); i++){
            if(bucket.count(arr[i]) == 0)
                bucket.insert({arr[i], vector<int>()={i}});
            else{
                bucket[arr[i]].push_back(i);
                ret[bucket[arr[i]][0]] += (i-bucket[arr[i]][0]);
            }
        }
        
        
        for(auto a : bucket){
            int key = a.first;
            vector<int> p = a.second;
            //cout << key << ' ' << p.size() << endl;    
            for(int i=1; i<p.size(); i++){
                //cout << p[i] << ' ' ;
                int idx = p[i];
                
                int diff = (p[i] - p[i-1]);
                
                ret[idx] = ret[p[i-1]] - (long long)diff * (p.size()-i-1) + (long long)diff * (i-1);
                
                
            }
            //cout << endl;
        }
        return ret;
        
        
    }
};

4.Fail
k의 가정을 하고 들어가야 하는 문제!
class Solution {
public:
    vector<int> canMakeIt(multiset<int>& st, int k){
        if(k <= 0)
            return {-1};
        multiset<int> erased;
        vector<int> ans;
        while(st.size() > 0){
            auto it = st.begin();
            int val = *it;//y-k라고 가정.
            int org = val + k;//y라고 가정
            st.erase(st.find(val));//y-k를 지운다.
            erased.insert(val);//y-k를 임시로 지워놓은거에다가 넣는다.
            if(st.find(org + k) != st.end()){ // y+k가 있으면?
                ans.push_back(org);//정답에 y를 넣고
                st.erase(st.find(org+k));//set에서 y+k를 찾아서 지운다.
                erased.insert(org + k);//erased에다가도 y+k를 넣는다.
            }else{//이건 y+k가 없는거임. 이러면 k의 가정이 잘못되었으므로 함수를 끝낸다.
                for(int x : erased)
                    st.insert(x);
                return {-1};
            }
        }
        return ans;
    }
    vector<int> recoverArray(vector<int>& nums) {
        sort(all(nums));
        multiset<int> st(all(nums));
        int smallest = nums[0];
        for(int j = 1; j < nums.size(); j++){
            int addi = smallest + nums[j];//addi는 (y-k)와 (y+k)가 더해졌다고 가정.
            if(addi % 2 == 0){//가정에 의해 addi는 2의 배수일 수 밖에.
                int org = addi / 2;//org = y라고 가정.
                int k = nums[j] - org;//가정에 의해 k도 이렇게 정해짐.
                vector<int> ans = canMakeIt(st, k);//k를 가정했으니, 나머지 요소들에 대해 검사.
                if(ans[0] != -1)
                    return ans;
            }
        }
        return {-1};
    }
};
