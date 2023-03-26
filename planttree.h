/*********************************************************
* The plant tree that will hold the plants within a binary
* tree structure. It has all of the responsibilities
* of organizing, populating, and finding the data within
* the structure
**********************************************************/

#ifndef PLANTTREE_H
#define PLANTTREE_H

#include "plant.h"
#include "treestruct.h" 
using namespace std;

class planttree{
    
    private:
        treenode    *root;
    
    public:
        planttree();
        planttree(const planttree &aData);
        ~planttree();

        void copyTree(treenode *&newRoot, treenode *root);        
        void setRoot(plant &aData);
        void addChildren(plant &parent, plant &childL, plant &childR);
        void addChildren(plant &parent, plant &childL, plant &childR, treenode *&root);
        void destroyTree(treenode *&root);
        void display();
        void display(treenode *&root, int tab);
        const plant* findBestGrowth();
        void findBestGrowth(treenode *&root, const plant *&greatest);
        const plant* findBestWater();
        void findBestWater(treenode *&root, const plant *&greatest);
        const plant* findBestNutrition();
        void findBestNutrition(treenode *&root, const plant *&greatest);
        
        const planttree& operator=(const planttree &aData);
};

#endif
