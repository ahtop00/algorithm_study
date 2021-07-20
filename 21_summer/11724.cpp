#include <iostream>
#define NOTTHING 0
#define UNCHECKED 1
#define CHECKING 2
#define CROSS 3
using namespace std;

class Graph
{
public:
    Graph(int size);
    void insertEdge(int v1, int v2);
    void DFS(int v);
    bool check;
    int connected;

private:
    int **matrix;
    int *vertex;
    int size;
};

int main()
{
    int N, M;
    cin >> N >> M;
    Graph g(N);
    for (int i = 0; i < M; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g.insertEdge(v1 - 1, v2 - 1);
    }

    for (int i = 0; i < N; i++)
    {
        g.check = true;
        g.DFS(i);

        if (g.check)
            g.connected++;
    }

    cout << g.connected;
}

Graph::Graph(int s)
{
    this->size = s;
    check = true;
    connected = 0;
    vertex = new int[size];
    for (int i = 0; i < size; i++)
    {
        vertex[i] = UNCHECKED;
    }
    matrix = new int *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = NOTTHING;
}

void Graph::insertEdge(int v1, int v2)
{
    if (matrix[v1][v2] != NOTTHING)
        return;

    matrix[v1][v2] = UNCHECKED;
    matrix[v2][v1] = UNCHECKED;
}

void Graph::DFS(int v)
{
    if (vertex[v] == CHECKING)
    {
        check = false;
        return;
    }

    vertex[v] = CHECKING;
    for (int i = 0; i < size; i++)
    {
        if (v != i)
        {
            if (matrix[v][i] == UNCHECKED && vertex[i] == UNCHECKED)
            {
                matrix[v][i] = CHECKING;
                matrix[i][v] = CHECKING;
                DFS(i);
            }
            else if (matrix[v][i] == UNCHECKED && vertex[i] == CHECKING)
            {
                matrix[v][i] = CROSS;
                matrix[i][v] = CROSS;
            }
        }
    }
}