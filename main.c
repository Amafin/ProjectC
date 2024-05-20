#include <stdio.h>
#include "column.h"
#include "cdataframe.h"

int main() {

///////////////////////////////// Variables /////////////////////////////////

    ENUM_TYPE type;
    int tmp;
    int entervalue = 1;

    char title[50];
    void* value;
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
    scanf("%s",title);
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
            while(entervalue == 1){
                printf("Enter a value:\n");
                scanf("%d", (int *) &value);
                insert_value(column1, (void *) value);
                printf("Do you want to enter another value (1=Yes, 0=No)\n");
                scanf("%d", &entervalue);
            }
            break;
        case CHAR:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%c", (char *)&value);
                insert_value(column1, value);
            }
            break;
        case FLOAT:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%f", (float *)&value);
                insert_value(column1, value);
            }
            break;
        case DOUBLE:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%lf", (double *)&value);
                insert_value(column1, value);
            }
            break;
        case STRING:
            for(int i=0; column1->log_size<column1->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%c", (char *)&value);
                insert_value(column1, value);
            }
            break;
        case STRUCTURE:
            // TO CHANGE //

            // type = STRUCTURE;
            break;
    }

    print_col(column1);


////////////////// TO CHANGE ///////////////////////////

    // printf("There are %d value less in col\n", value_less(column1, (void *)7));
    // printf("There are %d value more in col", value_greater(column1, (void *)5));


    return 0;
}
