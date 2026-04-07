#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <cctype>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& v){
    int n =v.size();
    for (int i=0;i<n-1;i++){
        for(int j =0; j<n-i-1;j++){
            if (v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
}

double medirTempo(void(*func)(vector<int>&),vector<int>v){
    auto inicio = high_resolution_clock::now();
    func(v);
    auto fim = high_resolution_clock::now();
    duration<double>duracao=fim-inicio;
    return duracao.count();
}

int main(){
    ifstream arquivo("C:\\Users\\David R\\Documents\\GitHub\\Analise-de-Desempenho\\atividades\\bsort-qsort\\arq.txt");
    vector<int>dados;
    int num;

    if(arquivo.is_open()){
        string linha;
        while(getline(arquivo,linha)){
            for (char&c : linha){
                if (!isdigit(c)&& c !='-'&& c !=' ') c = ' ';
            }
            stringstream ss(linha);
            while (ss>>num){
                dados.push_back(num);
            }
        }
        arquivo.close();
    }else{
        cout<<"erro ao abrir arquivo\n";
        return 1;
    }

    cout<<"Algoritmo: Bubble Sort\n";
    double somaBubble=0;
    for (int i =0;i<5;i++){
        vector<int> copia = dados;
        double tempo = medirTempo(bubbleSort, copia);
        somaBubble += tempo;
        cout <<"Execução " <<i+1<<": "<<tempo<<"s\n";
    }

    cout <<"Media: " <<somaBubble/5<< "s\n\n";


    cout <<"Algoritmo: Quick Sort\n";
    double somaQuick = 0;
    for (int i=0;i<5;i++){
        vector<int> copia=dados;
        auto inicio = high_resolution_clock::now();
        sort(copia.begin(),copia.end());
        auto fim = high_resolution_clock::now();
        duration<double> duracao = fim-inicio;
        double tempo=duracao.count();
        somaQuick +=tempo;
        cout <<"Execução " <<i+1<<": "<<tempo<<"s\n";
    }
    cout <<"Media: " <<somaQuick/5<< "s\n\n";


    vector<int> ordenado = dados;
    sort(ordenado.begin(), ordenado.end());

    ofstream saida("arq-ordenado.txt");

    if (saida.is_open()) {
        for (int n : ordenado) {
            saida << n << " ";
        }
        saida.close();
    } else {
        cout << "Erro ao criar arq-ordenado.txt\n";
    }

    return 0;
}
