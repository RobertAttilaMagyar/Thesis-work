//================================================================================================================
//                                      CREATING THE EDTITOR OBJECT
//================================================================================================================

#ifndef EDITOR_H
#define EDITOR_H
#include <iostream>
#include <stdlib.h>
#include <time.h>

class EDITOR{
    public:
    int DIMENSION; //the dimension is the same in case of every editor
    float* DIM_VALUES; //in every discipline of human knowledge every editor has values
    float PROB_pE; // The probability that an editor knows a given discipline
    float activity; //parameter to describe different activeness of editors;

    /*Constructor of object EDITOR*/
    EDITOR(int dim = 20, float pE = 0.2)
    {
        DIMENSION = dim;
        DIM_VALUES = new float[DIMENSION];
        PROB_pE = pE;

        activity = (float)rand()/RAND_MAX; //Not used in all simulations

        for(auto i = 0; i<DIMENSION; ++i)
        {
            //in order to decide if the editor knows the discipline or not
            float f1 = (float)rand() / RAND_MAX;

            if(f1<PROB_pE){
                DIM_VALUES[i] = (float)rand() / RAND_MAX;
            }
            else{
                DIM_VALUES[i] = 0;
            }
        }
    }

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

    void ChangeEdProps(int new_dim = 20, float new_p = 0.2){
        DIMENSION = new_dim;
        delete[] DIM_VALUES;
        DIM_VALUES = new float[DIMENSION];
        PROB_pE = new_p;

        activity = (float)rand()/RAND_MAX; //Not used in all simulations

        for(auto i = 0; i<DIMENSION; ++i)
        {
            //in order to decide if the editor knows the discipline or not
            float f1 = (float)rand() / RAND_MAX;

            if(f1<PROB_pE){
                DIM_VALUES[i] = (float)rand() / RAND_MAX;
            }
            else{
                DIM_VALUES[i] = 0;
            }
        }
    }

    ~EDITOR(){delete [] DIM_VALUES;}
};

#endif // EDITOR_H