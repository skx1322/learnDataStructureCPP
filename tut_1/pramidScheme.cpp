#include <iostream>
using namespace std;

int height;

void generatePyramid(int h){
    int j;
    for(int i = 1, k = 0; i <= h; i++, k = 0){
        // for first loop cycle, initialize k which are used to determine spacing or not
        for(j = 1 ; j <= h-i; j++){
            cout<<"  ";
        } // height - i, so first cycle it'll be 5 - 2, 3 so space 3 times
        while(k != 2*i-1){ // if k is not equal to 2 time cycle - 1, for first cycle, it'll be 2*2-1 = 2, so 0 != 2, true, print 4 times until k = 4 != 0
            cout<<"* ";
            k++;
        };
        cout<<endl;
    }
}

int main(){
    cout<<"Enter height: ";
    cin>>height;

    cout<<endl;

    if (height <= 0){
        return 0;
    };

    generatePyramid(height);
    
    return 0;
};
