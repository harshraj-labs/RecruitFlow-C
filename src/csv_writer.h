#ifndef CSV_WRITER_H
#define CSV_WRITER_H

#include "applicant.h"

//generating csv reports for eligible and not eligible applicants
int generate_csv_reports(struct Applicant applicants[], int num_applicants, const char* output_folder);

#endif