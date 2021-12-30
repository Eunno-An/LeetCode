//find의 구현에 대해서 물어보는 문제.
//직접 구현하거나, 그렇지 않고 find를 써서 할 수 있다.
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

for (int i = 0; ; i++) {
		for (int j = 0; ; j++) {
			if (j == needle.length()) return i;
			if (i + j == haystack.length()) return -1;
			if (needle[j] != haystack[i+j]) break;
		}
	}


public int strStr(String haystack, String needle) {
        // empty needle appears everywhere, first appears at 0 index
        if (needle.length() == 0)
            return 0;
        if (haystack.length() == 0)
            return -1;
        
        
        for (int i = 0; i < haystack.length(); i++) {
            // no enough places for needle after i
            if (i + needle.length() > haystack.length()) break;
            
            for (int j = 0; j < needle.length(); j++) {
                if (haystack.charAt(i+j) != needle.charAt(j))
                    break;
                if (j == needle.length()-1)
                    return i;
            }
        }
        
        return -1;
    }
