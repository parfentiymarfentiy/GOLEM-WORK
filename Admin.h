#pragma once
#pragma once
#include "Library.h"
#include "Test.h"

class Admin
{
    vector<Test> tests;
public:
    void create_test();
    void show_tests();
    void delete_test();
    void start_test();
    bool has_tests() const { return !tests.empty(); }
};