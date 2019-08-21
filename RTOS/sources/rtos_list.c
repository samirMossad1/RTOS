

/*Includes*/

#include "../rtosincludes/rtos_list.h"



void RTOS_listInsert(RTOS_list_t* list_ptr,RTOS_listItem_t* new_listItem_ptr)
{

	/*Check for Null pointers*/
	CHECK_ERROR(list_ptr==NULL_PTR);
	CHECK_ERROR(new_listItem_ptr==NULL_PTR);


    new_listItem_ptr->list_ptr=(void *)list_ptr;

	new_listItem_ptr->nextItem_ptr=list_ptr->index_ptr->nextItem_ptr;

	new_listItem_ptr->prevItem_ptr=list_ptr->index_ptr;

	new_listItem_ptr->nextItem_ptr->prevItem_ptr=new_listItem_ptr;

	list_ptr->index_ptr->nextItem_ptr=new_listItem_ptr;

	list_ptr->index_ptr=new_listItem_ptr;

	list_ptr->number_elements++;

}

void RTOS_listRemove(const RTOS_listItem_t* removed_listItem_ptr)
{

	CHECK_ERROR(removed_listItem_ptr==NULL_PTR);


	RTOS_list_t* list_ptr;

	removed_listItem_ptr->nextItem_ptr->prevItem_ptr=removed_listItem_ptr->prevItem_ptr;

	removed_listItem_ptr->prevItem_ptr->nextItem_ptr=removed_listItem_ptr->nextItem_ptr;

    list_ptr=(RTOS_list_t*)(removed_listItem_ptr->list_ptr);

    list_ptr->number_elements--;

    if(list_ptr->index_ptr == removed_listItem_ptr)
    {
    	list_ptr->index_ptr= removed_listItem_ptr->prevItem_ptr;
    }
    else
    {
    		/* Do Nothing*/
    }

    removed_listItem_ptr->list_ptr=NULL_PTR;

}


