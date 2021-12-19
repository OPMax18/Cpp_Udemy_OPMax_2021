#include <algorithm>
#include <iostream>
#include <queue>

void correct_exam(std::queue<int>& queue)
{
    while (queue.size() > 0U)
    {
        std::cout << "Done with student_ " << queue.front() << "\n";
        queue.pop();
    }
}

int main()
{

    std::queue<int> myQueue;
    myQueue.push(1080131311);
    myQueue.push(1080131312);
    myQueue.push(1080131313);

    correct_exam(myQueue);
    return 0;
}
