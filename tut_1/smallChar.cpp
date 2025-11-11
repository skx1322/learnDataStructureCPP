#include <cstring>
#include <iostream>

using namespace std;

string word_wisdom[] = "Test";
string word_des[20];

void findCOn(){
    strcpy(word_des, word_wisdom);
    cout<< word_des << endl;
}

int main(){
    // cout<<"Enter Word: ";
    // cin>>word_wisdom;

    findCOn();

    return 0;
};
