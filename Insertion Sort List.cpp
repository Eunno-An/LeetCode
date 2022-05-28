1차 22-05-28 Fail
링리 하는거에 정신을 못차림

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = NULL;//initializing the newHead for our sorted linkedlist
        while(head){
            // 노드 한번 사용하고 제외
            ListNode* temp = head;
            head = head->next;
            temp->next=NULL;
            
            //처음 하는거면 newHead를 temp로 수정 
            if(newHead == NULL) newHead = temp;
             // 만약 앞에다 붙여야 하는거라면 newHead앞에다가 붙임.
            else if(newHead->val >= temp->val){
                temp->next = newHead;
                newHead = temp;
            }
            // 만약 어떤 사이에 붙여야 되는거라면
            else{
                ListNode* root = newHead;
                {
                while(root->next){
                    if(temp->val > root->val and temp->val <= root->next->val){
                        temp->next = root->next;
                        root->next = temp;
                        break;
                    }
                    root = root->next;
                }  
                    //만약 끝에 붙여야 한다면 붙여줌.
                    if(root->next==NULL) root->next = temp;
                    
                }
            }
        }
        //Our sorted linkedlist
        return newHead;
    }
};
