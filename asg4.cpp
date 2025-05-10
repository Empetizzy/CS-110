//********************************
// 
// 
// Student name: Dairo Emmanuel
// 
// Student number: 200503652
// 
// Assignment number: 4
// 
// Date written: 05-April-2025
// 
// Problem Statement:Code to determine the condition of the indivisals using their heamoglobin genes 
// and determine if any of the individuals are related
// 
// Input: Taken from data.txt and stored into their respective Array
// Consist of char values
// 
// Output:  
// Outputed to DNAanalysis.txt
// The state of the individuals gene if he/she is a carrier, anaemic or normal
// If any of the individuals are related
// 
// Main algorithim:
// Declared void function to store the heamoglobin values into their respected array
// Declared value returning function to return bool values true or false if any individual's gene are related
// Declare const array size
// Declare array  and size for each gene
// Declare buffer name for file input and output
// Test if input file and output file could be opened succesfully
// 
// Major Variables:
// ARRAYSIZE which is a constant
// Array and their size which are Gene1A,Gene2A,Gene1B,Gene2B,Gene1C,Gene2C,Gene1D,Gene2D,
// heamoglobin values taken from input file
// 
// 
// *****************//



#include<iostream> // For I/O
#include<fstream>// for file I/O

using namespace std;

// Declared Function prototypes for void Get1Gene which gets the value from the text file and store it into the aray
void Get1Gene(ifstream& infile, char r[], int arraysize);
// Declared function prototype to compare two heamoglobin gene and return true if there are related and false if there are not
bool SameGene(const char d[],const char e[], int as);


