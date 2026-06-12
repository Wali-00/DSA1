#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

void printVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "index : " << i << " element : " << arr[i] << endl;
    }
    cout << endl;
}

int main()
{
    vector<int> arr;

    arr.push_back(15);
    arr.push_back(25);

    printVector(arr);

    arr[0] = 11;
    arr[1] = 22;

    printVector(arr);

    arr.pop_back();

    printVector(arr);

    stack<int> st;

    st.push(12);
    st.push(24);
    st.push(36);

    cout << "Stack top = " << st.top() << endl;

    st.pop();

    cout << "Stack top = " << st.top() << endl;
    cout << endl;

    queue<int> q;

    q.push(100);
    q.push(200);
    q.push(300);

    cout << "Queue front = " << q.front() << endl;
    q.pop();

    cout << "After pop, queue front = " << q.front() << endl;
    cout << endl;

    string str = "Brazil";

    cout << "String = " << str << endl;
    cout << "Length = " << str.length() << endl;
    cout << "First character = " << str[0] << endl;

    str = str + " Jitbe";

    cout << "After adding = " << str << endl;

    return 0;
}