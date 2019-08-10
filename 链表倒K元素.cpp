
/*
题目描述
输入一个链表，输出该链表中倒数第k个结点。
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* pNode1 = pListHead;
        ListNode* pNode2 = pListHead;
        while(k > 0){
            if(!pNode1)
                return NULL;
            pNode1 = pNode1->next;
            k--;
        }
        while(pNode1){
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        return pNode2;
    }
};
/*
这道题比较坑的地方在于只有5个元素，会让你输出倒数第6个
*/