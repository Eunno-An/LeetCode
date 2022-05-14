1차 22-04-03 Fail
2차 22-05-14 Fail.
2차 회고: Exchange 써서 해결하는 코드 보면 쉬워보이는데
Exchange에 대한 관련 문서가 없다. cplusplus에서도 안보인다.. 이해하다가 포기함.
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
    left와 right부분을 reverse해서 리턴해라.
    
    Follow-up:
    한번에 할 수 있냐?
    
    제한:
    
    해결방법:

    재귀함수같다.
    1. before left랑 after_right를 따로 저장한다.
    2. 두개의 노드를 스왑하는 방법.(사이에 무언가 있을 때)
    
    회고:
    재귀로 하려고 했으나 막혔음.
    틀림. 굳이 재귀로 안하고 짜도 된다. 단 구현이 좀 복잡하다.
    reverse하는 과정을 단순하게 왼쪽부터 훑으면서 할 수 있다.
    2의 next를 따른 변수에 집어넣고,
    2의 next를 1로 가르키고,
    2를 따로 저장하고
    다음차례인 3으로 넘어가고,
    똑같이 해주면 된다.
    그리고 처음 노드인 2가 5를 가르키게만 하면 된다.
    근데 exchange함수를 쓰는게 있었는데 이런 함수는 첨본다. 나중에 좀 더 공부해봐야 겠다. 지금은 너무 하기 싫다...
    */
    ListNode* reverseBetween(ListNode* head, int m, int n) 
{
    if(head == NULL)
        return NULL; //Handled an edge case
    
    ListNode *temp, *curr = head, *prev = NULL;
    while(m>1)
    {
        prev = curr;
        curr = curr->next;
        m--;
        n--; //Only relative shifting of variable n. Doesn't make a difference to the logic
    }
    //Through this We have traversed till the mth node.
    
    ListNode *con = prev, *tail = curr;
    //Two nodes to help the set the connections of the list at the end of sublist reversal
    
    while(n>0)
    { //The actual reversal happens here
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        n--;
    }
    //Setting the connections to complete sublist reversal
    if(con!= NULL) 
    {
        con->next = prev;
    }
    else
    { //To handle the case if m=0
        head = prev;
    }
    
    tail->next = curr; //Even if current node is NULL, the tail node is the last node of the new list which in turn points to null
    return head;
	}
};
