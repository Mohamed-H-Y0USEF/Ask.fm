#include "user.h"
#include "question.h"
#include <map>
using namespace std;
struct systemAsk{
    User curUser;
    bool logedIn;
    map<int , User>systemUsers;
    map<int , Question>questions;

    systemAsk();

    void run();
    int menu();


    void load();
    void logIn();
    void singUp();


    void askQuestion();
    void ansQuestion();
    void printQtoMe();
    void printQfromMe();
    void delQuestion();
    void feed();
    void listUsers();



    //helper functions
    void upDate();
    static int getID(string , string);

};