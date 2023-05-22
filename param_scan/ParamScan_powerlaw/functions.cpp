#include "functions.hpp"

using namespace std;
//======================================================================OFSTREAM FUNCTIONS======================================================

/*
    These functions are meant to write out different outputs into files.
    We need as many output functions as many different output formats we have
    This section contains the following items:
    * A function to write out editor properties
    * A function to write out andjacency matrix (WARNING! It should contain a header and row labels)
    * A function to write out matrices
    * Time development functions
*/


/*  Function to write editor properties to a file with a given set of editors   */
void Write_Editors(std::ofstream& of, EDITOR* editors, int num_editors){
    if (of.is_open()){
        //Basically a header that will be useful when it comes to plotting
        for(auto i = 0; i<editors[0].DIMENSION; ++i){
            of<<i;
            if(i != editors[0].DIMENSION-1) of<<";"; //avoid putting a terminator at the end of each line
        }
        of<<"\n";

        //Write each editors scores to a file
        for(auto i = 0; i<num_editors; ++i){
            for(auto j = 0; j<editors[i].DIMENSION; ++j){
                of<<editors[i].DIM_VALUES[j];
                if(j != editors[i].DIMENSION-1) of<<";"; //avoid putting a terminator at the end of each line
            }
            if(i != editors[i].DIMENSION-1) of<<"\n"; //somehow there is still an unnecessery \n in the file
        }
        of.close(); //Closing the file after writing it
    }
}

/*  Function to write N x N adjacency matrix to a file*/
void Write_AdjMx(std::ofstream& of, int** adj_mx, int n){
    if (of.is_open()){
        //Writing a header first
        for(auto i = 0; i < n; ++i){
            of<<','<<i;
        }
        of<<"\n";
        //Now writing the matrix out to a file
        for(auto i = 0; i < n; ++i){
            of<<i<<",";
            for(auto j = 0; j < n; ++j){
                of << adj_mx[i][j];
                if(j != n-1) of<<",";
            }
            of<<"\n";
        }
    }
}

/*  Function to write NXM matrix to a file  */
void Write_Matrix(std::ofstream& of, int** mx, int n, int m){
    if (of.is_open()){
        //Now writing the matrix out to a file
        for(auto i = 0; i < n; ++i){
            for(auto j = 0; j < m; ++j){
                of << mx[i][j];
                if(j != m-1) of<<",";
            }
            of<<"\n";
            //std::cout<<i<<"\n";
        }
    }
    of.close();
}

//======================================================================GENERAL FUNCTIONS======================================================

/*
    This section contains frequently used general functions which appear in multiple models
*/


/*  Function to print an N x M 2D matrix */
void print_matrix(float** mx, int n, int m){
    for(auto i = 0; i < n; ++i){
        for(auto j = 0; j < m; ++j) std::cout<<mx[i][j]<<" ";
        std::cout<<"\n";
    }
}

/*  Function to find maximum value in a given array */
int find_max(int** arr, int n, int m){
    int max = arr[0][0];
    for(auto i = 1; i<n; ++i){
        for(auto j = 0; j < m; ++j){
            if(arr[i][j]<max) max = arr[i][j];
        }
        
    }
    return max;
}

/*  Function to fill a 2D matrix with zeros*/
void fill_zeros(int** mx2d, int n, int m){
    for(auto i = 0; i < n; ++i)
        for(auto j = 0; j < m; ++j) mx2d[i][j] = 0;
}

/*  Function to calculate the sum of a given array  */
float sum_arr(float* arr, int arr_size){
    float sum = 0; 
    for(auto i = 0; i<arr_size; ++i) sum+=arr[i];
    return sum;
}

/*  Function to return the greater value of 2 numbers */
float max_2(float num1, float num2){
    if(num1>num2) return num1;
    else return num2;
}

//======================================================================MY OWN MODEL======================================================

