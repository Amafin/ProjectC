#ifndef COLUMN_H
#define COLUMN_H

///////////////////////////////// Creation of the structure of a column /////////////////////////////////

/**
 * Bastien COULON, Amandine FINAS
 * Column.h has to purpose defining all the functions and the structures required to create and manage a column
 */



// Column that can store different types of data


enum enum_type{
    NULLVAL = 1 , UINT = 2, INT = 3, CHAR = 4, FLOAT = 5, DOUBLE = 6, STRING = 7, STRUCTURE = 8
};
typedef enum enum_type ENUM_TYPE; // Rename enum enum_type as ENUM_TYPE for future uses


union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE; // Rename union column_type as COL_TYPE for future uses


struct column {
    char *title;
    unsigned int log_size; //logical size
    unsigned int phys_size; //physical size
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data
    unsigned long long int *index; // array of integers
};
typedef struct column COLUMN; // Rename struct column as COLUMN for future uses


///////////////////////////////// Header of the functions /////////////////////////////////


/**
* @brief: Create a new column
* @param1: Column type
* @param2: Column title
* @return: Pointer to the created column
*/
COLUMN *create_column(ENUM_TYPE type, char *title);


/**
* @brief: Insert a new value into a column
* @param1: Pointer to the column
* @param2: Pointer to the value to insert
* @return: 1 if the value is correctly inserted 0 otherwise
*/
int insert_value(COLUMN *col, void *value);


/**
* @brief: Free the space allocated by a column
* @param1: Pointer to the column
*/
void delete_column(COLUMN **col);


/**
* @brief: Convert a value into a string
* @param1: Pointer to the column
* @param2: Position of the value in the data array
* @param3: The string in which the value will be written
* @param4: Maximum size of the string
*/
void convert_value(COLUMN *col, unsigned long long int i, char* str[], int size);


/**
* @brief: Display the content of a column
* @param: Pointer to the column to display
*/
void print_col(COLUMN* col);


///////////////////////////////// Additional functions /////////////////////////////////


/**
 * @brief: Number of occurrences of a value in the column
 * @param1: Value we search fo
 * @param2: Pointer to the column in which we search
 * @return: Number of occurrences
 */
int value_occ(void* value, COLUMN* col);

/**
 * @brief: Give the value at a position given
 * @param1: Column in which we search
 * @param2: Index for which we search the value
 * @return: Value at the index
 */
void* value_position(COLUMN* col, unsigned long long int i);

/**
 * @brief: Give the number of value greater than the value given
 * @param1: Column in which we search
 * @param2: Value given
 * @return: Number of value greater
 */
int value_greater(COLUMN* col, void* value);

/**
 * @brief: Give the number of value less than the value given
 * @param1: Column in which we search
 * @param2: Value given
 * @return: Number of value less
 */
int value_less(COLUMN* col, void* value);

#endif