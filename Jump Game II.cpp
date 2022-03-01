//Success. 시간 25분?30분? 정확히 못쟀음..
//2차 22-03-01: Fail. DP도 제대로 못짰음. 집중 안하고 하면 진짜 안될듯
/*

Runtime: 1236 ms, faster than 5.01% of C++ online submissions for Jump Game II.
Memory Usage: 16.4 MB, less than 42.15% of C++ online submissions for Jump Game II.

문제:
        음이 아닌 정수 배열 nums가 주어지고, 현재 배열의 첫번재 인덱스에 위치해있다고 가정한다.
        각각의 요소들은 그 위치에서 jump할 수 있는 "최대"점프 길이를 나타낸다.
        내 목표는 "마지막 인덱스"에 "최소"점프로 가는 것이다.
        항상 마지막 인덱스에 도달할 수 있다고 봐도 무방하다.
        
    해결 방법:
    1) 브루트포스(시뮬레이션). 
    if nums[i] == 0 : fail
    1 ~ nums[i] 까지 시뮬레이션을 돌린다.
    시간복잡도? nums.length() = N, nums[i] = M 이라고 할 때, O(M!)엄청난 시간초과.
    
    2) dp(bottom-up, iterative)
    cache[i] = i까지 가는데 걸리는 최소 점프 횟수
    cache[i] = k is reachable to i: min(cache[k] + 1); 
    
    추가 첨부:
    3) dp(top-down, recursive)
    4) 😈Greedy. O(N)
    핵심 아이디어:
    우리는 모든 인덱스에대해서 반복할 수 있다. 현재 위치로부터, 가장 멀게 도착할 수 있는 위치까지를 유지하면서.

    maxReachable:가장 멀게 도착할 수 있는 위치
    lastJumpedPos:가장 멀게 도착하는 위치

    우리는 매번 maxReachable까지 lastJumpedPos를 업데이트 할 것이다.

    lastJumpedPos를 maxReachable과 분리햇 ㅓ업데이트 하는 것은, 최소 점프수를 유지하게 한다.
    lastJumpedPos를 업뎃할 때 마다, jumps또한 업데이트되고, lastJumpedPos로 도달하기위해 필요한 최소 점프 수를 쌓게 한다.

    (대조적으로, jumps를 maxReachable과 함께 업데이트하는 것은 최적의 솔루션을 주지 않는다.)
    
    내가 이해하기 쉽게 다시 한 번 정리하면,
    정리하면, maxReachable은 인덱스를 보면서 현재 어디까지 가장 멀리 갈 수 있는지이다.
    만약 i가 마지막으로 점프하는 위치(lastJumpedPos)까지 이동했다면, 우리는 maxReachable로 바로 이동시켜도 된다!
    왜냐하면 maxReachable은 현재위치 i부터 lastJumpedPos까지 사이에 우리가 이동할 수 있는 가장 먼 길이니까!
    그래서 그리디 하게 이동해도 되는것이다.
    핵심은 i ~ lastJumpedPos까지 등장하는 maxReachable에 대해서 계속 max값을 수정 받다가
    i가 lastJumpedPos에 위치해있을떄 바꿔주는 것이다.
    
*/
1)BruteForce
class Solution {
public:
    int minCount = 100001;
    void help(vector<int>& nums, int nowIdx, int count){
        if(nowIdx == nums.size() - 1){
            minCount = min(minCount, count);
            return;
        }    
        for(int i=1; i<=nums[nowIdx]; i++)
            if(nowIdx+i < nums.size())//실수 1: 범위에 대한 예외처리.
                help(nums, nowIdx+i, count+1);
        return;
    }
    int jump(vector<int>& nums) {
        help(nums, 0, 0);
        return minCount;
    }
};

2)DP(bottom-up)
class Solution {
public:
    /*
    
    
    */
    int cache[10001];
    int jump(vector<int>& nums) {
        memset(cache, 10001, sizeof(cache));
        cache[0] = 0;
        for(int i=0; i<nums.size(); i++){//10000 * 10000 = 1억. 간신히 시간 초과.
            int maxJump = nums[i];
            for(int k = 0; k<=i; k++){
                if(k + nums[k] >= i){//k is reachable to i
                    cache[i] = min(cache[i], cache[k] + 1);
                }
            }
        }
        return cache[nums.size()-1];
        
    }
};
3)DP(top-down, recursive)
int jump(vector<int>& nums) {
	vector<int> dp(size(nums), 1001); // initialise all to max possible jumps + 1 denoting dp[i] hasn't been computed yet
	return solve(nums, dp, 0);
}
// recursive solver to find min jumps to reach end
int solve(vector<int>& nums, vector<int>& dp, int pos) {
	if(pos >= size(nums) - 1) return 0;    // when we reach end, return 0 denoting no more jumps required
	if(dp[pos] != 1001) return dp[pos];    // number of jumps from pos to end is already calculated, so just return it
	// explore all possible jump sizes from current position. Store & return min jumps required
	for(int j = 1; j <= nums[pos]; j++)
		dp[pos] = min(dp[pos], 1 + solve(nums, dp, pos + j));        
	return dp[pos];
}

4)Greedy

int jump(vector<int>& nums) {
	int n = size(nums), i = 0, maxReachable = 0, lastJumpedPos = 0, jumps = 0;
	while(lastJumpedPos < n - 1) {  // loop till last jump hasn't taken us till the end
		maxReachable = max(maxReachable, i + nums[i]);  // furthest index reachable on the next level from current level
		if(i == lastJumpedPos) {			  // current level has been iterated & maxReachable position on next level has been finalised
			lastJumpedPos = maxReachable;     // so just move to that maxReachable position
			jumps++;                          // and increment the level
	// NOTE: jump^ only gets updated after we iterate all possible jumps from previous level
	//       This ensures jumps will only store minimum jump required to reach lastJumpedPos
		}            
		i++;
	}
	return jumps;
}
