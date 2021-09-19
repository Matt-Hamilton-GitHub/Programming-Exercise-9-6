 //                                            ********* Writer: Matt Hamilton    *********
 //                                             ******** Class: CS 136            ******** 
 //                                              ******* Professor: Brian Dauzat  *******
 //                                                ***** Programming Exercise 9-6 *****
 //                                                 **** ======================== ****
 //                                                   **  *** *** *** *** *** *** **

/*
Write a program whose main function is merely a collection of variable declarations and function calls. This program reads a text 
 * and outputs the letters, together with their counts, as explained below in the function printResult. (There can be no global 
 * variables! All information must be passed in and out of the functions. Use a structure to store the information.) Your program 
 * must consist of at least the following functions:

Function openFile: Opens the input and output files. You must pass the file streams as parameters (by reference, of course). 
 * If the file does not exist, the program should print an appropriate message ("The input file does not exist.") and exit.
 * The program must ask the user for the names of the input and output files.

Function count: Counts every occurrence of capital letters A-Z and small letters a-z in the text file opened in the function openFile. 
 * This information must go into an array of structures. The array must be passed as a parameter, and the file identifier must also be 
 * passed as a parameter.

Function printResult: Prints the number of capital letters and small letters, as well as the percentage of capital letters 
 * for every letter A-Z and the percentage of small letters for every letter a-z. The percentages should look like this: "25%".
 * This information must come from an array of structures, and this array must be passed as a parameter.
Your program should prompt the user for name of the input file, then the name of the output file.


Letters: A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z.
*/


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

//below is my structured data where every letter has an id, its symbol, and the number of times it appears in a text

struct LettersInfo {
      int id {}; // the purpose of id is just to keep a track of all the letters 
      char letterSymbol {}; // it stores the symbolic representation of each letter
	  int count {0}; // number of times the letter appears in the file
      float letterPercentage {0.0}; // it stores the percentage for every letter
};


// the function below opens the input and output files. the file streams are passed to it as a part of parameters
void openFile(ifstream& f_read, ofstream& f_alter, struct LettersInfo lettsArray[52]);

//the function below counts every occurrence of capital letters A-Z and small letters a-z in the text file opened in the function openFile. 
//The array of stucts is passed as a parameter, and the file identifier is also passed as a parameter.
void count(struct LettersInfo lettsArray[52], ifstream& f_read);

//the function below prints the number of capital letters and small letters, as well as the percentage of capital letters for every letter A-Z and the percentage of small letters for every letter a-z. 
//All the information comes from the array of structures, and this array is be passed as a parameter.
void printResults(struct LettersInfo lettsArray[52], ofstream& f_alter);


int main() {



LettersInfo lettersArray[52]; // here we create an array of structs. 52 elements for all letters, uppercase, and lower case

ifstream readFile;  //the file that contains text, where the program reads from
ofstream alterFile;  //the file that contains the results, where the program stores the letters  occurrence data

//openFile function calls here
openFile(readFile, alterFile, lettersArray);


system("pause");
return 0;

}



void openFile(ifstream& f_read, ofstream& f_alter, struct LettersInfo lettsArray[52]){
    
    string read_fn = ""; // name of the file the program is gonna read from 
    string alter_fn = ""; //name of the file the program is going to save the results
   


     cout << "Please enter the name of input and output files, including files' format: ";
	 cin >> read_fn >> alter_fn;

   f_read.open(read_fn);
   f_alter.open(alter_fn);

  // this command checks if the files were opened successfully
   if(f_read.is_open() && f_alter.is_open()){
       cout << "Files " + read_fn + " and " +  alter_fn +  " are  opened seccessfuly \n"; 
	   cout  << "-----------------------------------------------\n";

			
           //aafter the program is done copying, we pass the text to function 'count', to count the letters
           count(lettsArray, f_read);
 
         f_read.close(); // close the file
		 printResults(lettsArray, f_alter); // print the results 
		 
		  f_alter.close(); //close the output file
    }else{
		if(!f_read.is_open()){
			
			//if one of the files or both files do not exist, the program exits
     cout << "The files do not exist.\n";
     exit(0);
		}
   }

}

// ------------------- End Of openFile function  ----------------



