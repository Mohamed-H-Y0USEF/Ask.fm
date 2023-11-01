#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

struct Question{
    int ID , FromID , toID , parentID;

    vector<int>threads;
    bool isAnswred;
    string questionText , answerText;
    Question();
    Question(int , int , int  , string);
    void print(map<int,Question> & mp);
    void genID();
};
