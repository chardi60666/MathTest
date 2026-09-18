#include <gtest/gtest.h>

#include "../Lib/Task.h"

TEST(TaskTest, DefaultConstructorCreatesValidTask)
{
    Task task;

    EXPECT_TRUE(
        task.operation == '+' ||
        task.operation == '-' ||
        task.operation == '*' ||
        task.operation == '/'
    );

    if (task.operation == '+')
    {
        EXPECT_EQ(task.answer, task.num_1 + task.num_2);
    }

    if (task.operation == '-')
    {
        EXPECT_EQ(task.answer, task.num_1 - task.num_2);
    }

    if (task.operation == '*')
    {
        EXPECT_EQ(task.answer, task.num_1 * task.num_2);
    }

    if (task.operation == '/')
    {
        EXPECT_NE(task.num_2, 0);
        EXPECT_EQ(task.answer, task.num_1 / task.num_2);
    }
}


TEST(TaskTest, ConstructorWithOperation)
{
    Task task(10, 20, '+');

    EXPECT_GE(task.num_1, 10);
    EXPECT_LE(task.num_1, 20);

    EXPECT_GE(task.num_2, 10);
    EXPECT_LE(task.num_2, 20);

    EXPECT_EQ(task.operation, '+');
    EXPECT_EQ(task.answer, task.num_1 + task.num_2);
}


TEST(TaskTest, ConstructorWithSubtraction)
{
    Task task(1, 20, '-');

    EXPECT_GE(task.num_1, 1);
    EXPECT_LE(task.num_1, 20);

    EXPECT_GE(task.num_2, 1);
    EXPECT_LE(task.num_2, 20);

    EXPECT_EQ(task.operation, '-');
    EXPECT_EQ(task.answer, task.num_1 - task.num_2);
}


TEST(TaskTest, ConstructorWithMultiplication)
{
    Task task(1, 10, '*');

    EXPECT_EQ(task.operation, '*');
    EXPECT_EQ(task.answer, task.num_1 * task.num_2);
}


TEST(TaskTest, ConstructorWithDivision)
{
    Task task(1, 10, '/');

    EXPECT_EQ(task.operation, '/');
    EXPECT_NE(task.num_2, 0);
    EXPECT_EQ(task.answer, task.num_1 / task.num_2);
}