/*  Pairing editors and articles    */
//This one is quite long, but I didn't wanted to declare too many functions. I think it's simple enough.
void Pair_ed_to_art(EDITOR* editors, ARTICLE* articles, int* art_ind, int num_editors, int num_articles ){
    int dim = editors[0].DIMENSION;
    
    // CALCULATING THE d_{i,j}-s //////////////////////////////////////////////////////

    //float d[num_editors][num_articles]; //Working here with a 2D matrix is efficient
    float** d = new float*[num_editors];
    for(auto i = 0; i < num_editors; ++i) d[i] = new float[num_articles];
    for(auto i = 0; i < num_editors; ++i){
        for(auto j = 0; j < num_articles; ++j){
            //we should also calulate d^k_{i,j} values
            float* dks = new float[dim]; //This array is with respect to the i,j component of the d 2D array
            
            for(auto k = 0; k < dim; ++k){
                float a = editors[i].DIM_VALUES[k] - articles[j].DIM_VALUES[k];
                if(a <= 0) dks[k] = 0;
                else dks[k] = a;
            }

            d[i][j] = sum_arr(dks, dim);
            delete[] dks;   
        }      
    }
    ////////////////////////////////////////////////////////////////////////////////////

    // DECIDING WHICH ARTICLE j DO EDITOR i CHOOSES ////////////////////////////////////

    float* row_sums = new float[num_editors]; //for calculating norms we need the sums of each row. fill this wits 0s
    for(auto i = 0; i<num_editors; ++i) row_sums[i] = 0;

    //Calculate the sums of the rows
    for(auto i = 0; i < num_editors; ++i)
        for(auto j = 0; j < num_articles; ++j) row_sums[i] += d[i][j];

    

    //norming the "d" 2D matrix

    float** norm_d = new float*[num_editors];
    for(auto i = 0; i < num_editors; ++i) norm_d[i] = new float[num_articles];
    for(auto i = 0; i<num_editors; ++i){
        for(auto j = 0; j<num_articles; ++j){
            if(row_sums[i] == 0) norm_d[i][j] = 0;
            else norm_d[i][j] = (float)d[i][j]/row_sums[i];
        }
    }
    for(auto i = 0; i < num_editors; ++i) delete[] d[i];
    delete[] d;
    delete[] row_sums;


    //Random array for generating the pairs
    float* f = new float[num_editors];
    for(auto i = 0; i<num_editors; ++i){
        f[i] = (float)rand() / RAND_MAX;
    }

    for(int i = 0; i<num_editors; ++i) art_ind[i] = INT32_MAX;
    

    for(int i = 0; i<num_editors; ++i){
        float base = 0;
        for(int j = 0; j<num_articles; ++j){
            if(f[i] > base && f[i] < (base + norm_d[i][j]) ){ 
                art_ind[i] = j;
                base += norm_d[i][j];
                }
            else {
                base += norm_d[i][j];
                }
        }
    }

    //free the allocated memory
    delete[] f;
    for(auto i = 0; i < num_editors; ++i) delete[] norm_d[i];
    delete[] norm_d;

    /*------------------Now we have got that desired pairing pairing------------------*/
    ////////////////////////////////////////////////////////////////////////////////////   
}

/*  Generating the adjacency matrix from the pairs*/
void Gen_adj_matrix(int** adj_matrix, int* art_ind, int num_editors, int num_articles){
    //Filling the 2d matrix with zeros
    int mx_size = num_articles + num_editors;
    fill_zeros(adj_matrix, mx_size, mx_size);

    //Find the ones in the matrix
    for(auto i = 0; i < num_editors; ++i){
        for(auto j = 0; j< num_articles; ++j){
            if(art_ind[i] == j){
                adj_matrix[i][num_editors + j] = 1;
                adj_matrix[num_editors + j][i] = 1;
            }
        }
    }
}

