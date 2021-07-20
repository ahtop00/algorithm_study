//프린터 큐
#include <iostream>
using namespace std;

struct Paper
{
    int check; //이미 출력이 되었는지 o,x
    int priorty;

    Paper()
    {
        check = 0;   // 0은 출력x, 1은 출력o
        priorty = 0; //우선순위 입력
    }

    Paper(int p)
    {
        check = 0;
        priorty = p;
    }
};

class Printer
{
public:
    Printer(int);
    void InsertNumber(int, int);
    void PrintNumber(int);

private:
    int size;
    int count;
    int front;
    int max_idx;
    int max_priorty;
    Paper *printer_queue;
};

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int size, find_number;
        cin >> size >> find_number;
        Printer printer(size);
        for (int i = 0; i < size; i++)
        {
            int priorty;
            cin >> priorty;
            printer.InsertNumber(i, priorty);
        }
        printer.PrintNumber(find_number);
    }
}

Printer::Printer(int s)
{
    size = s;
    count = 0;
    front = 0;
    max_idx = 0;
    max_priorty = 0;
    printer_queue = new Paper[size];
}

//중요도를 입력할 때 미리 front를 찾아둔다.
void Printer::InsertNumber(int number, int priorty)
{
    printer_queue[number].priorty = priorty;
    if (max_priorty < priorty)
    {
        max_priorty = priorty;
        max_idx = number;
    }
}

void Printer::PrintNumber(int number)
{
    int current_number = front;
    front = max_idx;
    printer_queue[front].check = 1;
    count++;

    //count가 size를 넘어버리면 분명 오류 -> 무한루프 미리 방지
    //해당 숫자가 나오면 반복문 탈출
    while (current_number != number && count <= size)
    {
        int current = front;
        max_priorty = -1;
        max_idx = -1;
        //check가 0인 문서를 전부 비교한다.
        for (int i = 0; i < size; i++)
        {
            if (printer_queue[current].check == 0 && printer_queue[current].priorty > max_priorty)
            {
                max_idx = current;
                max_priorty = printer_queue[current].priorty;
            }
            current = (current + 1) % size;
        }
        //전부 비교결과 -> max_idx를 통해 다음으로 출력해야할 문서의 번호를 알 수 있다.
        printer_queue[max_idx].check = 1;
        front = max_idx;
        current_number = max_idx;
        count++;
    }
    cout << count << "\n";
}