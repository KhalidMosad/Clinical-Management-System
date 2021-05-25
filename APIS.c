#include <stdio.h>
#include <stdlib.h>
#include"list.h"
#include "APIS.h"
#include<string.h>


List l;
ListEntry e; 
SlotList s1;

SlotEntry DeletedSlots[5];
void ScreenInit(void)
{
    printf("____________________________________WELCOME TO SMART CLINC RESERVATION SYSTEM__________________________________________\n\n");
    printf("_________________________________________________ ITI MINIA_________________________________________________________\n\n");

}

int Password(void)
{
    int i =3;
    int pass;
    printf("please enter the password");
    while(i>0)
    {
        scanf("%d",&pass);
        if (pass ==DefaultPassword)
        {
            return 1;
        }
        else
        {
            i--;
            if(i !=0 )
                printf("You Entered wrong password, try again you have %d trial ",i);
            else
            {
                printf("The system will close...");
                break ;
            }    
        }
    }

    return 0;

}


int ModeSelection(void)
{

        
        int mode;
        printf("Press 1 for admin mode \npress 2 for user mode \n");

        scanf("%d",&mode);

        if (mode == 1)
        {
            static int userOp=0;
            static int state ;
            if(userOp == 0)
                state = Password();
            if(state == 1)
            {
                userOp=1;
                printf("________________________________________________________________________________________________\n");
                printf("welcome in admin mode \n");
                printf(".....................................................................\n");

                printf("You have those options: \n");
                printf("1. Add new patient record\n2. Edit patient record\n3. Reserve a slot with the doctor\n4. Cancel reservation\n");
                printf("________________________________________________________________________________________________\n");
            }
            else
            {
                printf("GoodBye");
                return 0;
            }



        }
        else if (mode == 2)
        {
            printf("________________________________________________________________________________________________\n");
            printf("welcome in user mode \n");
            printf(".....................................................................\n");
            printf("You have those options: \n");
            printf("1. View patient record.\n2.View today’s reservations.\n");
            printf("________________________________________________________________________________________________\n");       

        }
        return mode;
   


}

void ModeDetails(List l, ListEntry e)
{
    int CheckStatus;
    CheckStatus = ModeSelection();
    if (CheckStatus == 1)
    {
        AdminMode();

    }
    else
    {
        UserMode();
    }
}



void AdminMode(void)
{
    static int pos =0;

    char name1[60];
    int Op;
    int search;
    printf("Enter Your Choice \n");
    scanf("%d",&Op);
    if(Op == 1)
    {
        fflush(stdin);   
        if (pos ==0)     
            CreateList(&l);
        fflush(stdin);
        printf("Enter Patient name: ");
       // fgets(e.name, sizeof(e.name), stdin);
        scanf("%s",e.name);
        fflush(stdin);
        printf("Enter Patient age: ");
        scanf("%d",&e.age);
        fflush(stdin);
        printf("Enter gender male or female:  ");
        scanf("%s",e.gender);
        fflush(stdin);
        printf("Enter Patient ID");
        scanf("%d",&e.ID); 

        if(!ListFull(&l))
        {
           search= SequentialSearch(e.ID,&l);
            if(search==-1)
              {
                InsertList(pos,e,&l);
                pos++;
              }  
            else
            {
                printf("The ID exists \n");
            }
            

        }
        TraverseList(&l,&Display); 
        printf("%d", l.size);
        printf("\n");

    }
    else if (Op == 2)
    {
        int s2;
        int ID1;
        ListEntry e1;
        fflush(stdin);
        printf("Enter Patient ID: ");
        scanf("%d",&ID1); 
        s2= SequentialSearch(ID1,&l);
        if(s2 == -1)
        {
            printf("The Id not exists \n");
        }
        else
        {
            e1.ID = ID1;
            printf("Enter Patient name: ");
            scanf("%s",&e1.name);
            fflush(stdin);
            printf("Enter Patient age: ");
            scanf("%d",&e1.age);
            fflush(stdin);
            printf("Enter gender 1 if male 2 if female:  ");
            scanf("%s",&e1.gender);  
            ReplaceList(s2,e1,&l);
            TraverseList(&l,&Display);             
        }

    }
    else if (Op == 3)
    {   
        static int ItemNum =0;
        int num;
        int s2;
        int id;
        ListEntry e_local;
        int s3;
        static int flag = 0;
        if (flag == 0)
            CreateSlotList();
        if (flag == 1)
            TraverseSlotList(&s1,&DisplaySlot);
        printf("Enter your Id: ");
        scanf("%d",&id);
        s3= SequentialSearch(id,&l);
        if( s3 !=-1)
        {
            RetrieveList(s3,&e_local,&l);
            printf("Enter Number of the Slot: ");
            scanf("%d",&num);
            s2 = SequentialSearchSlots(num,&s1);
            if(s2 == -1)
            {
                printf("Uncorrect Slot Number");
            }
            else
            {
                SlotEntry e3;
                RetrieveListSlot(s2,&e3,&s1);
                printf("Hey:  %s Your ID is:%d  ,and ",e_local.name,e_local.ID);
                printf("Your Reserved from %s\n", e3.slot);
                DeleteSlotList(s2,&e3,&s1);
                e3.Patient_Id =id;
                DeletedSlots[ItemNum]=e3;
                ItemNum++;
            }
            flag = 1;
        }
        else
        {
            printf("There is no patient by this ID ");
        }

    } 
    else if (Op == 4)
    {
        int s2;
        int ID1;
        ListEntry e2;
        fflush(stdin);
        printf("Enter Patient ID: ");
        scanf("%d",&ID1); 
        s2= SequentialSearch(ID1,&l);
        if(s2 == -1)
        {
            printf("The Id not exists \n");
        }
        else
        {
            DeleteList(s2,&e2,&l);   
            printf("Reservation cancelled... \n");
        }     


    }     
    else
    {

    }



}
void UserMode(void)
{
    int Op;
    printf("Enter Your Choice \n");
    scanf("%d",&Op);
    if(Op == 1)
    {
        int ID1;
        ListEntry e2;
        int s2;
        printf("Enter Patient ID: ");
        scanf("%d",&ID1); 
        s2= SequentialSearch(ID1,&l);
        if(s2 == -1)
        {
            printf("The Id not exists \n");
        }
        else
        {
            RetrieveList(s2,&e2,&l);   
            Display(e2);
        } 


    }
    else if (Op == 2)
    {
        int i;
        ListEntry e3;
        int x = l.size;
        for(i =0; i<x;i++)
        {
            RetrieveList(i,&e3,&l);
            Display(e3);
            
            for(int j=0; j<=4;j++)
            {
                if(e3.ID == DeletedSlots[j].Patient_Id )
                {
                    printf("And Reversed From %s\n",DeletedSlots[j].slot);    
                    break;                  
                }
                else
                {
                    printf("There is no Reservation for This Id....\n");
                    break;
                }


            }
            printf("____________________________________________________________________________________________\n");

        }
    }
    else
    {

    }

}

