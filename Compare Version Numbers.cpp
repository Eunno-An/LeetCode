1차 22-06-08
Time: 20분 15초
Success
Details 
Runtime: 4 ms, faster than 27.43% of C++ online submissions for Compare Version Numbers.
Memory Usage: 6.2 MB, less than 70.52% of C++ online submissions for Compare Version Numbers.
class Solution {
public:
    /*
    문제:
    version1, version2가 주어진다. 그들을 비교해라.
    if version1 < version2: return -1
    else if version1 > version2: return 1
    else return 0
    
    제한:
    
    해결방법:
    1) 내 풀이
    stringstream 이용한다. 그래서 각각의 숫자를 비교한다.
    2) Discussion 풀이(시간 최적화)
    ->Dry run 풀이. 그냥 진짜 미친놈인가 싶다. 최적화는 오지게 잘 해놨다.
    
    */
    int compareVersion(string version1, string version2) {
        
        stringstream ss1(version1);
        stringstream ss2(version2);
        string temp;
        vector<int> vec1, vec2;
        while(getline(ss1, temp, '.'))
            vec1.push_back(stoi(temp));
        
        while(getline(ss2, temp, '.'))
            vec2.push_back(stoi(temp));
        int i=0;
        for(; i<vec1.size() && i < vec2.size(); i++){
            int num1 = vec1[i];
            int num2 = vec2[i];
            if(num1 > num2)
                return 1;
            else if(num1 < num2)
                return -1;
        }
        if(vec1.size() == vec2.size())
            return 0;
        else{
            bool isVersion1Bigger = true;
            if(vec1.size() < vec2.size()){
                swap(vec1, vec2);
                isVersion1Bigger = false;
            }
            for(; i<vec1.size(); i++)
                if(vec1[i] != 0)
                    return isVersion1Bigger ? 1 : -1;
            return 0;
        }
        
                
        return -2;
        
    }
    
    //Discussion풀이
    int compareVersion(string s1, string s2) {
        int n1 = s1.length(); // extracting length of string s1
        int n2 = s2.length(); //extracting length of string s2
        
        int i = 0, j = 0; // variables(pointers) used for moving
        
        int number1 = 0, number2 = 0;  // numbers that generated between any two dots of the strings
        
        // start traversing from string 1 and string 2
        while(i < n1 || j < n2)
        {
            // generating number between dots for string s1
            while(i < n1 && s1[i] != '.')
            {
                number1 = number1 * 10 + (s1[i] - '0');
                i++;
            }
            
            // generating number between dots for string s2
            while(j < n2 && s2[j] != '.')
            {
                number2 = number2 * 10 + (s2[j] - '0');
                j++;
            }
            
            // if number1 is greater than number2, from here return 1
            if(number1 > number2)
            {
                return 1;
            }
            
             // if number1 is less than number2, from here return -1
            if(number1 < number2)
            {
                return -1;
            }
            
            // if equal then we have to proceed further
            // again give numbers to zero, as we again generate numbers b/w dots 
            number1 = 0, number2 = 0;
            
            // move both pointers
            i++;
            j++;
        }
        
        // after traversing whole string, if all the versions are equal, that means
        // strings are equal, so return 0
        return 0;
    }
};
