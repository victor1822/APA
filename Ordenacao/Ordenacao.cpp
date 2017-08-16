#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include "print_vetor.hpp"// recebe um std::vector e imprime seu conteúdo 
#include "SelectionSort.hpp"//ss(x) //type(x) = std::vector(recebe um std::vector e ordena, assim como qs(),bs() e is())
#include "QuickSort.hpp"//qs(x,c,f) type(x) = std::vector, type(c) = int(começo) type(f) = int(fim)
#include "BubbleSort.hpp"//bs(vector<int>x) type(x) = std::vector
#include "IsertionSort.hpp"//is(x) type(x) = std::vector
using namespace std;

int main()
{   /**=====Abre arquivo(ler/input)=====*/
    vector<int> e;
    fstream file; 
    fstream file2;
    int s;
    file.open("input.txt");//abre o arquivo do mesmo diretorio do projeto com o nome input.txt

    if(!file.is_open()) cout<<"error while opening the file"<<endl;
    else cout<<"opened successfully"<<endl;// testa se abre sem problemas

   while(file.good()){//enquanto o arquivo nao terminar
    file>>s;
    e.push_back(s);
    }
	
    /**====Abre arquivo(escrever/output)====*/
    ofstream outputFile("output.txt");
    file2.open("output.txt");//arquivo para escrever a saída, deve estar no mesmo diretório do projeto e com nome:"output.txt"
    vector<int> meuvetor=e;
    qs(meuvetor,0,meuvetor.size()-2);
     for(int i=0;i<meuvetor.size()-1;i++){//loop de escrita dos valores ordenados do vetor no arquivo de saída
    file2<<meuvetor[i]<<" ";
    }
//Aqui testa cada algoritmo de ordenação implementado e exibe na tela do terminal o resultado encontrado para cada algoritmo
cout<<endl<<"O tamanho do vetor eh:"<<e.size()<<endl;
printv(e);//printv() recebe um vetor de entrada e imprime seus valores sequencialmente
vector<int>c=e;
vector<int>b=e;
vector<int>i=e;
cout<<endl<<"resolvendo com quicksort:"<<endl;
qs(c,0,c.size()-2);
printv(c);
cout<<endl<<"resolvendo com o selectionsort:"<<endl;
ss(e);
printv(e);
cout<<endl<<"resolvendo com o bubblesort:"<<endl;
bs(b);
printv(b);
cout<<endl<<"resolvendo com InsertionSort:"<<endl;
is(i);
printv(i);

    file.close();
    file2.close();
}
