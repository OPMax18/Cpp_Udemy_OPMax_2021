#include <algorithm>
#include <iostream>
#include <stack>

void correct_exam(std::stack<int>& stack)
{
    while (stack.size() > 0U)
    {
        std::cout << "Done with student_ " << stack.top() << "\n";
        stack.pop();
    }
}

int main()
{

    std::stack<int> myStack;
    myStack.push(1080131311);
    myStack.push(1080131312);
    myStack.push(1080131313);

    correct_exam(myStack);
    return 0;
}
