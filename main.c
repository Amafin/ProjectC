#include <stdio.h>
#include "functions.h"

int main() {

///////////////////////////////// Call of functions /////////////////////////////////
    ENUM_TYPE type;
    int tmp;
    int i = 0;

    char title[50];
    void* value;
    char string[50];
    COLUMN* column1;


///////////////////////////////// Call of functions /////////////////////////////////
    // Select the type of the data in the new column
    printf("You have: NULLVAL = 1, UINT = 2, INT = 3, CHAR = 4, FLOAT = 5, DOUBLE = 6, STRING = 7, STRUCTURE = 8\n");
    printf("Enter the type of value for the column:\n");
    scanf("%d", &tmp);
    // Depending on the number given, give the right type to the variable type
    switch(tmp){
        case 2:
            type = UINT;
            break;
        case 3:
            type = INT;
            break;
        case 4:
            type = CHAR;
            break;
        case 5:
            type = FLOAT;
            break;
        case 6:
            type = DOUBLE;
            break;
        case 7:
            type = STRING;
            break;
        case 8:
            type = STRUCTURE;
            break;
        default:
            type = NULLVAL;
    }

    // Enter the title of the new column
    printf("Enter the title of your new column:\n");
    scanf("%s", title);

    // Create the new column
    column1 = create_column(type, title);


    // Add your values to your new column
    switch(tmp){
        case 2:
            // TO CHANGE //
            // Use the function insert_value to add the value
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%ud", (unsigned int *)value);
                insert_value(column1, value);
            }
            // type = UINT;
            break;
        case 3:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%d", (int *)value);
                insert_value(column1, value);
            }
            break;
        case 4:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%c", (char *)value);
                insert_value(column1, value);
            }
            break;
        case 5:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%f", (float *)value);
                insert_value(column1, value);
            }
            break;
        case 6:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%lf", (double *) value);
                insert_value(column1, value);
            }
            break;
        case 7:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%s", (char *)value);
                insert_value(column1, value);
            }
            break;
        case 8:
            // TO CHANGE //

            // type = STRUCTURE;
            break;
        default:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                insert_value(column1, "");
            }
            break;
    }


    // Delete a column
    delete_column(&column1);


    // Convert the values in order to print them
    while(i<column1->log_size) {
        convert_value(column1, *column1->index, string, sizeof(string));
        column1->index ++;
    }


    // Print values


    return 0;
}
