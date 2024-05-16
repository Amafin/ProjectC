#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include "column.h"

///////////////////////////////// Filling of the data frame /////////////////////////////////


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
void fillingdataframe(COLUMN** dataframe,COLUMN* col,int place);

/**
 * @brief: Fill of the dataframe directly in
 */
void hardfillingdataframe();    // Hard filling of the CDataframe


///////////////////////////////// Displaying of the data frame /////////////////////////////////


void displaydataframe(COLUMN ** dataframe);    // Display the entire CDataframe

void displayrow(COLUMN** dataframe, int start, int end);    // Display a part of the CDataframe rows according to a user-provided limit

void displaycol(COLUMN** dataframe, int start, int end);    // Display a part of the columns of the CDataframe according to a limit supplied by the user


///////////////////////////////// Usual operations on the data frame /////////////////////////////////


void addrow(COLUMN** dataframe);    // Add a row of values to the CDataframe

void deleterow(COLUMN** dataframe, int RowToDel);    // Delete a row of values from the CDataframe

void addcol(COLUMN** dataframe);    // Add a column to the CDataframe

void delcol(COLUMN** dataframe, int ColToDel);   // Delete a column from the CDataframe

void renamecol(COLUMN** dataframe, int ColToRename);   // Rename the title of a column in the CDataframe

void checkvalue(COLUMN** dataframe, void* value);    // Check the existence of a value (search) in the CDataframe

void* accessvalue(int dataframe, int rownb, int colnb, void* ReplaceValue);    // Access/replace the value in a CDataframe cell using its row and column number

void display_name(COLUMN** dataframe);


///////////////////////////////// Analysis and statistics of the data frame /////////////////////////////////


void display_nbrow(COLUMN** dataframe);

void display_nbcol(COLUMN** dataframe);

void nb_occurences(COLUMN ** dataframe, void* x);

int nb_sup(COLUMN ** dataframe, void* x);

int nb_less(COLUMN ** dataframe, void* x);

#endif