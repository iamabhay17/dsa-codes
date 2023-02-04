// infix to post fix conversion

#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

// postfix conversion
string toPostfix(string str)
{
    stack<int> st;
    string ans = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
        {
            ans += str[i];
        }
        else if (str[i] == '(')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }

        else
        {
            while (!st.empty() && prec(st.top() > prec(str[i])))
            {
                ans += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string str = "(a-b/c)*(a/k-l)";
    cout << toPostfix(str);
    return 0;
}