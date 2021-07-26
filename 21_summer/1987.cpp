#include <iostream>
#include <cstring>
using namespace std;

class Graph
{
public:
    Graph(int R, int C);
    void Print();
    void DFS(int step, int row, int col);
    int dx[4] = {0, 0, -1, 1}; // 상하좌우
    int dy[4] = {-1, 1, 0, 0};

private:
    int maxStep;
    int row;
    int col;
    int **matrix;
    bool *check;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R, C;
    cin >> R >> C;
    Graph graph(R, C);
    graph.DFS(1, 0, 0);
    graph.Print();
}

Graph::Graph(int R, int C)
{
    maxStep = 0;
    row = C;
    col = R;
    matrix = new int *[col];
    for (int i = 0; i < col; i++)
        matrix[i] = new int[row];
    for (int i = 0; i < col; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < row; j++)
        {
            int alphabet = (int)str[j] - 65;
            matrix[i][j] = alphabet;
        }
    }
    check = new bool[26];
    for (int i = 0; i < 26; i++)
        check[i] = true;
}

void Graph::DFS(int step, int x, int y)
{
    if (x < 0 || y < 0 || x >= row || y >= col)
        return;
    int current = matrix[y][x];
    if (check[current] == false)
        return;

    check[current] = false;
    for (int i = 0; i < 4; i++)
    {
        int nextX = dx[i] + x;
        int nextY = dy[i] + y;
        DFS(step + 1, nextX, nextY);
    }

    if (maxStep < step)
        maxStep = step;

    check[current] = true;
    return;
}

void Graph::Print()
{
    cout << maxStep;
}