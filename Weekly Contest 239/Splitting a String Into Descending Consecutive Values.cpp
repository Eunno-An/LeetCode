//long long은 자릿수가 19자리 까지 가능하다.
//long과 longlong의 차이는 32비트냐 64비트의 차이이다.
//int와 long은 32비트일 때는 서로 같다. 64비트일 때 차이가 있다.
//이 문제는 try-exception을 사용해서 좀 특이했음.

class Solution {
public:
    
bool solve(string& s, int i, int len, long prev, int splits = 0) {
	// If we reach the end of string and have made splits >= 2, return true
	if(i == size(s) && splits >= 2) return true;
	while(i + len <= size(s)) {
		
			auto cur = stoll(s.substr(i, len++));         // convert s[i] to s[i + len] into number
			if(prev != -1 && cur != prev - 1) continue;   // and check if it is equal to prev - 1 (ignore for first call)
			// if the above condition satisfies, just  recurse for the remaining indices
			if(solve(s, i + len - 1, 1, cur, splits + 1)) return true;    
		
	}
	return false;        
}
bool splitString(string s) {
	return solve(s, 0, 1, -1);
}
};
