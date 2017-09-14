#ifndef RADIXSORT_HPP_INCLUDED
#define RADIXSORT_HPP_INCLUDED
#include <vector>
#include <iostream>
#include "CountSort.hpp"
using namespace std;
 
// A utility function to get maximum value in arr[]
int getMax(vector<int> ent)
{
    int mx = ent[0];
    for (int i = 1; i < ent.size()-1; i++)
        if (ent[i] > mx)
            mx = ent[i];
    return mx;
}

int getMin(vector<int> ent){
   int mx = ent[0];
    for (int i = 1; i < ent.size()-1; i++)
        if (ent[i] < mx)
            mx = ent[i];
    return mx;
}

void shift(vector<int> &ent,int m)
{
    for (int i = 0; i < ent.size()-1; i++)
 	ent[i]=ent[i]-m;
}

void rs(vector<int> &ent)
{
    // Find the maximum number to know number of digits

int min = getMin(ent);//pega o menor
//cout<<"min"<<min;
if(min<0)shift(ent,min);//se for menor que zero, da um shift
int *tmp=(int*)malloc((ent.size()-1)*sizeof(int));//aloca um array de inteiros para entrar na funcao
for(int i=0;i<ent.size()-1;i++)//passa os valores do vetor para o array
tmp[i]=ent[i];
    int max = getMax(ent);//pega o valor maximo para determinar o numero de digitos
    for (int exp = 1; max/exp > 0; exp *= 10)
        cs(tmp,ent.size()-1, exp);//chama o counting sort
for(int i=0;i<ent.size()-1;i++)
ent[i]=tmp[i];
if(min<0)shift(ent,-min);
free(tmp);
}


#endif // RADIXSORT_HPP_INCLUDED
