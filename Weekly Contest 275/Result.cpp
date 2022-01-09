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

2135. Count Words Obtained After Adding a Letter
못품. 실수한 부분 체크하기. 이것도 잘못품 어떤 부분을 놓쳤을까?
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int ret = 0;
        set<string> dict;
        for (int i = 0; i < targetWords.size(); i++) {
            sort(targetWords[i].begin(), targetWords[i].end());
            dict.insert(targetWords[i]);
        }
        for (int i = 0; i < startWords.size(); i++) {
            string temp = startWords[i];
            for (char j = 'a'; j <= 'z'; j++) {
                if (temp.find(j) == string::npos) {
                    string backUp = temp;
                    temp.push_back(j);
                    sort(temp.begin(), temp.end());
                    if (dict.find(temp) != dict.end()) {//dict에 존재할 때
                        ret++;
                        dict.erase(temp);//이것도 지워야함.
                    }
                    temp = backUp;
                }
            }
        }


        return ret;

    }
};
