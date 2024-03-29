#include "functions.h"
#include <stdio.h>

COLUMN* create_column(ENUM_TYPE type, char* title)
{
    COLUMN* col;
    col->title = title;
    col->column_type = type;
    col->data = NULL;
    return col->data;
};



/* int insert_value(COLUMN *col, void *value){
    if((col->log_size  < col->phys_size)
// check memory space
    ...
    switch(col->column_type){
        ...
        case INT:
            col->data[col->size] = (int*) malloc (sizeof(int));
            *((int*)col->data[col->size])= *((int*)value);
            break;
            ...
    }
    ...
    col->size++;
    ...
};
*/