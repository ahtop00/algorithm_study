#include <iostream>
#define WHITE 0
#define BLUE 1
using namespace std;

class Paper
{
public:
    Paper(int N);
    void CountPaper(int startX, int endX, int startY, int endY);
    void Print();

private:
    int size;
    int white;
    int blue;
    int **matrix;
};

int main()
{
    int N;
    cin >> N;
    Paper paper(N);
    paper.CountPaper(0, N, 0, N);
    paper.Print();
}

Paper::Paper(int N)
{
    size = N;
    white = 0;
    blue = 0;
    matrix = new int *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> matrix[i][j];
}

void Paper::CountPaper(int startX, int endX, int startY, int endY)
{
    if (startX >= endX || startY >= endY)
        return;

    bool checker = true;
    int checkColor = matrix[startY][startX];
    for (int col = startY; col < endY; col++)
    {
        if (!checker)
            break;
        for (int row = startX; row < endX; row++)
            if (checkColor != matrix[col][row])
            {
                checker = false;
                break;
            }
    }

    if (checker)
    {
        if (checkColor == BLUE)
            blue++;
        else if (checkColor == WHITE)
            white++;
    }
    else
    {
        CountPaper(startX, (startX + endX) / 2, startY, (startY + endY) / 2);
        CountPaper((startX + endX) / 2, endX, startY, (startY + endY) / 2);
        CountPaper(startX, (startX + endX) / 2, (startY + endY) / 2, endY);
        CountPaper((startX + endX) / 2, endX, (startY + endY) / 2, endY);
    }
}

void Paper::Print()
{
    cout << white << "\n"
         << blue;
}