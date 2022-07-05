실패

3*n개 중 n개를 뽑아야 함.
어떤 인덱스 i를 기준으로 앞에서는 i-n개 뽑고, 뒤에서는 2*n-i개를 뽑아야 한다.
뽑는 것도 앞에 있는거는 큰거를, 뒤에 있는거는 작은 거를 뽑아야 한다.
정렬은 "힙"을 통해서 이용한다. 왜냐하면 삽입 삭제가 자주 일어아는 과정에서 최대와 최소를 빠르게 찾아야 하기 때문이다.

//https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/discuss/1747244/Two-Heaps-and-Temp-Array

long long minimumDifference(vector<int>& nums) {
    int n = nums.size() / 3;
    priority_queue<int> pq_l(begin(nums), begin(nums) + n);
    priority_queue<int, vector<int>, greater<int>> pq_r(begin(nums) + 2 * n, end(nums));
    long long sum_first = accumulate(begin(nums), begin(nums) + n, 0LL);
    long long sum_second = accumulate(begin(nums) + 2 * n, end(nums), 0LL); 
    vector<long long> diffs(n + 1);
    for (int i = n; i <= 2 * n; ++i) {
        diffs[i - n] = sum_first;
        if (pq_l.top() > nums[i]) {//최대를 pq에서 뽑기
            sum_first += nums[i] - pq_l.top();
            pq_l.pop();
            pq_l.push(nums[i]);
        }
    }
    for (int i = 2 * n - 1; i >= n - 1; --i) {
        diffs[i - n + 1] -= sum_second;
        if (pq_r.top() < nums[i]) {//최소를 pq에서 뽑기
            sum_second += nums[i] - pq_r.top();
            pq_r.pop();
            pq_r.push(nums[i]);
        }
    }
  //diff[i] = i를 기준으로 sum_first - sum_second
    return *min_element(begin(diffs), end(diffs));
}
