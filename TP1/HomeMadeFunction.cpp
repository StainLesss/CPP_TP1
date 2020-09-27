#include <iostream>
#include <time.h>       /* time */
#include <string>
#include <stdlib.h>     /* random */
#include <ctype.h>      /* isblank isspace*/

using namespace std;

//I.1.1
int add_function(int a,int b){
    return a+b;
}
//I.1.2
void switchArg(int* a,int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//I.1.3

/* IN : Take two int and an int pointer
 * OUT: not returning value but update the third argument
 * arg 3 = arg 1 +arg 2 using POINTEUR */
void updateArg3(int a,int b,int* c){//Polymorphisme
    *c = a + b;
}
/* IN : Take two int and an int reference
 * OUT: not returning value but update the third argument
 * arg 3 = arg 1 +arg 2 using REFERENCE */
void updateArg3(int a,int b,int& c){//Polymorphisme
    c = a + b;
}

//I.1.4
//Alternative std::array or std::vector
int* createTable(int n) {
    return new int[n];
}

void showTable(int myTable[],int n){
    for(int i =0 ; i<n-1 ;i++){
        cout << myTable[i];
        cout << "|";
    }
    cout << myTable[n-1] << endl ;
}

void randomIntForTable(int myTable[],int n){
    srand(time(0)); // // Use current time as seed for random generator
    for (int i =0 ; i<n;i++){
        myTable[i] = rand();
    }
}

void bublesort(int* MyTable,int n){
    bool StayInLoop;
    do{
        StayInLoop = false;
        for(int i=1;i<n;i++){
            if(MyTable[i-1]>MyTable[i]){ // if one value is not sorted : restart the do while loop
                switchArg(&MyTable[i-1],&MyTable[i]);
                StayInLoop = true;
            }
        }
    }while (StayInLoop);
}


/* IN : The table to be modified, its length and if the sort must be ascendente(asc = 1) or descendente(asc = 0)
 * OUT: nothing but the provided table is updated
 * Sort the table in a growing way (asc= 1) or in a decreasing way (asc =0)*/
void bublesort(int* MyTable,int n,bool asc){
    bool StayInLoop;
    if(asc == true){
        do{
            StayInLoop = false;
            for(int i=1;i<n;i++){
                if(MyTable[i-1]>MyTable[i]){ // if one value is not sorted : restart the do while loop
                    switchArg(&MyTable[i-1],&MyTable[i]);
                    StayInLoop = true;
                }
            }
        }while (StayInLoop);
    }
    else { //equal asc == false meaning decreasing
        do{
            StayInLoop = false;

            for(int i=n-1;i>0;i--){
                if(MyTable[i]>MyTable[i-1]){ // if one value is not sorted : restart the do while loop
                    switchArg(&MyTable[i-1],&MyTable[i]);
                    StayInLoop = true;
                }
            }
        }while (StayInLoop);
    }
}

//== II => see Tennis.cpp

//== III.1

void sayHello(string Name){
    cout << "Bonjour " << Name <<endl;
}

/* IN : The requested phrase ask by the console to the user
 * OUT: The word entered as String
 * Asf for ONE WORD in console (IF SEVERAL WORD, RETRUN THE FIRST WORD)*/
string AskAndRecordWord(string CPU_request){
    string UserAnswer;
    cout << CPU_request << endl;
    cout << "->" ;
    cin >> UserAnswer;
    return UserAnswer;
}
/* IN : The requested phrase ask by the console to the user
 * OUT: The sentence entered as String
 * Ask for a sentence in console (several word separated by blank)*/
string AskAndRecordLine(string CPU_request){
    string UserAnswer;
    cout << CPU_request << endl;
    cout << "->" ;
    getline(cin,UserAnswer);
    return UserAnswer;
}

/* IN : The user name as a string
 * OUT: YES if the user name is well formated / NO if empty, got digit or ponctuation and not any space
 * Check if the input is a sentence with only letters */
bool conformNameOnly(string UsrName){
    int len = UsrName.length();// same as int sizeS = UsrName.size();

    bool Isconform=false;
    for(int i =0 ; i<len;i++){
        if(isdigit(UsrName[i])||ispunct(UsrName[i])){
            cout << "ERREUR : nombre ou ponctuation" <<endl;
            return false;
        }
        if(isblank(UsrName[i])){
            Isconform = true;
        }
    }
    if(Isconform == false)cout << "ERREUR : pas d'espace" <<endl;
    return Isconform; // there is only char PLUS at least a space
}

/* IN :An input from user as string
 * OUT:YES if the input containt letter only/NO if there is any space, digit ot punctuation
 * Check if the input is a word with only letters*/
bool conformWordsOnly(string input){
    int len = input.length();// same as int sizeS = UsrName.size();
    for(int i =0 ; i<len;i++){
        if(isdigit(input[i])||ispunct(input[i])||isblank(input[i])){
            cout << "ERREUR : nombre ,espace ou ponctuation" <<endl;
            return false;
        }
    }
    return true;
}
/* IN :An input from user as string
 * OUT:YES if the input containt letter only/NO if there is any space, digit ot punctuation
 * Check if the input is a word with only letters*/
bool conformIntOnly(string input){
    int len = input.length();// same as int sizeS = UsrName.size();
    for(int i =0 ; i<len;i++){
        if(isalpha(input[i])||ispunct(input[i])||isblank(input[i])){
            cout << "ERREUR : lettre ,espace ou ponctuation" <<endl;
            return false;
        }
    }
    return true;
}
string AskUserName(){
    string Name="";
    bool NotConform = true;
    while (NotConform){
        Name = AskAndRecordLine("Merci d'entrer votre nom en utlisant la forme suivante ->Nom Prenom");
        if (conformNameOnly(Name)){
            NotConform = false; // User input conform, quit the loop
        }
    }
    return Name;
}
/* IN :The user's last name AND user's first name (only letter and one space between both
 * OUT:The user last name and First name well formated (all upper case for last name, upper case only for the first letter of first name)
 * Take an user name and make it human nicely readable */
string formatUserName(string UserName){
    string result = UserName;
    int len = UserName.length();
    int i=0;
    while(!isblank(UserName[i])){
        result[i] = toupper(UserName[i]);
        i++;
    }
    i+= 2;
    while(i<len){
        result[i] = tolower(UserName[i]);
        i++;
    }
    return result;
}

//== III.2.1
void say(string s){
    cout << s << endl;
}
int randomFrom(int min,int max){
    return (min + (rand()%(max+1-min)));
}

/* IN : The user input as String
 * OUT: Yes if the user input contain only number / No in the others case
 * Check if the input contain only numbers */
bool conformIntegerOnly(string UsrName){
    int len = UsrName.length();
    for(int i =0 ; i<len;i++){
        if(!isdigit(UsrName[i])){
            cout << "ERREUR : ne contient pas exclusivement des chiffres";
            return false;
        }
    }
    return true; // there is only numbers
}

//III.2.1

void guessMyNumberPlay(int min,int max){
    int TargetVal= randomFrom(min,max);
    int cnt=0;
    //cout << TargetVal <<endl;// Line for testing, provide the Target Value
    string usrVal;
    cout << "Nombre entre "<< min << " et "<< max << " choisi ! Essaye de deviner !"<<endl;
    bool stillPlaying = true;
    while(stillPlaying){
        usrVal = AskAndRecordLine("Alors ?");
        if (conformIntegerOnly(usrVal)){
            if (TargetVal > stoi(usrVal)){
                cout << "Presque : essaye plus GRAND !"<< endl;
                cnt++;
            }
            else if (TargetVal < stoi(usrVal)){
                cout << "Presque : essaye plus PETIT !"<< endl;
                cnt++;
            }
            else{
                cout << "Bravo ! Fait en "<< cnt << " essai(s)"<<endl;
                stillPlaying = false;
            }

        }
        else{
            cout << "Je n'ai pas compris... Tu es sur que ce ne sont QUE des chiffres ?" <<endl;
        }
    }
}
int nextTry(int* inf,int* sup,int* val){

    int mid = static_cast<int>((*inf+*sup)/2);

    cout << mid <<endl; //DEBUG to delete
    return 0;
}

int get_avg(int a,int b){
    return (a+b)/2;
}

int guessMyNumberForPC(int min,int max){
    string usrInput;
    int avg = get_avg(min,max);//arrondie inf
    int cpuNumber = avg;
    int usrNumber;

    do{
        usrInput = AskAndRecordWord("Merci de choisir un numéro entre " + to_string(min)+" et " +to_string(max));
   } while(!conformIntegerOnly(usrInput));
   usrNumber = stoi(usrInput);

   say("Je vais essayer de deviner ! Saisir + si c'est plus grand, - si c'est plus petit");
   while (cpuNumber != usrNumber){
        string usrHelp = AskAndRecordWord("Est-ce : " + to_string(cpuNumber) +" ?");

        if((usrHelp.length()==1) && ( (usrHelp == "+")||(usrHelp == "-") )){
            if((usrHelp == "+")){
                min = cpuNumber+1;
                cpuNumber = get_avg(min,max);
            }
            else if((usrHelp == "-")){
                max = cpuNumber-1;
                cpuNumber = get_avg(min,max);
            }
        }

        else{say("Saisie non conforme..");}
   }
   cout << "Je sais ! Ton chiffre est " << cpuNumber<<endl;

   return avg;
}







/* Source are taken from :
 *
 * For the use of separate .cpp and .h
 * https://stackoverflow.com/questions/51488008/how-to-call-functions-from-one-cpp-file-in-another-cpp-file
 * https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/
 *
 * Table stuff
 * super => https://stackoverflow.com/questions/4264304/how-to-return-an-array-from-a-function
 *       => https://www.geeksforgeeks.org/references-in-c/
 * https://www.tutorialspoint.com/how-do-i-find-the-length-of-an-array-in-c-cplusplus
 * https://stackoverflow.com/questions/4264304/how-to-return-an-array-from-a-function
 * https://beginnersbook.com/2014/01/c-pointers/
 * https://www.geeksforgeeks.org/features-and-use-of-pointers-in-c-c/
 * https://stackoverflow.com/questions/23667497/update-int-variable-in-c-inside-a-function
 *
 * Random stuff
 * https://www.educba.com/random-number-generator-in-c-plus-plus/
 * http://www.cplusplus.com/reference/cstdlib/rand/
 * https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
 * https://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
 *
 * Commande Line compilation (g++ -c // g++ -o)
 * https://www.geeksforgeeks.org/compiling-with-g-plus-plus/
 *
 * C++ String
 * https://www.w3schools.com/cpp/cpp_strings_input.asp
 * */





