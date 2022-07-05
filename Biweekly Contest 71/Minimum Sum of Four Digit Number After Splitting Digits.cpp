class Solution {
public:
    int minimumSum(int num) {
        string num_s = to_string(num);
        
        //cout << num_s << endl;
        sort(num_s.begin(), num_s.end());
        //cout << num_s << endl;
        int ret = 100000;
        do{
            //string front = "", end="";
            for(int i = 1; i < num_s.size(); i++){   
                //cout << num_s.substr(0, i) << endl;
                int front_int = stoi(num_s.substr(0, i));
                int end_int = stoi(num_s.substr(i, num_s.size()-i));
                //cout << front_int << ' ' << end_int << endl;
                if(ret > (front_int + end_int))
                    ret = (front_int + end_int);
            }
            
        }while(next_permutation(num_s.begin(), num_s.end()));
        return ret;
    }
};