void Display(ListEntry e)
{
    printf("the name is %s\t",    e.name);
    printf("\tThe age  =  %d \t",     e.age);
    printf("\tYour gender is %s \t",   e.gender);    
    printf("\tID is %d\t",e.ID);
    printf("\n");
}

int SequentialSearch(int target, List *pl)
{
    int current, s= ListSize(pl);
    ListEntry currententry;

    for(current=0; current<s; current++)
    {
        RetrieveList(current, &currententry, pl);
        if(EQ(target , currententry.ID))
        {
            return current;
        }
            
    }
    return -1;
}



void CreateSlotList()
{
    static int pos =0 ;
    if(pos ==0)
        SlotListInit(&s1);
    SlotEntry e[5];
    e[0].ID = 1;
    e[0].slot = "2pm to 2:30pm";
    CreateSoltList(&s1,0,e[0])  ;

    e[1].ID = 2;
    e[1].slot = "2:30pm to 3pm";
    CreateSoltList(&s1,1,e[1])  ; 

    e[2].ID = 3;
    e[2].slot = "3pm to 3:30pm";
    CreateSoltList(&s1,2,e[2])  ;  
    
    e[3].ID = 4;
    e[3].slot = "4pm to 4:30pm";
    CreateSoltList(&s1,3,e[3])  ;  

    e[4].ID = 5;
    e[4].slot = "4:30pm to 5pm";
    CreateSoltList(&s1,4,e[4])  ;

    pos =1;     
    TraverseSlotList(&s1,&DisplaySlot);
           


}




void SlotListInit(SlotList * sl)
{
    sl->head =NULL;

}



void CreateSoltList(SlotList * sl, int pos, SlotEntry e2)
{
    SlotNode * p,*q;
    q = sl->head;
    if(p= (SlotNode*)malloc(sizeof(SlotNode)))
    {
        p->link =NULL;
        p->entry = e2;        
        if(pos ==0)
        {
            sl->head = p;

        }
        else
        {
            for(int i=0; i<pos-1;i++)
            {
                q=q->link;
            }
            p->link = q->link;
            q->link = p;

        }  
    }
}


int SequentialSearchSlots(int target, SlotList *pl)
{
    int current, s= 6;
    SlotEntry currententry;

    for(current=0; current<s; current++)
    {
        RetrieveListSlot(current, &currententry, pl);
        if(EQ(target , currententry.ID))
        {
            return current;
        }
            
    }
    return -1;
}

void RetrieveListSlot(int pos, SlotEntry *pe, SlotList *pl)
{
    // هنا انت عاوز فقط القيمه الي فالمكان دا من غير ما تغيرة ولا تشيله 
   int i;
   SlotNode * q = pl->head;
    for(i=0; i<pos; i++)
    {
        q= q->link;
    }
    *pe= q->entry;
}


void DeleteSlotList(int pos, SlotEntry *pe, SlotList*pl)
{
    int i;
    SlotNode *q, *tmp;
    q= pl->head;


    if (pos==0)
    {
        *pe = pl->head->entry;
        tmp = pl->head->link;
        free(pl->head);
        pl->head = tmp;

    }
    else
    {
        for(i=0; i<pos-1; i++)
        {
            q= q->link;
        }
        *pe = q->link->entry;
        tmp = q;

        q= q->link;
        tmp->link = q->link;
        free(q);       
    }

}

void TraverseSlotList(SlotList *pl, void(*Visit)(SlotEntry))
{
    SlotNode * p= pl->head;
    while(p)
    {
        (*Visit)(p->entry);
        p = p->link;
    }

}

void DisplaySlot(SlotEntry e)
{
    printf("The slot number %d is from %s \t",e.ID, e.slot);
    printf("\n");

}


void ReplaceSlotList(int pos, SlotEntry e, SlotList *pl)
{
   int i;
   SlotNode * q = pl->head;
    for(i=0; i<pos; i++)
    {
        q= q->link;
    }
    q->entry= e;

}





