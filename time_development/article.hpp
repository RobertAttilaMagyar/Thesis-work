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
    float popularity;

    ARTICLE(int dim  = 20, float aA = 1.1);

    
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