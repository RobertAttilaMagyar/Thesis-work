//================================================================================================================
//                          MAIN FUNCTION TO RUN THE PARAMETER SCANNING
//================================================================================================================

/*
    SCANNED PARAMETERS:
    * model
    * activity
    * number of articles and editors
    * "p" values in definition one
*/

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
#include "simulation.h" //The code running the simulation can be found in a different file

/*Objects included*/
#include "editor.h" //objects created to represent editors
#include "article.h" //objects created to represent articles

using namespace std;


int main(){
    srand(time(NULL));

/*
    FILE NAME RULES
    * ne - num editors, na - num articles
    * pe, pa: see the definition (It's not the most important one)
    * T: it's obvious
    * a: activity (not build in yet, filenames before including a = 0, after a = 1)
    * m: method observed:
        1. New generating of the graph, dA uniform between 0 and 1
        2. introducing the q-s mentioned by Dr. Török János
    * d: definition used(see overleaf document)
*/ 


////////////////////////////////////////// PARAMETER SCANNING THE RESULTS ////////////////////////////////////////
//================================================================================================================
    //SCANNING THE q PARAMETER IN MODEL 2
    for(auto q = 0.01; q <= 0.1; q += 0.01){
        SIMULATION(2, 1000, 1000, 0.2, 0.2, 20, 5000, q);
    }

    //SCANNING pE and pA IN MODEL 1
    for(auto p = 0.1; p <= 1; p += 0.1){
        SIMULATION(1, 1000, 1000, p, p, 20, 5000, 0.05);
    }

    //SCANNING NUMBER OF EDITORS AND ARTICLES IN MODEL 2
    for(auto num_arts = 500; num_arts <= 1500; num_arts += 100){
        for(auto num_eds = 500; num_eds <= 1500; num_eds += 100){
            SIMULATION(2, num_eds, num_arts, 0.2, 0.2, 20, 5000, 0.05);
        }
    }

    //SCANNING NUMBER OF EDITORS AND ARTICLES IN MODEL 1
    for(auto num_arts = 500; num_arts <= 1500; num_arts += 100){
        for(auto num_eds = 500; num_eds <= 1500; num_eds += 100){
            SIMULATION(1, num_eds, num_arts, 0.2, 0.2, 20, 3000, 0.05);
        }
    }

    return 0;
}
