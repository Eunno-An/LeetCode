1번문제 5분 44초
2148. Count Elements With Strictly Smaller and Greater Elements
/*
문제: 
정수 배열 nums가 주어지면, strictly smaller과 strictly greater element들의 개수를 구하여라.

해결방법:
선형 탐색으로 최저와 최대를 찾은 다음
nums를 다시 한 번 순회하면서 최저 < nums[i] < 최대인 i의 개수를 세면 된다.
*/
class Solution {
public:
    int countElements(vector<int>& nums) {
        if(nums.size() <= 2)
            return 0;
        
        sort(nums.begin(), nums.end());
        int minimum = nums[0];
        int maximum = nums.back();
        int ret = 0;
        for(int i=1; i<nums.size()-1; i++)
            if(nums[i] > minimum && nums[i] < maximum)
                ret++;
        return ret;
    }
};

2번문제 10분
2149. Rearrange Array Elements by Sign
/*
문제:
양수와 음수의 개수가 똑같은, 짝수길이의 정수배열 nums가 주어진다.
이걸 재배열해서 아래 조건에 따르게 만들어라.
1. 모든 연속적인 정수쌍은 반대부호를 갖고 있다.
2. 같은 부호를 가진 모든 정수의 경우, 숫자에 있는 순서는 보존된다.(in-place)
3. 재배열된 배열은 양의 정수로 시작합니다.

해결방법:
양수와 음수를 따로 따로 각각의 벡터에 넣은 다음에 그냥 꺼내면 되지 않나 하나씩?
회고:
난이도는 쉬웠으나,
만약 Follow-up이 선형 탐색을 단 한번만 하는 문제였다면?
그렇다면 아래와 같이 풀어야 한다. 음수의 인덱스와 양수의 인덱스를 각각 따로 두어서 순회하는 방식. 2배 더 효율적이다.
*/
//내 코드
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0)
                positive.push_back(nums[i]);
            else
                negative.push_back(nums[i]);
        }
        vector<int> ret;
        for(int i=0; i<positive.size(); i++){
            ret.push_back(positive[i]);
            ret.push_back(negative[i]);
        }
        return ret;
    }
};
//가져온 코드
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int start = 0, pos = 0, neg = 0;
        int n = nums.size();
        bool nextpos = true;
        vector<int> ans(n);
        while(start < n) {
            if(nextpos) {
                if(nums[pos] > 0) {
                    ans[start++] = nums[pos++];
                    nextpos ^= true;
                } else {
                    pos++;
                }
            } else {
                if(nums[neg] < 0) {
                    ans[start++] = nums[neg++];
                    nextpos ^= true;
                } else {
                    neg++;
                }
            }
        }
        
        return ans;
    }
};
3번문제 10분컷
2150. Find All Lonely Numbers in the Array
/*
문제:
정수배열 nums가 주어지면, 
외로운 수 x들을 찾아라.
외로운 수란 x가 단 한번만 등장하고, x+1, x-1 또한 없는 것이다.

해결방법:

유의할점:
nums의 길이는 십만
nums[i]는 0부터 백만까지.

회고:
nums에 x라는 숫자가 세번 등장하면? 결과상 이 숫자는 등장하면 안된다.
del_eternal이 필요한 이유이다.
예로들어, 처음에 x가 등장했고, x가 또 등장하면 지워야 한다. 만약 한번 더 x가 나타나면? 추가하면 안되므로 제외 대상에서 추가한다.
*/
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_set<int> hash_nums;//nums[i-1]과 nums[i]가 있나 없나를 보기 위한 hash
        unordered_set<int> hash;//nums[i]가 있나 없나 보기 위한 hash
        unordered_set<int> del_eternal; //nums[i]를 아얘 지우기 위한 애
        for(int i=0; i<nums.size(); i++)//일단 nums에 대한 것을 만들어 놓는다.
            hash_nums.insert(nums[i]);
        vector<int> ret;
        for(int i=0; i<nums.size(); i++){
            //일단 없는 수는 집어 넣고,
            if((hash.find(nums[i]) == hash.end()) && (hash_nums.find(nums[i]+1) == hash_nums.end()) && (hash_nums.find(nums[i]-1) == hash_nums.end()) && (del_eternal.find(nums[i]) == del_eternal.end()))
                hash.insert(nums[i]);
            //만약 중간에 그 수가 발견되면? 그 수를 지워버린다.
            else if(hash.find(nums[i]) != hash.end()){
                hash.erase(nums[i]);
                del_eternal.insert(nums[i]);
            }
                
        }
        for(auto it : hash)
            ret.push_back(it);
        return ret;
    }
};
4번문제 
/*
Fail
문제:
사람에는 두가지 타입이 있다.
좋은 사람: 항상 진실만 말한다
나쁜 사람: 거짓말을 할 수도 있고, 진실을 말 할 수도 있다.
"statements"라는 2차원 n*n배열이 주어진다. n명의 사람들이 각각 서로에 대해 진술한 내용이다.
statements[i][j] 
if 0: i 가 j한테 bad person이라고 한 것.
else if 1: i가 j한테 good person이라고 한 것
else if 2: 어떠한 발언도 하지 않음.

또한 어떠한 사람도 자기 자신한테는 진술을 하지 않는다.
즉 statements[i][i] = 2 for all 0 <= i < n

이때 GOOD이 될 수 있는 "최대 사람 수"를 구하여라.

예시:
212
122
202
해결방법:
BackTracking + Bitmasking..

회고:
문제를 풀면서 사람 하나하나를 가정하지 말고,
일단 처음에 들어가기 전에 모든 사람들을 가정하고 들어가자!
그럼 여기서 문제가 발생한다.
모든 사람들을 "111", "000" 이런 식으로 표현해야 하는데.. 
이때 비트마스킹 개념이 들어간다.
.
.
.
코드는 잘 짰다고 생각했으나.. 너무 복잡했다. 
복잡하게 짠다는 것은 실수하기 쉬운 부분이 있다는 것이고
하지만 의미는 있었다. 재귀함수를 그래도 함수를 잘 살려서 짰다고 생각한다. Hard문제였어도 시도는 좋았다고 생각한다.

근데 왜 Bad person은 그냥 skip할까?(194번째 줄).
확실하지 않으니까! 얘는 그냥 거짓말을 했을 수도 있고, 안했을 수도 있잖아
그리고 우리는 애초에 1인 애들의 개수를 세는거고, 0을 따져 볼 필요가 없지.
그냥 얘는 0인거야. 우리가 세지 않아도 되는 애.

*/
//비트마스킹 + BackTracking
int maximumGood(vector<vector<int>>& A) {
    int n = A.size(), ans = 0;
    for (int num = 1 << n; num < 1 << (n + 1); num++) {//n이 3이면 1000부터 15까지(01111) 본다.
        string permutation = bitset<15>(num).to_string().substr(15 - n);//permutation = 000 000 000 001 000 . 즉 000부터 111까지 본다는 뜻이다.. 대박!
        if (check(permutation, A, n)) {
            int c = count(begin(permutation), end(permutation), '1'); // permutation에서 1의 수를 센다.
            ans = max(ans, c);
        }
    }
    return ans;
}
bool check(string& perm, vector<vector<int>>& A, int n) {
    for (int i = 0; i < n; i++) {
        if (perm[i] == '0') continue;//Bad Person이라면 skip(?). 왜 Bad Person이면 skip할까?
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 2) continue;//난 말한적 없소.
            if ((A[i][j] == 1 && perm[j] == '0') || //i가 j한테 너 좋은 사람이야 라고 말하고, j는 사실 안좋은 사람이었으면? 거짓
                (A[i][j] == 0 && perm[j] == '1')) //i가 j한테 너 안좋은 사람이야 라고 말하고, j는 사실 좋은 사람이었으면? 거짓.
                return false;
        }
    }
    return true;
}
//틀린 코드
class Solution {
public:
    //person: 몇번째 사람인지
    //type: person이 진실을 말했는지 가짜를 말했는지, 0이면 거짓, 1이면 진실
    //nowGood: 현재 좋다고 가정하는 사람의 명수
    //persontypes: 0번쨰 사람부터 n-1번째 사람까지의 타입들. 초기에는 0:bad, 1: GOOD, 2:nothing. 
    //종료조건:
    //1)persontypes이 모순되는 내용이 있으면 바로 리턴하기,
    //2)만약 person이 statements의 size와 같다면? 만약 nowGood이 maxValue보다 크다면 값을 갱신하기
    int ret = 0;
    void help(vector<vector<int>> & statements, int person, bool type, int nowGood, vector<int> persontypes){
        if(person == statements.size()){
            if(nowGood > ret)
                nowGood = ret;
            return;
        }
        
        for(int i=0; i<statements.size(); i++){
            if(i == person)continue;
            if(statements[person][i] == 0){//person이 i사람한테 bad라고 함.
                if(persontypes[person] == 0){//만약 person이 good이라면, 언제나 사실만을 말함.          
                    if(persontypes[i] == 1)
                        return;
                    persontypes[i] = 0;//i는 항상 bad가 됨.
                    
                    
                }
                else if(type == 0){//만약 person이 bad이고, 거짓말을 했을 떄
                    if(persontypes[i] == 0)
                        return;
                    persontypes[i] = 1;
                }else if(type == 1){//만약 badperson이고, 진실을 말했을 때
                    if(persontypes[i] == 1)
                        return;
                    persontypes[i] = 0;
                }
                
                    
                
            }else if(statements[person][i] == 1){//person이 i한테 good이라고 함.
                if(persontypes[person] == 0){
                    if(persontypes[i] ==0 )
                        return;
                    persontypes[i] = 1;
                }
                else if(type == 0){
                    if(persontypes[i] == 1)
                        return;
                    persontypes[i] = 0;
                }
                else if(type == 1){
                    if(persontypes[i] == 0)
                        return ;
                    persontypes[i] = 1;
                }
            }
        }
        if(persontypes[person+1] == 1)
            help(statements, person+1, 1, nowGood+1, persontypes);
        else if(persontypes[person+1] == 0){
            help(statements, person+1, 0, nowGood, persontypes);
            help(statements, person+1, 1, nowGood, persontypes);
        }
        else{//person+1이 아직 정해지지 않았을 떄
            persontypes[person+1]=1;
            help(statements, person+1, 1, nowGood+1, persontypes);//좋은 사람이고, 진실을 말했을 때
            persontypes[person+1]=0;
            help(statements, person+1, 0, nowGood, persontypes);
            help(statements, person+1, 1, nowGood, persontypes);
        }
    }
    int maximumGood(vector<vector<int>>& statements) {
        vector<int> persontype(statements.size(), 0);
        persontype[0] = 1;
        help(statements, 0, 1, 1, persontype);
        persontype[0] = 0;
        help(statements, 0, 1, 0, persontype);//진실을 말했을 수도 있고
        help(statements, 0, 0, 0, persontype);//가짜를 말했을 수도 있고
        return ret;
    }
};
