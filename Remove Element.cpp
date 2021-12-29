//fail
//투포인터에 약하다. 굉장히 쉬운 문젠데 구현도 못하고.. 정말 심각하다~~
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int n = nums.size();
        while(i < n){
            if(nums[i] == val){
                nums[i] = nums[n-1];
                n--;
            }else{
                i++;
            }
        }
        return i;
    }
};
//erase와 remove를 같이 쓴 경우. 근데 이럴 필요가 없다.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
            nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};
//erase는 쓸 필요가 없다. 왜냐하면 val과 같은 요소들을 뒤로 옮기는건 아무래도 상관이 없기 때문이다.
//distance(): http://www.cplusplus.com/reference/iterator/distance/?kw=distance
//iterator간의 거리를 리턴한다!!
class Solution {
public:
    static int removeElement(std::vector<int>& nums, int val) {
        const auto it = std::remove(nums.begin(), nums.end(), val);
        return std::distance(nums.begin(), it);
    }
};
