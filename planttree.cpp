#include "planttree.h"

planttree::planttree():root(NULL){}

planttree::planttree(const planttree &aData):root(NULL){
       *this = aData; 
} 

const planttree& planttree::operator=(const planttree &aData){
    if (this == &aData)
        return *this;
    else{
        destroyTree(root);

        copyTree(root, aData.root);
        return *this;
    }
}
 
void planttree::copyTree(treenode *&newRoot, treenode *root){
    if (root){
         newRoot = new treenode(root->data);
    
         copyTree(newRoot->left, root->left);
         copyTree(newRoot->right, root->right);
    }else
        newRoot = NULL;
}
planttree::~planttree(){    
    destroyTree(root);
}

void planttree::destroyTree(treenode *&root){
    
    if (root){
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
        root = NULL;
    }
}

void planttree::setRoot(plant &aData){
    root = new treenode(aData);
}

void planttree::addChildren(plant &parent, plant &childL, plant &childR){
    addChildren(parent, childL, childR, root);
}

void planttree::addChildren(plant &parent, plant &childL, plant &childR, treenode *&root){
    if (root){
        if (parent == root->data){
            root->left = new treenode(childL);
            root->right = new treenode(childR);   
        }else{
                addChildren(parent, childL, childR, root->left);
                addChildren(parent, childL, childR, root->right);
        }
    }
}

void planttree::display(){
    display(root, 0);
}

void planttree::display(treenode *&root, int tab){
    for (int i = 0; i < tab*2; i++){
        cout << " ";
    }
    cout << root->data << endl;
    if(root->left && root->right){
        display(root->left, ++tab);
        display(root->right, tab++);
    }
}

const plant* planttree::findBestGrowth(){
    const plant *greatGrow = &(root->data);
    findBestGrowth(root, greatGrow); 
    return greatGrow;
}

void planttree::findBestGrowth(treenode *&root, const plant *&greatGrow){
     
     if(root){
        if (root->data.getGrowth() > greatGrow->getGrowth()){
            greatGrow = &(root->data);
        }
        findBestGrowth(root->left, greatGrow);
        findBestGrowth(root->right, greatGrow);
    }
}

const plant* planttree::findBestWater(){
    const plant *greatWat = &(root->data);
    findBestWater(root, greatWat); 
    return greatWat;
}

void planttree::findBestWater(treenode *&root, const plant *&greatWat){
     
     if(root){
        if (root->data.getWater() > greatWat->getWater()){
            greatWat = &(root->data);
        }
        findBestWater(root->left, greatWat);
        findBestWater(root->right, greatWat);
    }
}
const plant* planttree::findBestNutrition(){
    const plant *greatNutri = &(root->data);
    findBestNutrition(root, greatNutri); 
    return greatNutri;
}

void planttree::findBestNutrition(treenode *&root, const plant *&greatNutri){
    
    if(root){
        if (root->data.getNutrition() > greatNutri->getNutrition()){
            greatNutri = &(root->data);
        }
        findBestNutrition(root->left, greatNutri);
        findBestNutrition(root->right, greatNutri);
    }
}


