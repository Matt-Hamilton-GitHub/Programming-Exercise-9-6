 //                                            ********* Writer: Matt Hamilton    *********
 //                                             ******** Class: CS 136            ******** 
 //                                              ******* Professor: Brian Dauzat  *******
 //                                                ***** Programming Exercise 9-6 *****
 //                                                 **** ======================== ****
 //                                                   **  *** *** *** *** *** *** **





/*
Write a program whose main function is merely a collection of variable declarations and function calls. This program reads a text and outputs the letters, together with their counts, as explained below in the function printResult. (There can be no global variables! All information must be passed in and out of the functions. Use a structure to store the information.) Your program must consist of at least the following functions:

Function openFile: Opens the input and output files. You must pass the file streams as parameters (by reference, of course). If the file does not exist, the program should print an appropriate message ("The input file does not exist.") and exit. The program must ask the user for the names of the input and output files.

Function count: Counts every occurrence of capital letters A-Z and small letters a-z in the text file opened in the function openFile. This information must go into an array of structures. The array must be passed as a parameter, and the file identifier must also be passed as a parameter.

Function printResult: Prints the number of capital letters and small letters, as well as the percentage of capital letters for every letter A-Z and the percentage of small letters for every letter a-z. The percentages should look like this: "25%".This information must come from an array of structures, and this array must be passed as a parameter.
Your program should prompt the user for name of the input file, then the name of the output file.


A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z.
*/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct LettersInfo {
      int id;
      char letterSymbol;
      int letterPercentage;
};




void openFile(ifstream& f_read, ofstream& f_alter, struct LettersInfo lettsArray[52]);
void count(struct LettersInfo lettsArray[52]);
void printResults();


int main() {



LettersInfo lettersArray[52];

ifstream readFile;
ofstream alterFile;


openFile(readFile, alterFile, lettersArray);



system("pause");
return 0;


}


void openFile(ifstream& f_read, ofstream& f_alter, struct LettersInfo lettsArray[52]){
    
    string read_fn = "";
    string alter_fn = "";
    string text = "";
    int temp;


    cout << "Please enter name of the input and output  files you wish to open, including the extension :";
    cin >> read_fn;

    cin >> alter_fn;


   f_read.open(read_fn);
   f_alter.open(alter_fn);

   if(f_read.is_open() && f_alter){
       cout << "Files " + read_fn + " and " +  alter_fn +  "  opened seccessfuly \n"; 

        while (f_read >> temp) {
             text += temp;
            }
           cout << text << endl;
     count(lettsArray);

   }else{
     cout << "The input file does not exist.\n";
     exit(0);
   } 


}

void count(struct LettersInfo lettsArray[52]){



}