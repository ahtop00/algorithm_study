#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
void hanoi(int n, int start, int tmp, int end);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string answer = to_string(pow(2, N));
    int idx = answer.find(".");
    answer = answer.substr(0, idx);
    answer[answer.length() - 1] -= 1;
    cout << answer.c_str() << "\n";
    if (N <= 20)
        hanoi(N, 1, 2, 3);
}

void hanoi(int n, int start, int tmp, int end)
{
    if (n == 1)
        cout << start << " " << end << "\n";
    else
    {
        hanoi(n - 1, start, end, tmp);
        cout << start << " " << end << "\n";
        hanoi(n - 1, tmp, start, end);
    }
}
