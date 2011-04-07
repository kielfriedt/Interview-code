/*
* Copyright (C) 2011 Kiel Friedt
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/***********************************************************
Homework question for Amazon interview 4/6/2011
Name: Kiel Friedt
E-mail: kiel.friedt@gmail.com
Efficiency: O(n)
Notes: I tried using a hashmap and i have partial code if you would like 
to see it. I gave up on a hash map after 2 hours of writing a ton of 
useless code. I hope it is ok that i used a book for reference. I remembered
from a previous interview question with amazon that using a bitwise operator was
extremely helpful. So after some reading in the reference book and testing,
i decided on an XOR bitwise operator, which allowed me to compare all the array 
once and use no more memory. Which is what you requested in the interview.
Sorry i finally understood your hint. 

Simple truth table: XOR
A B output
0 0   0
0 1   1
1 0   1
1 1   0
   
array = {4,5,4}

example:
    4 100
xor 5 101
----------
      001
xor 4 100
----------
      101 <- gives me back 5 meaning that 5 was odd in the set
xor	5 101
----------
      000 <- meaning both 4 and 5 are even so none are odd

Sample syntax:
 ./findodd <File_Name> <Number_Elements>

File_Name: Must be a valid file name containing integers.
Number_Elements: Integer value indicating the number of integers in the file. 

File format:
1
2
2
3
1
**********************************************************/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/************************************************************
// Function Name: find
// Parameters: int * array, int count
// Description: Sets the first int from the array, then uses XOR 
// against the next element. The running int is then ran against the 
// next element until the end of the array.
// If all elements are not odd it will return 0 since 5 101 ^= 101 -> 000
// else the odd numbered integer.
************************************************************/
int find(int * array, int count){
	//Set up first element
	int oddOne = array[0];
	//Run through array doing XOR to each element and find out which one is odd numbered
	for(int i = 1; i < count; i++)
		oddOne ^= array[i];
	//Returns odd number or 0 if all elements are even
	return oddOne;
}

/************************************************************
// Function Name: Main
// Parameters: int argc, char * const argv[]
// Description: Checks arguments to see if syntax is correct.
// Creates the array and reads in the file line by line. Does simple 
// file error checking. Once the file is read in it does simple error 
// checking to make sure the data is correct compared to syntax input. 
// Calls the find function which returns the number that is odd in 
// the array or 0 if all of them are even.
************************************************************/
int main (int argc, char * const argv[]){
	int * array = NULL;
	int elementCount = 0, tmpContainer = 0;
	//Checks to see if the syntax is correct
	if (argc <= 2 || argc > 3) {
		cout << "Syntax: ./findodd <File_Name> <Number_Elements>\n";
		return 0;
	}
	int count = atoi(argv[2]);
	array = new int[count]; //Number of elements in the file per syntax
	ifstream myFile(argv[1]); //Sets file pointer
	//Checking to see if the file was opened properly or not.
	if(!myFile){
		 cout << "Unable to open file";
		 exit(1); //Terminate with error
	}else{
		while (myFile >> tmpContainer){
			if(tmpContainer != 0){
				array[elementCount] = tmpContainer;
				elementCount++;
			}
			//Number of elements read is more then syntax
			if(elementCount > count){
				cout << "Error: To many element in the file, check syntax!\n";
				exit(1);
			}
		}
		//Number of elements read is less then the syntax.
		if(elementCount+1 < count){
			cout << "Error: Not enough elements, check syntax!\n";
			exit(1);
		}
	}
	int oddNumber = find(array, count);
	//Output of find
	if(oddNumber == 0)
		cout << "The Array contains no odd numbered integers.\n";
	else
		cout << "Odd numbered number in the set: " << oddNumber << "\n";

	//Deallocate int array
	delete [] array;
	myFile.close();
	return 0;
}
