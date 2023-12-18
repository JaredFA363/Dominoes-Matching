#include "../headers/performanceTest.h"
#include "../headers/ASEDominoes.h"

using namespace std::chrono;

microseconds timingTest_dominoes(const std::string& startingDominoPath,
    const std::string& otherDominoes,
    const std::vector<std::string>& input)
{
    steady_clock::time_point startTime = steady_clock::now();

    Dominoes dominoes(startingDominoPath, otherDominoes);

    for (int x = 0; x < input.size(); x++) {
        if (input[x] == "Right" && !dominoes.completed()) {
            Domino nextrightDomino = dominoes.next_domino_right();
        }
        else if (input[x] == "Left" && !dominoes.completed()) {
            Domino nextleftDomino = dominoes.next_domino_left();
        }
        else {
            std::cout << "Incorrect Input" << std::endl;
        }
    }

    steady_clock::time_point finishTime = steady_clock::now();

    microseconds timeTaken = duration_cast<microseconds>(finishTime - startTime);
    microseconds meanTimePerOperation = timeTaken / input.size();

    return meanTimePerOperation;
}

int main1() //change mains when running
{
    const std::string startingDominoFile = "C:\\Users\\jared\\OneDrive\\Documents\\YEAR3\\AdvSoftEng\\Coursework1\\dominoes-test_data\\6k\\6k-starting-domino.txt"; // Input file path
    const std::string UnorderedDominoFile = "C:\\Users\\jared\\OneDrive\\Documents\\YEAR3\\AdvSoftEng\\Coursework1\\dominoes-test_data\\6k\\6k-input-coloured.txt"; // Input file path

    //std::vector<std::string> input = { "Left", "Right", "Left", "Left", "Left", "Left", "Right", "Right", "Right" };
    std::vector<std::string> input;
    for (int x = 0; x < 1000; x++) {
        input.push_back("Right");
    }
    std::chrono::microseconds meanTimePerOperation = timingTest_dominoes(startingDominoFile, UnorderedDominoFile, input);

    std::cout << "Dominoes being tested: Custom Dominoes Class" << std::endl;
    std::cout << "Number of operations: " << input.size() << std::endl;
    std::cout << "Mean time taken per operation: " << meanTimePerOperation.count() << " microseconds." << std::endl;

    return 0;
}