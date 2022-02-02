#include "iostream"

using namespace std;

class CQueue {
public:
    stack<int> stack1;
    stack<int> stack2;

    CQueue() {}

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if (stack1.empty() && stack2.empty())
            return -1;
        int tem = 0;
        if (!stack2.empty())
        {
            tem = stack2.top();
            stack2.pop();
            return tem;
        }else{
            while (!stack1.empty())
            {
                tem = stack1.top();
                stack1.pop();
                stack2.push(tem);
            }
        }
        stack2.pop();
        return tem;
    }
};

int main()
{

}