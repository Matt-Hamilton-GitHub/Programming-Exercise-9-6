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
*/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;



void openFile(ifstream& f_passed, ofstream& f_returned);
void count(struct letts_occurence);
void printResults();


int main() {


struct letterInfo {
      char letterSymbol;
      int letterPercentage;
};

// struct lowerLetters{
//     letterInfo letters;
// };

// struct upperLetters{
//     letterInfo letters;
// };

// struct letters{

// lowerLetters  l_latter;
// upperLetters u_letter;
 
// };



struct letters {
  letterInfo allLetters;
};

letters newLetters;

ifstream readFile;
ofstream alterFile;




openFile(readFile, alterFile);

}


void openFile(ifstream& f_read, ofstream& f_alter){
    
    string read_fn = "";
    string alter_fn = "";


    cout << "Please enter name of the file you wish to open (without the extension) :";
    cin >> read_fn;

     cout << "Please enter name of the file you wish to save the results (without its extension) :";
    cin >> alter_fn;


   f_read.open(read_fn+".txt");
   f_alter.open(alter_fn+".txt");

   if(f_read.is_open()){
       cout << "File " + read_fn +  " is open seccessfuly \n"; 


   }else{
     cout << "The input file does not exist.\n";
     exit(0);
   } 

if(f_alter.is_open()){
       cout << "File " + alter_fn +  " is open seccessfuly \n"; 


   }else{
     cout << "The output file does not exist.\n";
     exit(0);
   } 


}