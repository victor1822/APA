#ifndef COUNTSORT_HPP_INCLUDED
#define COUNTSORT_HPP_INCLUDED
#include <iostream>
#include<vector>
using namespace std;

int cs(vector<int> &ent){
//int vector<int> r;
int *resposta = (int*)malloc((ent.size()-1)*sizeof(int));
int menor,maior;
menor=maior=ent[0];
for(int i=0;i<ent.size()-1;i++){
if(ent[i]<menor)menor=ent[i];
if(ent[i]>maior)maior=ent[i];
}
int v=maior-menor+1;
int *tmp  = (int*)malloc(v*sizeof(int));

for(int i=0;i<v;i++){
tmp[i]=0;
}//zerando o vetor temporario

for(int i=0;i<ent.size()-1;i++){
tmp[ent[i]-menor]++;
}//contando

for(int i=1;i<v;i++){
tmp[i]=tmp[i]+tmp[i-1];
}//somando

for(int i=0;i<ent.size()-1;i++){
resposta[tmp[ent[i]-menor]-- -1]=ent[i];
}

for(int i=0;i<ent.size()-1;i++){
ent[i]=resposta[i];
}
free(tmp);
free(resposta);
}

int cs(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    //contador de ocorrencias
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
//calcula posicao correta no array de saida
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // constroi o array de saida
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
//passa os valores corretos para o array
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


#endif // COUNTSORT_HPP_INCLUDED