/*  Editor i editing article j   */
void Editing(EDITOR& e, ARTICLE& a){
    //Selecting the proper discipline////////////////////////////////////////////////////
    int dim = e.DIMENSION;
    float* dks = new float[dim];
    for(auto k = 0; k < dim;++k){
                float cucc = e.DIM_VALUES[k] - a.DIM_VALUES[k];
                if(cucc<=0) dks[k] = 0;
                else dks[k] = cucc;
            }
    
    float sum_dks = sum_arr(dks, dim);
    float* norm_dks = new float[dim];
    if(sum_dks <= 0.00001){ //Norming the set of dks
        for(auto i = 0; i<dim; ++i) norm_dks[i] = 0;
    }
    else{
        for(auto i = 0; i<dim; ++i) norm_dks[i] = dks[i] / sum_dks;
    }

    delete[] dks;

    //finding out the proper discipline which will be selected by the editor
    int chosen_k = INT32_MAX;
    float base = 0;
    float f = (float) rand()/RAND_MAX;
    for(auto i = 0; i < dim; ++i){
        if(base < f && f< base + norm_dks[i]){
            chosen_k = i;
            base += norm_dks[i];
        }
        else base += norm_dks[i];
    }
    delete[] norm_dks;

    //Increaseing the dim_value of the proper discipline, if chosen_k is valid
    float dA = (float)rand()/RAND_MAX;
    if(chosen_k < dim && 0<= chosen_k){
        a.DIM_VALUES[chosen_k] += dA*(e.DIM_VALUES[chosen_k] - a.DIM_VALUES[chosen_k]);
    }
    
}

/*  The "game" cycle*/
void Time_Development(EDITOR *editors, ARTICLE *articles,
                      int **editcount_matrix, int num_editors, int num_articles, int T, bool activ)
{
    int j;
    int dim = articles[0].DIMENSION;
    int* NumOfEdits = new int[T];
    // Running the process for T time, and counting how many times does the editor i edits article j
    for (auto x = 0; x < T; ++x)
    {
        std::cout<<"x: "<<x<<std::endl;

        int *art_ind = new int[num_editors];
        Pair_ed_to_art(editors, articles, art_ind, num_editors, num_articles);
        if (activ)
        {
            for (auto i = 0; i < num_editors; ++i)
            {
                j = art_ind[i];
                float act_rand = (float)rand() / RAND_MAX;
                //one plus if else deciding if editor edits or not
                if (act_rand < editors[i].activity)
                {
                    if (j < num_articles)
                    {
                        editcount_matrix[i][j] += 1;
                        Editing(editors[i], articles[j]);
                        NumOfEdits[x] += 1;
                    }
                }
            }
        }

        else
        {
            for (auto i = 0; i < num_editors; ++i)
            {
                j = art_ind[i];
                if (j < num_articles)
                {
                    editcount_matrix[i][j] += 1;
                    Editing(editors[i], articles[j]);
                    NumOfEdits[x] += 1;
                }
            }
        }

        delete[] art_ind;
    }

    std::string name;
    if (activ)
        name = "numedits_paramscan_powerlaw_ne" + to_string(num_editors) + "_na" + to_string(num_articles) + 
        "_aE" + to_string(editors[0].ALPHA_E) + "_aA" + to_string(articles[0].ALPHA_A) + "_T" + to_string(T) + "_a1_m" + "1.dat";

    else 
        name = "numedits_paramscan_powerlaw_ne" + to_string(num_editors) + "_na" + to_string(num_articles) +
         "_aE" + to_string(editors[0].ALPHA_E) + "_aA" + to_string(articles[0].ALPHA_A) + "_T" + to_string(T) + "_a0_m" + "1.dat";
    
    std::ofstream numedits(name);
    if(numedits.is_open()){
        for(auto i = 0; i < T ; ++i) numedits<<NumOfEdits[i]<<"\n";
    }
    numedits.close();


    delete[] NumOfEdits;
}

//======================================================================PAGE RANKING MODEL======================================================
