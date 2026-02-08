#ifndef APPLICANT_H
#define APPLICANT_H

//Structure to hold Applicant's information
struct Applicant
{
    char name[100];             // full name from CSV
    char email[100];            // Email from CSV
    char college[100];          // College/University name
    char degree[100];           // Degree/Major
    int year;                   // Year of Study

    //File Validation results
    int has_resume;             // 1=Found; 0=Missing
    int has_id;                 // 1=Found; 0=Missing
    int has_project;            // 1=Found; 0=Missing

    // Issue tracking for each file
    char resume_issue[200];      // What's wrong with resume (if anything)
    char id_issue[200];          // What's wrong with ID (if anything)
    char project_issue[200];     // What's wrong with project (if anything)

    //Final Status
    char status[20];        //"Eligible" or "Not Eligible"
    char reason[500];       //Detailed reason if rejected
};

#endif 