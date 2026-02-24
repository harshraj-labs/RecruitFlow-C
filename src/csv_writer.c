#include<stdio.h>
#include<string.h>
#include "utils.h"
#include "csv_writer.h"


int generate_csv_reports(struct Applicant applicants[], int num_applicants, const char* output_folder){
    char eligible_path[256];
    char not_eligible_path[256];

    //file path
    sprintf(eligible_path, "%s/eligible_applicants.csv", output_folder);
    sprintf(not_eligible_path,"%s/not_eligible_applicants.csv",output_folder);

    printf("\n Generating CSV reports... \n");
    printf("==========================================\n");

    //loading animation
    show_loading("Creating reports...",1000);

    //Writing Eligible Applicants CSV
    FILE* eligible_file = fopen(eligible_path,"w");
    if (eligible_file == NULL)
    {
        printf("Error: Could not create %s\n", eligible_path);
        return -1;
    }

    fprintf(eligible_file,"Name,Email,College,Degree,Year,Status,Files Found\n");

    int eligible_count = 0;

    //writing each eligible applicants

    for (int i = 0; i < num_applicants; i++)
    {
        if (strcmp(applicants[i].status,"Eligible") == 0){
            char files_found[200] = "";

            if (applicants[i].has_resume) {
                strcat(files_found, "Resume.pdf");
            }
            if (applicants[i].has_id) {
                if (strlen(files_found) > 0) strcat(files_found, ", ");
                strcat(files_found, "ID");
            }
            if (applicants[i].has_project) {
                if (strlen(files_found) > 0) strcat(files_found, ", ");
                strcat(files_found, "Project");
            }
            //writing in file

            fprintf(eligible_file, "%s,%s,%s,%s,%d,%s,\"%s\"\n",
                    applicants[i].name,
                    applicants[i].email,
                    applicants[i].college,
                    applicants[i].degree,
                    applicants[i].year,
                    applicants[i].status,
                    files_found);

            eligible_count ++;
        }
    }
    
    fclose(eligible_file);
    printf("Created: %s (%d applicants)\n", eligible_path, eligible_count);

    //Writing Not Eligible Applicants CSV

    FILE* not_eligible_file = fopen(not_eligible_path,"w");
    if(not_eligible_file == NULL){
        printf("Error: Could not create %s\n", not_eligible_path);
        return -1;
    }

    //Header
    fprintf(not_eligible_file, "Name,Email,College,Degree,Year,Status,Reason\n");

    int not_eligible_count =0;

    // Writing each not eligible applicant
    for (int i = 0; i < num_applicants; i++) {
        if (strcmp(applicants[i].status, "Not Eligible") == 0) {
            fprintf(not_eligible_file, "%s,%s,%s,%s,%d,%s,\"%s\"\n",
                    applicants[i].name,
                    applicants[i].email,
                    applicants[i].college,
                    applicants[i].degree,
                    applicants[i].year,
                    applicants[i].status,
                    applicants[i].reason);
            
            not_eligible_count++;
        }
    }
    fclose(not_eligible_file);
    printf("Created: %s (%d applicants)\n", not_eligible_path, not_eligible_count);
    
    printf("==========================================\n");
    printf("CSV reports generated successfully!\n\n");

    return 0;
}