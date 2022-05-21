1차 22-05-21
Success
Time: 8분
Details 
Runtime: 335 ms, faster than 5.12% of C++ online submissions for Linked List Cycle II.
Memory Usage: 7.6 MB, less than 33.97% of C++ online submissions for Linked List Cycle II.
회고: 다른 좋은 풀이가 있으니 꼭 참고할것.
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
    사이클이 존재하면, 사이클이 시작하는??곳의 노드를 리턴해라..
    링크드리스트를 변환하지도 말라!
    O(1)의 extra space만 사용해라.
    
    
    제한:
    
    해결방법:
    1. O(n^2)에 해결할 수 있을 것 같다.(n = 노드의 개수)
    2. 🎈Turtle and Hare Solution(토끼와 거북이, 전문 용어로는 플로이드 사이클 감지 알고리즘)
    -> 토끼는 두칸씩, 거북이는 한칸씩 간다. 토끼가 리스트의 끝에 도달(null)하면 사이클이 없고, 토끼가 거북이와 같으면 사이클이 있는것임.
    -> 근데 사이클이 시작하는 곳은 어떻게 알까? 왜 단순히 거북이와 토끼가 같은 곳에서, 토끼는 그대로 두고, 거북이는 head로 옮긴 다음에 둘다 next로 옮기면서 확인할까?
    -> 이는 공식으로 증명할 수 있다. 
    -> 처음 ~ cycle이 시작하는 곳의 길이 : x1
    -> cycle이 시작하는 곳에서 부터, 거북이와 토끼가 만나는 곳의 길이 : x2
    -> 거북이와 토끼가 만나는 곳에서부터, cycle이 시작하는 곳의 길이 : x3
    -> 거북이가 움직인 길이 : x1 + x2
    -> 토끼가 움직인 길이 : x1 + x2 + x3 + x2
    -> 우리는 거북이가 두배 느리게 움직였으니까, 만약 같은 속도로 움직였다고 가정하면
    2(x1 + x2) = x1 + x2 + x3 + x2, 즉 x1 = x3인 곳을 찾으면 그게 사이클이 시작한 곳이다.
    그래서 거북이를 head로 옮기고, 토끼와 거북이를 각각 한칸씩 움직이는 것이다.
    */
    ListNode *detectCycle(ListNode *head) {
        int count = 0;
        int maxCount = 10001;
        while(head != NULL && count < maxCount){
            ListNode* temp = head;
            ListNode* origin = temp;
            int tempCount = 0;
            int tempMaxCount= 10001;
            while(temp != NULL && tempCount < tempMaxCount){
                temp = temp->next;
                if(origin == temp)
                    break;
                tempCount++;
            }
            if(origin == temp)
                return origin;
            head = head->next;
            count++;
        }    
        return NULL;
    }
    
    //플로이드 사이클 감지 알고리즘
    ListNode *detectCycle(ListNode *head) {
        // edge case - empty list
        if (!head || !head->next || !head->next->next) return NULL;
        // support animals
        ListNode *turtle = head, *hare = head;
        // checking if we loop or not
        while (hare->next && hare->next->next) {
            hare = hare->next->next;
            turtle = turtle->next;
            if (hare == turtle) break;
        }
        // exiting if we do not find a loop
        if (hare != turtle) return NULL;
        // finding the start of the loop
        turtle = head;
        while (turtle != hare) {
            hare = hare->next;
            turtle = turtle->next;
        }
        return turtle;
    }
};
