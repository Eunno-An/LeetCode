/*
Merge Two Sorted Lists를 봤으면 쉽게 풀리는 문제.
근데 이런 문제는 하나하나씩 다 비교하기보다는, 다른 방법을 통해 시간을 줄일 수 있음.
각자 하나씩 따로따로 비교 한 다음 이 결과들을 합친다면? 그래도 결과에는 영향을 주진 않잖아? 
분할 정복을 통해 시간을 훨씬 빠르게 할 수 있음.
두번째 풀이는 분할정복임.
Runtime: 164 ms, faster than 23.69% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 13 MB, less than 86.09% of C++ online submissions for Merge k Sorted Lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* newH=NULL;
        ListNode* newT = NULL;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        if(l1->val < l2->val){
            newH = l1;
            newT = l1;
            l1 = l1->next;
        }else{
            newH = l2;
            newT = l2;
            l2 = l2->next;
        }
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                newT->next = l1;
                l1 = l1->next;
                newT = newT->next;
            }else{
                newT->next = l2;
                l2 = l2->next;
                newT = newT->next;
            }
        }
        newT->next = (l1 == NULL ? l2 : l1);
        return newH;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret=NULL;
        if(lists.size() == 0)
            return ret;
        ret = lists[0];
        for(int i=1; i<lists.size(); i++){
            ret = mergeTwoLists(ret, lists[i]);
        }
        return ret;
    }
};


/*
Runtime: 20 ms, faster than 86.09% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 13.2 MB, less than 73.21% of C++ online submissions for Merge k Sorted Lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* newH=NULL;
        ListNode* newT = NULL;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        if(l1->val < l2->val){
            newH = l1;
            newT = l1;
            l1 = l1->next;
        }else{
            newH = l2;
            newT = l2;
            l2 = l2->next;
        }
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                newT->next = l1;
                l1 = l1->next;
                newT = newT->next;
            }else{
                newT->next = l2;
                l2 = l2->next;
                newT = newT->next;
            }
        }
        newT->next = (l1 == NULL ? l2 : l1);
        return newH;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL; 
        vector<ListNode*> steps;
        while(lists.size() != 1){
            for(int i=0; i+1<lists.size(); i+=2){
                
                ListNode* add = mergeTwoLists(lists[i], lists[i+1]);
                steps.push_back(add);
            }
            if(lists.size() % 2 != 0)
                steps.push_back(lists.back());
            lists = steps;
            steps.clear();
        }
        return lists[0];
    }
};
