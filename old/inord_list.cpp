//============================================================================
// Name        : COLLEGE_HUEMOR.cpp
// Author      : newname
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <limits>

#include <fstream>
#include <sstream>
#include "inord_list.h"


using namespace std;

long int Real_NumberOfWords = 0, NumberOfCharacters = 0, Real_NumberOfCharacters = 0;
long int NumberOfDistinctWords = 0, Iam_the_Most_frequent = 0;

// Always make sure you make argv[1] a lower case litters
const char *operationsArray[NoOfOperations] = {
		"wordCount", "distWords", "charCount", "frequentWord",
		"countWord", "starting", "containing", "search"};

const string forbidden[] = {"a", "an", "the", "in", "on", "of", "and",
	"is", "are"};

const string forbidden_strings[forbidden_strings_count] = {"'", "\"", "]", "[", "}", ")", ",", ";", ":", "’", "‘", "&", "“", "”", ".", "(" ,"{"};
const char forbidden_chars[forbidden_char_count] = {'\'', ',', ';', ':', '’', '‘', '&', '“', '”', '.', ')', '(', '{', '}', '[', ']', '"'};


// Default constructor for a list
list:: list(const string FileToOpen)
{
	// Allocate a root node to start the list from
	node *root_ptr = new node;

	// Check for error allocating
	assert(root_ptr != NULL);

	//cout << "Default constructor for variable " << this << " is called \n";

	// Reset the list
	NumberOfWords = 0;

	// All point to root node (Parent node)
	head = root_ptr;
	prev = root_ptr;
	ptr_tmp = root_ptr;
	general_pointer = NULL;


	/* start the list darling */
	root_ptr -> next = NULL;
	root_ptr -> item = "";

	// Error handling required
/*	if(!LinkedList_Load(FileToOpen))
	{
		cout << "File not found\n";
	}
*/
	if(!LinkedList_Load_Enhanced_even_more(FileToOpen))
	{
		cout << "File not found\n";
	}
}

// Fast insertion, Insert from the root, head, node.
bool list :: LinkedList_Insertion(const listelementType &e, const string &line_to_append)
{
	node *tmp = new node;
	assert(tmp != NULL);

	bool insertion_flag = false;

	// Store
	tmp -> item = e;
	tmp -> Repeated_times = 1;

	// Empty lines
	tmp -> lines = line_to_append;

	// Indicate an empty list
	if(head -> next == NULL)
	{
		// root node is here and attach the tmp to it
		head -> next = tmp;
		tmp -> next = NULL;
	}

	// In this case insert at the very first element in the list
	else if((tmp -> item) < (head -> next -> item))
	{
		// Remove the equal sign to indicate a repeated word ( however the way you handle it)
		tmp -> next = head -> next;
		head -> next = tmp;
	}

	// In this case, loop the list till you are no longer greater
	else if((tmp -> item) > (head -> next -> item))
	{
		// Start from the root next node
		ptr_tmp = head -> next;

		for(int i = 0; ptr_tmp -> next != NULL; i++)
		{
			if((tmp -> item) <= (ptr_tmp -> item))
			{
				// Check equality
				if((tmp -> item) == (ptr_tmp -> item))
				{
				//	Real_NumberOfWords--;
				}

				else
				{
					// Switch and break the loop
					tmp -> next = prev -> next;
					prev -> next = tmp;
				}

				insertion_flag = true;
				break;
			}

			else
			{
				// Rembmer me
				prev = ptr_tmp;
				// Keep moving the pointer
				ptr_tmp = ptr_tmp -> next;
			}

		}

		if(!insertion_flag)
		{
			if((tmp -> item) < (ptr_tmp -> item))
			{
				// Switch and break the loop
				tmp -> next = prev -> next;
				prev -> next = tmp;
			}

			else if((tmp -> item) > (ptr_tmp -> item))
			{
				// Rembmer me
				ptr_tmp -> next = tmp;
				tmp -> next = NULL;
			}

			// Definetly you are equal
			else
			{
				//Real_NumberOfWords--;
			}
		}

		insertion_flag = true;
	}

	// Definetly you are equal
	else
	{
		//Real_NumberOfWords--;

	}


	Real_NumberOfWords++;
	return true;
}


