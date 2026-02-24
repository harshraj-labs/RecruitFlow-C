#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv_handler.h"
#include "utils.h"

/* Since the google form generated csv contains "Quotes",
we need to make a function to remove quotes first*/

void remove_quotes(char* str) {
    int len = strlen(str);

    if (len > 0 && str[0] == '"') {
        memmove(str, str + 1, len);
        len--;
    }
    if (len > 0 && str[len-1] == '"') {
        str[len-1] = '\0';
    }
}

// Function to remove a trailing new line from a string
void remove_newline(char* str) {
    int len = strlen(str); 

    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }

    len = strlen(str); 
    if (len > 0 && str[len-1] == '\r') {
        str[len-1] = '\0';
    }
}

int read_applicant_from_csv(const char* filename, struct Applicant applicants[], int max_applicants) {
    FILE* file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error: could not find file '%s'\n", filename);
        return -1;
    }
    
    printf("Reading CSV file: %s\n", filename);

    //loading animation
    show_loading("Loading applicants data...",1000);
    
    char line[2000];
    int applicant_count = 0;  
    
    // Skip the first line (headers)
    if (fgets(line, sizeof(line), file) == NULL) {
        printf("Error! CSV file is empty\n");
        fclose(file);
        return -1;
    }
    
    // Read line by line
    while (fgets(line, sizeof(line), file) != NULL && applicant_count < max_applicants) {
        remove_newline(line);
        
        // Parse CSV line
        char* token;
        int field = 0;
        token = strtok(line, ",");
        
        while (token != NULL && field < 7) {
            remove_quotes(token);

            switch (field) {
                case 0:  // Timestamp
                    break;
                case 1:  // Name
                    strcpy(applicants[applicant_count].name, token);
                    break; 
                case 2:  // Email
                    strcpy(applicants[applicant_count].email, token);
                    break;
                case 3:  // Phone (skip)
                    break;
                case 4:  // College
                    strcpy(applicants[applicant_count].college, token);
                    break;
                case 5:  // Degree
                    strcpy(applicants[applicant_count].degree, token);
                    break;
                case 6:  // Year
                    applicants[applicant_count].year = atoi(token);
                    break;
            }
            
            token = strtok(NULL, ",");
            field++;
        }
        
        applicants[applicant_count].has_resume = 0;
        applicants[applicant_count].has_id = 0;
        applicants[applicant_count].has_project = 0;
        strcpy(applicants[applicant_count].status, "Pending");
        strcpy(applicants[applicant_count].reason, "");
        strcpy(applicants[applicant_count].resume_issue, "");
        strcpy(applicants[applicant_count].id_issue, "");
        strcpy(applicants[applicant_count].project_issue, "");
        
        applicant_count++;
    }
    
    fclose(file); 
    printf("\n Successfully read %d applicants from CSV\n\n", applicant_count);
    return applicant_count;
}