1차
Time: 17분 43초
Success
Details 
Runtime: 3 ms, faster than 97.04% of C++ online submissions for Rotate List.
Memory Usage: 11.7 MB, less than 88.78% of C++ online submissions for Rotate List.
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
    링리의 헤드가 주어지면, k번 오른쪽으로 로테이트 해라.
    
    제한:
    k는 0이상 이십억이하
    
    해결방법:
    List의 길이를 n이라고 하자.
    그렇다면 k번 오른쪽으로 로테이트한 결과 리스트의 헤더값은 
    기존 리스트의 n-k번째 요소(첫번째 요소를 0번째 요소라고 가정)가 된다.
    그렇다면 n-k번째 요소를 따로 저장하고, n-k-1번째 요소의 next를 NULL로 둔다.
    그리고 n-k번째 요소의 맨 끝 부분이 기존 리스트의 헤더를 가르키게 한다.
    
    회고:
    핵심이 몇가지 부분이 있는데, 위에 해결방법에 어느정도 설명하였고
    48번째줄이 정말 중요하다.
    */
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        int n = 0;
        ListNode* temp = head;
        while(temp!= NULL){
            n++;
            temp = temp->next;
        }
        ListNode* ret = head;
        ListNode* ret_last;
        k = k % n;//k가 n보다 더 클 수도 있으니까!
        if(k == 0)
            return head;
        for(int i=0; i<n-k; i++){
            if(i == n-k-1)
                ret_last = ret;
            ret = ret->next;
        }
        ret_last->next = NULL;//3의 끝은 NULL로 한다.
        cout << ret->val << ' ' << ret_last->val << endl;
        temp = ret;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = head;
        return ret;
    }
};
