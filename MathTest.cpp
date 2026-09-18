#include "MathTest.h"
#include <iostream>
#include <iomanip>
#include <string>

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

char MathTest::get_mark() const
{
    if (count == 0) return 'F';
    double percent = static_cast<double>(correct_count) / count * 100.0;
    if (percent >= 80.0) return 'A';
    if (percent >= 60.0) return 'B';
    if (percent >= 40.0) return 'C';
    if (percent >= 20.0) return 'D';
    return 'F';
}

void MathTest::show_statistics() const
{
    // Заголовок (No)
    std::cout << "| " << std::setw(15) << "No" << " |";
    for (int i = 0; i < count; ++i) {
        std::cout << std::setw(5) << (i + 1) << " |";
    }
    std::cout << "\n+-----------------" << std::string(count * 8, '-') << "+\n";

    // Строка вопросов
    std::cout << "| " << std::setw(15) << "Question" << " |";
    for (int i = 0; i < count; ++i) {
        std::string q = std::to_string(tasks[i].num_1) + " " + tasks[i].operation + " " + std::to_string(tasks[i].num_2);
        std::cout << std::setw(7) << q << " |";
    }
    std::cout << "\n";

    // Правильные ответы
    std::cout << "| " << std::setw(15) << "True Answer" << " |";
    for (int i = 0; i < count; ++i) {
        std::cout << std::setw(7) << tasks[i].answer << " |";
    }
    std::cout << "\n";

    // Ответы пользователя
    std::cout << "| " << std::setw(15) << "Your Answer" << " |";
    for (int i = 0; i < count; ++i) {
        std::cout << std::setw(7) << user_answers[i] << " |";
    }
    std::cout << "\n";

    // Результаты (+ / -)
    std::cout << "| " << std::setw(15) << "Result" << " |";
    for (int i = 0; i < count; ++i) {
        char res = (user_answers[i] == tasks[i].answer) ? '+' : '-';
        std::cout << std::setw(7) << res << " |";
    }
    std::cout << "\n\n";

    // Итоговый счет и оценка
    std::cout << "Total Result: " << correct_count << " / " << count
              << " (mark: " << get_mark() << ")\n";
}