#include "Lap3.h"
#include <iostream>
using namespace std;

int main(){
    Vector<int> myVector(4);

    myVector.push_back(30);
    myVector.push_back(40);

    for(int i = 0; i< myVector.size(); i++){
        cout<<myVector[i]<<" ";
    }
    cout<<endl;
}

