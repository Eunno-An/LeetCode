/*
Success
2022-03-01
문제: 0 사이에 낀 수들을 다 더하여 새로운 링크드 리스트 만드는 문제.
단순 구현.
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* ret = temp;
        int sum = 0;
        while(head!=NULL){
            int sum = 0;
            if(head->val == 0){
                head = head->next;
                continue;
            }
            ListNode* newNode = new ListNode(0);
            while(head->val != 0){
                sum += head->val;
                head = head->next;
            }
            //cout << sum << endl;
            newNode->val = sum;
            temp->next = newNode;
            temp = temp->next;
            head = head->next;
        }
        return ret->next;
    }
};
