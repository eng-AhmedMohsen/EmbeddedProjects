/*
 * snakeGame.h
 *
 * Created: 29-May-22 4:35:02 AM
 *  Author: Ahmed
 */ 


#ifndef SNAKEGAME_H_
#define SNAKEGAME_H_

#define F_CPU	8000000UL
#include "CLCD_interface.h"


void snakeGame_voidInit();

void snakeGame_voidStartGame();

void snakeGame_move();
void snakeGame_Update();
void snakeGame_IsDead();
void snakeGame_IsFeedEaten();
#endif /* SNAKEGAME_H_ */