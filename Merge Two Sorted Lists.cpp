//fail
//혼동했던 사실.
//무지성으로 temp = list1이니까 temp->next하면 list1->next도 바뀐다고 생각하면 안됰!! 그림 그려가면서 생각하자~!

/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = list1;
        temp->next = list2->next;
        cout << list1->next->val << ' ' << temp->next->val << ' ';
        입력
        l1: [1,2,4]
        l2: [1,3,4]
        
        //결과 3 3
        return temp;
    }
};
*/
//재귀로짠거
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1 == NULL){
			return l2;
		}
		if(l2 == NULL){
			return l1;
		}        
		if(l1->val < l2->val){
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;            
		}
	}
};

//반복문
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        ListNode* newH = NULL;
        ListNode* newT = NULL;
        
        if(l1->val < l2->val){
            newH = l1;
            newT = l1;
            l1 = l1->next;
        }
        else{
            newH = l2;
            newT = l2;
            l2 = l2->next;
        }
        
        while(l1 != NULL and l2 != NULL){
            if(l1->val < l2->val){
                newT->next = l1;
                newT = newT->next;
                l1 = l1->next;
                
            }else{
                newT->next = l2;
                newT = newT->next;
                l2 = l2->next;
            }
        }
        newT->next = (l1 == NULL ? l2 : l1);
        return newH;
    }
};
