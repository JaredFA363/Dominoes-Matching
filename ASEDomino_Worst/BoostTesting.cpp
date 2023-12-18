#define BOOST_TEST_MODULE DominoTests

#include <boost/test/included/unit_test.hpp>

#include "../headers/ASEDomino_Worst.h"
#include <string>

BOOST_AUTO_TEST_CASE(dominoes_10_left_right)
{

    const std::string startingDominoFile = "C:\\Users\\jared\\OneDrive\\Documents\\YEAR3\\AdvSoftEng\\Coursework1\\dominoes-test_data\\10\\10-starting-domino.txt"; // Input file path
    const std::string UnorderedDominoFile = "C:\\Users\\jared\\OneDrive\\Documents\\YEAR3\\AdvSoftEng\\Coursework1\\dominoes-test_data\\10\\10-input-coloured.txt"; // Input file path
    std::vector<std::string> domino_line;

    std::vector<std::string> input = { "Left", "Right", "Left", "Right", "Left", "Right", "Left", "Right", "Left" };

    Dominoes dominoes(startingDominoFile, UnorderedDominoFile);

    for (int x = 0; x < input.size(); x++) {
        if (input[x] == "Right" && !dominoes.completed()) {
            Domino nextrightDomino = dominoes.next_domino_right();
        }
        else if (input[x] == "Left" && !dominoes.completed()) {
            Domino nextleftDomino = dominoes.next_domino_left();
        }
        else {
            BOOST_FAIL("Incorrect Input");
        }
    }

    std::ostringstream result;
    for (auto& domino : dominoes.domino_line) {
        result << domino.first << ":" << domino.second << " ";
    }

    std::ostringstream expectedOutput;
    expectedOutput << "rBC:biA biA:TDV TDV:jew jew:sbE sbE:iVk iVk:AGn AGn:XbL XbL:Cjj Cjj:wTb wTb:rBC "; // make sure space at end of string
    BOOST_CHECK_EQUAL(expectedOutput.str(), result.str());
}


BOOST_AUTO_TEST_CASE(dominoes_10_right)
{
    const std::string startingDominoFile = "C:\\Users\\jared\\OneDrive\\Documents\\YEAR3\\AdvSoftEng\\Coursework1\\dominoes-test_data\\10\\10-starting-domino.txt"; // Input file path
    const std::string UnorderedDominoFile = "C:\\Users\\jared\\OneDrive\\Documents\\YEAR3\\AdvSoftEng\\Coursework1\\dominoes-test_data\\10\\10-input-coloured.txt"; // Input file path
    std::vector<std::string> domino_line;

    std::vector<std::string> input = { "Right", "Right", "Right", "Right", "Right", "Right", "Right", "Right", "Right" };

    Dominoes dominoes(startingDominoFile, UnorderedDominoFile);

    for (int x = 0; x < input.size(); x++) {
        if (input[x] == "Right" && !dominoes.completed()) {
            Domino nextrightDomino = dominoes.next_domino_right();
        }
        else if (input[x] == "Left" && !dominoes.completed()) {
            Domino nextleftDomino = dominoes.next_domino_left();
        }
        else {
            BOOST_FAIL("Incorrect Input");
        }
    }

    std::ostringstream result;
    for (auto& domino : dominoes.domino_line) {
        result << domino.first << ":" << domino.second << " ";
    }

    std::ostringstream expectedOutput;
    expectedOutput << "iVk:AGn AGn:XbL XbL:Cjj Cjj:wTb wTb:rBC rBC:biA biA:TDV TDV:jew jew:sbE sbE:iVk "; // make sure space at end of string
    BOOST_CHECK_EQUAL(expectedOutput.str(), result.str());
}

