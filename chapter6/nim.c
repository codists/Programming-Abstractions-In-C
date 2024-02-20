//
// Created by codists on 2024/1/16.
//
/*
 * File: nim.c
 * ------------
 * This program simulates a simple variant of the game of nim.
 * In this version, the game starts with a pile of 13 coins
 * on a table. Player then take turns removing 1, 2, or 3
 * coins from the pile. The player who take the last coin
 * loses. This simulation allows a human player to compete
 * against the computer.
 */
#include <stdbool.h>
#define NoGoodMove -1
#define MaxTake 10

static bool IsBadPosition(int nCoins);
static int FindGoodMove(int nCoins);


static int FindGoodMove(int nCoins) {
    int nTaken;

    for (nTaken = 1; nTaken <= MaxTake; nTaken++) {
        if (IsBadPosition(nCoins - nTaken)) {
            return nTaken;
        }
    }
    return NoGoodMove;
}

static bool IsBadPosition(int nCoins) {
    if (nCoins == 1) {
        return true;
    }
    return FindGoodMove(nCoins) == NoGoodMove;
}

