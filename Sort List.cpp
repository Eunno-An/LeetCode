1차 22-05-28 Fail
링크드 리스트 형식에서 리스트의 가운데 요소를 찾는 꿀팁
Turtle-Hare algorithm(Finding the middle element)
이분탐색으로 하려고 했으나 너무 난이도가 어려웠다.
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
    리스트의 정렬을 O(nlogn)의 시간과 O(1)의 추가 공간으로 하라.
    
    제한:
    
    해결방법:
    1)mergeSort 재귀로
    ->근데 재귀에 필요한 stack place가 O(logN)일텐데... 흠...!
    */
    ListNode *mergeList(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* curr= dummy;
        
        while(l1 && l2){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        if(l1)
            curr->next = l1;
        if(l2)
            curr->next = l2;
        
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast  && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return mergeList(l1, l2);
    }
};
