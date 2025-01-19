#include <iostream>
#include <ranges>
#include <stack>

int main()
{
    std::string stroke = "({x-y-z} * [x + 2y] - (z + 4x))";
    std::string_view view = stroke;
    bool valid = true;

    std::stack<char> bracketsStack;
    int strokeCounter = 0;

    const std::string brackets = "[{(";
    const std::string reverseBrackets = "]})";

    for (char symbol : stroke) {
        if (brackets.find(symbol) != std::string::npos) 
            bracketsStack.push(symbol);

        else if (reverseBrackets.find(symbol) != std::string::npos)
        {
            if ((symbol == ')' && bracketsStack.top() != '(') ||
                (symbol == ']' && bracketsStack.top() != '[') ||
                (symbol == '}' && bracketsStack.top() != '{'))
            {
                valid = false;
                break;
            }

            bracketsStack.pop();
        }

        strokeCounter++;
    }

    if (!valid || !bracketsStack.empty())
        std::cout << view.substr(0, strokeCounter);

    else
        std::cout << "All is Ok!";

    return 0;
}