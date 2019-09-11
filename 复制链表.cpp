/*
题目描述
输入一个复杂链表
（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        map<RandomListNode*, RandomListNode*> addrMap;
        addrMap.insert(pair<RandomListNode*, RandomListNode*>(NULL,NULL));
        RandomListNode* pNewHead = NULL;
        RandomListNode* pNode1 = pHead;
        RandomListNode** pNode2 = &pNewHead;
        while(pNode1){
            RandomListNode* temp = new RandomListNode(0);
            temp->label = pNode1->label;
            temp->next = NULL;
            addrMap.insert(pair<RandomListNode*, RandomListNode*>(pNode1,temp));
            *pNode2 = temp;
            pNode2 = &(temp->next);
            pNode1 = pNode1->next;
            
        }
        
        //处理随机指针
        pNode1 = pHead;
        RandomListNode* pNode3 = pNewHead;
        while(pNode1){
            pNode3->random = addrMap[pNode1->random];
            pNode1 = pNode1->next;
            pNode3 = pNode3->next;
        }
        return pNewHead;
    }
};