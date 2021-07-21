#include <iostream>
#include <queue>
#define NOTHING 0
#define UNVISITED 1
#define LOCATED 2
using namespace std;

class Dummy
{
public:
    Dummy(int size);
    void insertApple(int col, int row);
    void insertDirection(int second, char rotation);
    void rotateDirection();
    bool checkMove();
    int startGame();

private:
    int size;
    int **matrix;
    char *information;
    string direction;
    queue<int> snakeRow;
    queue<int> snakeColumn;
    int count;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, L;
    cin >> N;
    cin >> K;
    Dummy dummy(N);
    for (int i = 0; i < K; i++)
    {
        int col;
        int row;
        cin >> col >> row;
        dummy.insertApple(col, row);
    }

    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int second;
        char rotation;
        cin >> second >> rotation;
        dummy.insertDirection(second, rotation);
    }
    cout << dummy.startGame();
}

Dummy::Dummy(int size)
{
    direction = "Right";
    count = 0;
    information = new char[10001];
    this->size = size;

    matrix = new int *[this->size];
    for (int i = 0; i < this->size; i++)
        matrix[i] = new int[this->size];

    for (int i = 0; i < this->size; i++)
        for (int j = 0; j < this->size; j++)
            matrix[i][j] = NOTHING;

    for (int i = 0; i < 10001; i++)
        information[i] = 'A';
    snakeRow.push(0);
    snakeColumn.push(0);
}

void Dummy::insertApple(int col, int row)
{
    matrix[row - 1][col - 1] = UNVISITED;
}

void Dummy::insertDirection(int second, char rotation)
{
    information[second] = rotation;
}

void Dummy::rotateDirection()
{
    if (information[count] == 'L')
    {
        if (direction == "Right")
            direction = "Up";
        else if (direction == "Left")
            direction = "Down";
        else if (direction == "Up")
            direction = "Left";
        else if (direction == "Down")
            direction = "Right";
    }
    else if (information[count] == 'D')
    {
        if (direction == "Right")
            direction = "Down";
        else if (direction == "Left")
            direction = "Up";
        else if (direction == "Up")
            direction = "Right";
        else if (direction == "Down")
            direction = "Left";
    }
}

bool Dummy::checkMove()
{
    // 1: 애초에 벽에 부딪칠때
    // 2: 뱀끼리 부딪칠때
    if (direction == "Right")
    {
        if (snakeRow.back() + 1 >= size)
            return false;
        else if (matrix[snakeRow.back() + 1][snakeColumn.back()] == LOCATED)
            return false;
    }
    else if (direction == "Left")
    {
        if (snakeRow.back() - 1 < 0)
            return false;
        else if (matrix[snakeRow.back() - 1][snakeColumn.back()] == LOCATED)
            return false;
    }
    else if (direction == "Up")
    {
        if (snakeColumn.back() - 1 < 0)
            return false;
        else if (matrix[snakeRow.back()][snakeColumn.back() - 1] == LOCATED)
            return false;
    }
    else if (direction == "Down")
    {
        if (snakeColumn.back() + 1 >= size)
            return false;
        else if (matrix[snakeRow.back()][snakeColumn.back() + 1] == LOCATED)
            return false;
    }
    else
        return false;
    return true;
}

int Dummy::startGame()
{
    matrix[0][0] = LOCATED;
    //snakeSize 뱀길이 count 시간
    while (checkMove())
    {
        //apple있을때 없을때
        if (direction == "Right")
        {
            snakeRow.push(snakeRow.back() + 1);
            snakeColumn.push(snakeColumn.back());
        }
        else if (direction == "Left")
        {
            snakeRow.push(snakeRow.back() - 1);
            snakeColumn.push(snakeColumn.back());
        }
        else if (direction == "Up")
        {
            snakeRow.push(snakeRow.back());
            snakeColumn.push(snakeColumn.back() - 1);
        }
        else if (direction == "Down")
        {
            snakeRow.push(snakeRow.back());
            snakeColumn.push(snakeColumn.back() + 1);
        }

        if (matrix[snakeRow.back()][snakeColumn.back()] == NOTHING)
        {
            matrix[snakeRow.back()][snakeColumn.back()] = LOCATED;
            matrix[snakeRow.front()][snakeColumn.front()] = NOTHING;
            snakeRow.pop();
            snakeColumn.pop();
        }
        else
        {
            matrix[snakeRow.back()][snakeColumn.back()] = LOCATED;
        }
        count++;
        rotateDirection();
    }
    return count + 1;
}