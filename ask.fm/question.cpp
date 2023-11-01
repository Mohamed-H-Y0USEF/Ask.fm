#include "question.h"
Question::Question(): parentID(-1) , isAnswred(0) {
}


void Question::genID() {
    ID = FromID + toID;
    int n = (int)questionText.size();
    for(int i = 0 ; i < n ; i++)
        ID += (questionText[i])*i;
}

void Question::print(map<int,Question> & mp) {
    cout<<"Question ID : " << ID <<" from user ID("<<this->FromID<<") to user ID("<<this->toID<<")"<<endl;
    cout<<"Question : " << this->questionText<<endl;
    cout<<"Answer : "<<this->answerText<<endl;
    for(auto Q : this->threads){
        Question QQ = mp[Q];
        cout<<"\t Thread : Question ID("<< QQ.ID <<") from user ID("<<this->FromID<<") to user ID("<<this->toID<<")"<<endl;
        cout<<"\t Question : " << QQ.questionText<<endl;
        cout<<"\t Answer : " << QQ.answerText<<endl;
    }
}

Question::Question(int From , int to , int parent, string Q) :
FromID(From) , toID(to) , parentID(parent) , questionText(Q) , isAnswred(0) {
    genID();
}


