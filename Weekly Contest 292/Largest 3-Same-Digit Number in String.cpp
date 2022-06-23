class Solution {
public:
    string largestGoodInteger(string num) {
        string goods[10]={"000", "111", "222", "333", "444", "555", "666", "777", "888", "999"};
        for(int i=9; i>=0; i--)
            if(num.find(goods[i]) != string::npos)
                return goods[i];
        return "";
    }
};

//Discussion Good Code
string largestGoodInteger(string num) {
    char res = 0;
    for(int i = 2; i < num.size(); ++i)
        if (num[i] == num[i - 1] && num[i] == num[i - 2])
            res = max(res, num[i]);
    return res == 0 ? "" : string(3, res);
}
