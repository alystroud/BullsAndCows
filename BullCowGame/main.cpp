//
//  main.cpp
//  BullCowGame
//
//  Created by Aly Stroud on 20/01/2018.
//  Copyright © 2018 Aly Stroud. All rights reserved.
//

#include <iostream>
#include <string>


void PrintIntro();
void PlayGame();
std::string GetGuess();
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
    std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram that I'm thinking of?" << std::endl;
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    constexpr int NUM_OF_TURNS = 5;
    for(int i = 0; i < NUM_OF_TURNS; i++)
    {
        std::string Guess = GetGuess();
        //repeat the guess back to them
        std::cout << "Your guess: " << Guess << std::endl;
        std::cout << std::endl;
    }
}

std::string GetGuess()
{
    //get a guess from the player
    std::cout << "Enter your guess: ";
    std::string Guess = "";
    getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again (y/n)? ";
    std::string Response = "";
    getline(std::cin, Response);
    std::cout << std::endl;
    return (Response[0] == 'y' || Response[0] == 'Y');
}
