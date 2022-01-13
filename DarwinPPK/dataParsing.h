/**
* @file dataParsing.h
* @brief plik z funkcja obslugujaca parsowanie
*/
#pragma once
#include<iostream>
#include<string.h>
#include"struct.h"
/*!
 * \brief init - funkcja parsuje argumenty wywolania programu
 * \param argGiven - argumenty podane wraz z jego parametrami
 * \return true jesli udalo sie pomyslnie zainicjowac kazdy parametr
 */
bool init(char** argGiven, startupParams& params);


