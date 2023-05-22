#include <vector>
#include <iostream>
#include "functions.hpp"
#include "editor.hpp"
#include "article.hpp"


int main(){
    std::vector<std::vector<int>> dv;
    for(auto i = 0; i < 10; ++i){
        std::vector<int> v; dv.push_back(v);
    }
    for(auto i = 0; i < 10; ++i){
        for(auto j = 0; j < 10; ++j) dv[i].push_back(j);
    }
    for(auto i = 0; i < 10; ++i){
        for(auto j = 0; j < 10; ++j){
            std::cout<<dv[i][j]<<" ";
        } 
        std::cout<<std::endl;
            
    }

    std::ofstream of("test.csv");
    Write_2dVector(of, dv);
    
}