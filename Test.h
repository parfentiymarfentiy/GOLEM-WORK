#pragma once
#include "Library.h"
#include "Question.h"

class Test
{
    string name_of_test;
    int count_of_question;
    vector<string> right_answers;
    vector<Question> questions;
public:
    Test();
    string get_name_of_test() const { return this->name_of_test; }
    vector<string> get_right_answers() const { return this->right_answers; }
    vector<Question> get_questions() const { return this->questions; }
    void show_test_details() const;
};