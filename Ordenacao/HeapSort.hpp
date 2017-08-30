#ifndef HEAPSORT_HPP_INCLUDED
#define HEAPSORT_HPP_INCLUDED
#include<vector>
#include"QuickSort.hpp"
using namespace std;


void CriaHeap(vector<int> &v,int i, int f){//vetor
int aux = v[i];
int j = i*2+1;
while(j<=f) {
if(j<f){
if(v[j]<v[j+1]) j = j+1;

}//if(j<f)
if(aux<v[j]){
v[i] = v[j];
i = j;
j= 2*i+1;
} else j = f+1;
}//while
v[i] = aux;
}


void hs(vector<int> &v){
int i,aux;
int size = v.size()-1;
for(i=(size-1)/2; i>=0 ;i--)
CriaHeap(v,i,size-1);

for(i=size-1;i>=1;i--){
swap(v[0],v[i]);
CriaHeap(v,0,i-1);
}
}

#endif // HEAPSORT_HPP_INCLUDED
