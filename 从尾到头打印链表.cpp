/*
题目：
	输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/


class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};
//通过
//运行时间：4ms
//占用内存：464k