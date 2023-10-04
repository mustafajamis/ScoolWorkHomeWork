/*
 * Mustafa, Jamshidi (T686B548)
 * lap2
 */
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSet(const std::vector<int>& vec) {
    for(size_t i = 0; i < vec.size(); ++i) {
        if(std::find(vec.begin() + i + 1, vec.end(), vec[i]) != vec.end()) {
            return false;  // Found a duplicate element
        }
    }
    return true;  // No duplicates found
}

//Set Union func
vector<int> setUnion(vector<int>vec1, vector<int>vec2){
    for( int i = 0; i<vec2.size(); i++){
        if(vec1.end() == find(vec1.begin(), vec1.end(), vec2[i])){
            vec1.push_back(vec2[i]);
        }
    }
    return vec1;
}

vector<int> setIntersection(vector<int>vec1, vector<int>vec2){
    vector<int>storage;
    for( int i = 0; i<vec2.size(); i++){
        if(vec1.end() != find(vec1.begin(), vec1.end(), vec2[i])){
            storage.push_back(vec2[i]);
        }
    }
    return storage;
}
vector<int> setDifference(vector<int>vec1, vector<int>vec2){
    vector<int>storage;
    for( int i = 0; i<vec2.size(); i++){
        if(vec2.end() == find(vec2.begin(), vec2.end(), vec1[i])){
            storage.push_back(vec1[i]);
        }
    }
    return storage;
}


int main() {
    std::vector<int> set1 = {1, 2, 3, 4};
    std::vector<int> set2 = {2, 4, 5, 6};


    if(isSet(set1)){
        cout<<"is a set";
    } else {
        cout<<"not a set";
    }
cout<<endl;

    vector<int> vecUnion;
    vecUnion = setUnion(set1, set2);
    for(int i = 0; i <vecUnion.size();i++){
        cout<<vecUnion[i]<<" ";
    }
cout<<endl;
    vector<int> vecIntersection;
    vecIntersection = setIntersection(set1, set2);
    for(int i = 0; i <vecIntersection.size();i++){
        cout<<vecIntersection[i]<<" ";
    }
cout<<endl;
    vector<int> vecDifference;
    vecDifference = setDifference(set1, set2);
    for(int i = 0; i <vecDifference.size();i++){
        cout<<vecDifference[i]<<" ";
    }
cout<<endl;

    vector<int> vecDifference2;
    vecDifference2 = setDifference(set2, set1);
    for(int i = 0; i <vecDifference2.size();i++){
        cout<<vecDifference2[i]<<" ";
    }
}

