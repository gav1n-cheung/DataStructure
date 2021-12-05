//
// Created by cheung on 11/26/21.
//

#ifndef CLASS1_STUDENT_H
#define CLASS1_STUDENT_H
#include <iostream>
#include <string>
using namespace std;
struct Student{
    string name;
    int score;
    bool operator<(const Student &otherStudent){
        return this->score!=otherStudent.score ? this->score<otherStudent.score: this->name<otherStudent.name;
    }
    friend ostream& operator<<(ostream &os,const Student &student){
        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }
};


#endif //CLASS1_STUDENT_H
