//fail
//상당히 깔끔한 링크드 리스트 코드이다.
//문제:
//두개의 0이상의 정수를 나타내는, 비어있지 않은 링크드 리스트 두 개가 주어진다. 이 숫자들은 역순으로 저장되어있고, 
//각 노드들은 하나의 숫자를 갖고 있따.
//두 링크드 리스트를 더해라.

//해결 아이디어:
//dummyNode는 리턴하기 위한 용도, curr은 while문에서 리스트를 순회하기 위한 용도,
//그리고 코드를 복잡하게 하지 않기 위해, while문의 조건과 그 안의 if문 조건들을 잘 보자.
//구현 자체는 간단하나 코드의 간결성을 보고 넘어가자.

//실수한점?
//마지막에 upper가 발생하는데, 새로운 노드를 추가해 줘야 할 경우 생각해주지않았다.
//기존에 있던 리스트에다가 더하는 방식은 오히려 새로운 예외를 나을 수도 있다.


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
