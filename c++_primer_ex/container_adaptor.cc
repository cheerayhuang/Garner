#include <iostream>
#include <stack>
#include <queue>
#include <list>

using namespace std;

int main() {
    stack<int> s;
    
    s.push(5);
    cout << s.top() << endl;
    //cout << s.pop() << endl;
    s.pop();
    cout << static_cast<bool>(s.empty()) << endl;

    queue<int> q;

    q.push(5);
    cout << q.front() << endl;
    cout << q.back() << endl;
    //cout << q.pop() << endl;
    q.pop();
    cout << q.empty() << endl;

    priority_queue<int> pq;

    pq.push(5);
    pq.push(4);

    for(;!pq.empty();) {
        cout << pq.top() << endl;
        pq.pop();
    }

    cout << pq.empty() << endl;
    pq.pop();
    cout << pq.top() << endl;

    queue<int> h1, h2; 

    h1.emplace(5);
    h2.push(5);
    h2.push(10);

    if (h1 == h2) {
        cout << "h1 == h2" << endl;
    }

    return 0;
}