BOOST_AUTO_TEST_CASE(dominoes_1k_left_right)
{

    const std::string startingDominoFile = "C:\\Users\\jared\\OneDrive\\Documents\\YEAR3\\AdvSoftEng\\Coursework1\\dominoes-test_data\\1K\\1k-starting-domino.txt"; // Input file path
    const std::string UnorderedDominoFile = "C:\\Users\\jared\\OneDrive\\Documents\\YEAR3\\AdvSoftEng\\Coursework1\\dominoes-test_data\\1K\\1k-input-coloured.txt"; // Input file path
    std::vector<std::string> domino_line;

    std::vector<std::string> input = { "Left", "Right", "Left", "Right", "Left", "Right", "Left", "Right", "Left", "Right", "Left", "Right", "Left" };

    Dominoes dominoes(startingDominoFile, UnorderedDominoFile);

    for (int x = 0; x < input.size(); x++) {
        if (input[x] == "Right" && !dominoes.completed()) {
            Domino nextrightDomino = dominoes.next_domino_right();
        }
        else if (input[x] == "Left" && !dominoes.completed()) {
            Domino nextleftDomino = dominoes.next_domino_left();
        }
        else {
            BOOST_FAIL("Incorrect Input");
        }
    }

    std::ostringstream result;
    for (auto& domino : dominoes.domino_line) {
        result << domino.first << ":" << domino.second << " ";
    }

    std::ostringstream expectedOutput;
    expectedOutput << "rkUZu:TBoWm TBoWm:RQskg RQskg:FuNrF FuNrF:LYhHN LYhHN:whoRM whoRM:QIGqf QIGqf:Xegdx Xegdx:lLqPY lLqPY:ERctc ERctc:ayGuS ayGuS:RttbJ RttbJ:TakDV TakDV:UIROI UIROI:xEKvj "; // make sure space at end of string
    BOOST_CHECK_EQUAL(expectedOutput.str(), result.str());
}


BOOST_AUTO_TEST_CASE(dominoes_1k_right)
{
    const std::string startingDominoFile = "C:\\Users\\jared\\OneDrive\\Documents\\YEAR3\\AdvSoftEng\\Coursework1\\dominoes-test_data\\1K\\1k-starting-domino.txt"; // Input file path
    const std::string UnorderedDominoFile = "C:\\Users\\jared\\OneDrive\\Documents\\YEAR3\\AdvSoftEng\\Coursework1\\dominoes-test_data\\1K\\1k-input-coloured.txt"; // Input file path
    std::vector<std::string> domino_line;

    std::vector<std::string> input = { "Right", "Right", "Right", "Right", "Right", "Right", "Right" };

    Dominoes dominoes(startingDominoFile, UnorderedDominoFile);

    for (int x = 0; x < input.size(); x++) {
        if (input[x] == "Right" && !dominoes.completed()) {
            Domino nextrightDomino = dominoes.next_domino_right();
        }
        else if (input[x] == "Left" && !dominoes.completed()) {
            Domino nextleftDomino = dominoes.next_domino_left();
        }
        else {
            BOOST_FAIL("Incorrect Input");
        }
    }

    std::ostringstream result;
    for (auto& domino : dominoes.domino_line) {
        result << domino.first << ":" << domino.second << " ";
    }

    std::ostringstream expectedOutput;
    expectedOutput << "Xegdx:lLqPY lLqPY:ERctc ERctc:ayGuS ayGuS:RttbJ RttbJ:TakDV TakDV:UIROI UIROI:xEKvj xEKvj:iYxIr "; // make sure space at end of string
    BOOST_CHECK_EQUAL(expectedOutput.str(), result.str());
}

BOOST_AUTO_TEST_CASE(dominoes_incorrect_input)
{
    const std::string startingDominoFile = "C:\\Users\\jared\\OneDrive\\Documents\\YEAR3\\AdvSoftEng\\Coursework1\\dominoes-test_data\\1K\\1k-starting-domino.txt"; // Input file path
    const std::string UnorderedDominoFile = "C:\\Users\\jared\\OneDrive\\Documents\\YEAR3\\AdvSoftEng\\Coursework1\\dominoes-test_data\\1K\\1k-input-coloured.txt"; // Input file path
    std::vector<std::string> domino_line;

    std::vector<std::string> input = { "Up" };

    Dominoes dominoes(startingDominoFile, UnorderedDominoFile);

    for (int x = 0; x < input.size(); x++) {
        if (input[x] == "Right" && !dominoes.completed()) {
            Domino nextrightDomino = dominoes.next_domino_right();
        }
        else if (input[x] == "Left" && !dominoes.completed()) {
            Domino nextleftDomino = dominoes.next_domino_left();
        }
        //else {
        //    BOOST_FAIL("Incorrect Input");
        //}
    }

    std::ostringstream result;
    for (auto& domino : dominoes.domino_line) {
        result << domino.first << ":" << domino.second << " ";
    }

    std::string expectedOutput = "Xegdx:lLqPY ";

    BOOST_CHECK_EQUAL(expectedOutput, result.str());
}