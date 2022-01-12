/*
문제: 
nums라는 정수 배열과, target이 주어지면, 두개의 정수를 더해서 target이 되는 정수들의 인덱스를 리턴해라.

Follow up:
O(n^2)시간보다 적은 걸로 해결할 수 있는가?

해결 아이디어:
unordered_map<int, int>를 이용한 find를 O(1)에 수행.
nums를 선형 탐색하면서, target-nums[i]가 bucket에 있나 확인함.
매 탐색마다, bucket[nums[i]] = i라고 저장함.
만약 있다면 i와 bucket[target-nums[i]]를 리턴.
unordered_map<int, int>.find()와 map<int, int>.find()의 수행시간은 다름.
전자는 O(1), 최악 O(n), 후자는 O(logn)임.

*/
vector<int> twoSum(vector<int>& nums, int target) {
    //Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        int numberToFind = target - nums[i];

        if (hash.find(numberToFind) != hash.end()) {
            result.push_back(hash[numberToFind]);
            result.push_back(i);
            return result;
        }
        //numbers was not found. Put it in the map.
        hash[nums[i]] = i;
    }

    return result;
}
