1차 22-05-25
시간: 16분 36초
Success
Details 
Runtime: 95 ms, faster than 11.29% of C++ online submissions for Reorder List.
Memory Usage: 20.2 MB, less than 5.82% of C++ online submissions for Reorder List.
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
    단일 링크드리스트의 헤드가 주어진다.
    이걸 rearrange 해라.
    단순히 값만 바꾸지 마라.
    
    제한:
    
    해결방법:
    1)벡터 두개로 해서 해결.
    2)Discussion참고: stack을 이용해서 전체 size/2만큼만 top에서 뽑아서 붙이면 된다. 코드 첨부함.
    */
    void reorderList(ListNode* head) {
        vector<ListNode*> temp;
        vector<ListNode*> temp2;
        
        while(head!=NULL){
            temp.push_back(head);
            head=head->next;
        }
        
        
        int start = 0, end = temp.size()-1;
        while(start < end){
            temp2.push_back(temp[start++]);
            temp2.push_back(temp[end--]);
        }
        if(start == end)
            temp2.push_back(temp[start]);
        
        for(int i=1; i<temp2.size(); i++){
            temp2[i-1]->next = temp2[i];
            cout << temp2[i-1]->val << endl;
        }
        
        //이거 안하니까 에러뜨넹
        temp2[temp2.size()-1]->next =  NULL;
        
        head = temp2[0];
        
        
    }
};

//Discussion코드
class Solution {
public:
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return; // Edge cases
        
        stack<ListNode*> my_stack;
        ListNode* ptr = head;
        int size = 0;
        while (ptr != NULL) // Put all nodes in stack
        {
            my_stack.push(ptr);
            size++;
            ptr = ptr->next;
        }
        
        ListNode* pptr = head;
        for (int j=0; j<size/2; j++) // Between every two nodes insert the one in the top of the stack
        {
            ListNode *element = my_stack.top();
            my_stack.pop();
            element->next = pptr->next;
            pptr->next = element;
            pptr = pptr->next->next;
        }
        pptr->next = NULL;
    }
};
