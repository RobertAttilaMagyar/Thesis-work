#ifndef SIMULATION_H
#define SIMULATION_H

/*Used libraries*/
#include <iostream> //Printing to console
#include <vector>   // Useful STL container
#include <fstream> //writing to files
#include <array> //size commands
#include <random> //random numbers
#include <time.h> //Keep track of running time
#include <string> //to use string manupulations

/*self written files with functions*/
#include "functions.h" //for better readability all functions will be in a different file

/*Objects included*/
#include "editor.h" //objects created to represent editors
#include "article.h" //objects created to represent articles



void SIMULATION(int model = 1, int num_editors = 1000, int num_articles = 1000, float pe = 0.2,
 float pa = 0.2, int dimensions = 20, int T = 5000, float q = 0.05);


#endif // SIMULATION_H