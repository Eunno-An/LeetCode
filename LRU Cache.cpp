1차 22-05-27 Fail
splice의 개념을 알았다면 쉽게 풀 수 있었을 것.
list의 사용방법 또한 숙지하지 않아 못푼 문제 같다.
class LRUCache {
public:
  /*
  문제: LRU 구현
  
  제한:
  
  해결방법:
  unordered_map을 통해 평균 수행 시간 (put, get)을 O(1)으로 해야한다.
  put와 get의 세부 구현에서 우선순위를 결정해야하는 문제가 있는데 이건 list로 해야한다.
  */
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator m;
    int size;
    
    LRUCache(int capacity) {
        size = capacity;    
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        l.splice(l.begin(), l, m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            l.splice(l.begin(), l, m[key]); // l의 앞 위치에다가, l에 존재하는 m[key]가 가르키는 데이터 값을 복사해서 넣는다. 
            m[key]->second = value;
            return;
        }
        if(l.size() == size){
            auto d_key = l.back().first;
            l.pop_back();
            m.erase(d_key);
        }
        l.push_front({key_value}); // 최근에 사용된건 앞에다가 넣는다.
        m[key]=l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
