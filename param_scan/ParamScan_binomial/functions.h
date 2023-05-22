//================================================================================================================
//                                THE FUNCTIONS THAT ARE USED IN THE SIMULATION
//================================================================================================================
/*
 * Filewriting functions
 * Basic mathematical functions
 * "Game function"
 * Maybe I'll write here some datastructures as well
 */

#ifndef FUNCTIONS_H // Make sure that don't declare any function twice
#define FUNCTIONS_H

// Including staff that we will need
#include <random>
#include <iostream>
#include <fstream>
#include "editor.h"
#include "article.h"

/*  Function to write editor properties to a file with a given set of editors   */

void Write_Editors(std::ofstream &of, EDITOR *editors, int num_editors);

/*  Function to write N x N adjacency matrix to a file  */
void Write_AdjMx(std::ofstream &of, int **adj_mx, int n);

/*  Function to write NXM matrix to a file  */
void Write_Matrix(std::ofstream &of, int **mx, int n, int m);

/*  Function to print an N x M 2D matrix */
void print_matrix(int **mx, int n, int m);

/*  Function to find maximum value in a given array */
int find_max(int **arr, int n, int m);

/*  Function to fill an N x M 2D matrix with zeros*/
void fill_zeros(int **mx2d, int n, int m);

/*  Function to return the greater value of 2 numbers */
float max_2(float num1, float num2);

/*  Function to calculate the sum of a given array  */
float sum_arr(float *arr, int arr_size);

// int* row_toarr(int* arr2d, int i, int m); //arr2d is 2d array with m coloumns, i is the i-th row

/*  Pairing editors and articles    */
void Pair_ed_to_art(EDITOR *editors, ARTICLE *articles, int *art_ind, int num_editors, int num_articles);

/*  Generating the adjacency matrix from the pairs*/
void Gen_adj_matrix(int **adj_matrix, int *art_ind,
                    int num_editors, int num_articles);

/*  Editor i editing article j   */
void Editing(EDITOR &e, ARTICLE &a);

/*  The "game" cycle*/
void Time_Development(EDITOR *editors, ARTICLE *articles,
                      int **editcount_matrix, int num_editors, int num_articles, int T, bool activ = false);

#endif