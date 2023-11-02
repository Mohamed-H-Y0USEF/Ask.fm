#include "askFmSys.h"
#include <regex>
void User::read() {
    cout << "Enter user name  (no space , start without number) : ";
    std::regex userName("[a-zA-Z]+\\w*");
    cin >> this->name;
    while(!regex_match(this->name , userName)){
        cout<<"ERROR : invalid userName try again .."<<endl;
        cout << "Enter user name  (no space , start without number) : ";
        cin>>this->name;
    }
    cout << "Enter passWord : ";
    cin >> this->passWord;
    cout << "Allow anonymous questions? (0 or 1) : ";
    cin >> this->allowAnon;
    this->ID = systemAsk::getID(this->name, this->passWord);
}