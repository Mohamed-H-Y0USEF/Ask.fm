#include "askFmSys.h"
#include <iostream>
#include <fstream>
#include <sstream>


systemAsk::systemAsk() {
    logedIn = false;
    load();
}
void systemAsk::run() {
    while (true) {
        int choice = menu();
        switch (choice) {
            case 10:
                logIn();
                break;
            case 20:
                singUp();
                break;
            case 1:
                printQtoMe();
                break;
            case 2:
                printQfromMe();
                break;
            case 3:
               ansQuestion();
                break;
            case 4:
                delQuestion();
                break;
            case 5:
                askQuestion();
                break;
            case 6:
                listUsers();
                break;
            case 7:
                feed();
                break;
            case 8:
                logedIn = false;
                break;
        }
    }
}
int systemAsk::menu() {
        int choice = -1;
        if(!logedIn) {
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
    bool found = false;
    int cnt = 3;
    while(!found && cnt--){
       cout<<"Enter userName and passWord : ";
        string Name , pass;cin>>Name>>pass;
        for(auto it : systemUsers){
            if(it.second.name == Name && it.second.passWord == pass){
                logedIn = true;
                curUser = it.second;
                found = true;
                return;
            }
        }
        if(!found) cout<<"ERROR : invlaid pass word or user name... try again "<<endl;
    }
}

int systemAsk::getID(string name , string password) {
    int x = 0;
    for(auto it : name) x += it;
    for(auto it : password ) x+=it;
    return x;
}

void systemAsk::upDate() {
    // run in ans , del , editAns
    /*
        ID FromID ToID isAns parentID
        question Text
        answer Text
     */
    fstream QFile("Questions.txt" , ios::out);
    if(QFile.fail()){
        cout<<"ERROR : can't open file questions file"<<endl;
        exit(0);
    }
    for(auto & it : questions){
        Question Q = it.second;
        QFile<<Q.ID<<' ' << Q.FromID << ' ' << Q.toID << ' ' << Q.isAnswred << ' ' << Q.parentID<<endl;
        QFile<<Q.questionText<<endl;
        QFile<<Q.answerText<<endl;
    }
    QFile.close();
}

void systemAsk::load() {

    fstream UFile("usersInfo.txt" , ios :: in);
    if(UFile.fail()){
        cout<<"ERROR : can't open file users file"<<endl;
        exit(0);
    }

    //ID name password allowAnonQuest
    User temp;
    while(UFile>>temp.ID>>temp.name>>temp.passWord>>temp.allowAnon){
        systemUsers[temp.ID] = temp;
    }
    UFile.close();




    fstream QFile("Questions.txt" , ios::in);
    if(QFile.fail()){
        cout<<"ERROR : can't open file questions file"<<endl;
        exit(0);
    }
    string l1 , l2 , l3;
    while(getline(QFile , l1) , getline(QFile , l2) , getline(QFile , l3)){
        Question Q;
        stringstream iDs (l1);
        iDs>>Q.ID>>Q.FromID>>Q.toID>>Q.isAnswred>>Q.parentID;
        Q.questionText = l2;
        Q.answerText = l3;
        systemUsers[Q.FromID].questionsFromMe.emplace_back(Q.ID);
        systemUsers[Q.toID].questionsToMe.emplace_back(Q.ID);
        if(Q.parentID != -1){
            questions[Q.parentID].threads.emplace_back(Q.ID);
        }
        questions[Q.ID] = Q;


    }
    QFile.close();

}

void systemAsk::singUp() {
    User newUser;
    newUser.read();
    systemUsers[newUser.ID] = newUser;
    fstream UserFile("usersInfo.txt" , ios :: app | ios :: out);
    if(UserFile.fail()){
        cout<<"ERROR : can't open file users info "<<endl;
    }
    UserFile<<newUser.ID<<' ' <<newUser.name<<' '<<newUser.passWord<<' '<<newUser.allowAnon<<endl;
    UserFile.close();
}

void systemAsk::feed() {
   for(auto [it , Q]: questions){
        if(Q.parentID == -1)
           Q.print(questions);

        cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
   }
}

void systemAsk::listUsers() {
    for(auto [id , user] : systemUsers){
        cout<<"ID : " << id<<'\t'<<user.name<<endl;
    }
}

void systemAsk::askQuestion() {
    cout<<"Enter user ID or -1 to cancel : ";
    int id;cin>>id;

    if(~id){
        if(!systemUsers[id].allowAnon){
            cout<<"Note : Anonymous questions are not allowed for this user ."<<endl;
        }
        cout<<"For thread question : Enter question ID or -1 for new question : ";
        int QID; cin>>QID; //question id for thread question
        cout<<"Enter Question text : ";
        string txt;
        cin.ignore();
        getline(cin , txt);
        Question quest(curUser.ID , id , QID , txt);

        if(QID != -1)
            questions[QID].threads.emplace_back(quest.ID);

        questions[quest.ID] = quest;
        systemUsers[curUser.ID].questionsFromMe.push_back(quest.ID);
        systemUsers[id].questionsToMe.push_back(quest.ID);


        fstream QFile("Questions.txt" , ios::out | ios::app);
        if(QFile.fail()){
            cout<<"ERROR : can't open file questions file"<<endl;
            exit(0);
        }
            Question Q = quest;
            QFile<<Q.ID<<' ' << Q.FromID << ' ' << Q.toID << ' ' << Q.isAnswred << ' ' << Q.parentID<<endl;
            QFile<<Q.questionText<<endl;
            QFile<<Q.answerText<<endl;

        QFile.close();
    }
}

void systemAsk::printQtoMe() {
    for(auto it : curUser.questionsToMe){
        Question Q = questions[it];
        cout<<"Question ID : " << Q.ID <<" from user ID("<<Q.FromID<<")"<<endl;
        cout<<"Question : " << Q.questionText<<endl;
        cout<<"Answer : "<<Q.answerText<<endl;
    }
}

void systemAsk::printQfromMe() {
    for(auto it : curUser.questionsFromMe){
        Question Q = questions[it];
        cout<<"Question ID : " << Q.ID <<" to user ID("<<Q.toID<<")"<<endl;
        cout<<"Question : " << Q.questionText<<endl;
        cout<<"Answer : "<<Q.answerText<<endl;
    }
}

void systemAsk::ansQuestion() {
    int questionID;
    cout<<"Enter Question ID or -1 to cancel : ";
    cin>>questionID;
    Question &Q =questions[questionID];
    Q.print(questions);
    if(Q.isAnswred)
        cout<<"Warning : Already answered. Answer will be updated ."<<endl;
    cin.ignore();
    string ans;
    cout<<"Enter Answer : ";
    getline(cin , ans);
    Q.answerText = ans;
    Q.isAnswred = true;
    upDate();
}

void systemAsk::delQuestion() {
    int Qid;
    cout<<"Enter question ID or -1 to cancel : ";
    cin>>Qid;
    if(questions[Qid].FromID != curUser.ID){
        cout<<"Warning : you can't remove questions not for you"<<endl;
        return;
    }
    for(auto it : questions[Qid].threads){
        questions.erase(it);
    }
    questions.erase(Qid);
    upDate();
}












