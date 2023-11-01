#include "askFmSys.h"
void User::read() {
    cout << "Enter user name  (no space) : ";
    cin >> this->name;
    cout << "Enter passWord : ";
    cin >> this->passWord;
    cout << "Allow anonymous questions? (0 or 1) : ";
    cin >> this->allowAnon;
    this->ID = systemAsk::getID(this->name, this->passWord);
}