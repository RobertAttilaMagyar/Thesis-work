#ifndef ARTICLE_H
#define ARTICLE_H
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


class ARTICLE{
    public:
    int DIMENSION; //same as editor
    float* DIM_VALUES; //same as editor
    float PROB_pA; //probability that the article is related to a given discipline

    ARTICLE(int dim  = 20, float pA = 0.2)
    {
        DIMENSION = dim;
        DIM_VALUES = new float[DIMENSION];
        PROB_pA = pA;

        for(auto i = 0; i<DIMENSION; ++i){
            float f1 = (float)rand() / RAND_MAX; //to decide if the given article contains a discipline or not
            if(f1<PROB_pA){
                DIM_VALUES[i] = 0;
            }
            else{
                DIM_VALUES[i] = 1;
            }
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

    void ChangeArtProps(int new_dim, float new_p){
        DIMENSION = new_dim;
        DIM_VALUES = new float[DIMENSION];
        PROB_pA = new_p;

        for(auto i = 0; i<DIMENSION; ++i){
            float f1 = (float)rand() / RAND_MAX; //to decide if the given article contains a discipline or not
            if(f1<PROB_pA){
                DIM_VALUES[i] = 0;
            }
            else{
                DIM_VALUES[i] = 1;
            }
        }
    }


    ~ARTICLE(){delete[] DIM_VALUES;}

    

};






#endif 