#ifndef TASK_H
#define TASK_H

struct Task
{
    int num_1;
    int num_2;
    char operation;
    int answer;

    Task();

    Task(int min, int max, char operation = '\0');
};

class MathTest;

#endif