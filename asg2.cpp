//*********************************************************************************************************************************************************
// ***********************************************************************************************************************************
//
//Student name: Dairo Emmanuel
//
// Student number: 200-503-652
//
//Assignment number: CS 110- 001 Assignmnet 2
//
//Program name: asg2.cpp
//
//Date written:25-02-2025
// 
//Problem Statement: This C++ program predicts the molecular geometry of molecules based on formulas using symbols and values taken from 
// the input file
// 
//The program also outputs the geometrical shape of the system, the symbol of the element while also outputing the number of bonding domains (b)
//
//Input: Values A,B and b taken from the input file 
// A and B representing the chemical symbols while 
// b representing the number of bonding domains
//
// Output: The geometrical shape of the atom surrounded by the element
//
//Main Algorithim: Collect values of Atom A, Atom B and number of bond domain (b) from the input file 
// 
// Identify the valence electrons (v) for each central atom A which will be harcoded and gotten using a nested if.
// 
//Subtract the number of bonding domains b from  v to determine the number of nonbonding electrons e
// 
// Divide electrons/2  to determine the number of bonding domains (n)
// 
// Determine the shape of the atom by using nested if with the values of b and n to find the molecular geometry(shape)
// 
//Hardcoded the shape in nested if.
//
// Major Variables: A  and B chemical symbols of the element taken from the input file
// A decalred as Atom_A
// B decalred as Atom_B
//
// b the bonding atom taken from the input file decalred as numofbond_b
// v center atom of A hardcoded
// e the non bonding electrons gotten from the formula electrons = valence - numofbond_b
// n the number of bonding domains gotten from numofbond_n = electrons/2
// s the geometrical shape gotten based on the values of b and n
//
//Assumptions: valence elentrons(v) of the element gotten from table 1
// Be - 3, C - 4, Si - 4, N - 5, P - 5, As - 5, O - 6, S - 6, Se - 6,
// F - 7, Cl - 7,Br - 7, I - 7, Xe - 8,
// 
// 2nd Assumption
// Value of the Molecular Geometry gotten using value of b and n to identify s(molecular geometry) and harcoding the value
// 
// The shape when b is 2
// if n is 0 it's linear, if n is 1 it's bent, if n is 2 it's bent, if n is 3 it's linear.
// 
// The shape when  b is 3
// if n is 0 it's trigonal planar, if n is 1 it's trigonal pyramidal, if n is 2 it's T-shaped.
// 
// The shape when b is 4
// if n is 0 it's tetrahedral, if n is 1 it's seesaw, if n is 2 it's square planar.
// 
// The shape when b is 5 
// if n is 0 it's trigonal bipyramidal, if n is 1 it's square pyramidal.
// 
// The shape when b is 6
// when n is 0 it's octahedral
// 
// Important detial: Any value that does not match the data above will be given unknown as the shape
//
//Program Limitations - 
// Hardcoded values for valence
// Hardcoded values for shapes
//
//**************************************************************************************************************************************

#include<iostream> // needed for  I/O
#include<fstream>  // needed for file I/O


using namespace std;

