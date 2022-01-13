/**
* @file DarwinPPK.cpp
* @brief plik z mainem
*/
#include <iostream>
#include "dataParsing.h"
#include "mainFunctions.h"
/*!
 * \brief main
 * \param argStartup - liczba argumentow uruchomieniowych
 * \param argGiven - nazwa programu i parametry podane wraz z jego parametrami.
 * \return 0 jesli program pomyslnie zakonczyl dzialanie
 */
int main(int argStartup, char** argGiven)
{
    startupParams params;
    run(argStartup, argGiven, params);
    return 0;
}