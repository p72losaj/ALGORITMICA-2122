#include "reinas.hpp"
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool Lugar(int k,std::vector<int> x){
    for(int i=1; i < (k-1); i++){
        int valor1 = abs(x[i]-x[k]);
        if( (x[i] == x[k] || valor1 ) == abs(i - k) ){
            return false;
        }
    }
    return true;
}

void Reinas(int n,std::vector<std::vector<int>> &matriz){
    
}