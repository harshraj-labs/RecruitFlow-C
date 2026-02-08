#include<stdio.h>
#include<string.h>
#include"applicant.h"

int main() {
    printf("================================\n");
    printf("Internship Application Validator\n");
    printf("================================\n\n");
    
    //Test aaplicant
    struct Applicant test;
    
    //Filling struct data
    strcpy(test.name,"John Doe");
    strcpy(test.email,"jhondoe@gmail.com");
    strcpy(test.college,"ICFAI");
    strcpy(test.degree,"B.Tech CSE");
    test.year = 3;
    test.has_resume = 1;
    test.has_id = 1;
    test.has_project = 1;
    strcpy(test.status, "Eligible");
    strcpy(test.reason, "All files present and valid");

    //Display Data
    printf("Testing Applicant Struct:\n");
    printf("------------------------\n");
    printf("Name: %s\n",test.name);
    printf("Email: %s\n",test.email);
    printf("College: %s\n",test.college);
    printf("Degree: %s\n",test.degree);
    printf("Year: %d\n",test.year);
    printf("Resume: %s\n",test.has_resume ? "Found":"Missing");
    printf("ID: %s\n",test.has_id ? "Found":"Missing");
    printf("Project: %s\n",test.has_project ? "Found":"Missing");
    printf("Status: %s\n",test.status);
    printf("Reason: %s\n",test.reason);

    // Another test applicant (rejected)

    struct Applicant test2;

    //data
    strcpy(test2.name,"Bob Lee");
    strcpy(test2.email,"bob@gmail.com");
    strcpy(test2.college,"MIT");
    strcpy(test2.degree,"Business");
    test2.year = 2;
    test2.has_resume = 1;
    test2.has_id = 1;
    test2.has_project = 0; //Missing
    strcpy(test2.status, "Not Eligible");
    strcpy(test2.reason, "Missing Project File");

    //Display
    printf("------------------------\n");
    printf("Name: %s\n",test2.name);
    printf("Email: %s\n",test2.email);
    printf("College: %s\n",test2.college);
    printf("Degree: %s\n",test2.degree);
    printf("Year: %d\n",test2.year);
    printf("Resume: %s\n",test2.has_resume ? "Found":"Missing");
    printf("ID: %s\n",test2.has_id ? "Found":"Missing");
    printf("Project: %s\n",test2.has_project ? "Found":"Missing");
    printf("Status: %s\n",test2.status);
    printf("Reason: %s\n",test2.reason);

    printf("\nStruct test successful!\n");
    return 0;
}