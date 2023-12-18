#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using Domino = std::pair<std::string, std::string>;

class Dominoes
{
public:
    Dominoes(std::string, std::string);
    Domino next_domino_right();
    Domino next_domino_left();
    bool completed();
    void output_line();
    Domino get_right_domino();
    Domino get_left_domino();
    std::vector<Domino> domino_line;

private:
    std::vector<Domino> read_dominoes(std::string);
    std::vector<Domino> unordered_dominoes;
    std::map<std::string, Domino> DomiMap_Right;
    std::map<std::string, Domino> DomiMap_Left;
};