int main() {

	const int ARRAYSIZE = 444; // Declared ARRAYSIZE constant

	// Declared arrayname and inputed the size for each array
	char gene1A[ARRAYSIZE];
	char gene2A[ARRAYSIZE];
	char gene1B[ARRAYSIZE];
	char gene2B[ARRAYSIZE];
	char gene1C[ARRAYSIZE];
	char gene2C[ARRAYSIZE];
	char gene1D[ARRAYSIZE];
	char gene2D[ARRAYSIZE];

	ifstream infile; // To call input buffer infile
	ofstream outfile; // To call outptut buffer outfile

	infile.open("dna.txt"); // To open input file

	if (!infile) 
	{
		cout << "Input file could not be opened successfully" << endl;
		return 1; // Stop the code in other to avoid errors
	}
	outfile.open("DNAanalysis.txt");
	if (!outfile) // Test if output file was opened succesfully
	{
		cout << "Output file could not be opened successfully" << endl;
		return 1; // Stop the code in other to avoid errors
	}
	// Called GetGene function to get values from the input file and store into the array
	Get1Gene(infile, gene1A, ARRAYSIZE);
	Get1Gene(infile, gene2A, ARRAYSIZE);
	Get1Gene(infile, gene1B, ARRAYSIZE);
	Get1Gene(infile, gene2B, ARRAYSIZE);
	Get1Gene(infile, gene1C, ARRAYSIZE);
	Get1Gene(infile, gene2C, ARRAYSIZE);
	Get1Gene(infile, gene1D, ARRAYSIZE);
	Get1Gene(infile, gene2D, ARRAYSIZE);

	// if statement to determine if the individual is a carrier anaemic or normal
	// Using Logic OR, AND and also not
	
	if (gene1A[19] == 'T' && gene2A[19] == 'T') // if statement to test for Person A's condition
	{
		outfile << "Person A is aneamic" << endl;
	}
	else if (gene1A[19] == 'T' || gene2A[19] == 'T') 
	{
		outfile << "Person A is a carrier" << endl;
	}
	else if (gene1A[19] != 'T' && gene2A[19] != 'T') {
		outfile << "Person A is normal" << endl;
	}

	if (gene1B[19] == 'T' && gene2B[19] == 'T') // if statement to test for Person B's condition
	{
		outfile << "Person B is anemic" << endl;
	}
	else if (gene1B[19] == 'T' || gene2B[19] == 'T')
	{
		outfile << "Person B is a carrier" << endl;
	}
	else if (gene1B[19] != 'T' && gene2B[19] != 'T') {
		outfile << "Person B is normal" << endl;
	}

	if (gene1C[19] == 'T' && gene2C[19] == 'T') // if statement to test for Person C's condition
	{
		outfile << "Person C is anemic" << endl;
	}
	else if (gene1C[19] == 'T' || gene2C[19] == 'T')
	{
		outfile << "Person C is a carrier" << endl;
	}
	else if (gene1C[19] != 'T' && gene2C[19] != 'T') 
	{
		outfile << "Person C is normal" << endl;
	}

	if (gene1D[19] == 'T' && gene2D[19] == 'T')  // if statement to test for Person D's condition
	{
		outfile << "Person D is anemic" << endl;
	}
	else if (gene1D[19] == 'T' || gene2D[19] == 'T')
	{
		outfile << "Person D is a carrier" << endl;
	}
	else if (gene1D[19] != 'T' && gene2D[19] != 'T') {
		outfile << "Person D is normal" << endl;
	}


	// if statement to determine if A is related to B,C or D
	if (SameGene(gene1A, gene1B, ARRAYSIZE) || SameGene(gene1A, gene2B, ARRAYSIZE) || SameGene(gene2A, gene1B, ARRAYSIZE) || SameGene(gene2A, gene2B, ARRAYSIZE)) 
	{
		outfile << "Person A and B are related"<< endl;
	}
	else if (SameGene(gene1A, gene1C, ARRAYSIZE) || SameGene(gene1A, gene2C, ARRAYSIZE) || SameGene(gene2A, gene1C, ARRAYSIZE) || SameGene(gene2A, gene2C, ARRAYSIZE)) 
	{
		outfile << "Person A and C are realated" << endl;
	}
	else if (SameGene(gene1A, gene1D, ARRAYSIZE) || SameGene(gene1A, gene2D, ARRAYSIZE) || SameGene(gene2A, gene1D, ARRAYSIZE) || SameGene(gene2A, gene2D, ARRAYSIZE))
	{
		outfile << "Person A and D are related" << endl;
	}
	

	// if statement to detremine if B is related to C and D
	 if (SameGene(gene1B, gene1C, ARRAYSIZE) || SameGene(gene1B, gene2C, ARRAYSIZE) || SameGene(gene2B, gene1C, ARRAYSIZE) || SameGene(gene2B, gene2C, ARRAYSIZE))
	{
		outfile << "Person B and C are realated" << endl;
	}
	else if (SameGene(gene1B, gene1D, ARRAYSIZE) || SameGene(gene1B, gene2D, ARRAYSIZE) || SameGene(gene2B, gene1D, ARRAYSIZE) || SameGene(gene2B, gene2D, ARRAYSIZE))
	{
		outfile << "Person B and D are related" << endl;
	}

	 // if statement to determine if C is related to D
	 if (SameGene(gene1C, gene1D, ARRAYSIZE) || SameGene(gene1C, gene2D, ARRAYSIZE) || SameGene(gene2C, gene1D, ARRAYSIZE) || SameGene(gene2C, gene2D, ARRAYSIZE)) {
		 outfile << "Person C and D are related " << endl;
	}
	 // No if statement to check for D because a similar check is already in the if statement for A,B,C



	 infile.close(); //Close inputfile
	 outfile.close(); //Close outputfile

	return 0; // To stop and return successfull file execution
}
/*Void functions for to get value for for arrays*/
/* Boolean value returning function to return true or false if individuals are related*/
void Get1Gene(ifstream& infile, char r[], int arraysize) // Declared void function and ifstream for file I/O and to also store the values for each character infile into the array
{


	for (int i = 0; i < arraysize; i++) // For loop to get charcater and store into each array
	{
		infile.get(r[i]); // To get values and store into the array position in the current loop

	}
}
bool SameGene(const char d[],const char e[], int as) // declared value return bool function to determinr if two individuals are related while also declaring char constant to prevent value change in arrays
{
	for (int i = 0; i < as; i++) {
		if (d[i] != e[i]) {
			return false; // To return false if  the individuals are not related
		}

	}
	return true;  // To return true if  the individuals are related
}
