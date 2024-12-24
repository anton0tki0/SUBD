#include <iostream>
#include "../Stack/Stack.h"

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Stack content: " << s.toString() << std::endl;
    std::cout << "Top element: " << s.top() << std::endl;

    std::cout << "Pop element: " << s.pop() << std::endl;
    std::cout << "Stack after pop: " << s.toString() << std::endl;

    std::cout << "Contains 20? " << (s.contains(20) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 100? " << (s.contains(100) ? "Yes" : "No") << std::endl;

    return 0;
}
