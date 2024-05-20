#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include "column.h"
#define CAPACITY 5

///////////////////////////////// Filling of the data frame /////////////////////////////////

/**
 * Bastien COULON, Amandine FINAS
 * Cdataframe.h is where we define all the functions to create and manage the Cdataframe
 */



/**
 * @brief: Create a dataframe (array of pointers to columns)
 * @return: Pointer to the dataframe created
 */
COLUMN** createdataframe();

/**
 * @brief: Add a column to the dataframe
 * @param1: Dataframe in which we add the column
 * @param2: Pointer to the column to add
 * @param3: Place to add the column
 */
void fillingdataframe(COLUMN** dataframe, COLUMN* col, int* log_size_array);

/**
 * @brief: Fill of the dataframe directly in the code
 */
void hardfillingdataframe(COLUMN** dataframe, int* log_size_array);    // Hard filling of the CDataframe


///////////////////////////////// Displaying of the data frame /////////////////////////////////

/**
 * @brief: Display the entire dataframe
 * @param: dataframe we want to display
 */
void displaydataframe(COLUMN** dataframe, int* log_size_array);    // Display the entire CDataframe

/**
 * @brief: Display a part of the row of the dataframe
 * @param1: Dataframe from which we display the rows
 * @param2: First row we display
 * @param3: Last row we display
 */
void displayrow(COLUMN** dataframe, int start, int end, int* log_size_array);    // Display a part of the CDataframe rows according to a user-provided limit

/**
 * @brief: Display part of the columns of a dataframe
 * @param1: Dataframe from which we display the columns
 * @param1: First column we display
 * @param2: Last column we display
 */
void displaycol(COLUMN** dataframe, int start, int end, int* log_size_array);    // Display a part of the columns of the CDataframe according to a limit supplied by the user


///////////////////////////////// Usual operations on the data frame /////////////////////////////////


/**
 * @brief: Add a row in a data frame
 * @param1: dataframe in which we want to add a row
 */
void addrow(COLUMN** dataframe);    // Add a row of values to the CDataframe

/**
 * @brief: Delete a row in a dataframe
 * @param1: Dataframe in which we delete the row
 * @param2: Index of the row we want to delete
 */
void delrow(COLUMN** dataframe, int RowToDel);    // Delete a row of values from the CDataframe

/**
 * @brief: Add a column in a dataframe
 * @param1: dataframe in which we want to add a column
 */
void addcol(COLUMN** dataframe, int* log_size_array);    // Add a column to the CDataframe

/**
 * @brief: Delete a column in a dataframe
 * @param1: Dataframe in which we delete the column
 * @param2: Index of the column we want to delete
 */
void delcol(COLUMN** dataframe, int ColToDel);   // Delete a column from the CDataframe

/**
 * @brief: Rename a column in a dataframe
 * @param1: Dataframe in which we want to rename the column
 * @param2: Indew of the column to rename
 */
void renamecol(COLUMN** dataframe, int ColToRename);   // Rename the title of a column in the CDataframe

/**
 * @brief: Search a value in the dataframe
 * @param1: Dataframe in which we search the value
 * @param2: Value we look for
 */
void checkvalue(COLUMN** dataframe, void* value);    // Check the existence of a value (search) in the CDataframe

/**
 * @brief: Access a value and replace it (if wanted)
 * @param1: Dataframe in which we access the value
 * @param2: Row of the value we want to access
 * @param3: Column of the value we want to access
 * @param4: Value to replace the old one
 */
void accessvalue(COLUMN* dataframe, int rownb, int colnb, void* ReplaceValue);    // Access/replace the value in a CDataframe cell using its row and column number

/**
 * @brief: Display the title of each column
 * @param: Dataframe from which we display the name of the column
 */
void display_name(COLUMN** dataframe);


///////////////////////////////// Analysis and statistics of the data frame /////////////////////////////////


/**
 * @brief: Display the number of rows in the dataframe
 * @param: Dataframe in which we want the number of rows
 */
unsigned int display_nbrow(COLUMN** dataframe, int* log_size_array);

/**
 * @brief: Return the number of column of a dataframe
 * @param: Dataframe in which we want to know the number of column
 * @return: Number of column in the dataframe
 */
int display_nbcol(COLUMN** dataframe, int* log_size_array);

/**
 * @brief: Return the number of occurrences of a value in a dataframe
 * @param1: Dataframe in which we search the value
 * @param2: Value we want to know the number of occurrences
 */
void nb_occurences(COLUMN ** dataframe, void* x);

/**
 * @brief: Return the number of values that are greater than the value entered by the user
 * @param1: Dataframe in which we are looking for the value greater than the entered one
 * @param: Value is the value entered by the user
 * @return: The number of values greater than the one given
 */
int nb_sup(COLUMN ** dataframe, void* x);

/**
 * @brief: Return the number of value less than the value given by the user
 * @param1: Dataframe in which we search the value less than the one given by the user
 * @param2: Value we want to know how many are less
 * @return: number of values less than the one given
 */
int nb_less(COLUMN ** dataframe, void* x);

#endif