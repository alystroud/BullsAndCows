//
//  main.cpp
//  BullCowGame
//
//  Created by Aly Stroud on 20/01/2018.
//  Copyright © 2018 Aly Stroud. All rights reserved.
//

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

//Entry point for application
int main(int32 argc, const char * argv[]) {
    
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
    std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram that I'm thinking of?" << std::endl;
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    //TODO: Change this to while loop
    for(int32 i = 0; i < MaxTries; i++)
    {
        FText Guess = GetGuess(); //TODO: Make loop checking valid
        
        //Submit valid game to game
        BullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        
        //Print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << " Cows = " << BullCowCount.Cows << std::endl;
        std::cout << std::endl;
        
    }
    //TODO: Summarise Game
}

FText GetGuess()
{
    //get a guess from the player
    std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
    FText Guess = "";
    getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again (y/n)? ";
    FText Response = "";
    getline(std::cin, Response);
    std::cout << std::endl;
    return (Response[0] == 'y' || Response[0] == 'Y');
}
