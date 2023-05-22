//================================================================================================================
//                                      CREATING THE EDTITOR OBJECT
//================================================================================================================

#ifndef EDITOR_H
#define EDITOR_H
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <cmath>
#include <algorithm>


class EDITOR{
    public:
    int DIMENSION; //the dimension is the same in case of every editor
    float* DIM_VALUES; //in every discipline of human knowledge every editor has values
    float ALPHA_E; // The probability that an editor knows a given discipline
    float activity; //parameter to describe different activeness of editors;

    /*Constructor of object EDITOR*/
    EDITOR(int dim = 20, float aE = 1.1);

    /*Function to print out editor properties*/
    void PrintEditor()
    {
        std::cout<<"Editor traits: "<<std::endl;
        for(auto i = 0; i<DIMENSION; ++i)
        {
            std::cout<<DIM_VALUES[i]<<" ";
        }
        std::cout<<'\n';
    }

    void ChangeParams_Editors(int new_dim = 20, float new_aE = 1.1);

    ~EDITOR(){delete [] DIM_VALUES;}
};

#endif // EDITOR_H