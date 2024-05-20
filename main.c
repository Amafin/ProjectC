#include <stdio.h>
#include "column.h"
#include "cdataframe.h"

int main() {

///////////////////////////////// Variables /////////////////////////////////

    int action, DoItAgain = 1, size = 0, *log_size_array = &size;
    int start = 0, end = 0, delete = 0, RenameCol = 0, row = 0, column = 0;
    char string[20];
    void* value;
    COLUMN** dataframe;

///////////////////////////////// MAIN /////////////////////////////////


    dataframe = createdataframe();
    // hardfillingdataframe(dataframe, log_size_array);

    printf("What do you want to do?\n");
    while(DoItAgain == 1) {
        printf("Add a column to the dataframe = 1 \nDisplay dataframe = 2 \nDisplay some rows of the dataframe = 3 \nDisplay some columns of the dataframe = 4 \nAdd a row to the dataframe = 5 \nDelete a row from the dataframe = 6 \nDelete a column of the dataframe = 7 \nRename a column of the dataframe = 8 \nCheck if a value is in the dataframe = 9 \nReplace a value in the dataframe = 10 \nDisplay the names of the columns in the dataframe = 11 \nDisplay the occurrences of a value = 12 \nDisplay the occurrences of a greater value = 13 \nDisplay the occurrences of a smaller value = 14\n");
        scanf("%d", &action);

        switch (action) {
            case 1:
                addcol(dataframe, log_size_array);
                break;

            case 2:
                print_col(dataframe[0]);
                displaydataframe(dataframe, log_size_array);
                break;

            case 3:
                printf("Enter the first row you want to display:\n");
                scanf("%d", &start);
                printf("Enter the last row you want to display:\n");
                scanf("%d", &end);
                displayrow(dataframe, start, end, log_size_array);
                break;

            case 4:
                printf("Enter the first column you want to display:\n");
                scanf("%d", &start);
                printf("Enter the last column you want to display:\n");
                scanf("%d", &end);
                displaycol(dataframe, start, end, log_size_array);
                break;

            case 5:
                addrow(dataframe);
                break;

            case 6:
                printf("Which row do you want to delete?\n");
                scanf("%d", &delete);
                delrow(dataframe, delete);
                break;

            case 7:
                printf("Which column do you want to delete?\n");
                scanf("%d", &delete);
                delcol(dataframe, delete);
                break;

            case 8:
                printf("Which column do you want to rename?\n");
                scanf("%d", &RenameCol);
                renamecol(dataframe, RenameCol);
                break;

                //////////////////// To change
            case 9:
                printf("What value are you looking for?\n");
                scanf("%s", string);
                checkvalue(dataframe, string);
                break;

            case 10:
                printf("What is the column of the value you want to replace?\n");
                scanf("%d", &column);
                printf("What is the row of the value you want to replace?\n");
                scanf("%d", &row);
                printf("What value do you want to insert?\n");
                switch (dataframe[column]->column_type) {
                    case NULLVAL:
                        break;

                    case UINT:
                        scanf("%ud", (unsigned int *) value);
                        break;

                    case INT:
                        scanf("%d", (int *) value);
                        break;

                    case CHAR:
                        scanf("%c", (char *) value);
                        break;

                    case FLOAT:
                        scanf("%f", (float *) value);
                        break;

                    case DOUBLE:
                        scanf("%lf", (double *) value);
                        break;

                    case STRING:
                        scanf("%s", (char *) value);
                        break;

                    case STRUCTURE:
                        scanf("%d", (int *) value);
                        break;
                }
                accessvalue(*dataframe, row, column, value);
                break;

            case 11:
                display_name(dataframe);
                break;


                //////////////////// To change
            case 12:
                printf("What value do you want to search for?\n");
                switch (dataframe[column]->column_type) {
                    case NULLVAL:
                        break;

                    case UINT:
                        scanf("%ud", (unsigned int *) value);
                        break;

                    case INT:
                        scanf("%d", (int *) value);
                        break;

                    case CHAR:
                        scanf("%c", (char *) value);
                        break;

                    case FLOAT:
                        scanf("%f", (float *) value);
                        break;

                    case DOUBLE:
                        scanf("%lf", (double *) value);
                        break;

                    case STRING:
                        scanf("%s", (char *) value);
                        break;

                    case STRUCTURE:
                        scanf("%d", (int *) value);
                        break;
                }
                //nb_occurences(dataframe);
                break;

                //////////////////// To change
            case 13:
                //nb_sup(dataframe);
                break;

                //////////////////// To change
            case 14:
                //nb_less(dataframe);
                break;

            default:
                printf("Not possible\n");
        }
        printf("Do you want to do something else? 1 = Yes, 0 = No\n");
        scanf("%d", &DoItAgain);
    }

    return 0;
}
