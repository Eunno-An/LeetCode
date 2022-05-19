1차 22-05-19 Success
Time: 40분
회고:
1) bucket2의 역할을 떠올리기에서 애먹음
2) 그리고 마지막 while문에 bucket2[head]->random을 해줬어야 했는데 next를 수정해줘서 시간 잡아먹음.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    /*
    문제:
    
    길이 n의 링크드 리스트가 주어진다.
    이 링크드리스트의 각 요소는 val, next, 그리고 random이라는 포인터를 갖고 있다.
    random 포인터는 null일 수도 있고, 아닐 수도 있다.
    이 링크드 리스트의 deep copy의 head를 리턴해라.
    
    제한:
    
    해결방법:
    bucket : origin과 origin_random을 matching
    bucket2: origin과 new를 매칭.
    */

    map<Node*, Node*> bucket;//origin, origin_random
    map<Node*, Node*> bucket2;//origin, new
    Node* copyRandomList(Node* head) {
        //size가 1 인 것
        if(head == NULL)
            return NULL;
        Node* backupHead = head;
        
        //bucket에 random의 정보를 저장하기.
        while(head!=NULL){
            bucket[head] = head->random;
            head = head->next;
        }
        
        head = backupHead;
        
        Node* prevNode = new Node(-1);
        Node* dummyNode = prevNode;
        
        
        //새로 만든 리스트 요소들의 next를 수정하기.
        while(head!=NULL){
            Node* newNode = new Node(head->val);
            
            bucket2[head] = newNode;
            
            prevNode->next = newNode;
            prevNode = prevNode->next;
            
            head = head->next;
        }
        
        head = backupHead;
        
        
        //random 요소 추가하기
        while(head != NULL){
            bucket2[head]->random = bucket2[bucket[head]];
            //cout << bucket2[head]->val << endl;
            head = head->next;
        }
        
        return bucket2[backupHead];
        
    }
};
