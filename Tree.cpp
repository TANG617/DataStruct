//
// Created by 李唐 on 2024/1/8.
//
#include <iostream>
#include "queue"
template<typename DataType>
class ParentNodeType{
    DataType Data;
    ParentNodeType *parentNode;
};

template<typename DataType>
class ChildNodeType{
    DataType Data;
    ChildNodeType *parentNode;
};

template<typename DataType>
class CSNodeType{
    DataType Data;
    CSNodeType *parentNode;
};