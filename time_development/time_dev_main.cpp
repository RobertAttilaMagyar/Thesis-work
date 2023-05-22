// used libraries
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <math.h>
#include <fstream>
#include <sstream>
#include <cstdlib>


// used self written additional files
#include "editor.hpp"
#include "article.hpp"
#include "functions.hpp"
#include "simulation.hpp"

int main(int argc, char **argv)
{
    srand(time(NULL));

    // declaring default numbers of parameters
    int num_editors = atoi(argv[1]);
    int num_articles = atoi(argv[2]);
    float aE = atof(argv[3]);
    float aA = atof(argv[4]);
    int dimensions = atoi(argv[5]);
    int T = atoi(argv[6]);

    float x = atof(argv[2]);
    std::cout<<"x: "<<x*1.3<<"\n";

    for (auto i = 1; i < argc; ++i)
    {
        std::cout << argv[i] << "\n";
    }

    //======================== RUNNING THE SIMULATIONS ============================
    // simulation without the activity property
    SIMULATION(false, num_editors, num_articles, aE, aA, dimensions, T);

    // simulation with the activity property
    //SIMULATION(true, num_editors, num_articles, aE, aA, dimensions, T);

/*
    //  === Changing number of editors and articles ===
    for (auto ed_numb = 100; ed_numb <= 2000; ed_numb += 100)
    {
        for (auto art_numb = 100; art_numb <= 2000; art_numb += 100)
        {
            // without activity
            SIMULATION(false, ed_numb, art_numb, aE, aA, dimensions, T);

            // with activity
            SIMULATION(true, ed_numb, art_numb, aE, aA, dimensions, T);
        }
    }

    //  === Changing aE and aA of editor/article distributions ===
    for (float new_ae = 1.1; new_ae <= 4; new_ae += 0.1)
    {
        for (float new_aa = 1.1; new_aa <= 4; new_aa += 0.1)
        {
            // without activity
            SIMULATION(false, num_editors, num_articles, new_ae, new_aa, dimensions, T);

            // with activity
            SIMULATION(true, num_editors, num_articles, new_ae, new_aa, dimensions, T);
        }
    }

    //  === Changing the dimensions of human knowledge ===
    for (auto dim = 5; dim <= 30; ++dim)
    {
        // without activity
        SIMULATION(false, num_editors, num_articles, aE, aA, dim, T);

        // with activity
        SIMULATION(true, num_editors, num_articles, aE, aA, dim, T);
    }


    /**/

    return 0;
}