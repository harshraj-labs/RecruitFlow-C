#include <stdio.h>
#include <string.h>
#include "applicant.h"
#include "csv_handler.h"
#include "file_validator.h" 

#define MAX_APPLICANTS 100

int main() {
    printf("================================\n");
    printf("Recruit Flow\n");
    printf("================================\n\n");
    
    // Array to hold all applicants
    struct Applicant applicants[MAX_APPLICANTS];
    
    // Read applicants from CSV
    int num_applicants = read_applicant_from_csv("../test_data/applicant_data.csv", applicants, MAX_APPLICANTS);
    
    if (num_applicants < 0) {
        printf("Failed to read CSV file!\n");
        return 1;
    }
    
    // Validating files for each applicant
    validate_applicant_files(applicants, num_applicants, "../test_data/Incoming");
    
    // Displaying summary
    printf("SUMMARY:\n");
    printf("========\n");
    
    int eligible_count = 0;
    int not_eligible_count = 0;
    
    for (int i = 0; i < num_applicants; i++) {
        if (strcmp(applicants[i].status, "Eligible") == 0) {
            eligible_count++;
        } else {
            not_eligible_count++;
        }
    }
    
    printf("Total Applicants: %d\n", num_applicants);
    printf("Eligible: %d\n", eligible_count);
    printf("Not Eligible: %d\n", not_eligible_count);
    
    printf("\n Program completed successfully!\n");
    
    return 0;
}