#include <cstdio>
#include <cstring>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 struct ListNode{
		int val;
		ListNode* next;
		ListNode(int x):val(x), next(NULL){}
};
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *tail_result = NULL;
        ListNode *p = head;
        while(p){
			ListNode *temp = p;
			p = p->next;
			
			temp->next = NULL;

			ListNode *q = tail_result, *pre = NULL;
			while(q!=NULL && q->val < temp ->val){
				pre = q;
				q = q->next;
			}
			if(pre==NULL){
				temp->next = tail_result;
				tail_result = temp;
			}else{
				temp->next = pre->next;
				pre->next = temp;
			}
		}
        return tail_result;
    }
};

int main(){
	
	Solution a;
	
	return 0;
}
