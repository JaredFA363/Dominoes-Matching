#include "../headers/ASEDominoes.h"

Dominoes::Dominoes(std::string startingDominoPath, std::string otherDominoes) {
    //Reading Dominoes from the starting and unordered files
    std::vector<Domino> startingDomino = read_dominoes(startingDominoPath);
    domino_line.push_back(startingDomino.front());
    unordered_dominoes = read_dominoes(otherDominoes);
    for (const auto& domino : unordered_dominoes) {
        DomiMap_Right[domino.first] = domino;
        DomiMap_Left[domino.second] = domino;
    }
}

std::vector<Domino> Dominoes::read_dominoes(std::string path) {
    //Reading dominoes and splitting into pairs
    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        std::cout << "Unable to open file " << path << std::endl;
        return {};
    }

    std::vector<Domino> dominoes;
    std::string line;
    while (std::getline(input_file, line)) {
        int pos = line.find(':');
        if (pos != std::string::npos) {
            std::string leftpart = line.substr(0, pos);
            std::string rightpart = line.substr(pos + 1);
            dominoes.emplace_back(leftpart, rightpart);
        }
    }
    input_file.close();
    return dominoes;
}

Domino Dominoes::next_domino_right() {
    //Finding domino in hash table adding to line then deleting
    Domino matchin_Domino = get_right_domino();
    domino_line.push_back(matchin_Domino);
    unordered_dominoes.erase(std::remove(unordered_dominoes.begin(), unordered_dominoes.end(), matchin_Domino), unordered_dominoes.end());
    return matchin_Domino;
    return {};
}

Domino Dominoes::next_domino_left() {
    //Finding domino in hash table adding to line then deleting
    Domino matching_Domino = get_left_domino();
    domino_line.insert(domino_line.begin(), matching_Domino);
    unordered_dominoes.erase(std::remove(unordered_dominoes.begin(), unordered_dominoes.end(), matching_Domino), unordered_dominoes.end());
    return matching_Domino;
    return {};
}

bool Dominoes::completed() {
    return unordered_dominoes.empty();
}

void Dominoes::output_line() {
    for (auto& domino : domino_line) {
        std::cout << domino.first << ":" << domino.second << " ";
    }
    std::cout << std::endl;
}

Domino Dominoes::get_left_domino() {
    Domino left_domino = DomiMap_Left[domino_line.front().first];
    return left_domino;
}

Domino Dominoes::get_right_domino() {
    Domino right_domino = DomiMap_Right[domino_line.back().second];
    return right_domino;
}
