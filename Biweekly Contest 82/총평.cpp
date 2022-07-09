1.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->val == 0 || root->val == 1)
            return root->val;
        if(root->val == 2){//OR
            return evaluateTree(root->left) or evaluateTree(root->right);
        }else{//AND
            return evaluateTree(root->left) and evaluateTree(root->right);
        }
    }
};

2.Fail
한번 비슷한 문제를 풀어봤었는데
까먹지 말도록 하자
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        queue<int> q;
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        int n=buses.size();
        int m=passengers.size();
        set<int> st;
        for(auto p:passengers)
        {
            q.push(p);
            st.insert(p);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int currbus=buses[i]; // curr bus depature time.
            int count=0; //number of people in curr bus
            int x;
            //CASE1
            while(!q.empty() && count<capacity && q.front()<=currbus)
            {
                x=q.front();
                q.pop();
                if(st.find(x-1)==st.end()) //checking if person timing-1 doesnt exist and update the answer.
                    ans=x-1; 
                count++;
            }
            //CASE2
            if(count<capacity)
            {
                while(st.find(currbus)!=st.end()) //starting from dept time find a time which does not exist int the set already.
                {
                    currbus--;
                }
                ans=max(ans,currbus);
            }
            
        }
        return ans;
    }
};

//3. Fail
//절댓값의 차를 k1+k2 만큼 줄여야 함.
//(a-b)^2에서 a-b를 절댓값을 취한 것들의 개수를 따로 저장하였음. -> diff
//아주 좋은 방법임. 왜냐? 이 문제에서는 절댓값이 큰 거부터 줄여나갔어야 했음.
//예로 들어 (1-8)^2 (2-1)^2 (3-5)^2 (2-4)^2 라고 하자.
//그럼 7 1 2 2인데 이걸 가장 큰 diff인 7을 M이라고 하고, M+1만큼을 diff 배열에 선언함.
//diff(8) = 0 1 2 0 0 0 0 1 
//이렇게 표현하면 장점이, 뒤에서(M)부터 순회하여 순차적으로 큰 diff를 줄여나갈 수 있음.
//이걸 만약에 set으로 구현했으면? set에서 가장 큰 값 찾고, 그거 지우고 다시 -1한 값 넣고..
//이러면 시간초과 난다 이거임.

//별개로 reverse_iterator를 설정하면 iterator++하면 rend()쪽으로 가는거임.
//뭔소리냐, map<int, vector<int>>::reverse_iterator rit = bucket.rbegin()
//이때, rend() 쪽으로 가려면 rit++을 해주어야 한다는 점.

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        for(int i = 0; i<n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }
        int M = *max_element(diff.begin(), diff.end());
        vector<int> bucket(M+1);
        for(int i = 0 ; i<n; ++i) {
            bucket[diff[i]]++;
        }
        int k = k1 + k2;
        for(int i = M; i > 0; --i) {
            if(bucket[i] > 0) {
                int minus = min(bucket[i], k);
                bucket[i] -= minus;
                bucket[i-1] += minus;
                k -= minus;
            }
        }
        long long ans = 0;
        for(long long i = M; i > 0; --i) {
            ans += bucket[i]*i*i;
        }
        return ans;
    }
};

//4.
