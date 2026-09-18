#include <gtest/gtest.h>
#include "../MathTest.h"

TEST(MathTestTest, CorrectAnswerIsAccepted)
{
    MathTest test(1, 1, 10, '+');
    int correct_answer = test.get_correct_answer(0); // Если такого метода нет — замените
    EXPECT_TRUE(test.check_answer(0, correct_answer));
}

TEST(MathTestTest, WrongAnswerIsRejected)
{
    MathTest test(1, 1, 10, '+');
    int correct_answer = test.get_correct_answer(0);
    EXPECT_FALSE(test.check_answer(0, correct_answer + 1));
}