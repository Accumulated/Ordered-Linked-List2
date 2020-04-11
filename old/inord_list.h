/*
 * COLLEGE_HUEMOR.h
 *
 *  Created on: Mar 7, 2020
 *      Author: newname
 */

#ifndef INORD_LIST_H
#define INORD_LIST_H


typedef std::string listelementType;

#define LENGTH			47
#define NoOfOperations	8
#define NoOfForbiddens	9

// Operation helper
#define	STARTING_WITH_MODE		0
#define	CONTAINING_STRING		1
#define	SEARCH_FOR_STRING		2
#define FREQUENT_WORD_SEARCH	3
#define GENERIC_SEARCH			4
#define WORD_COUNT_OPERATION	5


#define forbidden_strings_count	17
#define forbidden_char_count	17
// No direct submission in class variable
class list
{
	private:
		// State variable
		int NumberOfWords;

		// My structure
		struct node
		{
			listelementType item;
			node *next;
			int Repeated_times;
			std:: string lines;
		};

		node *head, *prev, *ptr_tmp, *general_pointer;

	public:

		// Construct and Destruct

		// Default constructor
		list(std:: string FileToOpen);
		~ list();


		// Functions go right here
		bool LinkedList_Insertion (const listelementType &e, const std:: string &line_to_append);
		bool LinkedList_Search(const listelementType &e, int mode);
		bool LinkedList_Load(const std:: string FileToOpen);
		bool LinkedList_Load_Enhanced_even_more(const std:: string FileToOpen);

		/* 8 Operations */
		bool LinkedList_size_words();
		bool LinkedList_distinct_words();
		bool LinkedList_size_chars();
		bool LinkedList_Frequent_Word();

		bool LinkedList_WordCout(std :: string &e);
		bool LinkedList_Starting_With(std :: string &e);
		bool LinkedList_Containing(std :: string &e);
		bool LinkedList_Search_With_Lines(std :: string &e);
		/*				*/

		void Operations_Help_Decide_Versio2(int i, std:: string str);
		bool Operations_Help_Decide(int argc, std:: string op, std :: string ptr);
		int CheckMyOperationAndExecute(const char *File_TO_OPEN);

		bool LinkedList_show_Whole();
		bool Delete_Whole_List();
		bool Delete_VIP();
};

void MyToLower(std:: string &x);

#endif /* COLLEGE_HUEMOR2_H_ */
