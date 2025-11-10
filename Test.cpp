#include "Test.h"

Test::Test()
{
    cout << "Write name of test: ";
    getline(cin, this->name_of_test);

    cout << "Write count of questions: ";
    cin >> this->count_of_question;
    cin.ignore();

    for (int i = 0; i < this->count_of_question; i++) {
        cout << "\nQuestion " << (i + 1) << ":" << endl;
        Question q;
        this->questions.push_back(q);
        this->right_answers.push_back(q.get_right_answer());
    }
}

void Test::show_test_details() const {
    cout << "Test: " << name_of_test << endl;
    cout << "Number of questions: " << count_of_question << endl;
}