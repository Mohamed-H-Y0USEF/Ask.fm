#include "askFmSys.h"

systemAsk::systemAsk() {
    logIN = false;
}
void systemAsk::run() {
    while (true) {
        int choice = menu();
        switch (choice) {
            case 10:
                logIn();
                break;
            case 20:
                cout << "sing up" << endl;
                break;
            case 1:
                cout << "print QeusTo Me" << endl;
                break;
            case 2:
                cout << "print ques From Me" << endl;
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
                logIN = 0;
                break;
        }
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

void systemAsk::logIn() {
    string userName , passWord;
    cout<<"Enter user name & password : ";
    cin>>userName>>passWord;
    int cnt = 3;
    // helper function to validate userName and password from file users
    while(!valid(userName , passWord)){
        if(!cnt){
            cout<<"try again later ... "<<endl<<endl;
            exit(10);
        }
        cout<<"ERROR : invalid user name or password... try again. (have " <<cnt<<" try)"<<endl<<endl;
        cout<<"Enter user name & password : ";
        cin>>userName>>passWord;
        cnt--;
    }
    cout<<"Welcome " << userName<<endl;
    run();

}

bool systemAsk::valid(string userName, string passWord) {
    ifstream userFile("usersInfo.txt");
    if(userFile.fail()){
        cout<<"ERROR can't open file usersInfo"<<endl;
        exit(10);
    }
    string line;
    while(getline(userFile , line)){
        string un , pw;
        ///3ali5momod
        un = line.substr(1 , line[0] - '0');
        int pos = (line[0]) - '0' + 1;
        int len = line[pos] - '0';
        pw = line.substr(pos+1,len);
        if(un == userName && passWord == pw){
            logIN = true;
            user = userName;
            userFile.close();
            return true;
        }
    }
    userFile.close();
    return false;
}




