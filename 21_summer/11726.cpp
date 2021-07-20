#include <iostream>
using namespace std;

class DP
{
public:
    DP(int n);
    void tile();

private:
    int size;
    int *count;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    DP dp(n);
    dp.tile();
}

DP::DP(int n)
{
    size = n;
    count = new int[size + 1];
    if (size == 1)
        count[1] = 1;
    else
    {
        count[1] = 1;
        count[2] = 2;
    }
}

void DP::tile()
{
    for (int i = 3; i <= size; i++)
        count[i] = (count[i - 1] + count[i - 2]) % 10007;
    cout << count[size];
}