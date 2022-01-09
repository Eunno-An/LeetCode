2133. Check if Every Row and Column Contains All Numbers
이건 스도쿠 문제와 매우 유사하게 접근함. 단 하나의 실수는 row(3),col(3)으로 선언해서..
더 좋은 방법 찾음. XOR의 성질과 sum 체크를 이용해서 푸는 방법이 있었음.
/*내 풀이*/
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<set<int>> row(n+1), col(n+1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(row[i].find(matrix[i][j]) != row[i].end())
                    return false;
                if(col[j].find(matrix[i][j]) != col[j].end())
                    return false;
                row[i].insert(matrix[i][j]);
                col[j].insert(matrix[i][j]);
            }
        }
        return true;
    }
};
/*XOR 풀이*/
class Solution {
public:
    bool checkValid(vector<vector<int>> &v) {
        int xor1 = 0, xor2 = 0,n = v.size();
        int colsum = 0, rowsum = 0,reqsum = (n*(n+1))/2;
        if(n<=1) {
            return true;
        }
        for(int i=0;i<n;i++) {
            xor1 = 0;    xor2 = 0;
            colsum = 0;  rowsum = 0;
            for(int j=0;j<n;j++) {
				// Checking xor column wise
                xor1 = xor1^(v[i][j]^(j+1));
                colsum = colsum + v[i][j];
				// Checking xor row wise
                xor2 = xor2^(v[j][i]^(j+1));
                rowsum = rowsum + v[j][i];
            }
			// Checking whether  rowsum and columnsum is equal to sum of all 
			// numbers from 1 to n
            if(xor1 || xor2 || rowsum != reqsum || colsum != reqsum) {
                return false;
            }
        }
        return true;
    }
};

2134. Minimum Swaps to Group All 1's Together II
못품. 이건 아얘 접근 자체를 잘못함.
실수한거: for문에서 nums.size()가 새로 갱신되는데도 
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        //직관:
        //써큘러 어레이 문제가 나오면, 어레이 그 자체를 뒤에 한 번 더 붙여서 써큘러 어레이라는 것을 없앨 수 있다.
        //이건 종만북에서도 문자열 ? 할 때 나온 팁이었음.
        
        //설명:
        //nums안에 있는 1의 개수를 센다. ones에 저장한다.
        //nums에다가 nums를 한 번 더 붙인다. 왜냐하면 이거 자체가 circular array처럼 보이게 하기 위해서.
        //ones의 사이즈와 같은 윈도우를 선형으로 움직여 가면서, 이 안에 최대 몇 개의 1이 들어갈 수 있는지 찾아간다. 이걸 maximum이라고 하자.
        //swap의 개수는 ones에서 maximum을 뺀 값이다.
        int ones=0;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++)
            if(nums[i] == 1)
                ones++;
        int ws=0, we=ones;
        //for(int i=0; i<nums.size(); i++) -> nums.size()는 계속 수정되는 값이므로 이렇게 하면 메모리 초과가 난다.
        for(int i=0; i<n; i++)
            nums.push_back(nums[i]);
        
        int maximum = -1;
        int count = 0;
        for(int i=ws; i<we; i++){
            if(nums[i] == 1)
                count++;
        }
        maximum = count;
        for(int i=we; i<nums.size(); i++){
            if(nums[i] == 1)
                count++;
            if(nums[i-we] == 1)
                count--;
            if(maximum < count)
                maximum = count;
        }
        return ones - maximum;
    }
};
2135. Count Words Obtained After Adding a Letter
못품. 실수한 부분 체크하기. 이것도 잘못품 어떤 부분을 놓쳤을까?
/*
핵심 아이디어:
targetWords[i]들을 정렬하고, startWords[i]에 어떤 lower case하나를 넣어서 정렬하는 것을 비교하면 될 것이다.

기본 아이디어:
targetWords에 있는 것들을 다 정렬하고, dict에다가 넣는다.
그 다음 startWords에 있는 단어들에다가
a부터 z까지 조건에 맞는 선에서 넣어본다.
그리고 정렬을 해서, dict에 혹시 그 단어가 있나 찾아본다.

실수한 부분: 
temp에다가 뭐 하나 추가하고 정렬한 뒤, 단순히 pop_back()을 해주면? 추가한게 빠지는게 아닐 수도 있다! 
그리고 startWords = [a, b] 이고 targetWords=[ac, bd, ca]면? 답은 3이다. 왜냐하면 a가 ac, ca를 다 만들 수 있기 때문이다.
따라서 map<string, int>로 개수를 세어 줘야 한다. 왜냐하면 우리는 정렬해서 쓰므로 ac와 ca가 같다.
따라서 ret에는 dict[temp]를 더해주어야 한다.

특이점:
시간이 참 딱 걸린다. 계산해보니까 상수시간들이 for문에 너무 중첩되어 있어서 겹친다.
Runtime: 1332 ms, faster than 57.14% of C++ online submissions for Count Words Obtained After Adding a Letter.
Memory Usage: 113.5 MB, less than 85.71% of C++ online submissions for Count Words Obtained After Adding a Letter.
Submit을 할 때마다 결과가 달라진다 ㅋㅋㅋ

다른 사람의 풀이:
1. Bitmask

*/
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int ret = 0;
        //multiset<string> dict;
        map<string, int> dict;
	    for (int i = 0; i < targetWords.size(); i++) {
            sort(targetWords[i].begin(), targetWords[i].end());
            if(dict.find(targetWords[i]) == dict.end())
                dict.insert({targetWords[i], 1});
            else
                dict[targetWords[i]]++;
        }
        for (int i = 0; i < startWords.size(); i++) {
            string temp = startWords[i];
            for (char j = 'a'; j <= 'z'; j++) {
                if (temp.find(j) == string::npos) {
                    string backUp = temp;
                    temp.push_back(j);
                    sort(temp.begin(), temp.end());
                    if (dict.find(temp) != dict.end()) {//dict에 존재할 때
                        //ret+;
                        ret+=dict[temp];
                        dict.erase(temp);//이것도 지워야함.
                    }
                    temp = backUp;
                }
            }
        }


        return ret;

    }
};
