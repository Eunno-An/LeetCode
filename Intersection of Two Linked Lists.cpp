1차 22-06-07
Time: 8분 51초
Success
Details 
Runtime: 75 ms, faster than 33.90% of C++ online submissions for Intersection of Two Linked Lists.
Memory Usage: 14.5 MB, less than 72.37% of C++ online submissions for Intersection of Two Linked Lists.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    문제:
    단일 링크드 리스트의 헤더 두개가 주어진다.(headA, headB)
    두 리스트가 교차하는 곳의 노드를 리턴하라.
    만약 두 리스트가 교차하지 않는다면 null을 리턴해라.
    
    반드시 함수가 끝난 후, 각 리스트는 원래의 구조를 유지하고 있어야 한다.
    
    제한:
    
    해결방법:
    🎈
    공통 조상 찾기 문제와 똑같다.
    두 리스트의 사이즈를 조사한 후
    사이즈가 큰 애를 먼저 이동시킨다.
    단, 만약 교차점이 맨 처음부터 존재하는데, 각 listA의 size가 5, listB의 size가 3이고 맨 처음 요소가 같을 수도 있다.
    이 점을 인지하여 사이즈가 큰 애를 이동시킬 때 headA와 headB가 같은지를 검사하면서 넘겨야 한다.
    🎈
    https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/1092898/JS-Python-Java-C%2B%2B-or-Easy-O(1)-Extra-Space-Solution-w-Visual-Explanation
    Discussion에서 참고한 방법.
    그냥 두개의 리스트를 붙여라!
    
    Follow-up:
    O(m+n) t.c와 O(1) memory로 해결하라.
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA=0, sizeB=0;
        ListNode *backupA = headA, *backupB = headB;
        while(headA != NULL){
            sizeA++;
            headA = headA->next;
        }
        while(headB != NULL){
            sizeB++;
            headB = headB->next;
        }
        //backup
        headA = backupA;
        headB = backupB;
        
        //항상 sizeA가 크거나 같도록!
        if(sizeA < sizeB){
            swap(headA, headB);
            swap(sizeA, sizeB);
        }
        
        for(int i=0; i<sizeA-sizeB; i++){
            if(headA == headB)
                return headA;
            headA = headA->next;
        }
        while(headA != NULL){
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
        
    }
  //Discussion방법
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = !a ? headB : a->next;
            b = !b ? headA : b->next;
        }
        return a;
    }
};
