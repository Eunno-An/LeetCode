class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        bool visit[101];
        memset(visit, false, sizeof(visit));
        
        queue<Node*> q;
        q.push(node);
        
        bool first = true;
        Node* ret = NULL;
        while(!q.empty()){
            Node* original = q.front(); q.pop();
            vector<Node*> original_neighbors = original->neighbors;
            
            if(visit[original->val])
                continue;
            visit[original->val] = true;
            
            Node* newOne = new Node(original->val);
            vector<Node*> newOne_neighbors;
            
            for(int i=0; i<original_neighbors.size(); i++){
                //원래 그래프의 인접한 요소
                Node* original_next = original_neighbors[i];

                //이웃 추가
                Node* newOne_next = new Node(original_next->val);
                newOne_neighbors.push_back(newOne_next);
                
                
                //만약 이게 한번 본 애면 컨티뉴.
                if(visit[original_next->val])
                    continue;
                
                
                
                q.push(original_next);
                
            }
            newOne->neighbors = newOne_neighbors;
            
            
            if(first == true){
                ret = newOne;
                first = false;
            }
        }
        cout << ret->val << ' ';
        return ret;
        
    }
};
