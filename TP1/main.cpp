#include <iostream>
#include <string>
#include "HomeMadeFunction.h"
#include "Tennis.h"

using namespace std;

void say(string s);
string AskAndRecordWord(string CPU_request);
bool conformIntOnly(string input);
void bublesort(int* MyTable,int n,bool asc);
string AskAndRecordLine(string CPU_request);
bool conformNameOnly(string UsrName);
string AskUserName();
string formatUserName(string UserName);


void partI(){
    say("### [I] ###");
    say("--- [1] ---");
    int a=4;
    int b = 5;
    int res = 0;
    res = add_function(a,b);
    cout << "a = "<< a <<endl
         <<"b = "<<b<<endl
        <<"res = add_function(a,b)"<<endl
        <<"res = "<< res <<endl;
    say("--- [2] ---");
    int *Arg1;
    int *Arg2;
    Arg1 = &a;
    Arg2 = &b;
    cout << "a = "<< a <<endl
         <<"b = "<<b<<endl
        <<"switchArg(Arg1,Arg2);"<<endl;
    switchArg(Arg1,Arg2);
    cout << "a = "<< a <<endl
         <<"b = "<<b<<endl;
    say("--- [3] ---");
    int arg1 = 15;
    int arg2 = 20;
    int tmp = 0;
    int* arg3;
    arg3 = &tmp;
    cout << "arg1 = "<< arg1 <<endl
         <<"arg2 = "<< arg2 <<endl
         <<"*arg3 = "<< *arg3 <<endl
         <<"updateArg3(arg1,arg2,arg3);"<<endl;
    updateArg3(arg1,arg2,arg3);
    cout << "arg1 = "<< arg1 <<endl
         <<"arg2 = "<< arg2 <<endl
        <<"*arg3 = "<< *arg3 <<endl;
    say("--- [4] ---");
    string usrInputDim;
    string usrInputSort;
    do {
        usrInputDim = AskAndRecordWord("Merci de saisir un entier pour la taille du tableau");
        usrInputSort = AskAndRecordWord("Merci de saisir 0 pour croissant OU 1 pour decroissant");
    }while(!(conformIntOnly(usrInputDim)&&conformIntOnly(usrInputSort)));
    int n = stoi(usrInputDim);
    bool choice = usrInputSort == "0" ? true: false;
    int* table = createTable(n);
    randomIntForTable(table,n);
    cout << "Table :" <<endl;
    showTable(table,n);
    cout << "Table MaJ :" <<endl;
    bublesort(table,n,choice);
    showTable(table,n);
    cout << "Table MaJ2 :" <<endl;
    bublesort(table,n,!choice);
    showTable(table,n);
}

void partII(){
    say("### [II] ###");
    say("--- [1] ---");
    bool stayloop = true;
    int J1_Table[3];
    int J2_Table[3];
    TableAtZero(J1_Table,3);
    TableAtZero(J2_Table,3);
    string usrInput;
    say("Jeux de tennis");
    while(stayloop){
        usrInput = AskAndRecordWord("Saisir 1 pour J1,Saisir 2 pour J2 et saisir 0 pour quitter");
        if(conformIntOnly(usrInput)){
            if(usrInput =="0"){
                stayloop = false;
            }
           else if(usrInput =="1"){
                BallWon(J1_Table,J2_Table);
                showScoreTables(J1_Table,J2_Table);
            }
            else if(usrInput =="2"){
                BallWon(J2_Table,J1_Table);
                showScoreTables(J1_Table,J2_Table);
            }
            else {say("Joueur inexistant.. ");}
        }
        else {
            say("Votre saisie est non conforme.. ");
        }
    }
}

void partIII(){
    say("### [III] ###");
    say("--- [1] ---");
    bool stayloop=true;
    string usrInput = AskUserName();
    cout << "Bonjour "<< formatUserName(usrInput)<<endl;
    say("--- [2] ---");
    guessMyNumberPlay(0,10);
    guessMyNumberForPC(0,10);
}


int main()
{
    bool stayloop = true;
    string usrInput;
    while(stayloop){
        say("### [Menu] ###");
        say("- 0 pour Quitter");
        say("- 1 pour I.Manipulation de nombres");
        say("- 2 pour II.Jeu de Tennis");
        say("- 3 pour III.Inscription dans la console et recep des saisies");
        usrInput = AskAndRecordWord("Alors ?");
        if(conformIntOnly(usrInput)){
            if(usrInput=="0"){
                stayloop = false;
            }
            else if (usrInput == "1"){partI();}
            else if (usrInput == "2"){partII();}
            else if (usrInput == "3"){partIII();}
            else {say("Menu inexistant..");}
        }
        else{ say("Votre saisie est non conforme..");}
    }
    return 0;
}
