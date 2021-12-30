//fail
//투포인터에 약하다. 굉장히 쉬운 문젠데 구현도 못하고.. 정말 심각하다~~
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       
        //아래의 코드로 하면 Input이 0일 때 따로 처리를 해주어야 한다.
        //int s = 0;
        //int e = nums.size()-1;
        //while(s < e){
           //if(nums[s] == val){
               // nums[s] = nums[e];
              //  e--;
          //  }else
          //      s++;
       // }
        
        //그 대신 e를 nums.size()로 초기화 해주고, nums[s] = nums[e-1]로 하면 해결 된다.
        int s = 0;
        int e = nums.size();
        while(s < e){
            if(nums[s] == val){
                nums[s] = nums[e-1];
                e--;
            }else
                s++;
        }
        return s;
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
//remove(): http://www.cplusplus.com/reference/algorithm/remove/?kw=remove
//10 20 30 30 20 10 10 20 -> remove(vec.begin(), vec.end(), 20) -> 10 30 30 10 10 ? ? ?가 되고, remmove가 반환하는 값은 맨 왼쪽 물음표가 된다.
class Solution {
public:
    static int removeElement(std::vector<int>& nums, int val) {
        const auto it = std::remove(nums.begin(), nums.end(), val);
        return std::distance(nums.begin(), it);
    }
};
