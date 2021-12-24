/*
22분 소요
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 10.8 MB, less than 31.01% of C++ online submissions for Remove Nth Node From End of List.


Follow-up은 ListNode를 한 번만 순회하라고 하는 것이였음.
그래서 이걸 저장할 벡터를 따로 선언하였음.

그리고 n이 1 또는 sz일 때 예외처리만 해 주었음.
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> lists;
        while(head != NULL){
            lists.push_back(head);
            head = head->next;
        }
        
        if(n == 1){
            if(lists.size() <= 2){
                if(lists.size() == 1)
                    return NULL;
                if(lists.size() == 2){
                    lists[0]->next=NULL;
                    return lists[0];
                }
            }
            lists[lists.size()-2]->next = NULL;
            return lists[0];
        }
        if(n == lists.size()){
            if(lists.size() == 1){
                return NULL;
            }
            lists[0] = lists[0]->next;
            return lists[0];
        }
        
        lists[lists.size()-n-1]->next = lists[lists.size()-n+1];
        return lists[0];
    }
};
