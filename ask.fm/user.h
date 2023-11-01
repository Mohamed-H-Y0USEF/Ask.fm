#include <string>
#include <vector>
#include <iostream>
using namespace std;
struct User{
    string name , passWord;
    int ID;
    bool allowAnon;
    vector<int>questionsFromMe , questionsToMe;
    void read();
};