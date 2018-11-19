#include<vector>
#include<iostream>
using namespace std;

ListNode * reverseList(ListNode* root){
	if(!root||!root->next) return root;
	ListNode * res=NULL;
	ListNode * left = root;
	ListNode * right = root->next;
	left->next=NULL;

	while(right){
		ListNode * tmp=right->next;
		if(!tmp){
			res=right;
			break;
		}
		right->next=left;
		left=right;
		right=tmp;
	}
	return res;
}