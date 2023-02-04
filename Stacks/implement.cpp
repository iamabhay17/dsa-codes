// implementation of stack using array

#include <bits/stdc++.h>
using namespace std;

class Stack
{
    // properties

public:
    int top, size, currSize;
    int *arr;

    Stack(int s)
    {
        this->size = s;
        this->top = -1;
        this->arr = new int[size];
        this->currSize = 0;
    }

    // functions

    // ---------------------------push-------------------------------------------
    void push(int element)
    {
        if (top == size - 1)
        {
            cout << "Cannot insert : Stack Overflow ";
            return;
        }
        top++;
        arr[top] = element;
        currSize++;
    }
    // ---------------------------pop-----------------------------------------------
    void pop()
    {
        if (top == -1)
        {
            cout << "Cannot pop : Stack Underflow ";
            return;
        }
        top--;
        currSize--;
    }
    //-----------------------------top---------------------------------------------------
    int getTop()
    {
        if (currSize)
            return arr[top];
        return INT_MIN;
    }
    //------------------------------get size-----------------------------------------------
    int getSize()
    {
        return currSize;
    }
    //-------------------------------is empty---------------------------------------------
    bool isEmpty()
    {
        return top == -1;
    }
};

//-------------------------main------------------------------
int main()
{
    Stack st(5);

    st.push(10);
    cout << st.getTop() << " ";
    st.push(9);
    cout << st.getTop() << " ";
    st.push(8);
    cout << st.getTop() << " ";
    st.push(7);
    cout << st.getTop() << " ";
    st.push(8);
    cout << st.getTop() << " ";
    st.push(12);
    cout << st.getTop() << " ";
    st.push(13);
    cout << st.getTop() << " ";

    cout << st.getSize() << endl;
    cout << endl;
    st.pop();
    cout << st.getTop() << " ";
    cout << st.getSize() << endl;

    return 0;
}