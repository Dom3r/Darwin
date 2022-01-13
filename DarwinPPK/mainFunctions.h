/**
* @file mainFunctions.h
* @brief plik z g³ównymi funkcjami programu 
*/
#pragma once
#include <random>
#include <algorithm>
#include <numeric>
#include "dataParsing.h"
#include "help.h"
#include "fileSupport.h"
/*!
 * \brief canReproduce - sprawdza czy wylosowana para osobnikow moze sie rozmnazac
 * \param parent1 - chromosom rodzica 1
 * \param parent2 - chromosom rodzica 2
 * \param params - struktura przechowujaca paramerty startowe
 * \return true jesli oosobniki moga sie rozmnazac
 */
bool canReproduce(const std::vector<int>& parent1, const std::vector<int>& parent2, startupParams& params);

/*!
 * \brief newGeneration - funkcja dodaje do kontenera przechowujacych chromosomy nowo narodzone osobniki
 * \param params - struktura przechowujaca paramerty startowe
 * \param vectorChromosomes - kontener przechowujacy chromosomy wszystkich osobnikow
 */
void newGeneration(std::vector<std::vector<int>>& vectorChromosomes, startupParams& params);

/*!
 * \brief extinction - funkcja usuwa osobniki z kontenera, ktore  spelniaja warunek wymarcia
 * \param vectorChromosomes - kontener przechowujacy chromosomy wszystkich osobnikow
 * \param params - struktura przechowujaca paramerty startowe
 */
void extinction(std::vector<std::vector<int>>& vectorChromosomes, startupParams& params);

/*!
 * \brief run - funkcja sprawdzajaca argumenty i wykonujaca odpowiednie instrukcje dla nich
 * \param argStartup - ilosc argumentow wywolania
 * \param argGiven - argumenty wywolania
 * \param params - struktura przechowujaca paramerty startowe
 */
void run(int argStartup, char** argGiven, startupParams& params);


