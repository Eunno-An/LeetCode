//10분만 더 생각해보기.
class Solution {
public:
    /*
    문제:
    
    문자열로 표시된 nums1과 nums2가 있다. 각각은 음이 아닌 정수이다.
    nums1와 nums2의 곱을 구하여라. 단 string으로 리턴해야 한다.
    
    해결 방법:
    1)
    stoi(num1) * stoi(num2)를 한다.
    근데 num1과 num2의 길이가 200을 넘어간다. 이건 존나 큰 수라는 얘기이다. unsigned long long int 로 해도 안된다.
    
    2)
    캐릭터를 저장하는 save배열에다가, 각각의 수들을 한 자리씩 곱하면 해당하는 인덱스에 넣는 방식이다.
    아직 upper가 남아있을 때에 대한 예외처리를 안해주었다. 이것도 생각해보기.
    */
    
    string multiply(string num1, string num2) {
        //뒷자리부터 본다.
        if(num1.length() > num2.length())
            return multiply(num2, num1);
        vector<char> save(num1.size() * num2.size() + 1, '\0');
        int upper = 0;
        for(int i=num1.size()-1; i>=0; i--){
            for(int j=num2.size()-1; j>=0; j--){
                int multi = (num1[i] - '0') * (num2[i] - '0') + upper;
                upper = multi / 10;
                save[num1.size()+num2.size()-2-i-j] = (multi%10) + '0';
            }
        }
        //upper가 남아있을 때에 대한 예외처리가 필요하다.
        
        for(int i=0; i<save.size(); i++)
            cout << save[i] << ' ';
        return "";
        
    }
};
