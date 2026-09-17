#ifndef MATHTEST_H
#define MATHTEST_H

#include "Lib/Task.h"

class MathTest
{
private:
    Task* tasks;
    int count;
    int* user_answers;
    int correct_count;

public:
    MathTest(int count);
    MathTest(int count, int min, int max, char operation = '\0');
    ~MathTest();
    void run();
    bool check_answer(int index, int user_answer);
    int get_correct_answer(int index) const;
    void show_statistics() const;
};

#endif