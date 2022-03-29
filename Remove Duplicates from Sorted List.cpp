1차 22-03-29 Success
Details 
풀이 시간:17분 30초
Runtime: 25 ms, faster than 10.26% of C++ online submissions for Remove Duplicates from Sorted List.
Memory Usage: 11.6 MB, less than 35.88% of C++ online submissions for Remove Duplicates from Sorted List.
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
    /*
    문제:
    중복 다 제거하고 각 요소마다 하나의 요소만 남겨라.
    
    제한:
        
    해결방법:
    
    회고:
    더 간단한 방법이 있다. 애초에 head를 리턴하고, 단순히 변수 하나만 선언해주면 됨. 코드 첨부함.
    
    */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ret = new ListNode(0);
        ListNode* prev = head;
        ret->next = prev;
        while(head!=NULL){
            if(head->next != NULL && head->val == head->next->val){
                
                while(head->next!=NULL && head->val == head->next->val){
                    head = head->next;
                }
                
                prev->next = head->next;
            }
            head = head->next;
            prev = head;
        }
        return ret->next;
    }
  ListNode* deleteDuplicates(ListNode* head) {
        
	if(!head) return head;
	ListNode* tmp = head;

	while(tmp && tmp -> next)
	{
		if(tmp -> val == tmp -> next -> val)
			tmp -> next = tmp -> next -> next;
		else
			tmp = tmp -> next; 
	}

	return head;
}
};
