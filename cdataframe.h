#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include "column.h"

///////////////////////////////// Creation of the structure of the data frame /////////////////////////////////

// Filling
COLUMN** createdataframe();

void fillingdataframe(COLUMN** dataframe,COLUMN* col,int place);

void hardfillingdataframe();    // Hard filling of the CDataframe


// Displaying
void displaydataframe(COLUMN ** dataframe);    // Display the entire CDataframe

void displayrow(int dataframe, int rowlimit);    // Display a part of the CDataframe rows according to a user-provided limit

void displaycol(COLUMN** dataframe, int start, int end);    // Display a part of the columns of the CDataframe according to a limit supplied by the user


// Usual operations
void addrow(int dataframe);    // Add a row of values to the CDataframe

void deleterow(int dataframe);    // Delete a row of values from the CDataframe

void addcol(COLUMN** dataframe,ENUM_TYPE type, char *title);    // Add a column to the CDataframe

void delcol(int dataframe, int ColToDel);   // Delete a column from the CDataframe

void renamecol(int dataframe, int ColToRename);   // Rename the title of a column in the CDataframe

int checkvalue(int dataframe, void* value);    // Check the existence of a value (search) in the CDataframe

void* accessvalue(int dataframe, int rownb, int colnb, void* ReplaceValue);    // Access/replace the value in a CDataframe cell using its row and column number


#endif