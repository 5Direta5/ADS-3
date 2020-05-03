#include "tstack.h"
#include <string>
#include <utility>

int torn(const char& simb) {
    std::pair<char, int> priority[6];
    priority[0].first = '('; priority[0].second = 0;
    priority[1].first = ')'; priority[1].second = 1;
    priority[2].first = '+'; priority[2].second = 2;
    priority[3].first = '-'; priority[3].second = 2;
    priority[4].first = '*'; priority[4].second = 3;
    priority[5].first = '/'; priority[5].second = 3;
    int x = -1;
        for (int j = 0; j < 6; ++j)
            if (simb == priority[j].first)
            {
              x = priority[j].second;
              break;
            }
    return x;
}

std::string infx2pstfx(std::string inf)
{
    std::string work;
    TStack<char> stack;
    for (auto &simb : inf) {
        int x = torn(simb);
        if (x == -1)
            work += simb;
        else
            if (stack.get() < x || x == 0 || stack.isEmpty())
                stack.push(simb);
            else if (simb == ')')
            {
                char y = stack.get();
                    while (torn(y) >= x)
                    {
                        work += y;
                        stack.pop();
                        y = stack.get();
                    }
                stack.pop();
            }
            else
            {
                char y = stack.get();
                    while (torn(y) >= x)
                    {
                        work += y;
                        stack.pop();
                        y = stack.get();
                    }
                stack.push(simb);
            }

    }
    while (!stack.isEmpty())
    {
        rake += stack.get();
        stack.pop();
    }
    return rake;
}

int eval(std::string pst)
int counter(const int& a, const int& b , const char& el)
{
    switch (el)
    {
        default:
        break;
    case '+':return a + b;
    case '-':return a - b;
    case '*':return a * b;
    case '/':return a / b;
    }
}


int eval(std::string pst)
{
    int summ{ 0 };
    TStack<int> stack;
    for (auto& el : pst)
    {
        if (torn(el) == -1)
        {
            char k[2];
            k[0] = el;
            k[1] = '\0';
            int r = atoi(k);
            stack.push(r);
        }
        else
        {
            int b = stack.get();
            stack.pop();
            int a = stack.get();
            stack.pop();
            stack.push(counter(a, b, el));
        }
    }
    return stack.get();
}
