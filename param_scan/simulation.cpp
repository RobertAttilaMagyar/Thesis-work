#include "simulation.h"

using namespace std;

void SIMULATION(int model, int num_editors, int num_articles, float pe,
 float pa, int dimensions, int T, float q){

    //srand(time(NULL));
    std::cout<<"Welcome to simulation\n\n";

    std::string filename;  
    float pE = pe;
    float pA = pa;

    //Creating array of editors with the given parameters
    EDITOR* editors = new EDITOR[num_editors] ;
    for(auto i = 0; i < num_editors; ++i) editors[i] = EDITOR(dimensions, pE);

    //Creating array of editors with the given parameters
    ARTICLE* articles = new ARTICLE[num_articles];
    for(auto i = 0; i < num_editors; ++i) articles[i] = ARTICLE(dimensions, pE);

    //Creating the edit counter matrix
    int** editcount_matrix = new int*[num_editors];
    for(auto i = 0; i < num_editors; ++i){
        editcount_matrix[i] = new int[num_articles];
    }
    for(auto i = 0; i < num_editors; ++i){
        for(auto j = 0; j < num_articles; ++j) editcount_matrix[i][j] = 0;
    }

    std::cout<<"Lets choose a model!\n\n";

     //___MODEL 1________________________________________________________________________________________________________________
    if(model == 1){
    std::cout<<"Model 1\n";

    //Creating a filename capable to track the main values
    filename = "ne" + to_string(num_editors)+"_na"
    +to_string(num_articles)+"_pe"+to_string(pE) + "_pa"+to_string(pA)+"_T"
    +to_string(T)+"_a0_m" +to_string(model)+"_d1.csv";

    Time_Development(editors, articles, editcount_matrix, num_editors, num_articles, T);

    cout<<"Saved to: "<<filename<<"\n";
    }

//___MODEL 2________________________________________________________________________________________________________________

    if(model == 2){
    std::cout<<"Model 2\n";

    //Creating a filename capable to track the main values
    filename = "ne" + to_string(num_editors)+"_na"
    +to_string(num_articles)+"_pe"+to_string(pE) + "_pa"+to_string(pA)+"_T"
    +to_string(T)+"_a0_m" +to_string(model)+"_q"+to_string(q)+"_d1.csv";

    Time_Dev2(editors, articles, editcount_matrix, num_editors, num_articles, T, q);

    cout<<"Saved to: "<<filename<<"\n";
    }

    std::ofstream of (filename);
    Write_Matrix(of, editcount_matrix, num_editors, num_articles);
    delete[] editors;
    delete[] articles;
    for(auto i = 0; i < num_editors; ++i) delete[] editcount_matrix[i];
    delete[] editcount_matrix;
 }