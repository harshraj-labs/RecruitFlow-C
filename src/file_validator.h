#ifndef FILE_VALIDATOR_H
#define FILE_VALIDATOR_H

#include "applicant.h"

// Function to validate files for all applicants
void validate_applicant_files(struct Applicant applicants[], int num_applicants, const char* incoming_folder);

// Helper function to check if a file exists
int file_exists(const char* filepath);

#endif