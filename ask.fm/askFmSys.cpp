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
                SignUP();
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
                AskQuestion();
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
    string name , pass ;
    int id;
    bool status;
    while(userFile>>name>>pass>>id>>status){
        if(userName == name && passWord == pass){
            logIN = true;
            user = name;
            curID = id;
            userFile.close();
            return true;
        }
    }
    userFile.close();
    return false;
}

void systemAsk::SignUP() {

    cout<<endl<<endl;
    string userName , passWord ;
    bool anonoQues;
    cout<<"Enter user name. (No spaces):";
        cin>>userName;
    cout<<"Enter password : " ;
        cin>>passWord;
    cout<<"Allow anonymous questions?: (0 or 1) : ";
        cin>>anonoQues;

    auto mode = ios::out | ios::app;

    fstream userFile("usersInfo.txt" , mode);
    if(userFile.fail()){
        cout<<"ERROR can't open file usersInfo"<<endl;
        exit(20);
    }
    userFile<<userName<<' ' << passWord<<' ' <<getID()<<' ' << anonoQues<<endl;
    userFile.close();
}

int systemAsk::getID() {
    srand(time(0));
    return rand()%1001;
}

void systemAsk::AskQuestion() {
    cout<<"Enter id or -1 to cancel : ";
    int userID;cin>>userID;
    if(!allowAnonQuest(userID)){
        cout<<"Note: Anonymous questions are not allowed for this user "<<endl;
    }
    cout<<"For thread question: Enter Question id or -1 for new question : ";
    int type;cin>>type;
    if(type == -1){
        string text;
        cout<<"Enter question test : ";
        cin.ignore();
        getline(cin , text);

        fstream questFile("Questions.txt" , ios::out | ios::app);
        questFile<<curID<<' '<<userID<<' '<< 0 << ' ' << text<<endl;
        questFile.close();
    }else{
        // thead questions
    }
}

bool systemAsk::allowAnonQuest(int id) {
    ifstream users("usersInfo.txt");
    string name;
    int pass , userId , isAnon ;
    while(users>>name>>pass>>userId>>isAnon){
        if(userId == id)
            return isAnon;
    }
    return false;
}






