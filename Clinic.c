/*
 ============================================================================
 Name        : clinic.c
 Author      : Hamada Ahmed 
 Version     : 1.00
 Description : source file for the project
 ============================================================================
 */

/*******************************************************************************
*                                  Inclusions                                  *
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"Clinic.h"



void Select_Modes()
{
    int mode_select,iterator;
    static int password=1234;

 printf("[1] To Login in Admin Mode\n");
 printf("[2] To Login in User Mode\n\n");
 scanf("%d",&mode_select);                               //GET USER INPUT FOR ACCESSING ([1]USER OR [2] ADMIN)
        
        while(mode_select> 2 || mode_select < 1){                   //LOOP TO CHECK IF USER ENTERED INVALID CHOICE
            printf("Invalid Choice!!\n");
            printf("[1] To Login in Admin Mode\n");
            printf("[2] To Login in User Mode\n\n");
            scanf("%d",&mode_select); 
            }                          //ASK THE USER TO ENTER VALID INPUT

 if(ADMIN_MODE==mode_select){
        printf("\n-----------------------You Choosed Admin Mode---------------------------\n");
    int selected_pass;
    int attempts = 0;
    int admin_mode_features;

    while (attempts < 3) {
        printf("Enter the password:");
        scanf("%d",&selected_pass);

        if (selected_pass == password) {
           // while(1){                  /*INFINITE LOOP FOR ADMIN MODE */
                printf("\n------------------------Welcome to admin mode---------------------------\n");
                 printf("[1] Add new patient record\n");
                 printf("[2] Edit patient record\n");
                 printf("[3] Reserve a slot with the doctor\n");
                 printf("[4] Cancel reservation\n");
                 printf("[5] Logout and clear screan\n\n");
                scanf("%d",&admin_mode_features);                                        //ASK THE USER TO ENTER CHOICE
            while(admin_mode_features> 5 || admin_mode_features < 1){                     //LOOP TO CHECH IF THE USER ENTERED INVALID CHOICE
                printf("\nINVALID CHOICE!!\n\n");
                printf("[1] Add new patient record\n");
                printf("[2] Edit patient record\n");
                printf("[3] Reserve a slot with the doctor\n");
                printf("[4] Cancel reservation\n");
                printf("[5] Logout and clear screan\n\n");
                scanf("%d",&admin_mode_features);                            //ASK THE USER TO ENTER A VALID CHOICE
            }
        switch (admin_mode_features)
        {
        case ADD_PATIENT:Add_Patient();break;
        case EDIT_PATIENT:Edit_patient();break;
        case RESERVE_SLOT: Reserve();break;
        case  CANCEL_RES :Cancel();break;
        case LOGOUT: system("cls");break;

       default:printf("You may have some errors while using the program ,Loading ...\n\n");
             break;
        }
     
           // }
          
            break;
        }

         else {
            attempts++;
         
            printf("\nIncorrect password. %d attempts remaining.\n", 3-attempts);
        }
    }
Select_Modes();
    if (attempts == 3) {
        printf("\nToo many incorrect attempts. System closing.\n");
    }
  
 } 


 else if(USER_MODE == mode_select ){
      
    printf("\n------------------------Welcome To User Mode-----------------------\n");
            // while(TRUE){ 
                int user_mode_features; 
                printf("[1] View Patient Record\n");                                                    
                printf("[2] View Today Reservation\n");
                printf("[3] Clear screan\n\n");
                scanf("%d",&user_mode_features);                                                                     //ASK USER TO ENTER MENU CHOICE
              while(user_mode_features> 3 || user_mode_features < 1){                                                         //CHECK IF THE INPUT IS INVALID
                    printf("\nINVALID CHOICE!!\n\n");
                    printf("[1] View Patient Record\n");
                    printf("[2] View Today Reservation\n");
                    printf("[3] Clear screan\n\n");
                    scanf("%d",&user_mode_features);                                                                 //ASK THE USER TO ENTER AGAIN
                }
            switch (user_mode_features)
            {
            case VIEW_PATIENT_INFORMATION: view_Record();break;
            case VIEW_TODAY_RES:view_Reservations();break;
            case LOGOUT2: system("cls");break;
            default:printf("You may have some errors while using the program ,Loading ...\n\n");
                break;
            }
           Select_Modes(); 
 }           
}
void Add_Patient()
{
	patient *newpatient = (patient*) malloc(sizeof(patient));
	printf("Please Enter patient ID: ");
	scanf("%d", &newpatient->id);
	patient *current = patientList;

	while (current != NULL)
	{
		if (current->id == newpatient->id)
		{
			printf("Patient with ID %d already exists.\n", newpatient->id);
			free(newpatient);
			return;
		}
			current = current->next;
	}

	printf("Please Enter new patient information: \n");
	printf("Name: ");
	scanf("%s",&newpatient->name);
	printf("Age: ");
	scanf("%d",&newpatient->age);
	printf("gender: ");
	scanf("%s",&newpatient->gender);

	newpatient->next = patientList;
	patientList=newpatient;
	printf("Patient record added successfully. \n\n");
}

