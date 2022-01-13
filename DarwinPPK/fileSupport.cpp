#include "fileSupport.h"

bool load(std::vector<std::vector<int>>& vectorChromosomes, startupParams& params)
{
    std::ifstream infile(params.inputFile);
    if (infile.is_open())
    {
        std::string line;
        while (std::getline(infile, line))
        {
            vectorChromosomes.emplace_back();
            std::stringstream lines(line);
            int value;
            while (lines >> value)
            {
                vectorChromosomes.back().push_back(value);
            }
        }
        infile.close();
        return true;
    }

    std::cout << "Niemozna otworzyc pliku wejsciowego!!!" << std::endl;
    return false;
}

void print(const std::vector<std::vector<int>>& vectorChromosomes)
{
    std::cout << "Lista chromosomow wszystkich osobnikow" << std::endl;
    for (const auto& chromosom : vectorChromosomes)
    {
        for (const auto& gen : chromosom)
        {
            std::cout << gen << " ";
        }
        std::cout << std::endl;
    }
}

void save(const std::vector<std::vector<int>>& vectorChromosomes, startupParams& params)
{
    std::ofstream fileOut(params.outputFile);
    if (!fileOut.is_open())
    {
        std::cout << "Nie mozna otworzyc pliku wyjsciowego!" << std::endl;
        return;
    }
    for (const auto& chromosom : vectorChromosomes)
    {
        for (const auto& gen : chromosom)
        {
            fileOut << gen << " ";
        }
        fileOut << std::endl;
    }
}