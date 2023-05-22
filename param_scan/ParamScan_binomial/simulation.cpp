#include "simulation.h"

using namespace std;

void SIMULATION(bool activ, int num_editors, int num_articles, float pe,
                float pa, int dimensions, int T)
{

    std::string filename;
    float pE = pe;
    float pA = pa;

    // Creating array of editors
    EDITOR *editors = new EDITOR[num_editors];

    // Creating array of articles
    ARTICLE *articles = new ARTICLE[num_articles];

    // Change the editors and articles with the new parameters
    for (auto i = 0; i < num_editors; ++i)
        editors[i].ChangeEdProps(dimensions, pE);

    for (auto i = 0; i < num_articles; ++i)
        articles[i].ChangeArtProps(dimensions, pA);

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

    //___MODEL 1________________________________________________________________________________________________________________

    // Creating a filename capable to track the main values
    if (activ)
        filename = "paramscan_binomial_ne" + to_string(num_editors) + "_na" + to_string(num_articles) + 
        "_pe" + to_string(pE) + "_pa" + to_string(pA) + "_T" + to_string(T) + "_a1_m" + "1.csv";

    else 
        filename = "paramscan_binomial_ne" + to_string(num_editors) + "_na" + to_string(num_articles) +
         "_pe" + to_string(pE) + "_pa" + to_string(pA) + "_T" + to_string(T) + "_a0_m" + "1.csv";

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