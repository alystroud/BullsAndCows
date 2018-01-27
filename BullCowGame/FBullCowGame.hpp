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


class FBullCowGame {
public:
    void Reset(); //TODO make a more rich return value
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;
    bool CheckStringValidity(std::string);
    
private:
    int CurrentTry = 1;
    int MaxTries = 5;
    bool IsIsogram(std::string);
};
#endif /* FBullCowGame_hpp */
