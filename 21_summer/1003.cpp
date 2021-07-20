#include <iostream>
using namespace std;

class DP
{
public:
    DP(int n);
    void print();
    int fibonacci(int n);

private:
    int *arr;
    int size;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        DP dp(N);
        dp.print();
    }
}

DP::DP(int n)
{
    size = n;
    arr = new int[size + 1];
    if (size == 0)
        arr[0] = 0;
    else if (size == 1)
    {
        arr[0] = 0;
        arr[1] = 1;
    }
    else
    {
        for (int i = 0; i <= size; i++)
            arr[i] = 0;
        arr[1] = 1;
        fibonacci(size);
    }
}

int DP::fibonacci(int n)
{
    if (n == 0)
    {
        return arr[0];
    }
    else if (n == 1)
    {
        return arr[1];
    }
    else if (arr[n] != 0)
        return arr[n];
    else
    {
        return arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
        //top down?!
    }
}

void DP::print()
{
    if (size != 0)
        cout << arr[size - 1] << " " << arr[size] << "\n";
    else
        cout << 1 << " " << 0 << "\n";
}