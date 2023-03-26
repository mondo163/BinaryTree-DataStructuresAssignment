#include "plant.h"

plant::plant(){
    int idBufferSize = strlen("No Plant") + 1;
    id = new char[idBufferSize];
    strcpy_s(id, idBufferSize, "No Plant");
    growth = 0;
    nutrition = 0;
    water = 0;
}



plant::plant(const char newId[], int newGrow, int newNutr, int newWat){
    int idBufferSize = strlen(newId) + 1;
    id = new char[idBufferSize];
    strcpy_s(id, idBufferSize, newId);
    growth = newGrow;
    nutrition = newNutr;
    water = newWat; 
}

plant::plant(const plant& aData){
    int idBufferSize = strlen(aData.id) + 1;
    id = new char[idBufferSize];
    strcpy_s(id, idBufferSize, aData.id);
    water = aData.water;
    nutrition = aData.nutrition;
    growth = aData.growth; 
}

plant::~plant(){
    if (id){
        delete [] id;
        id = NULL;
    }
}

void plant::getId(char *&returnId) const{
    if (returnId){
        delete [] returnId;
        returnId = NULL;
    }
    int idBufferSize = strlen(id) + 1;
    returnId = new char[idBufferSize];
    strcpy_s(returnId, idBufferSize, id);
}

int plant::getGrowth() const { 
    return growth; 
}

int plant::getNutrition() const { 
    return nutrition; 
}

int plant::getWater() const { 
    return water;   
}


void plant::setId(char newId[]){
    if (id){
        delete [] id;
        id = NULL;
    }
    int idBufferSize = strlen(newId) + 1;
    id = new char[idBufferSize];
    strcpy_s(id, idBufferSize, newId);
}

void plant::setGrowth(int &newGrowth){
    growth = newGrowth;
}
void plant::setNutrition(int &newNutrition){
    nutrition = newNutrition;
}

void plant::setWater(int &newWater){
    water = newWater;
}

plant& plant::operator=(const plant &aData){
    if(this == &aData)
        return *this;
    else{
        if (id){
            delete [] id;
            id = NULL;
        }
        int idBufferSize = strlen(aData.id) + 1;
        id = new char[idBufferSize];
        strcpy_s(id, idBufferSize, aData.id);
        growth = aData.growth;
        nutrition = aData.nutrition;
        water = aData.water;
        return *this;
    }
}

bool operator==(const plant &aData, const plant &bData){
    bool    same = false;

    if (aData.id && bData.id){    
        if (strcmp(bData.id, aData.id) == 0)
            same = true;
    }

    return same;
}

ostream& operator<<(ostream &out, const plant &aData){
    out << "Plant ID: Plant " << aData.id 
        << " (G: " << aData.growth
        << " N: " << aData.nutrition
        << " W: " << aData.water << ")"; 

    return out;
}
