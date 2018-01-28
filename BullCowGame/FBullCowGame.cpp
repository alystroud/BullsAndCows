//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Aly Stroud on 23/01/2018.
//  Copyright © 2018 Aly Stroud. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <map>
#define TMap std::map

int32 FBullCowGame::GetMaxTries() const { return MaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return (int32) HiddenWord.length(); }

FBullCowGame::FBullCowGame()
{
    Reset();
}

bool FBullCowGame::IsGameWon() const { return bGameWon; }

void FBullCowGame::Reset()
{
    const FString HIDDEN_WORD = "plane";
    constexpr int32 MAX_TRIES = 5;
    
    MaxTries = MAX_TRIES;
    CurrentTry = 1;
    HiddenWord = HIDDEN_WORD;
    bGameWon = false;
    return;
}

EWordStatus FBullCowGame::CheckStringValidity(FString Guess) const
{
    //if it isn't an isogram
    if(!IsIsogram(Guess))
    {
        return EWordStatus::NOT_ISOGRAM;
    }
    //if isnt all lowercase
    if(false)
    {
        return EWordStatus::NOT_LOWER_CASE;
    }
    //if wrong length guess
    if(Guess.length() != GetHiddenWordLength())
    {
        return EWordStatus::WRONG_LENGTH;
    }
    return EWordStatus::OK;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
    return true;
}

//Receives valid guess, increments current try
//Returns count
BullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    CurrentTry++;
    BullCowCount Count;
    for(int32 i = 0; i < HiddenWord.length(); i++)
    {
        for(int32 j = 0; j < Guess.length(); j++)
        {
            if(HiddenWord[i] == Guess[j])
            {
                if(i == j)
                {
                    Count.Bulls++;
                }
                else{
                    Count.Cows++;
                }
            }
        }
    }
    if(Count.Bulls == HiddenWord.length())
    {
        bGameWon = true;
    }
    else
    {
        bGameWon = false;
    }
    return Count;
}




