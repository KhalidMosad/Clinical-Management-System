/******************************************************************************************************
 * File: list.c 
 * Author: Khalid Mosaad Zakaria
 * Data: Edited june 2021
 * Description: This File include List of functions that we need to build our project.
*/

/*************************************************************
 *  Inclusion of Header Files Required for the project 
*/


#include<stdio.h>
#include<stdlib.h>


/********************************************************************************
* This header file include functions Declartion 
*/
#include"list.h"

/*****************************************************************
 * Function: CreateList.
 * Description: 
 *      This function takes a list variable that you want to create. 
 * Parameters: 
 *      List *pl------- pointer of type List. 
 * Return: 
 *        void ----- it returns nothing. 
 *               
*/
void CreateList(List *pl)
{
    pl->head = NULL;
    pl->size = 0;
}

/*****************************************************************
 * Function: ListEmpty.
 * Description: 
 *      This function Checks if the Created List is Empty . 
 * Parameters: 
 *      List *pl------- pointer of type List. 
 * Return: 
 *        It returns 0 if the list is empty and 1 if size incremented. 
 *               
*/


int ListEmpty(List *pl)
{
    return (pl->size==0) ;
}
/*****************************************************************
 * Function: ListFull.
 * Description: 
 *      This function Checks if the Created List is  Full. 
 * Parameters: 
 *      List *pl------- pointer of type List. 
 * Return: 
 *        It returns 0 because The list is always Empty...... There is no limit to Items in Linkedbased Lists . 
 *               
*/
int ListFull(List *pl)
{
    return 0 ;

}
/*****************************************************************
 * Function: ListSize.
 * Description: 
 *      This function give us information about the size or number of element in the list. 
 * Parameters: 
 *      List *pl------- pointer of type List. 
 * Return: 
 *        It returns size 
 *               
*/

int ListSize(List *pl)
{
    return pl->size ;

}

/*****************************************************************
 * Function: DestroyList.
 * Description: 
 *      This function Delete the entire List. 
 * Parameters: 
 *      List *pl------- pointer of type List. 
 * Return: 
 *        It returns nothing 
 *               
*/

void DestroyList(List *pl)
{
   ListNode *q;
   while(pl->head)
   {
       q=pl->head->next;
       free(pl->head);
       pl->head = q;
   }  
   pl->size = 0;
}

/*****************************************************************
 * Function: InsertList.
 * Description: 
 *      This function insert element to List. 
 * Parameters: 
 *      int pos ------- The specific position to add the listEntry in.
 *      ListEntry e---- This is the item to be inserted.
 *      List *pl------- pointer of type List. 
 * 
 * Return: 
 *        It returns 1 if insertion done successfully and 0 if no. 
 *               
*/

int InsertList(int pos, ListEntry e, List *pl)
{
    ListNode *p,*q;
    q= pl->head;
    int i;
   if(p= (ListNode *)malloc(sizeof(ListNode))) 
    {
        p->entry = e;
        p->next = NULL;

        if(pos== 0)
        {
            p->next = pl->head;
            pl->head = p;
        }
        else
        {
            for(i=0; i<pos-1; i++)
            {
                q = q->next;
            }
            p->next = q->next;
            q->next= p;
    
        }
        pl->size++;       
        return 1;
    }
    else
        return 0;
}

/*****************************************************************
 * Function: DeleteList.
 * Description: 
 *      This function Delete just one node from the List. 
 * Parameters: 
 *      int pos ------- The specific position to delete.
 *      ListEntry*pe---- pointer to Hold The data of the deleted node.
 *      List *pl------- pointer of type List. 
 * 
 * Return: 
 *        It returns nothing. 
 *               
*/


void DeleteList(int pos, ListEntry *pe, List*pl)
{
    int i;
    ListNode *q, *tmp;
    q= pl->head;


    if (pos==0)
    {
        *pe = pl->head->entry;
        tmp = pl->head->next;
        free(pl->head);
        pl->head = tmp;

    }
    else
    {
        for(i=0; i<pos-1; i++)
        {
            q= q->next;
        }
        *pe = q->next->entry;
        tmp = q;

        q= q->next;
        tmp->next = q->next;
        free(q);       
    }
    pl->size--;
}
/*****************************************************************
 * Function: TraverseList.
 * Description: 
 *      This function pass through each node of the List and do the required function. 
 * Parameters: 
 *      List *pl------- pointer of type List. 
 *      void(*Visit)(ListEntry) ---- pointer to function
 * 
 * Return: 
 *        It returns nothing. 
 *               
*/

void TraverseList(List *pl, void(*Visit)(ListEntry))
{
    ListNode * p= pl->head;
    while(p)
    {
        (*Visit)(p->entry);
        p = p->next;
    }

}

/*****************************************************************
 * Function: RetrieveList.
 * Description: 
 *      This function just to get the data from one node from the List without doing any operation. 
 * Parameters: 
 *      int pos ------- The specific position to get the data from.
 *      ListEntry*pe---- pointer to a variable that Hold The data.
 *      List *pl------- pointer of type List. 
 * 
 * Return: 
 *        It returns nothing. 
 *               
*/
void RetrieveList(int pos, ListEntry *pe, List *pl)
{
    // هنا انت عاوز فقط القيمه الي فالمكان دا من غير ما تغيرة ولا تشيله 
   int i;
   ListNode * q = pl->head;
    for(i=0; i<pos; i++)
    {
        q= q->next;
    }
    *pe= q->entry;
}
/*****************************************************************
 * Function: ReplaceList.
 * Description: 
 *      This function just to Replace the data of one node from the List with a new data. 
 * Parameters: 
 *      int pos ------- The specific position to Replace the data from.
 *      ListEntry p---- Variable that Hold The new data.
 *      List *pl------- pointer of type List. 
 * 
 * Return: 
 *        It returns nothing. 
 *               
*/

void ReplaceList(int pos, ListEntry e, List *pl)
{
   int i;
   ListNode * q = pl->head;
    for(i=0; i<pos; i++)
    {
        q= q->next;
    }
    q->entry= e;


}
