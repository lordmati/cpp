#include "RPN.hpp"

void makeStack(std::string str)
{
 	std::stack<int> listStack;
    
    for(int i = 0; str[i]; i++)
	{
        if (str[i] >= '0' && str[i] <= '9')
            listStack.push(str[i] - '0');
        else if (str[i] != ' ')
		{
            if (listStack.size() < 2)
			{
                std::cout << "Error" << std::endl;
                return;
            }
            int b = listStack.top();
            listStack.pop();
            int a = listStack.top();
            listStack.pop();
            switch(str[i])
			{
                case '+':
                    listStack.push(a + b);
                    break;
                case '-':
                    listStack.push(a - b);
                    break;
                case '*':
                    listStack.push(a * b);
                    break;
                case '/':
                    if (b == 0)
					{
                        std::cout << "Error: Division by zero" << std::endl;
                        return;
                    }
                    listStack.push(a / b);
                    break;
            }
        }
    }
    if (listStack.size() == 1)
        std::cout << listStack.top() << std::endl;
    else
        std::cout << "Error" << std::endl;
}