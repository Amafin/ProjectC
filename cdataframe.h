#ifndef CDATAFRAME_H
#define CDATAFRAME_H

///////////////////////////////// Creation of the structure of the data frame /////////////////////////////////

// Filling
int createdataframe();    // Creation of an empty CDataframe

void fillingdataframe(int* col);  // Filling in the CDataframe with user input

void hardfillingdataframe();    // Hard filling of the CDataframe


// Displaying
void displaydataframe(int dataframe);    // Display the entire CDataframe

void displayrow(int dataframe, int rowlimit);    // Display a part of the CDataframe rows according to a user-provided limit

void displaycol(int dataframe, int collimit);    // Display a part of the columns of the CDataframe according to a limit supplied by the user


// Usual operations
void addrow(int dataframe);    // Add a row of values to the CDataframe

void deleterow(int dataframe);    // Delete a row of values from the CDataframe

void addcol(int dataframe);    // Add a column to the CDataframe

void delcol(int dataframe, int ColToDel);   // Delete a column from the CDataframe

void renamecol(int dataframe, int ColToRename);   // Rename the title of a column in the CDataframe

int checkvalue(int dataframe, void* value);    // Check the existence of a value (search) in the CDataframe

void* accessvalue(int dataframe, int rownb, int colnb, void* ReplaceValue);    // Access/replace the value in a CDataframe cell using its row and column number


#endif