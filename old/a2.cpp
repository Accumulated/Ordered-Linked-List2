/*
 * app.c
 *
 *  Created on: Mar 7, 2020
 *      Author: newname
 */


#include <iostream>
#include "inord_list.h"

using namespace std;

/* Normal Linked list structure for Insertion, Deletion, Showing data and retrieval */
/* linear and Circular Single list */

int main(int argc, char *argv[])
{
	if(argc > 3)
	{
		cout << "Incorrect number of arguments\n";
		return 1;
	}
	else
	{
		list my_list(argv[1]);
		my_list.CheckMyOperationAndExecute(argv[2]);
	}




/*
	// 1-
	my_list.LinkedList_size_words();
	// 2-
	my_list.LinkedList_distinct_words();
	// 3-
	my_list.LinkedList_size_chars();
	// 4-
	my_list.LinkedList_Search("Start_Process", FREQUENT_WORD_SEARCH);

	// 5- my_list.LinkedList_Search("m", WORD_COUNT_OPERATION);

	// 6-
	my_list.LinkedList_Search("m", STARTING_WITH_MODE);

	// 7-
	my_list.LinkedList_Search("new", CONTAINING_STRING);

	// 8-
	my_list.LinkedList_Search("new", SEARCH_FOR_STRING);

*/


}