void count(struct LettersInfo lettsArray[52], ifstream& f_read){

	
string text = ""; // this variable stores the text from the file in order to analyze it
char temp; // it is a temporary variable that helps the one above to store the data from the file
string allLetters =	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //stores all the letters

 // below the program copies all the data from the file and store it to variable 'text' as a string without spaces
        while (f_read >> temp) {
             text += temp;
            }

//the for loop below sets the initial values such as id and symbol for each letter, upper case, and lower case
for(unsigned int i{0}; i <= 51; i++){
		
	// the if statement sets values for lowercase letters
	if(i <= 25){
		
		  lettsArray[i].id = i;
		  lettsArray[i].letterSymbol = tolower(allLetters[i]);
		 
		// the else statement sets values for uppercase letters
	}else{
		  lettsArray[i].id = i;
		  lettsArray[i].letterSymbol = allLetters[i-26];
		  }
		  
}
	
		
	
	//below we set the count value for each letter in the array of structs
for(char c: text){
	switch(c){
//		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
		case 'a':
		  lettsArray[0].count+=1;
		   break;
		
		case 'b':
		  lettsArray[1].count+=1;
		   break;
		
		case 'c':
		  lettsArray[2].count+=1;
		   break;
		   
		case 'd':
		  lettsArray[3].count+=1;
		    break;
		case 'e':
		  lettsArray[4].count+=1;
		   break;
		case 'f':
		  lettsArray[5].count+=1;
		   break;
		case 'g':
		  lettsArray[6].count+=1;
		   break;
		case 'h':
		  lettsArray[7].count+=1;
		   break;
		   
		case 'i':
		  lettsArray[8].count+=1;
		   break;
    
	    case 'j':
		  lettsArray[9].count+=1;
		   break;
		case 'k':
		  lettsArray[10].count+=1;
		   break;
		case 'l':
		  lettsArray[11].count+=1;
		   break;
		case 'm':
		  lettsArray[12].count+=1;
		   break;
		case 'n':
		  lettsArray[13].count+=1;
		   break;
		case 'o':
		  lettsArray[14].count+=1;
		   break;
		case 'p':
		  lettsArray[15].count+=1;
		   break;
		case 'q':
		  lettsArray[16].count+=1;
		   break;
		case 'r':
		  lettsArray[17].count+=1;
		   break;
		case 's':
		  lettsArray[18].count+=1;
		   break;
		case 't':
		  lettsArray[19].count+=1;
		   break;
		case 'u':
		  lettsArray[20].count+=1;
		   break;
		case 'v':
		  lettsArray[21].count+=1;
		   break;
		 case 'w':
		  lettsArray[22].count+=1;
		   break;
		case 'x':
		  lettsArray[23].count+=1;
		   break;
		case 'y':
		  lettsArray[24].count+=1;
		   break;
		case 'z':
		  lettsArray[25].count+=1;
		   break;
		// Upper case letters
		
		case 'A':
		  lettsArray[26].count+=1;
		   break;
		
		case 'B':
		  lettsArray[27].count+=1;
		   break;
		
		case 'C':
		  lettsArray[28].count+=1;
		   break;
		   
		case 'D':
		  lettsArray[29].count+=1;
		    break;
		case 'E':
		  lettsArray[30].count+=1;
		   break;
		case 'F':
		  lettsArray[31].count+=1;
		   break;
		case 'G':
		  lettsArray[32].count+=1;
		   break;
		case 'H':
		  lettsArray[33].count+=1;
		   break;
		   
		case 'I':
		  lettsArray[34].count+=1;
		   break;
    
	    case 'J':
		  lettsArray[35].count+=1;
		   break;
		case 'K':
		  lettsArray[36].count+=1;
		   break;
		case 'L':
		  lettsArray[37].count+=1;
		   break;
		case 'M':
		  lettsArray[38].count+=1;
		   break;
		case 'N':
		  lettsArray[39].count+=1;
		   break;
		case 'O':
		  lettsArray[40].count+=1;
		   break;
		case 'P':
		  lettsArray[41].count+=1;
		   break;
		case 'Q':
		  lettsArray[42].count+=1;
		   break;
		case 'R':
		  lettsArray[43].count+=1;
		   break;
		case 'S':
		  lettsArray[44].count+=1;
		   break;
		case 'T':
		  lettsArray[45].count+=1;
		   break;
		case 'U':
		  lettsArray[46].count+=1;
		   break;
		case 'V':
		  lettsArray[47].count+=1;
		   break;
		 case 'W':
		  lettsArray[48].count+=1;
		   break;
		case 'X':
		  lettsArray[49].count+=1;
		   break;
		case 'Y':
		  lettsArray[50].count+=1;
		   break;
		case 'Z':
		  lettsArray[51].count+=1;
		   break;
		   
		default: break;
	}
	
// here the program counts the percentage for every letter that appears in the text and sets the value to the array of structs
	
	int totalLetts = {0};
	
	for(unsigned int i{0}; i <= 51; i++){
		
		totalLetts+= lettsArray[i].count;
	}
	
	for(unsigned int i{0}; i <= 51; i++){
		
		 lettsArray[i].letterPercentage = ( lettsArray[i].count * 100.0)/totalLetts;
	}
	
};


}

// -----------------END OF COUNT FUNCTION -----------------



void printResults(struct LettersInfo lettsArray[52], ofstream& f_alter){
	
	
	
    	
	

	 //print 
	 cout << setw(28) << left << "    LETTER " 
			  << setw(20) << left << "COUNT" 
              << setw(20) << left << "PERCENTAGE" << endl;
     cout << "--------------------------------------------------------------------------------" << endl;
	
	 //store to the file 
	 	 f_alter << setw(28) << left << "    LETTER " 
			  << setw(20) << left << "COUNT" 
              << setw(20) << left << "PERCENTAGE" << endl;
     f_alter << "--------------------------------------------------------------------------------" << endl;
	
	for(unsigned int i{0}; i <= 51; i++){
		
		//store the results into the file 
		
		f_alter << "***|  " << setw(20) << left << lettsArray[i].letterSymbol << ": " <<
		setw(20) << left << lettsArray[i].count << 
		setw(5)<< left <<  " ~ "  << fixed << setprecision(1) << lettsArray[i].letterPercentage << " %"<<endl;
		
		// output the data from the array of structs	
		
		cout<< "***|  " << setw(20) << left << lettsArray[i].letterSymbol << ": " <<
		setw(20) << left << lettsArray[i].count << 
		setw(5)<< left <<  " ~ "  << fixed << setprecision(1) << lettsArray[i].letterPercentage << " %"<<endl;

	}
	
	
}


