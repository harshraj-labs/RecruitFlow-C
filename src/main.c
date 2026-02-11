#include <stdio.h>
#include <string.h>
#include "applicant.h"
#include "csv_handler.h"

#define MAX_APPLICANTS 100

int main() {
    printf("================================\n");
    printf("Recruit Flow\n");
    printf("================================\n\n");
    
    // Array to hold all applicants
    struct Applicant applicants[MAX_APPLICANTS];
    
    // Read applicants from CSV (correct path!)
    int num_applicants = read_applicant_from_csv("../test_data/applicant_data.csv", applicants, MAX_APPLICANTS);
    
    if (num_applicants < 0) {
        printf("Failed to read CSV file!\n");
        return 1;
    }
    
    // Display all applicants
    printf("\nApplicants loaded:\n");
    printf("------------------\n");
    for (int i = 0; i < num_applicants; i++) {
        printf("%d. %s (%s) - %s, Year %d\n", 
               i+1,
               applicants[i].name,
               applicants[i].email,
               applicants[i].college,
               applicants[i].year);
    }
    
    printf("\n Program completed successfully!\n");
    
    return 0;
}