#include <iostream>
#include <time.h>

using namespace std;


/* 1 Table per player such as :
 *      Table[0]          Table[1]            Table[2]
 * | set won       | Cuurrent points   | Got avantage ? |
 *    [1;+inf]          [0;15;30;40]            [0;1]
*/

void TableAtZero(int* aTable,int n) {
    for(int i=0;i<n;i++){
        aTable[i]=0;
    }
}
void setWon(int Table[]){
    Table[0]++;
}
void updatePointsAt(int *Table,int points){
    Table[1] = points;
}
void updateAvantage(int *Table,int YesNo){
    Table[2]=YesNo;
}
void showScoreTables(int Table[],int aTable[]){
    cout << "J |Set\t|Points\t|Avantage\t|" <<endl;
    cout << "J1|" << Table[0] << "\t|" << Table[1] << "\t|" << Table[2] <<"\t|" <<endl;
    cout << "J2|" << aTable[0] << "\t|" << aTable[1] << "\t|" << aTable[2] <<"\t|" << endl;
}

void BallWon(int TableOfWinner[],int TableOfLooser[]){
    if(((TableOfWinner[1]<=40)&&(TableOfLooser[1]<40))||((TableOfWinner[1]<40)&&(TableOfLooser[1]<=40))){//Simple case : point added or set won
        switch(TableOfWinner[1]){
            case 0:     TableOfWinner[1] += 15;break;
            case 15:    TableOfWinner[1] += 15;break;
            case 30 :   TableOfWinner[1] += 10;break;
            case 40 :   setWon(TableOfWinner);
                        updatePointsAt(TableOfWinner,0);
                        updatePointsAt(TableOfLooser,0);
            break;
        }
    }
    else{// More complex case : both player are at 40 pts

        if((TableOfWinner[2]==1)&&(TableOfLooser[2]==0)){ // Player having avantage win
            setWon(TableOfWinner);
            updatePointsAt(TableOfWinner,0);
            updatePointsAt(TableOfLooser,0);
            updateAvantage(TableOfWinner,0);}
        else if ((TableOfWinner[2]==0)&&(TableOfLooser[2]==1)){ //Player remove the avantage of adverse player
            updateAvantage(TableOfLooser,0);}
        else if ((TableOfWinner[2]==0)&&(TableOfLooser[2]==0)){
            updateAvantage(TableOfWinner,1);}               // Player got advantage
    }
}
// NOT NEEDED, FOR TEST PURPOSE
void AutomaticMatch(int* TablePlayer1,int*TablePlayer2,int cntBall){
    int tmp;
    cout << "Tennis Match : Automatic test - " << cntBall << " balls" << endl;
    srand(time(0));
    for(int i=0; i<= cntBall; i++){
        tmp = rand();
        if((tmp%100)>=50){
            BallWon(TablePlayer1,TablePlayer2);
        }
        else{ //(tmp%100)<50)
            BallWon(TablePlayer2,TablePlayer1);
        }
    }

}

