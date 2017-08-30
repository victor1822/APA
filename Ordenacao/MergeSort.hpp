#ifndef MERGESORT_HPP_INCLUDED
#define MERGESORT_HPP_INCLUDED
#include<vector>
#include<stdlib.h>
#include<math.h>
using namespace std;
/*
void merge(vector<int>&v,int inicio,int meio,int fim){
int *temp,p1,p2,tamanho,i,j,k;
int fim1=0,fim2=0;
tamanho=fim-inicio+1;
p1=inicio;
p2=meio+1;
temp = (int *)malloc(tamanho*sizeof(int));
if(temp){
if(!fim1 && !fim2){
if(v[p1]<v[p2])temp[i]=v[p1++];
else temp[i]=v[p2++];
if(p1>meio) fim1=1;
if(p2>fim) fim2=1;
} else{
if(!fim1) temp[i]=v[p1++];
else temp[i]=v[p2++];
}
}//if(temp)
for(j=0,k=inicio;j<tamanho;j++,k++) v[k]=temp[j];
free(temp);
}

void ms(vector<int> &v,int inicio,int fim){
int meio;
if(inicio<fim){
meio=floor((inicio+fim)/2);
ms(v,inicio,meio);
ms(v,meio+1,fim);
merge(v,inicio,meio,fim);
}
}*/

void ms(vector<int> &v, int beg, int end)
{
	//int* v;
	//v = new int[end-beg+1];

	int i, j, k, middle;
	int* v_aux;

	if(beg == end)
		return;

	middle = (beg+end)/2; ///meio do vetor
	ms(v, beg, middle); //smalleramada recursiva que divide os vetores ao meio (a partir do inicio)
	ms(v, middle+1, end); //smalleramada recursiva que divide os vetores ao meio (a partir do meio)

	i = beg;
	j = middle+1;
	k = 0;

	v_aux = new int[end-beg+1];

	while((i < middle+1) || (j < end+1)) //enquanto o indicie incial for menor que o meio
	{									 //ou enquanto o indice do meio for menor que o fim

		if(i == middle+1) // se i(beg) passou da metade
		{

			v_aux[k] = v[j]; //vetor temporário pega o v[j]
			j++;
			k++;

		}
		else
		{

			if(j == end+1) //caso j passo da segunda metade
			{

				v_aux[k] = v[i]; //vetor temporario pega o v[i]
				i++;
				k++;

			}
			else
			{

				if(v[i] < v[j])
				{

					v_aux[k] = v[i];
					i++;
					k++;

				}
				else
				{

					v_aux[k] = v[j];
					j++;
					k++;

				}

			}

		}

	}

	for(i = beg; i <= end; i++) // copia para o vetor original no final
		v[i] = v_aux[i-beg];

	delete[] v_aux;

}

#endif // MERGESORT_HPP_INCLUDED
