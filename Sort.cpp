//
// Created by 李唐 on 2024/1/10.
//
#include <iostream>
#include <vector>
using namespace std;

class SortType{
public:
    vector<int>Data;
    void InitData(){
        Data.push_back(6);
        Data.push_back(3);
        Data.push_back(8);
        Data.push_back(2);
        Data.push_back(5);
        Data.push_back(9);
        Data.push_back(4);
        Data.push_back(5);
        Data.push_back(1);
        Data.push_back(7);
    }
    SortType(){
        InitData();
    }
};
class QuickSortType: SortType{
public:
    QuickSortType():SortType(){}
    int QuickPartition(int loIndex  ,int hiIndex){
        int Pivot = Data[loIndex];
//        loIndex = 0;
//        hiIndex = Data.size()-1;
        while(loIndex < hiIndex)
        {
            while(loIndex < hiIndex && Data[hiIndex] >= Pivot) hiIndex--;
            Data[loIndex] = Data[hiIndex];
            while(loIndex < hiIndex && Data[loIndex] <= Pivot) loIndex++;
            Data[hiIndex] = Data[loIndex];
        }
        Data[loIndex] = Pivot;
        return loIndex;
    }
    void QuickSort(int fromIndex, int toIndex){
        if(toIndex - fromIndex < 2) return;
        int Pa = QuickPartition(fromIndex,toIndex);
//        if(fromIndex >= toIndex || Pa == fromIndex || Pa == toIndex) return;
        QuickSort(fromIndex,Pa-1);
        QuickSort(Pa+1,toIndex);
    }
    void QuickSort(){
        QuickSort(0,Data.size()-1);
    }
};

int main(){
    QuickSortType Sort = QuickSortType();
//    Sort.QuickPartition(0);
    Sort.QuickSort();


}