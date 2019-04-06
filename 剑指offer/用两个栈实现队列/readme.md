# 题目链接
[牛客网剑指offer-用两个栈实现队列](https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
# 解题思路
队列的特点是先进先出，而栈的特点的先进后出。用两个栈来实现一个队列，队列插入结点，可以stack1进行入栈操作，队列删除结点，可以将stack1的所有结点依次入栈
stack2,此时在对stack2进行出栈操作，此时出栈的即是队列的第一个结点。如果还要进行出栈操作，如果stack2不为空，那么删除队列结点即对stack2进行出栈操作，
因为stack2的栈顶始终是队列的队头，如果stack2为空，那么依然是将stack1的所有结点依次入栈stack2,再取stack2的栈顶。
# C++代码
```
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int t;
        if(!stack2.empty()) {t=stack2.top();stack2.pop();}
        else
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            t=stack2.top();
            stack2.pop();
        }
        return t;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```
