#include<string.h>
#include "mainFunctions.h"
#include "struct.h"

bool canReproduce(const std::vector<int>& parent1, const std::vector<int>& parent2, startupParams& params)
{
    double tmp = std::accumulate(parent1.begin(), parent1.end(), 0.0);
    double arg1 = (tmp - *std::min(parent1.begin(), parent1.end())) / tmp;
    tmp = std::accumulate(parent2.begin(), parent2.end(), 0.0);
    double arg2 = (tmp - *std::min(parent2.begin(), parent2.end())) / tmp;
    return (arg1 > params.r) && (arg2 > params.r);
}

void newGeneration(std::vector<std::vector<int>>& vectorChromosomes, startupParams& params)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, vectorChromosomes.size() - 1);

    std::vector<std::vector<int>> child;
    for (int i = 0; i < params.k; ++i)
    {
        int parent_idx_1 = distrib(gen);
        int parent_idx_2 = distrib(gen);
        while (parent_idx_1 == parent_idx_2) parent_idx_2 = distrib(gen);
        if (canReproduce(vectorChromosomes[parent_idx_1], vectorChromosomes[parent_idx_2], params))
        {
            child.emplace_back();
            for (int j = 0; j < vectorChromosomes[parent_idx_1].size() / 2; ++j)
            {
                child.back().push_back(vectorChromosomes[parent_idx_1][j]);
            }
            for (int j = vectorChromosomes[parent_idx_2].size() / 2; j < vectorChromosomes[parent_idx_2].size(); ++j)
            {
                child.back().push_back(vectorChromosomes[parent_idx_2][j]);
            }
        }
    }
    vectorChromosomes.insert(vectorChromosomes.end(), child.begin(), child.end());
}

void extinction(std::vector<std::vector<int>>& vectorChromosomes, startupParams& params)
{
    vectorChromosomes.erase(std::remove_if(vectorChromosomes.begin(), vectorChromosomes.end(), [&params](auto& elem)
        {
            double tmp = std::accumulate(elem.begin(), elem.end(), 0.0);
            double arg = (tmp-*std::max_element(elem.begin(),elem.end())) / tmp;
            return arg < params.w;
        }),
        vectorChromosomes.end());
 
}

void run(int argStartup, char** argGiven, startupParams& params)
{
    if (argStartup == 1 || (argStartup == 2 && (strcmp(argGiven[1], "-h") == 0)))
    {
        help();
    }
    else if (argStartup == 13)
    {
        if (!init(argGiven, params))
        {
            std::cout << "Nieprawidlowe wartosci przy wybranych parametrach!!!" << std::endl;
            return;
        }
        std::vector<std::vector<int>> vectorChromosomes;
        if (!load(vectorChromosomes, params)) return;
        std::cout << "Pokolenie poczatkowe!" << std::endl;
        print(vectorChromosomes);
        for (int i = 0; i < params.p; ++i)
        {
            newGeneration(vectorChromosomes, params);
            extinction(vectorChromosomes, params);
        }
        std::cout << "Pokolenie koncowe!" << std::endl;
        print(vectorChromosomes);
        save(vectorChromosomes, params);
    }
    else
    {
        std::cout << "Nieprawidlowe parametry przy uruchomieniu programu!!!" << std::endl;
    }
}