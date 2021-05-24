
#include "list.h"

typedef struct slotentry
{
 	int ID ;
    char * slot;
}SlotEntry;


typedef struct Slotnode
{	
    SlotEntry entry;
	struct Slotnode *link;	
}SlotNode;

typedef struct slotlist
{	
	SlotNode * head;	
}SlotList;



#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LE(a,b) ((a)<=(b))
#define GT(a,b) ((a)>(b))
#define GE(a,b) ((a)>=(b))

#define DefaultPassword     1234
int Password(void);
void ScreenInit(void);
int ModeSelection(void);
void ModeDetails(List l, ListEntry e);
void AdminMode();
void UserMode();
void Display(ListEntry e);
int SequentialSearch(int target, List *pl);


void SlotListInit(SlotList * sl);
void CreateSoltList(SlotList * sl, int pos, SlotEntry e2);
void CreateSlotList();
void RetrieveListSlot(int pos, SlotEntry *pe, SlotList *pl);
void DeleteSlotList(int pos, SlotEntry *pe, SlotList*pl);
void TraverseSlotList(SlotList *pl, void(*Visit)(SlotEntry));
void DisplaySlot(SlotEntry e);
int SequentialSearchSlots(int target, SlotList *pl);