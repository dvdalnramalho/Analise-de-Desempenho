#include <iostream>

int main(){
    int contador = 0;
    int numero;
    while (true)
    {
        std::cin >> numero;

        if(std::cin.fail() || numero <= 0) {
            std::cin.clear();               
            std::cin.ignore(1000, '\n');
            std::cout << "Numero ou caractere invalido, tente novamente:\n";
    }
        else{
            break;
        }
    }
    std::cout<<numero<<'\n';
    for(int i = 2; i <= numero; i++){
        if(i == 2 || i == 3){
            contador +=1;
            std::cout << i << "-";
        }
        else if(i % 2 != 0 && i % 3 != 0){
            bool primo = true;
            for (int j = 5; j * j <= i; j += 6){
                if((i % j == 0) || (i % (j + 2) == 0)){
                    primo = false;
                    break;
                }
            }
            if(primo){
                contador +=1;
                std::cout << i << "-";
            }
        }
    }
    std::cout<<'\n'<<contador;
    std::cin.ignore();
    std::cin.get();
    return 0;
}
