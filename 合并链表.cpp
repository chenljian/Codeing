/*
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，
当然我们需要合成后的链表满足单调不减规则。
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* pHead = NULL;
        ListNode** ppHead =  &pHead;
        while(pHead1 && pHead2){
            if(pHead1->val <= pHead2->val){
                *ppHead = pHead1;
                pHead1 = pHead1->next;
            }
            else{
                *ppHead = pHead2;
                pHead2 = pHead2->next;
            }
            ppHead = &((*ppHead)->next);
        }
        if(pHead1){
            *ppHead = pHead1;
        }
        if(pHead2){
            *ppHead = pHead2;
        }
        return pHead;
    }
};