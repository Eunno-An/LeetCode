//fail
//상당히 깔끔한 링크드 리스트 코드이다.
//이 문제는 
//1. 링크드 리스트를 반환하는 용도로 dummyHead를 썼다는 점을 유의 깊게 봐야 하고
//2. while문 안에 예외 처리들을 잘 보자. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* curr = dummyHead;
        int carry = 0;
        
        while(p != NULL || q != NULL){
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if(p != NULL) p = p->next;
            if(q != NULL) q = q->next;
        }
        if(carry > 0)
            curr->next = new ListNode(carry);
        
        return dummyHead->next;
    }
};
