#include <bits/stdc++.h>
using namespace std;

void print(string a, int n)
{
    if (n == 5)
        return;
    cout << a << endl;
    print(a, n + 1);
}
void print_n(int s, int n)
{
    if (s == n + 1)
        return;
    cout << s << endl;
    print_n(s + 1, n);
}
void printn_1(int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    printn_1(n - 1);
}
void back_print_n(int s, int e)
{
    if (e < s)
        return;
    back_print_n(s, e - 1);
    cout << e << endl;
}
void back_printn_1(int n, int s)
{
    if (s > n)
        return;
    back_printn_1(n, s + 1);
    cout << s << endl;
}
int sum_n(int n)
{
    if (n <= 1)
        return n;
    return n + sum_n(n - 1);
}
bool check(string a, int i)
{
    if (i >= a.length() / 2)
        return true;
    if (a[i] != a[a.length() - i - 1])
        return false;
    return check(a, i + 1);
}

int optimized_fib(int n, vector<int> &f)
{
    if (f[n] != 0)
        return f[n];
    f[n] = optimized_fib(n - 1, f) + optimized_fib(n - 2, f);
    return f[n];
}
int fib(int n)
{
    // fib(ith num)=fib(i-1)+fib(i-2)
    // if i<2 return i
    // n=  0 1 2 3 4 ....
    // fib=0 1 1 2 3 .....
    if (n < 2)
        return n;
    return fib(n - 1) + fib(n - 2);
}
void print_fib(int n, vector<int> &f)
{
    if (n < 0)
        return;
    print_fib(n - 1, f);
    cout << optimized_fib(n, f) << " ";
}
void print_sub(int arr[], int n, int i, vector<int> &v)
{
    if (i == n)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    v.push_back(arr[i]);
    print_sub(arr, n, i + 1, v);
    v.pop_back();
    print_sub(arr, n, i + 1, v);
}
void sub_sum_k(int arr[], int n, int i, vector<int> &vec, int k, int &sum)
{
    if (i == n)
    {
        if (sum == k)
        {
            if (vec.size() != 0)
            {
                for (int i : vec)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
        }
        return;
    }

    vec.push_back(arr[i]);
    sum += arr[i];
    sub_sum_k(arr, n, i + 1, vec, k, sum);
    sum -= arr[i];
    vec.pop_back();
    sub_sum_k(arr, n, i + 1, vec, k, sum);
}
int main()
{
    // print name 5 times
    print("sahaj", 0);
    // print from 1 to n
    print_n(1, 5);
    printn_1(3);
    back_print_n(3, 5);
    back_printn_1(4, 2);
    // sum of first n numbers
    cout << sum_n(5) << endl;
    // checking if string is palindrome or not
    cout << check("sahaj", 0) << endl;
    // fibonacci
    cout << fib(6) << endl;
    // print first 20 fib numbers
    vector<int> f(20);
    f[0] = 1;
    f[1] = 1;
    print_fib(19, f);
    cout << endl;
    // printing subsequences
    // sunsequenced is selecting some, none or all characters or values from a sttring or an array while keeping order same
    // so for abc- _,a,b,c,ab,ac,bc,abc
    int arr[] = {1, 0, 1};
    vector<int> v;
    print_sub(arr, 3, 0, v);
    // all subsequences whose sum is k
    vector<int> vec;
    int sum = 0;
    sub_sum_k(arr, 3, 0, vec, 0, sum);
    return 0;
}