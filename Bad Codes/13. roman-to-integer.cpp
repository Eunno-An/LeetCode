
class Solution {
public:
    const int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string rom[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int romanToInt(string s) {
        map<string, int> Rom;
    Rom.insert({ "M", 1000 });
    Rom.insert({ "CM", 900 });
    Rom.insert({ "D", 500 });
    Rom.insert({ "CD", 400 });
    Rom.insert({ "C", 100 });
    Rom.insert({ "XC", 90 });
    Rom.insert({ "L", 50 });
    Rom.insert({ "XL", 40 });
    Rom.insert({ "X", 10 });
    Rom.insert({ "IX", 9 });
    Rom.insert({ "V", 5 });
    Rom.insert({ "IV", 4 });
    Rom.insert({ "I", 1 });
    int ret = 0;
    for (int i = 0; i < s.size(); i++) {
        string one = string(1, s[i]);
        string two = "";
        if (i + 1 < s.size()) {
            two = s.substr(i, 2);
        }
        if (two != "" && Rom.find(two) != Rom.end()) {
            ret += Rom[two];
            i++;
        }
        else {
            ret += Rom[one];
        }
    }
    return ret;
    }
};
