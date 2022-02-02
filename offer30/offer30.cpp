#include "iostream"
#include "stack"

using namespace std;

class MinStack {
private:
    stack<int> sadstack;
    stack<int> minstack;
public:
    /** initialize your data structure here. */
    MinStack()
    {
        
    }

    void push(int x) {
        sadstack.push(x);
        if (minstack.empty())
        {
            minstack.push(x);
        }else if (minstack.top() >= sadstack.top())
        {
            minstack.push(x);
        }
    }

    void pop() {
        if (minstack.top() == sadstack.top())
            minstack.pop();
        sadstack.pop();
    }

    int top() {
        return sadstack.top();
    }

    int min() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main()
{
    MinStack s;
    s.push(2147483646);
    s.push(2147483646);
    s.push(2147483647);
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.min()<<" ";
    s.pop();
    cout<<s.min()<<" ";
    s.pop();
    s.push(2147483647);
    cout<<s.top()<<" ";
    cout<<s.min()<<" ";  //error
    s.push(-2147483648);
    cout<<s.top()<<" ";
    cout<<s.min()<<" ";
    s.pop();
    cout<<s.min()<<endl;  //error


}