// load dictionary in the Linked List
bool list :: LinkedList_Load(const string FileToOpen)
{
	bool Iam_A_Wrong_string_Neglect_Me = false;
	
	// Define the file that contains the dictionary
	ifstream file;

	int line_Number = 0;

	// Empty string to save lines at
	string Line_Number_Append_ME = "";

	// Open dictionary
	file.open(FileToOpen, ios::in);

	// Check for file status
	if (!file.is_open())
	{
		return false;
	}

	// For number of chars
	file.ignore( std::numeric_limits <std::streamsize>::max());
	std::streamsize length = file.gcount();
	NumberOfCharacters = length;
	file.seekg( 0, std::ios_base::beg );


    // Buffer for a word in a line
    string word(LENGTH, '/');

    // Buffer for a line fetched from the file
    string line;

    Real_NumberOfCharacters = -1;

    // Insert words into trie
     while (!file.eof())
     {
    	 // Get a whole line
 		getline(file, line);
 		Real_NumberOfCharacters++;

 		// Save the line number
 		line_Number++;

 		Line_Number_Append_ME = to_string(line_Number);

 		// Initialize ss to read the whole line for further manipulation
 		stringstream ss(line);

 		// Get a word from the buffered line
 		while(std:: getline(ss, word, ' '))
 		{
			//cout << word << " is here\n";
			// Check for invalid strings
			for(int i = 0; i < forbidden_strings_count; i++)
			{
				if(word.compare(forbidden_strings[i]) == 0)
				{
					cout << "Wrong word -> " << word <<"\n";
					Iam_A_Wrong_string_Neglect_Me = true;
					break;
				}
			}
 			// Check for extra space i.e: ' ' ' '
 			if(word.compare("") == 0);
 			/*else if(word.compare("'") == 0);
			else if(word.compare("\"") == 0);

			else if(word.compare(",") == 0);
			else if(word.compare(";") == 0);
			else if(word.compare(":") == 0);
			else if(word.compare("’") == 0);
			else if(word.compare("‘") == 0);
			else if(word.compare("&") == 0);
			else if(word.compare("“") == 0);
			else if(word.compare("”") == 0);
			else if(word.compare(".") == 0);

			else if(word.compare("(") == 0);
			else if(word.compare(")") == 0);
			else if(word.compare("{") == 0);
			else if(word.compare("}") == 0);
			else if(word.compare("[") == 0);
			else if(word.compare("]") == 0);*/
			else if(Iam_A_Wrong_string_Neglect_Me)
				Iam_A_Wrong_string_Neglect_Me = false;
			else
			{
				MyToLower(word);
/*				if(word.back() == '\'')
					word.pop_back();
				else if(word.back() == ',')
					word.pop_back();
				else if(word.back() == ';')
					word.pop_back();
				else if(word.back() == ':')
					word.pop_back();
				else if(word.back() == '’')
					word.pop_back();
				else if(word.back() == '‘')
					word.pop_back();
				else if(word.back() == '&')
					word.pop_back();
				else if(word.back() == '“')
					word.pop_back();
				else if(word.back() == '”')
					word.pop_back();
				else if(word.back() == '.')
					word.pop_back();
				else if(word.back() == ')')
					word.pop_back();
				else if(word.back() == '(')
					word.pop_back();
				else if(word.back() == '}')
					word.pop_back();
				else if(word.back() == '{')
					word.pop_back();
				else if(word.back() == '[')
					word.pop_back();
				else if(word.back() == ']')
					word.pop_back();
				else;
*/
				
				for(int i = 0; i < forbidden_char_count; i++)
				{
					if(word.back() == forbidden_chars[i])
					{
						word.pop_back();
						i = 0;
					}
				}

				// True for exisiting word
				if(LinkedList_Search(word, GENERIC_SEARCH) == true)
				{
					// Warning:: general_pointer is updated with the required ptr

					// Indicate repetetion for further instructions
					general_pointer -> Repeated_times = general_pointer -> Repeated_times + 1;

					/* Frequent word is decided here */
					if(Iam_the_Most_frequent <= general_pointer -> Repeated_times)
						Iam_the_Most_frequent = general_pointer -> Repeated_times;

					// You are here because the word is repeated in the file

					// Remember Line number
					// Line is already in the list, don't insert
					if(general_pointer -> lines.find(Line_Number_Append_ME) != string:: npos);
					else
					{
						general_pointer -> lines.append(" ");
						general_pointer -> lines.append(Line_Number_Append_ME);
					}

					//cout << general_pointer -> lines << " are the lines\n";

					// Reset the general pointer so it doesn't make an undefiend error
					general_pointer = NULL;
				}
				else
				{
					LinkedList_Insertion(word, Line_Number_Append_ME);

					// Every word is a distinct word, untill searched otherwise
					NumberOfDistinctWords++;
				}

				NumberOfWords++;
			}
		}
	 }

     //cout << "Linked list is loaded \n";

     file.close();
	return true;
}


