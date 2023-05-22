#ifndef ARTICLE_H
#define ARTICLE_H
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>       /* vector */
#include <algorithm>    /*sort*/


class ARTICLE{
    public:
    int DIMENSION; //same as editor
    float* DIM_VALUES; //same as editor
    float ALPHA_A; //probability that the article is related to a given discipline

    ARTICLE(int dim  = 20, float aA = 3);

    ARTICLE(const ARTICLE &a1);

    ARTICLE& operator=(ARTICLE const &a1){
        this->DIMENSION = a1.DIMENSION;
        this->DIM_VALUES = new float[this->DIMENSION];
        this->ALPHA_A = a1.ALPHA_A;
        for(auto i = 0; i < this->DIMENSION; ++i){
            this->DIM_VALUES[i] = a1.DIM_VALUES[i];
        }
    }

    
    /*Function to print out Article properties*/
    void PrintArticle()
    {
        std::cout<<"Article traits: "<<std::endl;
        for(auto i = 0; i<DIMENSION; ++i)
        {
            std::cout<<DIM_VALUES[i]<<" ";
        }
        std::cout<<'\n';
    }

    void ChangeParam_Articles(int new_dim = 20, float new_aA = 1.1);

    ~ARTICLE(){delete[] DIM_VALUES;}
};






#endif 