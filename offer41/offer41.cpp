#include "iostream"
#include "queue"

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    void addNum(int num) {
        if (max_heap.size() == min_heap.size())
        {
            min_heap.push(num);
            int tem = min_heap.top();
            max_heap.push(tem);
            min_heap.pop();
        } else{
            max_heap.push(num);
            int tem = max_heap.top();
            min_heap.push(tem);
            max_heap.pop();
        }
    }

    double findMedian() {
        if (max_heap.size() == min_heap.size())
            return (double)(max_heap.top() + min_heap.top())/2;
        else
            return (double)max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{




}