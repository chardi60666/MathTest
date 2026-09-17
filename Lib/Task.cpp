#include "Task.h"

#include <random>

namespace
{
    int randomInt(int min, int max)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());

        std::uniform_int_distribution<int> dist(min, max);

        return dist(gen);
    }

    char randomOperation()
    {
        const char operations[] = {'+', '-', '*', '/'};

        return operations[randomInt(0, 3)];
    }
}

Task::Task()
{
    operation = randomOperation();

    if (operation == '/')
    {
        num_2 = randomInt(1, 10);
        num_1 = num_2 * randomInt(1, 10);
    }
    else
    {
        num_1 = randomInt(1, 100);
        num_2 = randomInt(1, 100);
    }

    switch (operation)
    {
        case '+':
            answer = num_1 + num_2;
            break;

        case '-':
            answer = num_1 - num_2;
            break;

        case '*':
            answer = num_1 * num_2;
            break;

        case '/':
            answer = num_1 / num_2;
            break;
    }
}

Task::Task(int min, int max, char operation)
{
    num_1 = randomInt(min, max);
    num_2 = randomInt(min, max);

    if (operation == '\0')
    {
        this->operation = randomOperation();
    }
    else
    {
        this->operation = operation;
    }

    if (this->operation == '/')
    {
        num_2 = randomInt(1, max);

        if (num_2 < min)
        {
            num_2 = min;
        }

        num_1 = num_2 * randomInt(1, max / num_2);
    }

    switch (this->operation)
    {
        case '+':
            answer = num_1 + num_2;
            break;

        case '-':
            answer = num_1 - num_2;
            break;

        case '*':
            answer = num_1 * num_2;
            break;

        case '/':
            answer = num_1 / num_2;
            break;
    }
}