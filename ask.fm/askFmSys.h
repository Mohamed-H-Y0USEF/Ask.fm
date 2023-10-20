#include <iostream>
#include <fstream>
#include "question.h"
#include "user.h"

using namespace std;
struct systemAsk{
    bool logIN;
    string user;
    systemAsk();
    void run();
    int menu();
    void logIn();
    bool valid(string , string);
};