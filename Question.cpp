#include "Question.h"

Question::Question()
{
    cout << "Write question: ";
    getline(cin, this->question);

    cout << "Write 4 answers:" << endl;
    for (int i = 0; i < 4; i++) {
        string answer;

        cout << char('a' + i) << ") ";
        getline(cin, answer);

        answer = string(1, char('a' + i)) + ") " + answer;
        this->answers.push_back(answer);
    }

    cout << "Write letter of right answer: ";
    getline(cin, this->right_answer);
}