#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include "print_vetor.hpp"
#include "SelectionSort.hpp"//ss(x) //type(x)==vector<int>x
#include "QuickSort.hpp"//qs(x,c,f) x vector, c int(começo) f int(fim)
#include "BubbleSort.hpp"//bs(vector<int>x)
using namespace std;

int main()
{   /**=====Abre arquivo(ler/input)=====*/
    vector<int> e;
    fstream file;
    fstream file2;
    int s;
    file.open("input.txt");//abre o arquivo d mesmo diretorio do projeto com o nome entrada.txt

    if(!file.is_open()) cout<<"error while opening the file"<<endl;
    else cout<<"opened successfully"<<endl;// testa se abre sem problemas

   while(file.good()){//enquanto o arquivo nao terminar
    file>>s;
    e.push_back(s);
    }
	
    /**====Abre arquivo(escrever/output)====*/
    ofstream outputFile("output.txt");
    file2.open("output.txt");
//implementar heuristica aq <3
cout<<endl<<"O tamanho do vetor eh:"<<e.size()<<endl;
printv(e);
vector<int>c=e;
vector<int>b=e;
cout<<endl<<"resolvendo com quicksort:"<<endl;
qs(c,0,c.size()-2);
printv(c);
cout<<endl<<"resolvendo com o selectionsort:"<<endl;
ss(e);
printv(e);
cout<<endl<<"resolvendo com o bubblesort:"<<endl;
bs(b);
printv(b);

    file.close();
    file2.close();
}
