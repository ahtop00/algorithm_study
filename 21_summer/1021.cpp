//회전하는 큐
#include <iostream>
using namespace std;

class Queue
{
public:
    Queue(int size);
    void pop(int idx);
    int printRotation();

private:
    int rotation;
    int *q_array;
    int q_size;
    int front;
    int count;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    Queue q(N);

    for (int i = 0; i < M; i++)
    {
        int data;
        cin >> data;
        q.pop(data - 1);
    }

    cout << q.printRotation();
}

Queue::Queue(int size)
{
    rotation = 0;
    q_size = size;
    q_array = new int[q_size];
    front = 0;
    count = size;

    for (int i = 0; i < q_size; i++)
    {
        q_array[i] = 1;
    }
}

void Queue::pop(int idx)
{
    if (front == idx)
    {
        q_array[front] = 0;
        count--;
        if (count == 0)
        {
            return;
        }

        while (q_array[front] == 0)
        {
            front = (front + 1) % q_size;
        }
        return;
    }

    int check1 = 0;
    int check2 = 0;
    int blank1 = 0;
    int blank2 = 0;

    if (front > idx)
    {
        check1 = front - idx;
        check2 = q_size - front + idx;
        for (int i = idx; i < front; i++)
        {
            if (q_array[i] == 0)
                blank1++;
        }

        for (int i = 0; i < idx; i++)
        {
            if (q_array[i] == 0)
                blank2++;
        }

        for (int i = front; i < q_size; i++)
        {
            if (q_array[i] == 0)
                blank2++;
        }
    }
    else //front < idx
    {
        check1 = q_size - idx + front;
        check2 = idx - front;
        for (int i = front; i < idx; i++)
        {
            if (q_array[i] == 0)
                blank2++;
        }

        for (int i = 0; i < front; i++)
        {
            if (q_array[i] == 0)
                blank1++;
        }

        for (int i = idx; i < q_size; i++)
        {
            if (q_array[i] == 0)
                blank1++;
        }
    }

    if (check1 - blank1 <= check2 - blank2)
    {
        rotation += (check1 - blank1);
    }
    else
    {
        rotation += (check2 - blank2);
    }

    front = idx;
    q_array[front] = 0;
    count--;

    if (count == 0)
    {
        return;
    }

    while (q_array[front] == 0)
    {
        front = (front + 1) % q_size;
    }
}

int Queue::printRotation()
{
    return rotation;
}