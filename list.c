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


void CreateList(List *pl)
{
    pl->head = NULL;
    pl->size = 0;
}




int ListEmpty(List *pl)
{
    return (pl->size==0) ;
}

int ListFull(List *pl)
{
    return 0 ;

}


int ListSize(List *pl)
{
    return pl->size ;

}



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


void TraverseList(List *pl, void(*Visit)(ListEntry))
{
    ListNode * p= pl->head;
    while(p)
    {
        (*Visit)(p->entry);
        p = p->next;
    }

}


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