/*	Warning code might explode */
// load dictionary in the Linked List
bool list :: LinkedList_Load_Enhanced_even_more(const string FileToOpen)
{
	bool Iam_A_Wrong_string_Neglect_Me = false;
	
	// Define the file that contains the dictionary
	ifstream file;

	int line_Number = 0;

	// Empty string to save lines at
	string Line_Number_Append_ME = "";

	// Open dictionary
	file.open(FileToOpen, ios::in);

	// Check for file status
	if (!file.is_open())
	{
		return false;
	}

	// For number of chars
	file.ignore( std::numeric_limits <std::streamsize>::max());
	std::streamsize length = file.gcount();
	NumberOfCharacters = length;
	file.seekg( 0, std::ios_base::beg );


    // Buffer for a word in a line
    string word(LENGTH, '/');

    // Buffer for a line fetched from the file
    string line;

    Real_NumberOfCharacters = -1;

    // Insert words into trie
     while (!file.eof())
     {
    	 // Get a whole line
 		getline(file, line);
 		Real_NumberOfCharacters++;

 		// Save the line number
 		line_Number++;

 		Line_Number_Append_ME = to_string(line_Number);

 		// Initialize ss to read the whole line for further manipulation
 		stringstream ss(line);

 		// Get a word from the buffered line
 		while(std:: getline(ss, word, ' '))
 		{
			stringstream buff(word);
			string buffe;
			while(std:: getline(buff, buffe, ','))
			{
				stringstream buffr(buffe);
				string buffee;
				while(std:: getline(buffr, buffee, '.'))
				{
					//cout << buffee << endl;
					stringstream buffrr(buffee);
					string buffeee;
					while(std:: getline(buffrr, buffeee, '\t'))
					{
						if(buffeee.compare("") == 0);
						else
						{
							//cout << buffeee << endl;
							// Check for invalid strings
							for(int i = 0; i < forbidden_strings_count; i++)
							{
								if(buffeee.compare(forbidden_strings[i]) == 0)
								{
									Iam_A_Wrong_string_Neglect_Me = true;
									break;
								}
							}
							
							// Check for extra space i.e: ' ' ' '
							if(buffeee.compare("") == 0);

							else if(Iam_A_Wrong_string_Neglect_Me)
								Iam_A_Wrong_string_Neglect_Me = false;
							else
							{
								MyToLower(buffeee);

								for(int i = 0; i < forbidden_char_count; i++)
								{
									if(buffeee.back() == forbidden_chars[i])
									{
										buffeee.pop_back();
										i = 0;
									}
								}

								// True for exisiting buffeee
								if(LinkedList_Search(buffeee, GENERIC_SEARCH) == true)
								{
									// Warning:: general_pointer is updated with the required ptr

									// Indicate repetetion for further instructions
									general_pointer -> Repeated_times = general_pointer -> Repeated_times + 1;

									/* Frequent buffeee is decided here */
									if(Iam_the_Most_frequent <= general_pointer -> Repeated_times)
										Iam_the_Most_frequent = general_pointer -> Repeated_times;

									// You are here because the buffeee is repeated in the file

									// Remember Line number
									// Line is already in the list, don't insert
									if(general_pointer -> lines.find(Line_Number_Append_ME) != string:: npos);
									else
									{
										general_pointer -> lines.append(" ");
										general_pointer -> lines.append(Line_Number_Append_ME);
									}

									//cout << general_pointer -> lines << " are the lines\n";

									// Reset the general pointer so it doesn't make an undefiend error
									general_pointer = NULL;
								}
								else
								{
									LinkedList_Insertion(buffeee, Line_Number_Append_ME);

									// Every buffeee is a distinct buffeee, untill searched otherwise
									NumberOfDistinctWords++;
								}

								NumberOfWords++;
							}
						}
					}
				}
			}
			
		}
	 }

     //cout << "Linked list is loaded \n";

     file.close();
	return true;
}


