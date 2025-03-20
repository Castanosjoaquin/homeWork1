#include <iostream>
#include <cstring> 
#include <chrono>

using namespace std; 

consteval bool are_equal(const char* txt1, const char* txt2);

bool are_equal(char* txt1,  char* txt2); 

void check_comparation_time(auto txt1,auto txt2);

bool are_equal(string txt1, string txt2); 