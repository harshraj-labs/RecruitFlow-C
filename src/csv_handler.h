#ifndef CSV_HANDLER_H
#define CSV_HANDLER_H

#include "applicant.h"

int read_applicant_from_csv(const char* filename, struct Applicant applicants[], int max_applicants);

#endif