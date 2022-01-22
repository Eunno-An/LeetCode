
//13분 40초
//2차 복습: 7분?대에 끊은듯.
//단순 구현 문제. 아래에 다른 해법들도 했으니 잘 봐둘것
/*
    문제:
    2-9사이 숫자가 써져있는 문자열이 주어지면, 
    숫자들이 제공할 수 있는 모든 문자 조합을 리턴해라.
    순서는 상관없다.
    
    해결방법:
    
    */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        map<char, string> number;
        number['2']="abc";
        number['3']="def";
        number['4']="ghi";
        number['5']="jkl";
        number['6']="mno";
        number['7']="pqrs";
        number['8']="tuv";
        number['9']="wxyz";
        vector<string> ret;
        
        for(int i=0; i<digits.size(); i++){
            string str_i = number[digits[i]];
            vector<string> temp;
            
            if(i == 0){
                
                for(int j=0; j<str_i.size(); j++){
                    temp.push_back(string(1, str_i[j]));
                }
                ret = temp;
                continue;
            }
            for(int j=0; j<ret.size(); j++){
                for(int k=0; k<str_i.size(); k++){
                    temp.push_back(ret[j] + string(1, str_i[k]));
                }
            }
            ret = temp;
            
        }
        return ret;
    }
};
//단순 반복문. 내가 짠 코드와 로직은 같음. 그런데 엄청나게 간결하게 짠 것을 볼 수 있음.
vector<string> letterCombinations(string digits) {
	if(digits == "") return {};
	vector<string> mappings{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans{""};
	for(auto digit : digits){
		vector<string> extendCombination;
		for(auto& currentCombination : ans)
			for(auto newChar : mappings[digit - '2'])
				extendCombination.push_back(currentCombination + newChar);                            
		ans = move(extendCombination); // same as ans = extendCombination, just avoids copying each value. You Can also use swap(ans,extendCombination)
	}
	return ans;
}

//재귀. 여기서 볼 포인트가 많다.
//1. move()함수. 이건 있어도 되고 없어도 되지만, 메모리 차이가 심하게 난다. move는 rvalue를 실제로 옮기는 것. issue에 남겨놓겠음.
//2. auto c : mappings[digits[i]-'2'] 이 부분도 좋은 코드. 숫자는 어짜피 2부터 9까지 밖에 없으니 저런 식으로 해도 됨.
class Solution {
public:
    vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;
    vector<string> letterCombinations(string digits) {
        if(digits == "")return ans;
        helper(digits, 0, "");
        return ans;
    }
    
    //recursive felper function
    void helper(string &digits, int i, string combi){
        if(i == size(digits))//base condition - push when we have recursed for all digits
            ans.push_back(move(combi));
        else
            for(auto c : mappings[digits[i]-'2'])
                helper(digits, i + 1, combi + c);
    }
};
//이건 백트랙킹 + 재귀임. 이런 식으로도 해결할 수 있음.
vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;
vector<string> letterCombinations(string digits) {
	if(digits == "") return ans;        
	string combination = "";
	helper(digits, 0, combination);
	return ans; 
}
//                  passing by reference ⬇️ so copies are not made at each function call
void helper(string &digits, int i, string &combi){
	if(i == size(digits)) {
		ans.push_back(combi);    
		return;
	}
	for(auto c : mappings[digits[i] - '2']){
		combi.push_back(c);            // add a character from mappings for current position,
		helper(digits, i + 1, combi);  // and recurse for next positions
		combi.pop_back();              // backtrack
	}   
}


//2차풀이
class Solution {
public:
    /*
    문제:
    2-9사이 숫자가 써져있는 문자열이 주어지면, 
    숫자들이 제공할 수 있는 모든 문자 조합을 리턴해라.
    순서는 상관없다.
    
    해결방법:
    
    */
    vector<string> ret;
    map<char, string> phoneNumber;
    void help(string digits, int idx, string now){
        if(idx == digits.size()){
            ret.push_back(now);
            return;
        }
        string phoneStr = phoneNumber[digits[idx]];
        for(int i=0; i<phoneStr.size(); i++){//실수: i=idx부터 시작하는게 아님!
            help(digits, idx+1, now + phoneStr[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return ret;
        phoneNumber['2']="abc";
        phoneNumber['3']="def";
        phoneNumber['4']="ghi";
        phoneNumber['5']="jkl";
        phoneNumber['6']="mno";
        phoneNumber['7']="pqrs";
        phoneNumber['8']="tuv";
        phoneNumber['9']="wxyz";
        help(digits, 0, "");
        return ret;
    }
};
