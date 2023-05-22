#include "simulation.hpp"

using namespace std;

void SIMULATION(bool activ, int num_editors, int num_articles, float ae,
                float aa, int dimensions, int T)
{

    std::string filename;
    float pE = ae;
    float pA = aa;

    // Creating array of editors
    EDITOR *editors = new EDITOR[num_editors];

    // Creating array of articles
    ARTICLE *articles = new ARTICLE[num_articles];

    // Change the editors and articles with the new parameters
    for (auto i = 0; i < num_editors; ++i)
        editors[i].ChangeParams_Editors(dimensions, pE);

    for (auto i = 0; i < num_articles; ++i)
        articles[i].ChangeParam_Articles(dimensions, pA);

    // Creating the edit counter matrix
    int **editcount_matrix = new int *[num_editors];
    for (auto i = 0; i < num_editors; ++i)
    {
        editcount_matrix[i] = new int[num_articles];
    }
    for (auto i = 0; i < num_editors; ++i)
    {
        for (auto j = 0; j < num_articles; ++j)
            editcount_matrix[i][j] = 0;
    }

    /*
        FILENAME RULES
        * ne, na: number of editors/articles
        * aE, aA: exponent of powerlaw distribution
        * T: number of iterations
        * a: 1 if activity is switched on, 0 if not
        * m: model used
          - 1: random measure of difference when editing
          - 2: page ranking (not completed yet) 
          - 3: constant measure of difference (just an idea)
    */

    // Creating a filename capable to track the main values
    if (activ)
        filename = "paramscan_powerlaw_ne" + to_string(num_editors) + "_na" + to_string(num_articles) + 
        "_aE" + to_string(pE) + "_aA" + to_string(pA) + "_T" + to_string(T) + "_a1_m" + "1.csv";

    else 
        filename = "paramscan_powerlaw_ne" + to_string(num_editors) + "_na" + to_string(num_articles) +
         "_aE" + to_string(pE) + "_aA" + to_string(pA) + "_T" + to_string(T) + "_a0_m" + "1.csv";

    
    Time_Development(editors, articles, editcount_matrix, num_editors, num_articles, T, activ);

    cout << "Saved to: " << filename << "\n";

    std::ofstream of(filename);
    Write_Matrix(of, editcount_matrix, num_editors, num_articles);
    delete[] editors;
    delete[] articles;
    for (auto i = 0; i < num_editors; ++i)
        delete[] editcount_matrix[i];
    delete[] editcount_matrix;
}