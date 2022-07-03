String두개를 사용하여 비트셋 구현하기
class Bitset {
public:
    string s;
    string reverseS;
    int oneCount = 0;
    int zeroCount = 0;
    Bitset(int size) {
        s = string(size, '0');
        reverseS = string(size, '1');
        zeroCount = size;
    }
    
    void fix(int idx) {
        if(s[idx] == '1')
            return;
        s[idx] = '1';
        reverseS[idx] = '0';
        oneCount++;
        zeroCount--;
    }
    
    void unfix(int idx) {
        if(s[idx] == '0')
            return;
        s[idx] = '0';
        reverseS[idx] = '1';
        zeroCount++;
        oneCount--;
    }
    
    void flip() {
        string temp = reverseS;
        reverseS = s;
        s = temp;
        int tempCount = zeroCount;
        zeroCount = oneCount;
        oneCount = tempCount;
    }
    
    bool all() {
        return zeroCount == 0 ? true : false;
    }
    
    bool one() {
        return oneCount != 0 ? true : false;
    }
    
    int count() {
        return oneCount;
    }
    
    string toString() {
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
