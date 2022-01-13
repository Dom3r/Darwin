/**
* @file struct.h
* @brief plik z struktur¹ startowa
*/
#pragma once
#include<iostream>

struct startupParams
{
    std::string inputFile = "", outputFile = "";
    double w = -1, r = -1;
    int p = -1, k = -1;
};