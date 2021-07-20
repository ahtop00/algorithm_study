#include <iostream>
#define NOTTHING 0
#define UNCHECKED 1
#define CHECKING 2
using namespace std;

class Graph
{
public:
    Graph(int M, int N);
    void insertVertex(int col, int row);
    void DFS(int col, int row);
    int count;
    bool check;

private:
    int **matrix;
    int column;
    int row;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int M, N, K;
        cin >> M >> N >> K;
        Graph g(M, N);
        for (int j = 0; j < K; j++)
        {
            int x, y;
            cin >> x >> y;
            g.insertVertex(x, y);
        }
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                g.check = true;
                g.DFS(i, j);
                if (g.check)
                    g.count++;
            }
        cout << g.count << "\n";
    }
}

Graph::Graph(int M, int N)
{
    check = true;
    count = 0;
    column = M;
    row = N;
    matrix = new int *[column];
    for (int i = 0; i < column; i++)
        matrix[i] = new int[row];

    for (int i = 0; i < column; i++)
        for (int j = 0; j < row; j++)
            matrix[i][j] = NOTTHING;
}

void Graph::insertVertex(int col, int row)
{
    matrix[col][row] = UNCHECKED;
}

void Graph::DFS(int x, int y)
{
    if (matrix[x][y] == CHECKING || matrix[x][y] == NOTTHING)
    {
        check = false;
        return;
    }

    matrix[x][y] = CHECKING;
    if (y - 1 >= 0) //상
        if (matrix[x][y - 1] == UNCHECKED)
            DFS(x, y - 1);
    if (y + 1 < row) //하
        if (matrix[x][y + 1] == UNCHECKED)
            DFS(x, y + 1);
    if (x - 1 >= 0) //좌
        if (matrix[x - 1][y] == UNCHECKED)
            DFS(x - 1, y);
    if (x + 1 < column) //우
        if (matrix[x + 1][y] == UNCHECKED)
            DFS(x + 1, y);
}