/*
 ============================================================================
 Name        : clinic.h
 Author      : Hamada Ahmed
 Version     : 1.00
 Description : header file for the project
 ============================================================================
*/

#ifndef CLINIC_H_
#define CLINIC_H_


/* Global variables*/
static int password=1234;
#define max_name_char 20
#define max_slots 5

/* define the boolean data type */
typedef enum {
	False=0, True=1
}bool;

/* structure for patient data */
typedef struct patient
{
    char name[max_name_char];
    int id;
    int age;
	char gender;
    struct patient* next;
}patient;

/* structure for reservation slots */
typedef struct slot {
    int slot;
    int id;
    struct slot* next;
}slot;

/* global pointer to structure to make the linked-list */
static patient *patientList = NULL;
static slot *reservationList = NULL;



/*********************Select modes*******************/
#define     ADMIN_MODE         1
#define     USER_MODE          2

 /**************************************************/
 #define    ITERATOR_NUM      3

 /******************ADMIN FEATURES********************/

#define     ADD_PATIENT        1
#define     EDIT_PATIENT       2
#define     RESERVE_SLOT       3
#define     CANCEL_RES         4
#define     LOGOUT             5

/******************USER FEATURES********************/

#define      VIEW_PATIENT_INFORMATION      1
#define      VIEW_TODAY_RES                2
#define      LOGOUT2                       3


/******************** General Function Prototypes********/
void Select_Modes();

/******************** Admin Function Prototypes********/
void Add_Patient();
void Edit_patient();
void Reserve() ;
void Cancel();

/******************** User Function Prototypes********/

void view_Record();
void view_Reservations();

#endif