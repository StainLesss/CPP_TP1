#ifndef HOMEMADEFUNCTION_H
#define HOMEMADEFUNCTION_H


void test(int tb[],int n);


int getRandomValue();
void randomIntForTable(int myTable[],int n);
int* createTable(int n);
void switchArg(int* a,int*b);

void updateArg3(int a,int b,int* c);
void updateArg3(int a,int b,int& c);

void showTable(int myTable[],int n);
void bublesort(int* MyTable,int n);

int add_function(int a,int b);

//III
void guessMyNumberPlay();
int guessMyNumberForPC();
#endif // HOMEMADEFUNCTION_H
