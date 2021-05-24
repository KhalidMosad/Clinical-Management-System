#include <stdio.h>
#include<stdlib.h>
#include "list.h"
#include "APIS.h"


    extern      List l;
    extern    ListEntry e; 

void main(void)
{

    while(1)
    {

        ScreenInit();
        ModeDetails(l,e);

    }


}