2154. Keep Multiplying Found Values by Two

Runtime: 8 ms, faster than 60.00% of C++ online submissions for Keep Multiplying Found Values by Two.
Memory Usage: 12.3 MB, less than 10.00% of C++ online submissions for Keep Multiplying Found Values by Two.
/*
소요 시간: 1분 미만

문제:
정수 배열 nums가 주어진다. 그리고 original이라는 정수도 주어진다.
original을 2씩 곱해서 nums라는 배열에 있으면 한번 더 곱한다.
original이 존재하지 않으면 그 original을 리턴한다.

해결방법:
1. unordered_set을 이용.
2. 수의 범위가 크지 않으므로, 수를 인덱스로 이용해서 O(1)에 찾는 방법.
*/

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> hash;
        for(int i=0; i<nums.size(); i++)
            hash.insert(nums[i]);
        
        while(hash.find(original) != hash.end()){
            original *= 2;
        }
        return original;
    }
};

2155. All Divisions With the Highest Score of a Binary Array
Runtime: 640 ms, faster than 22.73% of C++ online submissions for All Divisions With the Highest Score of a Binary Array.
Memory Usage: 286.7 MB, less than 22.73% of C++ online submissions for All Divisions With the Highest Score of a Binary Array.

/*
문제:
0indexed의 이진 배열 nums가 주어진다. 길이는 n이다.
index i에 의해 왼쪽과 오른쪽으로 나뉘어 진다.(0 <= i <= n) i는 n과 같을수 있음에 주의하자.
nums_left = 0부터 i-1까지. nums_right = i부터 n-1까지
if i == 0 : nums_left is empty()
if i == n: nums_left  == nums

i의 division score라는 것은 nums_left에 있는 0의 개수와 nums_right에 있는 1의 개수의 총 합이다.

가능한 가장 높은 division score를 갖는 모든 distinct indices를 리턴해라.
순서는 상관없다.

제한:
1<=n<=100000(십만)

해결방법:
1)가장 쉽게
모든 i에 대해서 왼쪽과 오른쪽을 선형 탐색 하면서 스코어를 판단한다.
->Time limit이 발생한다.

2)multiset을 이용한 개수 탐색 시간 줄이기
-> 한계점: 😣 multiset.erase(1)하면 1이란 요소가 다 지워진다!! 이걸 모르고 있었다.

3)map을 이용. value는 key의 개수.
    -> map<int, int> left, right;
    -> right에 모든 배열들을 넣는다.

4)prefixSum(Discussion 참조)
    -> sum[i+1] = A[0] + ... + A[i]라는 점을 이용
    -> score = i - sum[i] + sum[N]-sum[i].

회고:
실수한 점이 좀 많다.
division_score보다 now_div_sc가 크면 division_score를 갱신해줘야 한다.

*/
    class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {

    map<int, int> left, right;//vector로 하면 지우기에 시간이 너무 오래걸린다.
    for (int i = 0; i < nums.size(); i++) {
        if (right.find(nums[i]) == right.end())
            right.insert(make_pair(nums[i], 1));
        else
            right[nums[i]]++;
    }
    vector<int> ret;
    int division_score = right.find(1) == right.end() ? 0 : right[1];

    for (int i = 0; i <= nums.size(); i++) {
        int left_sc = left.find(0) == left.end() ? 0 : left[0];
        int right_sc = right.find(1) == right.end() ? 0 : right[1];
        int now_div_sc = left_sc + right_sc;

        if (division_score < now_div_sc) {
            ret.clear();
            ret.push_back(i);
            division_score = now_div_sc; // 이거 안해줬네
        }
        else if (division_score == now_div_sc)
            ret.push_back(i);

        if (i == nums.size())
            break;


        right[nums[i]]--;
        //erase는 하나만 지우는게 아니라 다 지워버림.. 이걸 몰랐네 시발...
        left[nums[i]]++;
    }
    return ret;

}
};


//4.prefixSum 풀이 방법
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& A) {
        int N = A.size(), mx = 0;
        vector<int> sum(N + 1, 0), ans;
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];
        for (int i = 0; i <= N; ++i) {
            int score = i - sum[i] + sum[N] - sum[i];
            if (score > mx) {
                ans = {i};
                mx = score;
            } else if (score == mx) ans.push_back(i);
        }
        return ans;
    }
};


2156. Find Substring With Given Hash Value
/*
Fail
문제:
k라는 길이를 가진 문자열 s가 주어지고, 정수 p와 m이 주어지는데,
hash(s, p, m) = (val(s[0]) * p0 + val(s[1]) * p1 + ... + val(s[k-1]) * pk-1) mod m.
이런 식이래
val(s[i])는 val('a') = 1이고, val('z') = 26임. 즉, 알파벳에서 s[i]의 인덱스.

s와 p, m, k, 그리고 hashValue가 주어지면, 
hash(sub, power, modulo) == hashValue를 만족하는
k길이의 s의 첫 부분문자열을 리턴해라
답은 항상 반드시 존재하니까 걱정 ㄴ

해결방법:
1) 브루트 포스 + hash
-> 시간초과남.
-> 이유는 ? O(s.length * s.length) = 대략 1초 넘어감.

2) 슬라이딩 윈도우 + hash(rolling hash)
-> 선형 탐색이고, 왼쪽 인덱스가 사라지면, 오른쪽 인덱스 추가해주면됨.
-> 그러나 여기서 문제가 발생한다. 
-> hash공식에 의하면 오른쪽 요소를 추가하고 왼쪽 요소를 빼는 과정에서 전체를 p로 나누게 된다.
-> 컴퓨터 연산에서 왠만하면 나누기는 피해야한다. 그래서 end에서부터 start까지, 반대로 순회를 한다.
-> 이걸 라빈카프 알고리즘 이라고 한단다.

회고:
mod 반드시 주의하고,
굳이 binPow 함수를 구현할 필요는 없다.

*/



string subStrHash(string s, int power, int mod, int k, int hashValue) {
    long long hash = 0, res = 0, power_k = 1;
    auto val = [&](int i){ return s[i] - '`'; };
    for (int i = s.size() - 1; i >= 0; --i) {
        hash = (hash * power + val(i)) % mod;
        if (i < s.size() - k)
            hash = (mod + hash - power_k * val(i + k) % mod) % mod;
        else
            power_k = power_k * power % mod;
        if (hash == hashValue)
            res = i;        
    }
    return s.substr(res, k);
}

/*
4번은 아얘 접근조차 하지 못하였음. 3번에서 45분 소요.
*/
