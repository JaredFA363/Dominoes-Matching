#include "../headers/ASEDominoes.h"

int main() //change mains when running
{
    std::string startingDominoFile = "C:\\Users\\jared\\OneDrive\\Documents\\YEAR3\\AdvSoftEng\\Coursework1\\dominoes-test_data\\10\\10-starting-domino.txt"; //Add file path
    std::string UnorderedDominoFile = "C:\\Users\\jared\\OneDrive\\Documents\\YEAR3\\AdvSoftEng\\Coursework1\\dominoes-test_data\\10\\10-input-coloured.txt"; //Add file path

    Dominoes dominoes(startingDominoFile, UnorderedDominoFile);

    std::vector<std::string> input = { "Left", "Right", "Left", "Left" };
    //std::vector<std::string> input = { "Right", "Right", "Right"};

    for (int x = 0; x < input.size(); x++) {
        if (input[x] == "Right" && !dominoes.completed()) {
            Domino nextrightDomino = dominoes.next_domino_right();
        }
        else if (input[x] == "Left" && !dominoes.completed()) {
            Domino nextleftDomino = dominoes.next_domino_left();
        }
        else if (dominoes.completed()) {
            std::cout << "Line Complete" << std::endl;
        }
        else {
            std::cout << "Incorrect Input" << std::endl;
        }
    }

    dominoes.output_line();
    return 0;
}