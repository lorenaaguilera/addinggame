// a very simple c++ additon game
// g++ addinggame.cpp -o addinggame -Wall -std=c++11

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int main() {

    int ran1, ran2, num, realnum;
    double tries, score, correct;
    string name;
    correct = 0;
    tries = 0;

    cout << "what is your name? ";
    cin >> name;
    cout << endl;

    while (tries < 9) {
        srand(time(0));

        ran1 = rand() % 100 + 1;
        ran2 = rand() % 100 + 1;
        
        realnum = ran1 + ran2;
        
        cout << "What is the sum of " << ran1 << "+" << ran2 << "?: ";
        cin >> num;
        cout << endl;

        if (num != realnum) {
            cout << "incorrect" << endl;
            tries++;
            cout << endl;
        }

        else if (num == realnum) {
            cout << "correct" << endl;
            tries++;
            cout << endl;
            correct ++;
        }
    }

    if (tries == 9) {
        score = (correct / tries) * 100;
        cout << "game over! your score was " << score << "%" << endl;
    }

    fstream writefs;
    writefs.open("scores.txt", fstream::in | fstream::out | fstream::app);
    writefs << "Name: " << name << " Score: " << score << "% \n";
    writefs << "***************************";
    writefs << endl;
    writefs.close();
    return 0;

}