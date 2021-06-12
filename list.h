
#ifndef LIST_H_
#define LIST_H_

#define MAXLIST         50

typedef struct listentry
{
    char name[60];
    int age;
    char gender[60];
    int ID;

}ListEntry;

typedef struct  listnode
{
    ListEntry entry;
    struct  listnode* next;
}ListNode;


typedef struct list
{
    ListNode *head;
    int size;
}List;

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

void CreateList(List *pl);

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
int ListEmpty(List *pl);

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
int ListFull(List *pl);

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
int ListSize(List *pl);
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
void DestroyList(List *pl);

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
int InsertList(int pos, ListEntry e, List *pl);

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
void DeleteList(int pos, ListEntry *pe, List*pl);
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
void TraverseList(List *pl, void(*Visit)(ListEntry));
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
void RetrieveList(int pos, ListEntry *pe, List *pl);
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
void ReplaceList(int pos, ListEntry e, List *pl);


#endif