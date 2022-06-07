1차 22-06-07
문제 해석을 잘못해서 애매한 Success임. 애초에 문제가 애매하게 써 있는 것 같기도?...
class MinStack {
public:
    /*
    문제:
    🎈잘못 해석: 스택에서 push, pop, top을 디자인 해라. 그리고 최소 요소를 얻는 것을 상수시간에 구현해라.
    🎈진짜 해석: 네개의 연산을 모두 다 상수시간에 수행해라.
    제한:
    
    해결방법:
    문제가 원하는 해결 방법대로 하면
    vector<pair<int, int>>로다가
    각각의 요소마다 i까지의 최솟값을 저장하는 것. 
    
    */
    vector< pair<int,int> > s;
	
    MinStack() { }
    
    void push(int val) {
        if(s.empty())
            s.push_back({val,val});
        else
            s.push_back({val,min(s.back().second,val)});    
    }
    
    void pop() { s.pop_back(); }
    
    int top() { return s.back().first; }
    
    int getMin() { return s.back().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
