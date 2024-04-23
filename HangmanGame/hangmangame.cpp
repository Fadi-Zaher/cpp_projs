#include <iostream>
#include "SecretWord.h"
#include <vector>

using namespace std;

#define NUM_OF_ERRORS 4

SecretWord Init();
void printInstructions();
void printCurrentResult(const vector<char> &current_result);
void printHangedMan(int errors);

int main()
{
    SecretWord sw = Init();
    printInstructions();
    string explanation =
        "\n\nGAME STARTED!!\n\n"
        "in this game you will need to insert letters and try to achive revealing the full word\n"
        "if the letter you insert is wrong the chances of survival of the man is going to decrease\n"
        "if you succeed to reveal the full word, you win and you will win\n"
        "anytime you can type : restart, to start over..... have fun!!\n";

    int input;
    cin >> input;

    bool game_started = (input == 1);

    if (!game_started)
        return 0;

    cout << "\n\nGAME STARTED!!\n\n"
         << sw.explanation << endl;

    vector<char> current_result(sw.word.size(), '_');

    printCurrentResult(current_result);

    int count_error = 0;
    int num_of_success_inputs = 0;
    printHangedMan(count_error);
    while (count_error < NUM_OF_ERRORS && num_of_success_inputs != sw.word.size())
    {
        cout << "Input letter: ";
        string input_letter;
        cin >> input_letter;

        if (input_letter == "2")
            break;

        if (input_letter.size() != 1)
        {
            cout << "You have entered wrong input <" + input_letter + ">" << endl;
            continue;
        }

        bool found = false;
        for (int i = 0; i < sw.word.size(); ++i)
        {
            if (input_letter[0] == sw.word[i])
            {
                current_result[i] = input_letter[0];
                sw.word[i] = '?';
                num_of_success_inputs++;
                found = true;
            }
        }

        if (!found)
            count_error++;

        printHangedMan(count_error);

        printCurrentResult(current_result);
        cout << "Current error count: " << count_error << endl
             << endl;
    }

    bool won = (num_of_success_inputs == sw.word.size());
    if (won)
        cout << "YOU ARE THE WINNER" << endl;
    else
        cout << "YOU HAVE LOST :(" << endl;

    return 0;
}
void printInstructions()
{
    cout << "Welcome to Hangman game" << endl;
    cout << "Guide:" << endl;
    cout << "- To start the game, enter 1" << endl;
    cout << "- To exit the game, enter 2" << endl;
}

void printCurrentResult(const vector<char> &current_result)
{
    for (char c : current_result)
        cout << c << " ";
    cout << endl
         << endl;
}
void printHangedMan(int errors)
{
    switch (errors)
    {
    case 0:
        cout << "    ____" << endl;
        cout << "   |    |" << endl;
        cout << "   |" << endl;
        cout << "   |" << endl;
        cout << "   |" << endl;
        cout << "   |" << endl;
        cout << "___|___" << endl;
        break;
    case 1:
        cout << "    ____" << endl;
        cout << "   |    |" << endl;
        cout << "   |    O" << endl;
        cout << "   |" << endl;
        cout << "   |" << endl;
        cout << "   |" << endl;
        cout << "___|___" << endl;
        break;
    case 2:
        cout << "    ____" << endl;
        cout << "   |    |" << endl;
        cout << "   |    O" << endl;
        cout << "   |    |" << endl;
        cout << "   |" << endl;
        cout << "   |" << endl;
        cout << "___|___" << endl;
        break;
    case 3:
        cout << "    ____" << endl;
        cout << "   |    |" << endl;
        cout << "   |    O" << endl;
        cout << "   |   /|\\" << endl;
        cout << "   |   " << endl;
        cout << "   |" << endl;
        cout << "___|___" << endl;
        break;
    case 4:
        cout << "    ____" << endl;
        cout << "   |    |" << endl;
        cout << "   |    O" << endl;
        cout << "   |   /|\\" << endl;
        cout << "   |    |  " << endl;
        cout << "   |   / \\  " << endl;
        cout << "___|___" << endl;
        break;
    default:
        break;
    }
}

SecretWord Init()
{
    SecretWord sw;
    vector<string> word_explanation = sw.generate();
    sw.word = word_explanation[0];
    sw.explanation = word_explanation[1];
    return sw;
}