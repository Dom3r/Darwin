#include"dataParsing.h"
bool init(char** argGiven, startupParams& params)
{
    std::string c;
    for (int i = 1; i < 13; ++i)
    {
        c = argGiven[i];
        if (strcmp(argGiven[i], "-i") == 0)
        {
            params.inputFile = argGiven[i + 1];
        }
        else if (strcmp(argGiven[i], "-o") == 0)
        {
            params.outputFile = argGiven[i + 1];
        }
        else if (strcmp(argGiven[i], "-w") == 0)
        {
            params.w = atof(argGiven[i + 1]);
        }
        else if (strcmp(argGiven[i], "-r") == 0)
        {
            params.r = atof(argGiven[i + 1]);
        }
        else if (strcmp(argGiven[i], "-p") == 0)
        {
            params.p = atoi(argGiven[i + 1]);
        }
        else if (strcmp(argGiven[i], "-k") == 0)
        {
            params.k = atoi(argGiven[i + 1]);
        }
    }

    if (params.inputFile.empty() || params.outputFile.empty())
    {
        return false;
    }
    if (params.w < 0 || params.w > 1)
    {
        return false;
    }
    if (params.r < 0 || params.r > 1)
    {
        return false;
    }
    if (params.p < 0 || params.k < 0)
    {
        return false;
    }
    return true;
}