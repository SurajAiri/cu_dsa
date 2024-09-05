#include <iostream>
#include <stack>
using namespace std;
int eval(string A[], int size)
{
stack<int> st;
for (int i = 0; i < size; i++)
{
if (A[i] != "+" && A[i] != "-" && A[i] != "/" && A[i] != "*")
{
st.push(atoi(A[i].c_str()));
continue;
}
else
{
int b = st.top();
st.pop();
int a = st.top();
st.pop();
if (A[i] == "+")
st.push(a + b);
else if (A[i] == "-")
st.push(a - b);
else if (A[i] == "*")
st.push(a * b);
else
st.push(a / b);
}
}
return st.top();
}
int main()
{
string A[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
int res = eval(A, 13);
cout << res << endl;
return 0;
}
