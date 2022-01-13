#include "help.h"

void help()
{
    std::cout << "Program nalezy uruchomic z nastepuj¹cymi parametrami: " << std::endl;
    std::cout << "-i plik wejsciowy " << std::endl;
    std::cout << "-o plik wyjsciowy " << std::endl;
    std::cout << "-w wspolczynnik wymierania [0, 1]" << std::endl;
    std::cout << "-r wspolczynnik rozmnazania [0, 1]" << std::endl;
    std::cout << "-p liczba pokolen " << std::endl;
    std::cout << "-k liczba k par osobnikow losowanych do krzyzowania " << std::endl;
    std::cout << "-h wyswietlenie wszystkich mozliwych przelanikow " << std::endl;
}