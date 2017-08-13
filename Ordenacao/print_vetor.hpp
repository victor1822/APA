#ifndef PRINT_VECTOR_HPP_INCLUDED
#define PRINT_VECTOR_HPP_INCLUDED
#include<vector>
using namespace std;

void printv(vector<int> v){
for(int i=0;i<v.size()-1;i++) cout<<v[i]<<" ";
}

#endif // PRINT_VECTOR_HPP_INCLUDED
