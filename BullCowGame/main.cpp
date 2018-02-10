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
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

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
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram that I'm thinking of?" << std::endl;
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    
    while(BCGame.GetMaxTries() >= BCGame.GetCurrentTry() && !BCGame.IsGameWon())
    {
        FText Guess = GetValidGuess();
        BullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        
        //Print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << " Cows = " << BullCowCount.Cows << std::endl;
        std::cout << std::endl;

    }

    PrintGameSummary();
    return;
}

FText GetValidGuess()
{
    EWordStatus Status = EWordStatus::INVALID;
    FText Guess = "";
    do {
        //get a guess from the player
        std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
        getline(std::cin, Guess);
        Status = BCGame.CheckStringValidity(Guess);
        switch(Status){
            case EWordStatus::NOT_LOWER_CASE:
                std::cout << "Please enter the word in lower case" << std::endl << std::endl;
                break;
            case EWordStatus::WRONG_LENGTH:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word." << std::endl << std::endl;
                break;
            case EWordStatus::NOT_ISOGRAM:
                std::cout << "That is not an isogram. Please enter a word without repeating letters." << std::endl << std::endl;
                break;
            default:
                break;
        }
    }while(Status != EWordStatus::OK);
    return Guess;
}

void PrintGameSummary()
{
    if(BCGame.IsGameWon())
    {
        std::cout << "WELL DONE - YOU WIN!" << std::endl;
    }
    else
    {
        std::cout << "Bad Luck :( Try again!" << std::endl;
    }
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again with the same hidden word (y/n)? ";
    FText Response = "";
    getline(std::cin, Response);
    std::cout << std::endl;
    return (Response[0] == 'y' || Response[0] == 'Y');
}
