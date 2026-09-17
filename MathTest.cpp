#include "MathTest.h"

MathTest::MathTest(int count)
{
    this->count = count;
    correct_count = 0;

    tasks = new Task[count];
    user_answers = new int[count];
}

MathTest::MathTest(int count, int min, int max, char operation)
{
    this->count = count;
    correct_count = 0;

    tasks = new Task[count];
    user_answers = new int[count];

    for (int i = 0; i < count; i++)
    {
        tasks[i] = Task(min, max, operation);
    }
}

MathTest::~MathTest()
{
    delete[] tasks;
    delete[] user_answers;
}