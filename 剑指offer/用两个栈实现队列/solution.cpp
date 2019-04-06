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
