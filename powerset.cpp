/***********************************************************
Homework question for Amazon interview 1/18/2011
Name: Kiel Friedt
E-mail: kiel.friedt@gmail.com
Efficiency: O(2^n)
***********************************************************/

#include <iostream>
#include <math.h>

using namespace std;

/************************************************************
// Function Name: powerset
// Parameters: char ** buffer, int size
// Description: loops through all possible subsets ie: 2^argc-1.
// Checks if valueInBits ends in 1, ie: 0001, if so prints current buffer element by index.
// Then divides valueInBits by 2 each time until 0, while also incrementing the index of array.
************************************************************/

void powerset(char ** buffer, int size)
{
	int i = 0, index = 0, valueInBits = 0;
	
	for (i = 0 ; i < size ; ++i) { // loops through all possible subsets ie: size = 2^argc-1
		printf("{");
		valueInBits = i;
		index = 0;
		while(valueInBits){//loops while valueInBits != 0
			if(valueInBits & 1)//logical &, if valueInBits has a 1 in 1's place, it will be true
				cout << " " <<buffer[index] << " ";
			valueInBits >>= 1; //shift valueInBits by 1 and reassign value
			index++;
		}
		printf("} ");
	}
	
}


/************************************************************
// Function Name: Main
// Parameters: int argc, char * const argv[]
// Description: Reads in arguments from the command line. 
// Then creates a dynamic two dem array and fills it will argument list. 
// Then calls powerset with array and total possible elements, then deallocates memory.
************************************************************/

int main (int argc, char * const argv[]) {
	char **buffer;
	int size = 0, i = 0;
	if (argc < 2) {
		cout << "error: must have a set to make a powerset.\n";
		return 0;
	}
	size = pow(2,argc-1);
	
	/* fills array with argv[]*/
	buffer = new char*[argc-1];
	for (i = 0; i < argc-1;++i){
		buffer[i] = new char[(strlen(argv[i+1]))+1];
		strcpy(buffer[i],argv[i+1]);
	}
	cout << "size of powerset: " << size << " {";
	powerset(buffer,size);
	cout << "}\n";
	
	/* deallocates memory*/
	for(i = 0 ; i < argc-1 ; ++i )
		delete [] buffer[i];
	delete [] buffer;
	
    return 0;
}