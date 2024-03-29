#include <stdio.h>
#include "functions.h"

int main() {
    ENUM_TYPE type;
    char title;
    COLUMN* column1;

    printf("You have: NULLVAL = 1 , UINT = 2, INT = 3, CHAR = 4, FLOAT = 5, DOUBLE = 6, STRING = 7, STRUCTURE = 8\n");
    printf("Enter the type of value for the column: \n");
    scanf("%d", &type);
    printf("Enter the title of your new column: \n");
    scanf("%s", &title);

    column1 = create_column(type, &title);
    printf("%s, %d", column1->title, column1->column_type);




    return 0;
}