void Edit_patient()
{
	int id;
	printf("Enter patient ID: ");
	scanf("%d", &id);
	patient *currentpatient = patientList;

	while (currentpatient != NULL)
	{
		if (currentpatient->id == id)
		{
			printf("Your patient information is: \n");
			printf("Name: %s\n",currentpatient->name);
			printf("ID: %d\n",currentpatient->id);
			printf("Age: %d\n",currentpatient->age);
			//printf("Gender:%s\n",currentpatient->gender);
			
			printf("\n");
			
			printf("Enter patient edited information:\n");
			printf("Name: ");
			scanf("%s",&currentpatient->name);
			printf("Age: ");
			scanf("%d",&currentpatient->age);
			//printf("Gender: ");
			//scanf("%s",&currentpatient->gender);
			return;
		}

	    currentpatient = currentpatient->next;
	}

		printf("Patient not found.\n");
}

void Reserve()
{
    int n,id;
    bool found = False, slot1, slot2, slot3, slot4, slot5;
    printf("Reserve a slot with the doctor: \n");
    printf("#### Available slots ####\n");

    slot *checkSlot = reservationList;
    slot1 = slot2 = slot3 = slot4 = slot5 = True;
    while (checkSlot != NULL)
    {
    	if (checkSlot->slot != 1 && slot1)
    	{
    		slot1 = True;
    	}
    	else
    	{
    		slot1 = False;
    	}

    	if (checkSlot->slot != 2 && slot2)
    	{
    		slot2 = True;
    	}
    	else
    	{
    		slot2 = False;
    	}

    	if (checkSlot->slot != 3 && slot3)
    	{
    		slot3 = True;
    	}
    	else
    	{
    		slot3 = False;
    	}

    	if (checkSlot->slot != 4 && slot4)
    	{
    		slot4 = True;
    	}
    	else
    	{
    		slot4 = False;
    	}

    	if (checkSlot->slot != 5 && slot5)
    	{
    		slot5 = True;
    	}
    	else
    	{
    		slot5 = False;
    	}

    	checkSlot = checkSlot->next;
    }

    if (slot1)
    {
    	printf("1) 2 pm to 2:30 pm\n");
    }
    if (slot2)
    {
    	printf("2) 2:30 pm to 3 pm\n");
    }
    if (slot3)
    {
    	printf("3) 3 pm to 3:30 pm\n");
    }
    if (slot4)
    {
    	printf("4) 4 pm to 4:30 pm\n");
    }
    if (slot5)
    {
    	printf("5) 4:30 pm to 5 pm\n");
    }

    printf("Enter patient ID: \n");
    scanf("%d", &id);

	patient *current = patientList;
	while (current != NULL)
	{
		if (current->id == id)
	    {
			found = True;
			break;
		}

		current = current->next;
	}

	if (!found)
	{
		printf("Patient with ID %d not found.\n",id);
		return;
	}

	printf("Enter slot number: \n");
	scanf("%d",&n);

	if(n<1 || n>max_slots)
	{
		printf("You may have some errors while using the program ,Loading...\n\n");
		return;
    }

	slot *currentReservation = reservationList;
	while (currentReservation != NULL)
	{
		if (currentReservation->slot == n)
		{
			printf("Slot is already reserved.\n");
			return;
		}

		currentReservation = currentReservation->next;
	}

	slot *newReservation = (slot*) malloc(sizeof(slot));

	newReservation->slot = n;
	newReservation->id = id;
	newReservation->next = reservationList;
	reservationList = newReservation;
	printf("Slot reserved successfully.\n");
}

void Cancel()
{
	int id;
	printf("Enter patient ID: ");
	scanf("%d", &id);
	slot *currentReservation = reservationList;
	slot *pastReservation = NULL;

	while (currentReservation != NULL)
	{
		if (currentReservation->id == id)
		{
			reservationList = currentReservation->next;
		}
		else
		{
			pastReservation->next = currentReservation->next;
		}

		free(currentReservation);
		printf("Reservation cancelled.\n");
		return;

		pastReservation = currentReservation;
		currentReservation = currentReservation->next;

		printf("No reservation found for the given patient ID.\n");
	}
}

void view_Record()
{
	int id;
	printf("Enter patient ID: ");
	scanf("%d", &id);
	patient *currentpatient = patientList;

	while (currentpatient != NULL)
	{
		if (currentpatient->id == id)
		{
			printf("Your patient information is: \n");
			printf("Name: %s\n",currentpatient->name);
			printf("ID: %d\n",currentpatient->id);
			printf("Age: %d\n",currentpatient->age);
			return;
		}
	    currentpatient = currentpatient->next;
	}
		printf("Patient not found.\n");
}

void view_Reservations()
{
	if(reservationList == NULL)
	{
		printf("No reservations yet.\n");
		return;
	}

	slot *currentReservation = reservationList;

	while (currentReservation != NULL)
	{
		printf("Slot : %d\n",currentReservation->slot);
		printf("Patient ID: %d\n",currentReservation->id);

		currentReservation = currentReservation->next;
	}
}
