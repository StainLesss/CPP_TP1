#ifndef TENNIS_H
#define TENNIS_H

void TableAtZero(int* aTable,int n);
void setWon(int Table[]);
void updatePointsAt(int *Table,int points);
void updateAvantage(int *Table,int YesNo);
void showScoreTables(int Table[],int aTable[]);
void BallWon(int TableOfWinner[],int TableOfLooser[]);
void AutomaticMatch(int* TablePlayer1,int*TablePlayer2,int cntBall);

#endif // TENNIS_H
