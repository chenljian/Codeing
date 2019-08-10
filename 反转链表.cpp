/*
题目描述
输入一个链表，反转链表后，输出新链表的表头。

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pNode = NULL;
        while(pHead){
            ListNode* pTem = pHead->next;
            pHead->next = pNode;
            pNode = pHead;
            pHead = pTem;
        }
        return pNode;
    }
};