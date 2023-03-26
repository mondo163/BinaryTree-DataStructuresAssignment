/***********************************************************
* This is the node object that the tree structure is made of.
* It contains the plant associated with it and the children
* below it. 
************************************************************/

#ifndef TREESTRUCT_H
#define TREESTRUCT_H
    
#include "plant.h"
using namespace std;

struct treenode{
    plant    data;
    treenode *left;
    treenode *right;

    treenode():left(NULL), right(NULL){}
    treenode(const plant &aData):left(NULL), right(NULL){
        data = aData;
    }
};

#endif
