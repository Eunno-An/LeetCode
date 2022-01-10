/*
Fail.
시간은 어찌저찌 해결 했으나, 공간을 O(1)에 처리하지 못함.
시간 해결은 unordered_set으로 하였음. 이것만 해도 잘 했다고 생각함.

문제:
배열에서 안쓰인 가장 작은 양수를 리턴해라.
시간은 O(n)이고, 공간은 O(1)에 해라.

핵심 아이디어:
우리는 배열에서 처음 n개의 양의 정수 중 어떤 것이 발생하는지 추적하기만 하면 된다. 
"이를 위해 추가 공간 없이 배열을 부울 배열처럼 처리할 수 있으며, 여기서 부호(arr[i])는 i번째 양의 정수가 존재하는지 여부"를 나타낸다.
먼저 양수가 아닌 모든 값을 n + 1로 바꿉니다. 이러한 인덱스는 저장 공간으로만 사용됩니다. 
그런 다음 배열의 처음 n개 양수에 대해 해당하는 지수의 값을 음수로 돌립니다. 
마지막으로, 우리가 해야 할 일은 첫 번째 양수 값을 확인하는 것이고, 이것은 우리에게 첫 번째 누락된 양수 값을 줄 것이다. 
만약 우리가 이러한 인덱스를 찾지 못하면, n까지의 자연수는 모두 존재하므로 n + 1을 반환한다.
https://leetcode.com/problems/first-missing-positive/discuss/781724/C%2B%2B-simple-5-line-solution-O(n)-time-and-O(1)-space

*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) if (nums[i] <= 0) nums[i] = n + 1;
        //모든 0 이하의 수들은 볼 필요도 없다.
        for (int i = 0; i < n; i++) if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1;
        //이미 배열에 존재하는 양수들은 음수로 처리해서 안본다는 얘기.
        for (int i = 0; i < n; i++) if (nums[i] > 0) return i + 1;
        return n + 1;
    }
};
