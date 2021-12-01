/*
https://leetcode.com/problems/two-sum/
처음엔 단순히 O(n^2)으로 끝낼 수 있겠다 싶었지만,
문제의 특성상 답이 반드시 인덱스 페어 한개밖에 없어서 시간을 O(n)으로 줄일 수 있었음.
여기서 의문이 든건, map이든 unordered_map이든 반드시 find를 할 때는 O(logn)이 걸릴 수 있겠다고 생각했으나,
map과 unordered_map은 구현 자체가 다름. map은 balanced_binary_tree이고 unordered_map은 hash table임!
따라서 hash.find()는 평균 O(1)이 걸리게 되고, 
전체 수행 시간은 O(n)이 걸리게 됨. 
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
