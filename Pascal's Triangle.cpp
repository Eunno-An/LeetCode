1차 22-04-18
Success
Time: 6분 30초
Details 
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
Memory Usage: 6.6 MB, less than 33.33% of C++ online submissions for Pascal's Triangle.
회고:
단순한 파스칼 삼각형 만들기 이다.
좋은 코드 아래에 첨부함. 로직은 같음.
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows, vector<int>());
        ret[0].push_back(1);
        if(numRows == 1)
            return ret;
        ret[1].push_back(1);
        ret[1].push_back(1);
        if(numRows == 2)
            return ret;
        for(int i=2; i<numRows; i++){
            ret[i].push_back(1);
            for(int j=1; j<i; j++){
                ret[i].push_back(ret[i-1][j] + ret[i-1][j-1]);
            }
            ret[i].push_back(1);
        }
        return ret;
    }
};
// Please, UpVote, if you like it :-) Thank you
vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ret;
	for (int i = 0; i < numRows; i++) {
		vector<int> row(i + 1, 1);
		for (int j = 1; j < i; j++) {
			row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
		}
		ret.push_back(row);
	}
	return ret;
}
