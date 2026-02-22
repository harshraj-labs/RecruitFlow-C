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
        
        //Check Resume
        sprintf(filepath, "%s/%s_%s_Resume.pdf", incoming_folder, first_name, last_name);
        
        if (file_exists(filepath)) {
            applicants[i].has_resume = 1;
            strcpy(applicants[i].resume_issue, "OK");
            printf("Resume: found\n");
        } else {
            // Check for wrong capitalization
            char wrong_case[512];
            sprintf(wrong_case, "%s/%s_%s_resume.pdf", incoming_folder, first_name, last_name);
            
            if (file_exists(wrong_case)) {
                applicants[i].has_resume = 0;
                strcpy(applicants[i].resume_issue, "Wrong capitalization: 'resume' should be 'Resume'");
                strcat(issues_list, "Resume: wrong capitalization; ");
                issues_found++;
                printf("Resume: wrong capitalization\n");
            } else {
                applicants[i].has_resume = 0;
                strcpy(applicants[i].resume_issue, "File not found");
                strcat(issues_list, "Resume: missing; ");
                issues_found++;
                printf("Resume: missing\n");
            }
        }

        //Check ID
        sprintf(filepath, "%s/%s_%s_ID.jpg", incoming_folder, first_name, last_name);

        if (file_exists(filepath))
        {
           applicants[i].has_id = 1;
           strcpy(applicants[i].id_issue,"OK");
           printf("ID: Found\n");

        } // checking for png
        else{
            sprintf(filepath, "%s/%s_%s_ID.png", incoming_folder, first_name, last_name);

            if (file_exists(filepath))
            {
                applicants[i].has_id = 1;
                strcpy(applicants[i].id_issue, "OK");
                printf("ID: Found\n");
            }
            else{ //checking for jpeg
                sprintf(filepath, "%s/%s_%s_ID.jpeg", incoming_folder, first_name, last_name);

                if (file_exists(filepath))
                {
                applicants[i].has_id = 1;
                strcpy(applicants[i].id_issue, "OK");
                printf("ID: Found\n");

                }
                else{ //file not found
                    applicants[i].has_id = 0;
                    strcpy(applicants[i].id_issue,"File not Found");
                    strcat(issues_list,"ID: Missing; ");
                    issues_found ++;
                    printf("ID: missing\n");

                }
            }

        }

        //check project
        sprintf(filepath,"%s/%s_%s_Project.mp4",incoming_folder,first_name,last_name);
        // checking for mp4 project showcase
        if (file_exists(filepath))
        {
            applicants[i].has_project = 1;
            strcpy(applicants[i].project_issue,"OK");
            printf("Project Found\n");
        }
        else{ //file missing

            applicants[i].has_project =0;
            strcpy(applicants[i].project_issue,"File not Found");
            strcat(issues_list,"Project: Missing; ");
            issues_found ++;
            printf("Project: missing\n");

        }
        //Final Status
        if (issues_found == 0) {
            strcpy(applicants[i].status, "Eligible");
            strcpy(applicants[i].reason, "All files present and valid");
            printf("  Status: ELIGIBLE\n");
        } else {
            strcpy(applicants[i].status, "Not Eligible");
            strcpy(applicants[i].reason, issues_list);
            printf("  Status: NOT ELIGIBLE\n");
        }
        
        printf("\n");
        printf("==========================================\n");
        
    }
    
    printf("==========================================\n");
    printf("Validation complete!\n\n");
}