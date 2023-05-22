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

int main(int argc, char **argv)
{
    srand(time(NULL));

    // declaring default numbers of parameters
    int Tprime = atoi(argv[1]);
    int Nprime = atoi(argv[2]);
    int Tmax = 2000;
    std::cout << "Meg elek\n";
    std::vector<EDITOR> editors;
    std::vector<ARTICLE> articles;
    for (auto i = 0; i < 1000; ++i)
    {
        std::cout<<"i: "<<i<<std::endl;
        EDITOR new_ed;
        editors.push_back(new_ed);      
    }
    for(auto i = 0; i < 1000; ++i){
        std::cout<<"j: "<<i<<std::endl;
        ARTICLE new_art;
        articles.push_back(new_art);
    }

    std::cout << "Notsure\n";

    //======================== RUNNING THE SIMULATIONS ============================
    Time_Development(editors, articles, Tmax, Tprime, Nprime);
    

    std::vector<EDITOR>().swap(editors);
    std::vector<ARTICLE>().swap(articles);

    return 0;
}