int main() {

	// Variables of element and data type for atom
	string Atom_A;
	string Atom_B;
	// Declared variable and datatype for number of bond b
	int numofbond_b;
	// Decalred variable and datatype for  valence elctrons (v)
	int valence;
	// Decalred variable and datatype for electrons
	int electrons;
	int numofbond_n = 0; // Declared number of bond n and set equal to zero to initialize memory
	string shape; // Decalred variable and data type for geometric shape 
	

	ifstream infile; // To Call input file buffer infile
	ofstream outfile;// To Call output file buffer outfile

	infile.open("molecules.text"); // try to open input file

	if (!infile) // Error check to see if there was a probelm opening the input file
	{
		cout << "Error opening input file, molecules.txt. Exiting..." << endl; // To print out error message if input file could not be opened succesfully

		return 1; // Stop the program
	}

	outfile.open("geometricalshapes.txt"); // try to open output file

	if (!outfile) // Error check to see if there was a problem opening the output file
	{
		cout << "Error openign output file, geometricalshapes.txt " << endl; // To print out error message if output file could not be opened succesfully

		return 1; // Stop the program
	}

	// Priming Read to get value from text file
	infile >> Atom_A;
	infile >> Atom_B;
	infile >> numofbond_b;

	while (infile) // To start loop which reads the values from infile
	{
		
		// Use if else  statemement  using atom_A to assign values for valence based on their atoms
		// added formula expression in each if statement to prevent intializating memory for valence and electrons at the start of code
		if (Atom_A == "Be")
		{
			valence = 3;
			electrons = valence - numofbond_b;
			numofbond_n = electrons / 2;
		
		}
		else if (Atom_A == "C" || Atom_A == "Si") {
			valence = 4;
			electrons = valence - numofbond_b;
			numofbond_n = electrons / 2;
			
		}
		else if (Atom_A == "N" || Atom_A == "P" || Atom_A == "As") {
			valence = 5;
			electrons = valence - numofbond_b;
			numofbond_n = electrons / 2;
			
		}
		else if (Atom_A == "O" || Atom_A == "S" || Atom_A == "Se") {
			valence = 6;
			electrons = valence - numofbond_b;
			numofbond_n = electrons / 2;
			
		}
		else if (Atom_A == "F" || Atom_A == "Cl" || Atom_A == "Br" || Atom_A == "I") {
			valence = 7;
			electrons = valence - numofbond_b;
			numofbond_n = electrons / 2;
			
		}
		else if (Atom_A == "Xe") {
			valence = 8;
			electrons = valence - numofbond_b;
			numofbond_n = electrons / 2;
			
		}

		
	    // Nested if statement to assign shapes based on number of bonds (b)
		if (numofbond_b == 2) 
		{
		    // nested if statement to assign value of shape to atom based on number of bond n after checking if numofbond_b	
			if (numofbond_n == 0 || numofbond_n == 3) {
				shape = "linear";
			}
			else if (numofbond_n == 1 || numofbond_n == 2) {
				shape = "bent";
			}
			
			else {
				shape = "unknown"; // Coded an else statement in case numofbond_n was not true for any of the statements
			}
		}
		else if (numofbond_b == 3) 
		{
			// nested if statement to assign value of shape to atom based on number of bond n after checking if numofbond_b
			if (numofbond_n == 0) {
				 shape = "trigonal planar";
			}
			else if (numofbond_n == 1) {
				shape = "trigonal pyramidal";
			}
			else if (numofbond_n == 2) {
				shape = "T-shaped";
			}
			else {
				shape = "unknown"; // Coded an else statement in case numofbond_n was not true for any of the statements
			}
		}
		else if (numofbond_b == 4) 
		{
			// nested if statement to assign value of shape to atom based on number of bond n after checking if numofbond_b
			if (numofbond_n == 0) {
				shape = "tetrahedral";
			}
			else if (numofbond_n == 1) {
				shape = "seesaw";
			}
			else if (numofbond_n == 2) {
				shape = "square planar";
			}
			else {
				shape = "unknown"; // Coded an else statement in case numofbond_n was not true for any of the statements
			}
		}
		else if (numofbond_b == 5) 
		{
			// nested if statement to assign value of shape to atom based on number of bond n after checking if numofbond_b
			if (numofbond_n == 0) {
				shape = "trigonal bipyramidal";
			}else if (numofbond_n == 1) {
				shape = "square pyramidal";
			}
			else {
				shape = "unknown"; // Coded an else statement in case numofbond_n was not true for any of the conditions
			}
		}
		else if (numofbond_b == 6) 
		{
			// nested if statement to assign value of shape to atom based on number of bond n after checking if numofbond_b

			if (numofbond_n == 0) {
				shape = "octahedral";
			}
			else {
				shape = "unknown"; // Coded an else statement in case numofbond_n was not true for any of the conditions
			}
		}
		else {
			shape = "unknown"; // Coded an else statement in case numofbond_b was not true for any of the conditions
		}
		// To print the geometrical shape to output file
		outfile << "The geometrical shape of one " << Atom_A << " atom surrounded by " << numofbond_b << " " << Atom_B << " atoms is " << shape << endl;

		// TO get the next value from the input file to continue the end of file loop
		infile >> Atom_A;
		infile >> Atom_B;
		infile >> numofbond_b;
	}

	infile.close(); // Closed input text file 
	outfile.close(); // closed output text file
	return 0; // To show succesful code excecution
}



