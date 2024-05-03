#include <stdio.h>
#include "column.h"
#include "cdataframe.h"

int main() {

///////////////////////////////// Variables /////////////////////////////////

    ENUM_TYPE type;
    int tmp;

    char title[50];
    void* value;
    char string[50];
    COLUMN* column1;


///////////////////////////////// MAIN /////////////////////////////////

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
    switch(column1->column_type){
        case NULLVAL:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                value = NULL;
                insert_value(column1, (void*)&value);
            }
            break;
        case UINT:
            // TO CHANGE //
            // Use the function insert_value to add the value
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%u", (unsigned int *)&value);
                insert_value(column1, value);
            }
            break;
        case INT:
            printf("Hello");
            printf("%u\n", column1->log_size);
            printf("%u\n",column1->phys_size);
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%d", (int *)&value);
                printf("eheheh\n");
                insert_value(column1, (void *)value);
                printf("poupouloupoupou\n");
            }
            break;
        case 4:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%c", (char *)&value);
                insert_value(column1, value);
            }
            break;
        case 5:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%f", (float *)&value);
                insert_value(column1, value);
            }
            break;
        case 6:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%lf", (double *)&value);
                insert_value(column1, value);
            }
            break;
        case 7:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%c", (char *)&value);
                insert_value(column1, value);
            }
            break;
        case 8:
            // TO CHANGE //

            // type = STRUCTURE;
            break;
    }
    printf("Bonjour");





    return 0;
}
