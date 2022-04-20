1차
Success
Time: 10분 12초
Details 
Runtime: 40 ms, faster than 13.33% of C++ online submissions for Populating Next Right Pointers in Each Node.
Memory Usage: 17.1 MB, less than 51.20% of C++ online submissions for Populating Next Right Pointers in Each Node.
회고: 
Follow-up이 있는지 몰랐다. Follow-up은 O(1)의 추가 공간만 사용하라는 것이었음.
한번 다시 풀어보기
1) level-order순으로 탐색. extra space O(n).
  
  /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

  //Extra Space O(n)
class Solution {
public:
    /*
    문제:
    "완전 이진 트리"가 주어진다.
    오른쪽 다음 노드를 가리키도록 각 다음 포인터를 채웁니다. 다음 오른쪽 노드가 없으면 다음 포인터를 NULL로 설정해야 합니다.
    처음에는 모든 다음 포인터가 NULL로 설정됩니다.
    
    제한:
    
    Follow-up:
    오로지 상수 추가 공간만 사용할것.
    
    해결방법:
    level-order순위 문제와 비슷하다.
    
    */
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        Node* ret = root;
        queue<Node*> q;
        q.push(ret);
        while(!q.empty()){
            int qSize = q.size();
            Node* now = q.front(); q.pop();
            if(now->left != NULL)
                q.push(now->left);
            if(now->right != NULL)
                q.push(now->right);
            Node* next;
            for(int i=0; i<qSize-1; i++){
                next = q.front(); q.pop();
                if(next->left != NULL)
                    q.push(next->left);
                if(next->right != NULL)
                    q.push(next->right);
                now->next = next;
                now = next;
            }
        }
        return ret;
        
    }
};

//Follow-up에 맞는 코드
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* current = root;
        while(current) {
            // this will always be the first node of any level
            Node* level1stNode = current;
            // this runs until we iterate over all the nodes of any level
            while(current) {
                // this links the child nodes (L child -> next = R child) of the same parent node
                if(current->left) {
                    current->left->next = current->right;
                }
                // this checks whether there are more nodes towards right at the same level
                if(current->right && current->next) {
                    current->right->next = current->next->left;
                }
                // move on the next node of the current level (L -> R)
                current = current->next;
            }
            // move onto the first node of the next level
            current = level1stNode->left;
        }
        return root;
    }
};
