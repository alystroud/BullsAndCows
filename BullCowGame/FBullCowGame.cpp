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



int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return (int32) HiddenWord.length(); }

FBullCowGame::FBullCowGame()
{
    Reset();
}

bool FBullCowGame::IsGameWon() const { return bGameWon; }

int32 FBullCowGame::GetMaxTries() const
{
    TMap<int32, int32> WordLengthToMaxTries {{3, 4}, {4, 7}, {5, 10}, {6, 15}, {7, 20}};
    return WordLengthToMaxTries[GetHiddenWordLength()];
}

void FBullCowGame::Reset()
{
    const FString HIDDEN_WORD = "plane";
    
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
    if(!IsLowerCase(Guess))
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

bool FBullCowGame::IsIsogram(FString Word) const
{
    if(Word.length() <= 1){
        return true;
    }
    TMap<char, bool> LettersSeen;
    for(auto c : Word){
        c = tolower(c);
        if(!LettersSeen[c]){
            LettersSeen[c] = true;
        }
        else {
            return false;
        }
    }
    return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
    if(Word.length() <= 1){
        return true;
    }
    
    for(char c : Word){
        if(!islower(c)){
            return false;
        }
    }
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




