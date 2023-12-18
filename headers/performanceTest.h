#pragma once
#include <chrono>
#include <string>
#include <vector>

std::chrono::microseconds timingTest_dominoes(const std::string& startingDominoPath, const std::string& otherDominoes, const std::vector<std::string>& input);