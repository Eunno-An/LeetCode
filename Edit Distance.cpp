1차 Fail. 2022-02-28
2차 Fail. 2022-04-06. 아이디어를 아얘 생각 못함.
//word1 = "ab", word2 = "ba"라고 생각하면
    //insert과정은 "ab"앞에다가 b를 넣었다고 생각하면? word1=  "bab", word2 = "ba". 그럼 일단 word1은 그대로 두고 word2의 다음 글자부터 보면 되겠지?
    //그리고 p1, p2 포인터 개념 상당히 중요하다. dp를 쓸때 사용할 수 있음과 동시에 insertion의 필요수를 바로 리턴할 수 있다.
    //base case를 생각해주는게 조금은 어렵다.
class Solution {
public:
    /*
    Fail
    
    문제:
    word1과 word2가 주어지는데, 
    word1을 word2로 바꾸기 위한 최소 작동 횟수를 리턴해라.
    단, character를 삽입, 삭제, 대체 세가지 동작만으로 제한된다.
    
    제한:
    word1의 길이와 word2는 500 이하이다.
    다 소문자로만 이루어져 있음!
    
    해결방법:
    우리는 하나의 단어만 edit할 필요가 있다. 왜냐? word1에 insert하는건 word2에 delete하는 거와 똑같으니까
    https://leetcode.com/problems/edit-distance/discuss/159295/Python-solutions-and-intuition
    DP 솔루션
    */
    int minDistance(string word1, string word2) {
        vector<vector<int>> mem(word1.size(), vector<int>(word2.size(), -1));
        return minDistance(0, 0, word1, word2, mem);
    }
    int minDistance(int p1, int p2, string& word1, string& word2, vector<vector<int>>& mem){
        //우리는 지금 word1을 수정중이라고 생각하면 됨.
        if(p1 == word1.size()) return word2.size()-p2;
        if(p2 == word2.size()) return word1.size()-p1;
        if(mem[p1][p2]>=0)return mem[p1][p2];
        
        if(word1[p1] == word2[p2]) return mem[p1][p2] = minDistance(p1+1, p2+1, word1, word2, mem);
        int ins = minDistance(p1, p2+1, word1, word2, mem) + 1;
        int del = minDistance(p1+1, p2, word1, word2, mem) + 1;
        int rpl = minDistance(p1+1, p2+1, word1, word2, mem) + 1;
        return mem[p1][p2] = min(ins, min(del, rpl)); 
    }
};
/*
horse, ros
ins = 5
del = 
*/
