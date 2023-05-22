#ifndef SIMULATION_H
#define SIMULATION_H

/*Used libraries*/
#include <iostream> //Printing to console
#include <vector>   // Useful STL container
#include <fstream>  //writing to files
#include <array>    //size commands
#include <random>   //random numbers
#include <time.h>   //Keep track of running time
#include <string>   //to use string manupulations

/*self written files with functions*/
#include "functions.hpp" //for better readability all functions will be in a different file

/*Objects included*/
#include "editor.hpp"  //objects created to represent editors
#include "article.hpp" //objects created to represent articles

void SIMULATION(bool activ, int num_editors = 1000, int num_articles = 1000, float ae = 1.1,
                float aa = 1.1, int dimensions = 20, int T = 5000);

                

#endif // SIMULATION_H