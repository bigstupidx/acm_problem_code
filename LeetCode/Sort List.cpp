
#include <cstdio>
#include <cstring>


struct ListNode{
       int val;
       ListNode *next;
       ListNode(int x):val(x), next(NULL){
       }
};

class Solution {
public:
	
	ListNode *mergeSort(ListNode *head, int len){
		if(len<2)return head;

		
		int xlen = len/2;
		
		ListNode *right = head;
		
		while(xlen>0){
			right = right->next;
			--xlen;
		}
		
		if(len==2){
			if(head->val > right->val){
				head->next = NULL;
				right ->next = head;
				return right;
			}else{
				return head;
			}
		}
		
		ListNode *p = right;
		right =right->next;
		p->next = NULL;
		
		xlen = len/2;
		head = mergeSort(head, xlen + 1);
		right = mergeSort(right, len - xlen -1);
		
		ListNode *head_result = NULL, *result = NULL;
		while(head || right){
			ListNode *temp = NULL;
			if(head&&right){
				if(head->val > right->val){
					temp = right;
					right = right->next;
					
				}else{
					temp = head;
					head = head->next;
				}
			}else if(head){
				temp = head;
				head = head->next;
			}else{
				temp = right;
				right = right->next;
			}
			if(head_result==NULL)
				head_result = temp;
			else
				result->next = temp;
			result = temp;
			temp->next = NULL;
		}
		return head_result;
	}
	
    ListNode *sortList(ListNode *head) {
        int cnt = 0;
        ListNode*p = head;
        while(p!=NULL){++cnt;p = p->next;}
        return mergeSort(head, cnt);
    }
};

int main(){
    
    Solution a;
    
    ListNode*head = new ListNode(3), *p = head;

	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(4);
    
    head = a.sortList(head);
    
    while(head){
		printf("%d ", head->val);
		head = head->next;
	}
    
    getchar();
    
    return 0;
}
