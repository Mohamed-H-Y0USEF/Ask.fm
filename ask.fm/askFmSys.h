#include <iostream>
#include <fstream>
#include "question.h"
#include "user.h"
#include <cstdlib>
#include <time.h>

using namespace std;
struct systemAsk{
    bool logIN;
    string user;
    systemAsk();
    void run();
    int menu();
    void logIn();
    bool valid(string , string);
    void SignUP();
    int getID();
};