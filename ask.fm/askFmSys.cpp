#include "askFmSys.h"
systemAsk::systemAsk() {
    logIN = false;
}
void systemAsk::run() {
    int choice = menu();
    switch (choice) {
        case 10:
            //log in
            break;
        case 20:
            //sign up
            break;
        case 1:
            //print QeusTo Me
            break;
        case 2:
            //print ques From Me
            break;
        case 3:
            // ans quest
            break;
        case 4:
            // del quest
            break;
        case 5:
            // ask quest
            break;
        case 6:
            //list user
            break;
        case 7:
            //feed;
            break;
        case 8:
            //logout
            break;
    }
}
int systemAsk::menu() {
        int choice = -1;
        if(!logIN) {
            while (choice != 1 && choice != 2) {
                cout << "Menu: " << endl;
                cout << '\t' << "1: Log in ." << endl;
                cout << '\t' << "2: Sign up ." << endl;
                cout<<"Enter number in range 1 - 2 : ";
                cin >> choice;
                if (choice != 1 && choice != 2)
                    cout << "Please Enter a valid choice ."<<endl<<endl;
            }
            return (choice == 1 ? 10 : 20);
        }else{
            while (choice == -1 ) {
                cout << "Menu: " << endl;
                cout << '\t' << "1: Print Questions To Me ." << endl;
                cout << '\t' << "2: Print Questions From Me ." << endl;
                cout << '\t' << "3: Answer Question ." << endl;
                cout << '\t' << "4: Delete Question ." << endl;
                cout << '\t' << "5: Ask Question ." << endl;
                cout << '\t' << "6: List System Users ." << endl;
                cout << '\t' << "7: Feed ." << endl;
                cout << '\t' << "8: Logout ." << endl;

                cout<<"Enter number in range 1 - 8 : ";
                cin >> choice;
                if (choice < 1 || choice > 8) {
                    cout << "ERROR : invalid number...Try again" << endl<<endl;
                    choice = -1;
                }
            }
            return choice;
        }


}




