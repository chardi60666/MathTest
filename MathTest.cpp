#include "MathTest.h"
#include <iostream>
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
bool MathTest::check_answer(int index, int user_answer)
{
    user_answers[index] = user_answer;

    if (user_answer == tasks[index].answer)
    {
        correct_count++;
        return true;
    }

    return false;
}
int MathTest::get_correct_answer(int index) const
{
    return tasks[index].answer;
}
void MathTest::run()
{
    for (int i = 0; i < count; i++)
    {
        std::cout << "Question " << i + 1 << ": "
                  << tasks[i].num_1 << " "
                  << tasks[i].operation << " "
                  << tasks[i].num_2
                  << " = ";

        int user_answer;
        std::cin >> user_answer;

        check_answer(i, user_answer);
    }
}