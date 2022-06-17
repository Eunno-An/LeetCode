Hard문제 침착하게 잘 풀어서 뿌듯하다!
class Solution {
public:
    /*
    문제:
    s와 sub라는 두개의 문자열이 주어진다.
mappings[i] = [old_i, new_i]라는 2차원 캐릭터 배열도 주어진다.
sub의 old_i 캐릭터의 수를 new_i로 바꿀 수 있다는 말이다.
sub의 각각 캐릭터는 한번을 초과하여 대체될 수 없다.
s의 substring으로 sub을 mappings에 따라 0번 아니면 한번 replacing 하여 만들 수 있는지 리턴하라.

    제한:
    sub의 길이와 s의 길이는 각각 1 이상 5000이하
    mappings의 길이는 0 이상 1000이하.
    old_i != new_i
    
    해결방법:
    1) 재귀가 딱 떠오른다. 
    -> 얘를 변환 할지? 안할지?를 각각 재귀로 만들어서 만들어진 문자열이 s의 부분 문자열인지 확인하는 문제이다.
    -> 근데 mappings가 0이상 1000이하인데, 1000번을 각각 할까 안할까로 비교하면 재귀는 최소 2^1000번 만져야 한다.
    -> 근데 이러면 너무 많이 중복이 존재할 것이다.
    
    2) 그냥 s와 sub를 2중 포문으로 비교한다.
    -> 만약 첫 문자가 같거나, 아니면 mappings로 변환할 수 있거나 해서 걸리면? 그때 보기 시작한다.
    */
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char, unordered_set<char>> bucket;
        
        //mappings[i][0] = "sub"에 있는 문자
        //mappings[i][1] = "sub"에 있는 문자를 이걸로 바꿀 수 있다는 것.
        
        for(int i=0; i<mappings.size(); i++){ 
            char old = mappings[i][0];
            char newOne = mappings[i][1];

            if(bucket.find(old) != bucket.end())
                bucket[old].insert(newOne);
            else{
                unordered_set<char> temp = {newOne};
                bucket.insert({old, temp});
            }
        }
        for(int i=0; i<s.size(); i++){
            if(s[i] == sub[0] or (bucket.find(sub[0]) != bucket.end() and bucket[sub[0]].find(s[i]) != bucket[sub[0]].end())){//s[i]가 sub[0]와 같거나, sub[0]의 newOne인가?
                int sub_idx = 1;
                int s_idx = i+1;
                char char_s, char_sub;
                while(s_idx < s.size() && sub_idx < sub.size()){
                    char_s = s[s_idx];
                    char_sub = sub[sub_idx];
                    if(char_sub == char_s or (bucket.find(char_sub) != bucket.end() and bucket[char_sub].find(char_s) != bucket[char_sub].end())){//s[i]가 sub[idx]와 같거나, s[i]가 sub[idx]의 newOnew인가
                        s_idx++;
                        sub_idx++;
                    }
                    else
                        break;
                }
                cout << sub_idx << endl;
                if(sub_idx == sub.size())
                    return true;
            }
        }
        return false;
    }
};
