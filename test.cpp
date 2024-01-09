//
// Created by 李唐 on 2024/1/9.
//
#include <iostream>
#include "vector"
using namespace std;
int main(){
    vector<vector<int>> test;
//    test[0][0] = 1;
    vector<int>b;
    b.push_back(9);
//    b[0]=9;
    test.insert(test.begin(),b);
}