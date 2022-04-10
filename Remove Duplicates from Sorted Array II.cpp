1차 Fail 22-03-28
2차 Fail 22-04-10
회고
풀이에 다시 한번 놀람.. ㅋ
class Solution {
public:
    /*
    문제:
    오름차순으로 정렬되어 있는 nums가 주어진다.
    in-place알고리즘으로 중복을 제거해라.
    각각의 유니크 요소는 최대 두번 나타난다!! 그니까 중복은 두번까지는 허용한다.
    
    중복을 제거한 후에 남아있는 k개의 요소 뒤에
    어떤 요소가 들어가든지 상관없다.
    이때 k를 리턴해라!
    
    회고:
    접근도 못했다.
    투포인터라는 개념은 이해하고있었지만...
    
    Discussion에서 엄청난 코드를 발견했다.
    k개의 중복을 허용하면서 in-place로 O(n)에 중복을 제거하는 알고리즘.
    
    */
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int n : nums)
            if(i < 2 || n > nums[i-2])
                nums[i++]=n;
        return i;
    }
    int removeDuplicates_allow_k_dup(vector<int>& nums, int k) {
        int i = 0;
        for (int n : nums)
            if (i < k || n > nums[i-k])
                nums[i++] = n;
        return i;
    }
};
