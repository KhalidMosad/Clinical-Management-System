/******************************************************************************************************
 * File: main.c 
 * Author: Khalid Mosaad Zakaria
 * Data: Edited june 2021
 * Description: A simple C programming project for clinic management system.
 *              .c Files: 
 *                      1- list.c
 *                      2- APIS.c
 *              .h File:
 *                      1- APIS.h
 *                      2. list.h
*/

/*************************************************************
 *  Inclusion of Header Files Required for the project 
*/
#include <stdio.h>
#include<stdlib.h>
#include "list.h"
#include "APIS.h"

/*************************************************************
 *  using the extern Keyword to get The defined global varibale l and e from another .c file.
 */ 
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