// Search for an item
bool list :: LinkedList_Search(const listelementType &e, int mode)
{
	bool starting_with_flag = true, Just_Indication = false, I_Need_A_New_Line = false;;
	unsigned int x = 0;

	// Start from the beginning of the list
	ptr_tmp = head -> next;

	// Avoid empty list
	if(Real_NumberOfWords == 0)
	{
		//cout << "No data to compare \n";
		return false;
	}

	// Operations:: starting with, containing, Search for string, Generic Search
	switch(mode)
	{
		// Starting mystr function
		case STARTING_WITH_MODE:

			// Check if the stirng is starting with a given substring
			for(int i = 0; i < Real_NumberOfWords; i++)
			{
				for(int i = 0; e[i] != '\0'; i++)
				{
					if((ptr_tmp -> item)[i] == e[i]);
					else
					{
						starting_with_flag = false;
						break;
					}
				}

				// This string is indeed starting with that substring, print it
				if(starting_with_flag)
				{
					if(I_Need_A_New_Line == true)
					{
						//cout << " ";
						cout << "\t";
					}

					Just_Indication = true;
					I_Need_A_New_Line = true;
					cout << ptr_tmp -> item << ": " << ptr_tmp -> Repeated_times;
				}

				// Reset the flag for further investigations
				starting_with_flag = true;

				// Keep moving
				ptr_tmp = ptr_tmp -> next;
			}

			// Error handling
			if(Just_Indication == true)
				return true;
			else
				return false;
			
			break;

			// Containing mystr function
		case CONTAINING_STRING:

			// Check if the string has the required pattern
			for(int i = 0; i < Real_NumberOfWords; i++)
			{
				// Patern check
				if((ptr_tmp -> item).find(e) != string:: npos)
				{
					if(I_Need_A_New_Line == true)
					{
						//cout << " ";
						cout << "\t";
					}

					Just_Indication = true;
					I_Need_A_New_Line = true;
					cout << ptr_tmp -> item << ": " << ptr_tmp -> Repeated_times;
				}
				ptr_tmp = ptr_tmp -> next;
			}

			// Error handling
			if(Just_Indication == true)
				return true;
			else
				return false;

			break;

		// Containing mystr function
		case SEARCH_FOR_STRING:

			// Check if the string has the required pattern
			for(int i = 0; i < Real_NumberOfWords; i++)
			{
				// Patern check

				if((ptr_tmp -> item).find(e) != string::npos)
				{
					if(I_Need_A_New_Line == true)
					{
						cout << "\n";
					}

					Just_Indication = true;
					//cout << ptr_tmp -> item << ": lines " << ptr_tmp -> lines;
					cout << ptr_tmp -> item << ":\t lines " << ptr_tmp -> lines;
					I_Need_A_New_Line = true;
				}
				ptr_tmp = ptr_tmp -> next;
			}

			// Error handling
			if(Just_Indication == true)
				return true;
			else
				return false;

			break;

		// To search for a word for multiple words sake during loading list
		case GENERIC_SEARCH:

			// Search for a word in the list
			for(int i = 0; i < Real_NumberOfWords; i++)
			{
				// Word check to avoid multiple spots in the list
				if(ptr_tmp -> item  == e)
				{
					// Remeber that you need its address to increase number of occuarances
					general_pointer = ptr_tmp;
					return true;
				}
				ptr_tmp = ptr_tmp -> next;
			}

			return false;
			break;

			// Frequent word operation
		case FREQUENT_WORD_SEARCH:

			// Loop the whole list to find the most frequent word
			for(int i = 0; i < Real_NumberOfWords; i++)
			{
				// Compare with the most frequent
				if(ptr_tmp -> Repeated_times == Iam_the_Most_frequent)
				{
					for(int j = 0; j < NoOfForbiddens; j++)
					{
						if(ptr_tmp -> item == forbidden[j])
						{
							Just_Indication = true;
						}
					}
					
					if(Just_Indication == true);
					else
					{
						if(I_Need_A_New_Line == true)
						{
							cout << " ";
						}

						Just_Indication = true;
						cout << ptr_tmp -> item;

					}
				}

				ptr_tmp = ptr_tmp -> next;
			}

			return true;
			break;

		// Word count operation
		case WORD_COUNT_OPERATION:

			// Loop the whole list to find the most frequent word
			for(int i = 0; i < Real_NumberOfWords; i++)
			{
				// Compare with the word
				if(ptr_tmp -> item == e)
				{
					Just_Indication = true;
					cout << ptr_tmp -> item << " is repeated " << ptr_tmp -> Repeated_times << " times\n";
					return true;
				}
				ptr_tmp = ptr_tmp -> next;
			}

			// Error handling
			if(Just_Indication == true)
				return true;
			else
				return false;

			break;

		default:
			break;
	}


	cout << "Not found in the entire list \n";
	return false;
}

