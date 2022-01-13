/*!
 * @file fileSupport.h
 * @brief plik z funkcjami obs³uguj¹cymi pliki
 */
#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "struct.h"

 /*!
  * \brief load - odczytuje plik wejsciowy
  * \param vectorChromosomes - kontener przechowujacy chromosomy wszystkich osobnikow
  * \return true jesli udalo sie zaladowac chromosomy z pliku wejsciowego
  */
bool load(std::vector<std::vector<int>>& vectorChromosomes, startupParams& params);
/*!
 * \brief print - wyswietla na konsole aktualnie istniejace chromosomy
 * \param vectorChromosomes - kontener przechowujacy chromosomy wszystkich osobnikow
 */
void print(const std::vector<std::vector<int>>& vectorChromosomes);
/*!
 * \brief save - funkcja zapisuje do pliku wyjsciowego wszystkie chromosomy ktore przezyly do ostatniego pokolenia
 * \param params - struktura przechowujaca paramerty startowe
 * \param vectorChromosomes kontener przechowujacy chromosomy wszystkich osobnikow
 */
void save(const std::vector<std::vector<int>>& vectorChromosomes, startupParams& params);

