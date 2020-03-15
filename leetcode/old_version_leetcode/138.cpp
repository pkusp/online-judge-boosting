/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(!head) return NULL;
    	RandomListNode* p=head;
    	while(p){
    		RandomListNode* inst = new RandomListNode(p->label);
    		inst->next = p->next;
    		p->next = inst;
    		p=inst->next;
    	}
    	p=head;
    	while(p){
    		if(p->random){
    			p->next->random=p->random->next;
    		}
    		p=p->next->next;
    	}
    	RandomListNode* resHead=head->next;
    	RandomListNode* cur = head;
    	while(cur){
    		RandomListNode* tmp = cur->next;
    		cur->next = tmp->next;
    		cur=cur->next;
    		if(tmp->next){
    			tmp->next=tmp->next->next;
    		}    
    	}
    	return resHead;
    }
};