#include "Admin.h"

void Admin::create_test()
{
    Test t;
    this->tests.push_back(t);
    cout << "Test created successfully!\n";
}

void Admin::show_tests()
{
    if (tests.empty()) {
        cout << "No tests available.\n";
        return;
    }

    for (int i = 0; i < this->tests.size(); i++) {
        cout << i << ") " << this->tests[i].get_name_of_test() << endl;
    }
}

void Admin::delete_test()
{
    if (tests.empty()) {
        cout << "No tests to delete.\n";
        return;
    }

    show_tests();
    int index = 0;
    cout << "Write index: ";
    cin >> index;
    cin.ignore();

    if (index >= 0 && index < tests.size()) {
        tests.erase(tests.begin() + index);
        cout << "Test deleted successfully!\n";
    }
    else {
        cout << "Invalid index!\n";
    }
}

void Admin::start_test()
{
    if (tests.empty()) {
        cout << "No tests available.\n";
        return;
    }

    show_tests();
    cout << "Write index: ";
    int index_of_test;
    cin >> index_of_test;
    cin.ignore();

    if (index_of_test < 0 || index_of_test >= tests.size()) {
        cout << "Invalid test index!\n";
        return;
    }

    vector<string> user_answers;
    vector<Question> questions = tests[index_of_test].get_questions();

    cout << "\nStarting test: " << tests[index_of_test].get_name_of_test() << endl;
    cout << "Number of questions: " << questions.size() << "\n\n";

    for (int i = 0; i < questions.size(); i++) {
        cout << "Question " << (i + 1) << ":\n";
        questions[i].show_question();
        cout << "Your answer (a/b/c/d): ";
        string answer;
        getline(cin, answer);
        user_answers.push_back(answer);
        cout << endl;
    }

    vector<string> correct_answers = tests[index_of_test].get_right_answers();
    int correct_count = 0;

    cout << "Results:\n";
    for (int i = 0; i < correct_answers.size(); i++) {
        cout << "Question " << (i + 1) << ": ";
        cout << "Your answer: " << user_answers[i];
        cout << " | Correct answer: " << correct_answers[i] << endl;

        if (user_answers[i] == correct_answers[i]) {
            correct_count++;
        }
    }

    cout << "\nFinal Results:\n";
    cout << "Correct answers: " << correct_count << endl;
    cout << "Wrong answers: " << (questions.size() - correct_count) << endl;
    cout << "Score: " << correct_count << "/" << questions.size() << endl;
}