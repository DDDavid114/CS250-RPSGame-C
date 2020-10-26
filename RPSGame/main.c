/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: yusheng
 *
 * Created on 2020年9月23日, 下午5:27
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rpsHeader.h"

enum CHOICE{rock=1, paper, scissors};

int main() {
    printf("Welcome to ROCK PAPER SCISSORS game\n");
    printf("-----------------------------------\n");
    int playerScore = 0;
    int computerScore = 0;
    int tie = 0;//intial score
    
    for(int round = 0; round < ROUND; round++){
        int playerChoice = 0;
        int computerChoice = 0;
        while(playerChoice == 0){
            playerChoice = collectInput();
        }//if input is incorrect, repeat collecting
        computerChoice = computerInput();
        switch(findWinner(playerChoice,computerChoice)){
            case 0:
                tie++;
                break;
            case 1:
                playerScore++;
                break;
            case 2:
                computerScore++;
                break;
        }//score recording
    }//for loop that run game for certain rounds
    
    printf("\nGame Over! You won %d rounds, computer won %d rounds, tied %d rounds\n",playerScore,computerScore,tie);
    if(playerScore > computerScore){
        printf("Champion: YOU\n");
    }else if(playerScore < computerScore){
        printf("Champion: COMPUTER\n");
    }else{
        printf("TIE\n");
    }//find champion
    return 0;
}//main

    /**
     * collect input, return 0 for incorrect input
     * @return int 1 for rock, 2 for paper and 3 for scissors
     */
int collectInput(){
    printf("\n");
    printf("Please enter your choice: \"Rock\", \"Paper\", or \"Scissors\" \n");
    char input[100];
    fflush(stdout);
    fgets(input,100,stdin);//take input
    char playerChoice[1];
    playerChoice[0] = input[0];
    playerChoice[1] = '\0';//first letter of player's input
    if(strcmp(playerChoice, "R") == 0 || strcmp(playerChoice, "r") == 0){
        printf("You entered ROCK     ");
        return 1;
    }else if(strcmp(playerChoice, "P") == 0 || strcmp(playerChoice, "p") == 0){
        printf("You entered PAPER     ");
        return 2;
    }else if(strcmp(playerChoice, "S") == 0 || strcmp(playerChoice, "s") == 0){
        printf("You entered SCISSORS     ");
        return 3;
    }else{
        printf("Not sure of your selection. Try again.\n");
    }
    return 0;//if input is incorrect
}//collectInput

/**
 * generate a random int from 1-3
 * @return int represent same thing as collect input 
 */
int computerInput(){
    srand(time(NULL));
    enum CHOICE cChoice;
    cChoice = rand() % 3;//random int for 0 to 2
    cChoice ++;
    switch(cChoice){
        case rock:
            printf("Computer chose ROCK    ");
            break;
        case paper:
            printf("Computer chose PAPER    ");
            break;
        case scissors:
            printf("Computer chose SCISSORS    ");
            break;
        default:
            cChoice = rand() % 3;
            cChoice ++;//default case
    }//switch
    return cChoice;
}//computerInput

/**
 * compare player choice and computer choice and find winner
 * @param player player's choice, an int from 1-3
 * @param computer
 * @return 0 for tie, 1 for player win and 2 for computer win
 */
int findWinner(int player, int computer){
    if(player == computer){
        printf("TIE\n");
        return 0;
    }else if(player == computer + 1 || player == computer - 2){
        printf("Winner is YOU\n");
        return 1;
    }else{
        printf("Winner is COMPUTER\n");
        return 2;
    }
}//findWinner

