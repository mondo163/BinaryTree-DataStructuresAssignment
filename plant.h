/*****************************************************
* This represents the plant object and plant it contains.
******************************************************/

#ifndef PLANT_H
#define PLANT_H

#include<iostream>
#include<cstring>
using namespace std;

class plant{

    private:
        char    *id;
        int     growth;
        int     nutrition;
        int     water;

    public:
        plant();
        plant(const char newId[], int newGrow, int newNutr, int newWat);
        plant(const plant &aData);
        ~plant();

        void getId(char *&returnId) const;
        int getGrowth() const;
        int getNutrition() const;
        int getWater() const;

        void setId(char newId[]);
        void setGrowth(int &newGrowth);
        void setNutrition(int &newNutrition);
        void setWater(int &newWater);

        plant& operator=(const plant &aData);
        friend bool operator==(const plant &bData, const plant &aData);
        friend ostream& operator<<(ostream &out, const plant &aData);
};

#endif
