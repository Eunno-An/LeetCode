1차 22-05-17 Fail.
회고:
가장 큰 실수는
[[2, 3], [1], [1]]
에서 
[[2,3],[],[]]를 리턴하는 것을 보면 알 수 있다.
visit[]을 통해 해결해주었기 떄문에 안됨.
1자체도 인접 리스트를 추가해주어야 한다.
아얘 코드 접근 자체를 잘못한게 맞다.
map을 통해서 기존에 이게 만든 copy인지도 체크해주어야 한다. 잘못 짠 코드는 따로 bad codes에 첨부하였음.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* , Node*> mp; // declaring map, to check whwther we have a copy of node or not and also to store copy
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) // if node is null, then simply return null
        {
            return NULL;
        }
        
        Node* first = new Node(node -> val, {}); // make a copy of first node
        mp[node] = first;
        
        queue<Node*> q; //For bfs, we create queue
        q.push(node); // push into queue
        
        while(q.empty() == false) // until q. empty == false
        {
            Node* curr = q.front(); // extract front node
            q.pop(); // pop that from queue
            
            for(auto adj: curr -> neighbors) // now travel in adjcant
            {
                if(mp.find(adj) == mp.end()) // if not present in map
                {
                    mp[adj] = new Node(adj -> val, {}); // then create copy
                    q.push(adj); // push nto the queue
                    
                }
                
                mp[curr] -> neighbors.push_back(mp[adj]); // in current node push adjcant node
            }
        }
        
        return mp[node];
    }
};
