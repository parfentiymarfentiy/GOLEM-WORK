#pragma once
#include "Library.h"

class Question
{
    string question;
    vector<string> answers;
    string right_answer;
public:
    Question();
    string get_question() const { return this->question; }
    string get_right_answer() const { return this->right_answer; }
    void show_question() const {
        cout << this->question << endl;
        for (int i = 0; i < answers.size(); i++) {
            cout << answers[i] << endl;
        }
    }
};