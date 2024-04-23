
#include "SecretWord.h"
#include <cstdlib> // for rand()

vector<string> SecretWord::generate()
{
    map<string, string> words_dictionary =
        {
            {"hangman", "the game you are playing"},
            {"computer", "an electronic device for processing data"},
            {"algorithm", "a step-by-step procedure for solving a problem"},
            {"galaxy", "a large system of stars, gas, and dust held together by gravity"},
            {"jazz", "a genre of music characterized by improvisation of syncopation"}};
    
    
    vector<string> s = {"hangman", "computer", "algorithm", "galaxy", "jazz"};
    srand(time(0));
    int x = rand() % s.size();
    vector<string> res = {s[x], words_dictionary[s[x]]};
    return res;
};