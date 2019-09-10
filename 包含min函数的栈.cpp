/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/
class Solution {
public:
    void push(int value) {
        intStack.push(value);
        if(minStack.empty() || minStack.top() >= value){
            minStack.push(value);
        }
    }
    void pop() {
        if(intStack.empty())
            return;
        if(intStack.top() == minStack.top()){
            minStack.pop();
        }
        intStack.pop();
        
    }
    int top() {
        if(!intStack.empty())
            return intStack.top();
    }
    int min() {
        if(!minStack.empty())
            return minStack.top();
    }
    
private:
    stack<int> intStack;
    stack<int> minStack;
};