//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Aly Stroud on 23/01/2018.
//  Copyright © 2018 Aly Stroud. All rights reserved.
//
#pragma once
#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <iostream>
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EWordStatus {
    INVALID,
    OK,
    NOT_ISOGRAM,
    WRONG_LENGTH,
    NOT_LOWER_CASE
};

class FBullCowGame
{
public:
    FBullCowGame(); //Constructor 

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    int32 GetHiddenWordLength() const;
    EWordStatus CheckStringValidity(FString) const;
    
    void Reset(); //TODO make a more rich return value
    BullCowCount SubmitValidGuess(FString);
    bool IsIsogram(FString) const;
    bool IsLowerCase(FString) const;
    
private:
    int32 CurrentTry;
    FString HiddenWord;
    bool bGameWon;
};
#endif /* FBullCowGame_hpp */
