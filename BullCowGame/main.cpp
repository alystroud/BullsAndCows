//
//  main.cpp
//  BullCowGame
//
//  Created by Aly Stroud on 20/01/2018.
//  Copyright © 2018 Aly Stroud. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

//Entry point for application
int main(int argc, const char * argv[]) {
    
    do
    {
        PrintIntro();
        PlayGame();
        
    } while(AskToPlayAgain());
    
    return 0;
}

void PrintIntro()
{
    //introduce the game
    constexpr int WORD_LENGTH = 5;
    cout << "Welcome to Bulls and Cows, a fun word game" << endl;
    cout << "Can you guess the " << WORD_LENGTH << " letter isogram that I'm thinking of?" << endl;
    cout << endl;
    return;
}

void PlayGame()
{
    constexpr int NUM_OF_TURNS = 5;
    for(int i = 0; i < NUM_OF_TURNS; i++)
    {
        string Guess = GetGuess();
        //repeat the guess back to them
        cout << "Your guess: " << Guess << endl;
        cout << endl;
    }
}

string GetGuess()
{
    //get a guess from the player
    cout << "Enter your guess: ";
    string Guess = "";
    getline(cin, Guess);
    return Guess;
}

bool AskToPlayAgain()
{
    cout << "Do you want to play again (y/n)? ";
    string Response = "";
    getline(cin, Response);
    cout << endl;
    return (Response[0] == 'y' || Response[0] == 'Y');
}
