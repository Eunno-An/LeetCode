//틀림.
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        ListNode* nowNode = head;
        ListNode* nextNode = nowNode->next;
        ListNode* ret = nextNode;
        while(nowNode!= NULL && nextNode != NULL){
            
            nowNode->next = nextNode->next;
            nextNode->next = nowNode;
            
            nowNode = nowNode->next;
            if(nowNode == NULL)
                break;
            nextNode = nowNode->next;
        }
        return ret;
        
    }
};