// Show the whole list
bool list :: LinkedList_show_Whole()
{
	node *ptr = head;

	if(Real_NumberOfWords == 0)
	{
		cout << "Not enough data in the list \n";
		return false;
	}

	// Head is root, can't be accessed
	ptr = ptr -> next;

	for(int i = 0; i < Real_NumberOfWords; i++)
	{
		cout << ptr -> item << " ";
		ptr = ptr -> next;
	}

	return true;
}

// Delete from here, Do not delete directly from DELETE_WHILE_LIST
bool list :: Delete_VIP()
{
	ptr_tmp = head;
	Delete_Whole_List();

	return true;
}


// Recursive Deletion
bool list :: Delete_Whole_List()
{
	// Buffer to save the previous condition of ptr
	node *last_before_stack = NULL;

	// Checking on the next field
	if(ptr_tmp -> next != NULL)
	{
		last_before_stack = ptr_tmp;
		ptr_tmp = ptr_tmp -> next;
		//cout << ptr_tmp -> item << "exist, then Loop in the stack \n";
		Delete_Whole_List();
		ptr_tmp = last_before_stack;
	}

	//cout << "current Node item is " << ptr_tmp -> item << " and is deleted\n";
	// free ptr_tmp node and return
	delete(ptr_tmp);
	NumberOfWords = 0;

	return true;
}


// Print the number of chars
bool list :: LinkedList_size_chars()
{
	cout << NumberOfCharacters << " characters\n";

	return true;
}

// Print number of words
bool list :: LinkedList_size_words()
{
	cout << NumberOfWords << " words\n";
	return true;
}

// Print number of distinct words
bool list :: LinkedList_distinct_words()
{
	cout << NumberOfDistinctWords << " distinct words\n";
	return true;
}

// Frequent word operation
bool list :: LinkedList_Frequent_Word()
{
	cout << "Most frequent word is: ";
	LinkedList_Search("Start_Process", FREQUENT_WORD_SEARCH);
	cout << "\n";

	return true;
}

bool list :: LinkedList_WordCout(std :: string &e)
{

	if(LinkedList_Search(e, WORD_COUNT_OPERATION) == true);
	else
		cout << "Word not found\n";

	return true;
}

// Starting with operation
bool list :: LinkedList_Starting_With(std :: string &e)
{
	// Send the string to search for it
	if(LinkedList_Search(e, STARTING_WITH_MODE) == true);
	else
		cout << "Word not found";

	cout << "\n";
	return true;
}

// Containing string operation
bool list :: LinkedList_Containing(std :: string &e)
{
	// Send the string to search for it
	if(LinkedList_Search(e, CONTAINING_STRING) == true);
	else
		cout << "Word not found";

	cout << "\n";

	return true;
}

// Search for string and print its lines
bool list :: LinkedList_Search_With_Lines(std :: string &e)
{

	// Send the string to search for it
	if(	LinkedList_Search(e, SEARCH_FOR_STRING) == true);
	else
		cout << "Word not found";

	cout << "\n";

	return true;
}

// Deconstructor is here for you bitch
list :: ~list()
{
	Delete_VIP();
	//cout << "Deconstructor is called for " << this << " object\n";
}


// Always execute this function to modify the operation argument
void MyToLower(string &x)
{
	for(unsigned char i = 0; x[i] != '\0'; i++)
	{
		if(x[i] >= 'a' && x[i] <= 'z');
			// Move to the next byte1

		// Update the string with a lower case letter instead
		else if( x[i] >= 'A' && x[i] <= 'z')
			x[i] = x[i] + 32;
		else;
	}
}


/* ALL COMING ARE FOR OPERATIONS */


