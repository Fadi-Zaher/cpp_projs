#include <string>
#include <map>
#include <vector>
#include <iostream>
#ifndef SecretWord_H
#define SecretWord_H

using namespace std;

class SecretWord
{
public:
    string word;
    string explanation;
    vector<string> generate();
};
#endif