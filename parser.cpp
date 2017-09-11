/**
*  Dishant Bhatt, cssc1029, 818082740
*  James Lawrence, 817812210
*  CS530, Spring 2017
*  Assignment #3, Parser for Assignments and Expressions
*  parser.cpp
*
*/








#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;


char line[255];
int universalPointer;






bool checkOp(char c)
{
	if((c== '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%') && c != ' ')
		{ 	
			return true;
		}
	
	return false;
}



bool opTester(string str,int pointer)
{

	
	if(pointer +1 != str.length()-1)
		{
			if(str[pointer + 1] != ' ')
			{
				return false;
			}
		}
		
	
	if(pointer + 1 != str.length())
		{
			int tempPointer = pointer + 1;
	
		while(str[tempPointer] == ' ')
			{
				tempPointer++;
		
			}
	
	if(checkOp(str[tempPointer]) == true || str[tempPointer] == ';' )
		{
			return false;
		}
	
}

	

	 
		

	return true;
}


bool semiColonChecker(string str, int pointer)
{
	int tempPointer = pointer;
		
	if(tempPointer + 1 != str.length())
		{
			do
				{
					tempPointer++;
					if(str[tempPointer] != ' ')
						return false;
						
					
				}while(str[tempPointer] == ' ');
		}
				
				
				
	return true;
				
				
}


bool checkNum(string str, int pointer)
{
	if(str[pointer - 1] == ' ')
		{return false;}
		
		return true;
}




bool tester(string str, ofstream &stream)
{ 
	bool error = true;
	bool semiColonFlag = false;
	int semiColons = 0;
	int paren = 0;
	int equalSigns = 0;
	
	
	
	if(checkOp(str[0]) || isdigit(str[0]))
		{
			
			stream << "Expression or Assignment starts with an operand or Number:FAIL     ";
			cout << "Expression or Assignment starts with an operand or Number:FAIL     ";
			return false;
		}
		
		
		
	for(universalPointer = 0; universalPointer < str.length() ; universalPointer++)
	{	
		 
		
		bool isOp = checkOp(str[universalPointer]);
		
		
		if(str[universalPointer] == '=')
			{equalSigns++;}
			
		if(isOp == true)
			 {
			error = opTester(str, universalPointer);
			
			
			
			
			if(!error)
			{
			stream << "Invalid Use of Ops:FAIL                                            ";
			cout << "Invalid Use of Ops:FAIL                                            ";
			return false;}
				
			}
			
			error = true;
			
			
		if(str[universalPointer] == ';')
			{
				semiColons++;
				error = semiColonChecker(str, universalPointer);
				if(!error)
					{
			stream << "Invalid use of semi-colons:FAIL                                    ";
			cout << "Invalid use of semi-colons:FAIL                                    ";
					return false;
					}
					
					
				
			}
			
			error = true;
			if(isdigit(str[universalPointer]))
			{
				error = checkNum(str, universalPointer);
				if(!error)
					{
			stream << "Invalid use of a number:FAIL                                       ";
			cout << "Invalid use of a number:FAIL                                       ";
			return false;
					}
			}
	
			if(str[universalPointer] == '(')
				{paren++;}
			if (str[universalPointer] == ')')
			 	{paren--;}

		
	}
	
	
	
	if(paren != 0)
		{
			stream << "Unbalanced Parenthesis:FAIL                                        ";
			cout << "Unbalanced Parenthesis:FAIL                                        ";
			return false;
		}
	if(semiColons != 1)
	{ 
	  		stream << "No semi-colon at end of statement:FAIL                             ";
			cout << "No semi-colon at end of statement:FAIL                             ";
			return false;
	 }
	
	
	int equalSignPos = str.find_first_of('=');
	int firstSpace = str.find_first_of(' ');
	
	if((firstSpace +  1 != equalSignPos && equalSignPos != -1) || equalSigns > 1)
		{
			stream << "Equal Sign is used incorrectly:FAIL                                ";
			cout << "Equal Sign is used incorrectly:FAIL                                ";
			return false;
		
		
		}
		
		
	
	
	

	return true;
	

}



int main()
{

	ifstream in;
	ofstream writeFile;
	writeFile.open("out.txt");
	in.open("in.txt");
	
	int lineCounter = 1;
	string str;

	while(getline(in, str)){
		
	
	bool error = tester(str, writeFile);
	if(error == false)
		{writeFile << str <<  endl;
		cout << str <<  endl;
		}
	else{
	writeFile << "PASS                                                               " << str << endl;
	cout << "PASS                                                               " << str << endl;
	}
	lineCounter++;
}




in.close();

return 0;





}