int list :: CheckMyOperationAndExecute(const char *File_TO_OPEN)
{
	// Simulate main funcation's argc and argv
	string argument_vector1, argument_vector2;
	int argument_counter = 0;

	// Indication for the current word iam at
	bool The_Most_Important_Flag = true;

	// Define the file that contains the dictionary
	ifstream file;

	// Open command file as an input
	file.open(File_TO_OPEN, ios::in);

	// Check for file status
	if (!file.is_open())
	{
		cout << "File not found\n";
		return false;
	}

	// Buffer for a word in a line
	string word(LENGTH, '/');

	// Buffer for a line fetched from the file
	string line;

	// Ready to read commands
	 while (!file.eof())
	 {
		 // Get a whole line
		getline(file, line);

		// Initialize ss to read the whole line for further manipulation
		stringstream ss(line);

		// Strings are separated by space
		// Retrieve the first word

		// Skip the first spaces if any
		while(getline(ss, word, ' '))
		{
			if(word.compare("") == 0);
			else
				break;
		}

		// That's an empty line, watch out and break out of it
		if(word.compare("") == 0)
		{
			// Do nothing
		}

		// it's a valid word, keep going
		else
		{
			// assign the word to argv[1]
			argument_vector1 = word;

			// Retrieve the second word

			// Skip the first spaces if any
			while(getline(ss, word, ' '))
			{
				// Indication that there is still words on the line
				The_Most_Important_Flag = false;
				if(word.compare("") == 0);
				else
					break;
			}

			// Check for the word to see if still ""
			if(word.compare("") == 0 || The_Most_Important_Flag)
			{
				The_Most_Important_Flag = true;
				argument_counter = 1;
				/* you are here in case argument counter == 1 only*/
				Operations_Help_Decide(argument_counter, argument_vector1, argument_vector2);
				// Here the word should have a valid string, print it
			}
			else
			{
				The_Most_Important_Flag = true;

				argument_counter = 2;
				argument_vector2 = word;

				// Retrieve the second word

				// Skip the first spaces if any
				while(getline(ss, word, ' '))
				{
					The_Most_Important_Flag = false;

					if(word.compare("") == 0);
					else
						break;
				}

				// Valid data, 2 arguments
				if(word.compare("") == 0 || The_Most_Important_Flag)
				{
					/* You are here in case argument counter == 2 only */
					Operations_Help_Decide(argument_counter, argument_vector1, argument_vector2);
					The_Most_Important_Flag = true;
				}

				// 3 Arguments are invalid arguments
				else
				{
					The_Most_Important_Flag = true;
					cout << "Incorrect number of arguments\n";
					// Reset the counter
					argument_counter = 0;
				}
			}


		}
	 }

	 return 1;
}



bool list :: Operations_Help_Decide(int argc, std:: string op, string ptr)
{
	int i = 0;

	switch(argc)
	{
		// Wordcount, distWords,charCout, Frequentword
		case 1:

			// These operations don't require any input
			for(i = 0; i < NoOfOperations / 2; i++)
			{
				if(op.compare(operationsArray[i]) == 0)
				{
					// Inputs other than i, don't matter.
					Operations_Help_Decide_Versio2(i, ptr);

					return true;
				}
			}

			// These operations don't require any input
			for(i = NoOfOperations/ 2; i < NoOfOperations; i++)
			{
				if(op.compare(operationsArray[i]) == 0)
				{
					// Inputs other than i, don't matter.
					cout << "Incorrect number of arguments\n";
					return true;
				}
			}

			cout << "Undefined command\n";
			return false;
			break;

		// CountWord, starting, containing, search
		case 2:

			for(i = NoOfOperations / 2; i < NoOfOperations; i++)
			{
				if(op.compare(operationsArray[i]) == 0)
				{
					// send a string and a pointer, choose in the function which one you need
					Operations_Help_Decide_Versio2(i, ptr);
					return true;
				}
			}

			for(i = 0; i < NoOfOperations / 2; i++)
			{
				if(op.compare(operationsArray[i]) == 0)
				{
					// send a string and a pointer, choose in the function which one you need
					cout << "Incorrect number of arguments\n";
					return false;
				}
			}

			cout << "Undefined command\n";
			return false;

			break;

		default:
			cout << "AN ERROR HAPPENED\n";
			break;
	}

	return true;
}


void list :: Operations_Help_Decide_Versio2(int i, string str)
{
	switch(i)
	{
		case 0:
			LinkedList_size_words();
			break;

		case 1:
			LinkedList_distinct_words();
			break;

		case 2:
			LinkedList_size_chars();
			break;

		case 3:
			LinkedList_Frequent_Word();
			break;

		case 4:
			LinkedList_WordCout(str);
			break;

		case 5:
			LinkedList_Starting_With(str);
			break;

		case 6:
			LinkedList_Containing(str);
			break;

		case 7:
			LinkedList_Search_With_Lines(str);
			break;

		default:
			cout << "NO WAY!!!!\n";
			break;
	}
}
