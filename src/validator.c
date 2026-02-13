#include <stdio.h>
#include <string.h>
#include "file_validator.h"

// Check if a file exists
int file_exists(const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if (file) {
        fclose(file);
        return 1;  // File exists
    }
    return 0;  // File doesn't exist
}

//Validating files by naming format

void validate_applicant_files(struct Applicant applicants[], int num_applicants, const char* incoming_folder) {
    printf("Validating applicant files in: %s\n", incoming_folder);
    printf("==========================================\n\n");
    
    for (int i = 0; i < num_applicants; i++) {
        char filepath[512];
        int issues_found = 0;
        char issues_list[500] = "";
        
        // Extract first and last name from full name
        char first_name[50], last_name[50];
        sscanf(applicants[i].name, "%s %s", first_name, last_name);
        
        printf("Checking: %s\n", applicants[i].name);
        
        // === Check Resume ===
        sprintf(filepath, "%s/%s_%s_Resume.pdf", incoming_folder, first_name, last_name);
        
        if (file_exists(filepath)) {
            applicants[i].has_resume = 1;
            strcpy(applicants[i].resume_issue, "OK");
            printf("  ✓ Resume found\n");
        } else {
            // Check for common mistake: wrong capitalization
            char wrong_case[512];
            sprintf(wrong_case, "%s/%s_%s_resume.pdf", incoming_folder, first_name, last_name);
            
            if (file_exists(wrong_case)) {
                applicants[i].has_resume = 0;
                strcpy(applicants[i].resume_issue, "Wrong capitalization: 'resume' should be 'Resume'");
                strcat(issues_list, "Resume: wrong capitalization; ");
                issues_found++;
                printf("  ✗ Resume: wrong capitalization\n");
            } else {
                applicants[i].has_resume = 0;
                strcpy(applicants[i].resume_issue, "File not found");
                strcat(issues_list, "Resume: missing; ");
                issues_found++;
                printf("  ✗ Resume: missing\n");
            }
        }
    }
    
    printf("==========================================\n");
    printf("Validation complete!\n\n");
}