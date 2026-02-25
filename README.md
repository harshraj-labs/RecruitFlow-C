# RecruitFlow - Internship Application Validator

A C-based command-line tool that automates the validation and organization of internship applications. Built to help HR teams efficiently process bulk applications from Google Forms.

## 🎯 Problem Statement

When companies receive hundreds of internship applications via Google Forms, manually checking if each applicant submitted the correct files (resume, ID, project showcase) with proper naming conventions is time-consuming and error-prone. This tool automates that entire process.

## ✨ Features

- **📊 CSV Import** - Reads applicant data directly from Google Forms exports
- **✅ File Validation** - Checks for proper file naming: `FirstName_LastName_FileType.extension`
- **🔍 Format Checking** - Validates file extensions (PDF for resumes, JPG/PNG for IDs, MP4 for projects)
- **⚠️ Error Detection** - Identifies missing files and capitalization errors
- **📈 Report Generation** - Creates CSV reports for eligible and rejected applicants
- **🎬 Loading Animations** - Professional CLI experience with rotating spinner

## 🛠️ Tech Stack

- **Language:** C
- **Compiler:** GCC
- **Version Control:** Git/GitHub
- **Resource Compiler:** windres (for application icon)
- **Platform:** Windows (portable to Linux/Mac)

## 💡 Why I Built This

As a first-year CSE student and member of the placement committee, I wanted to understand how bulk internship applications are processed and 
validated. This project simulates that workflow and helped me practice file handling, parsing, and modular C programming.

## 📂 Project Structure
```
RecruitFlow/
├── src/
│   ├── main.c              # Main program
│   ├── applicant.h         # Applicant struct definition
│   ├── csv_handler.c/h     # CSV reading logic
│   ├── validator.c/h       # File validation logic
│   ├── csv_writer.c/h      # CSV report generation
│   └── utils.c/h           # Utility functions (loading animation)
├── test_data/
│   ├── applicant_data.csv  # Sample Google Forms data
│   └── Incoming/           # Sample submitted files
├── output/
│   ├── eligible_applicants.csv
│   └── not_eligible_applicants.csv
└── README.md
```

## 🚀 Getting Started

### Option 1: Download Pre-built Executable (Recommended for Users)


**Prerequisites:** Windows OS

**Quick Start:**

1. Download the latest release:
   - Go to [Releases](https://github.com/harshraj-labs/RecruitFlow-C/releases)
   - Download `RecruitFlow-v1.0.zip`
   - Extract the ZIP file

2. Prepare your data:
   - Export your Google Form responses as CSV
   - Save it as `applicant_data.csv` in the `test_data/` folder
   - Place applicant files in `test_data/Incoming/` folder

3. Run the program:
   - Double-click `RecruitFlow.exe` in the `src/` folder
   - OR open Command Prompt and run:
```bash
   cd src
   ./RecruitFlow.exe
```

4. Check results:
   - Find CSV reports in the `output/` folder
   - `eligible_applicants.csv` - Approved applicants
   - `not_eligible_applicants.csv` - Rejected applicants with reasons

---

### Option 2: Build from Source (For Developers)

**Prerequisites:**
- GCC compiler installed
- Windows OS

**Setup:**

1. Clone the repository:
```bash
git https://github.com/harshraj-labs/RecruitFlow-C
cd RecruitFlow
```

2. Make your changes to the `.c` files in `src/`

3. Compile the resource file:
```bash
   windres resource.rc -o resource.o
```
4. Compile the program:
```bash
   gcc main.c csv_handler.c validator.c csv_writer.c utils.c resource.o -o RecruitFlow.exe
```
5. Test your changes:
```bash
RecruitFlow.exe
```

## 📋 Usage

### Input Format

**CSV File** (`test_data/applicant_data.csv`):
```csv
Timestamp,Name,Email,Phone number,College/University Name,Degree Name,Year of Study
2026/02/08 2:54:20 pm GMT+5:30,John Doe,john@email.com,1234567890,MIT,Computer Science,3
```

**File Naming Convention** (`test_data/Incoming/`):
- Resume: `FirstName_LastName_Resume.pdf`
- ID Card: `FirstName_LastName_ID.jpg` (or .png/.jpeg)
- Project: `FirstName_LastName_Project.mp4` (or .avi/.mov)

### Output

The program generates two CSV reports in `output/`:

1. **eligible_applicants.csv** - Applicants who submitted all files correctly
2. **not_eligible_applicants.csv** - Rejected applicants with specific reasons

## 📊 Example Output
```
================================
Recruit Flow
================================

Reading CSV file: ../test_data/applicant_data.csv

 Successfully read 4 applicants from CSV

Validating applicant files in: ../test_data/Incoming
==========================================

Checking: John Doe
Resume: found
ID: Found
Project Found
  Status: ELIGIBLE

==========================================
Checking: Bob Lee
Resume: found
ID: Found
Project: missing
  Status: NOT ELIGIBLE

==========================================
Checking: Jane Smith
Resume: found
ID: Found
Project: missing
  Status: NOT ELIGIBLE

==========================================
Checking: Alice Wong
Resume: found
ID: Found
Project Found
  Status: ELIGIBLE

==========================================
==========================================
Validation complete!


 Generating CSV reports...
==========================================
Created: ../output/eligible_applicants.csv (2 applicants)
Created: ../output/not_eligible_applicants.csv (2 applicants)
==========================================
CSV reports generated successfully!

SUMMARY:
========
Total Applicants: 4
Eligible: 2
Not Eligible: 2

 Program completed successfully!
```

## 🎯 Validation Rules

| File Type | Required Format | Accepted Extensions |
|-----------|----------------|---------------------|
| Resume | `FirstName_LastName_Resume.pdf` | `.pdf` |
| ID Card | `FirstName_LastName_ID.jpg` | `.jpg`, `.jpeg`, `.png` |
| Project | `FirstName_LastName_Project.mp4` | `.mp4`|

**Rejection Reasons:**
- Missing files
- Wrong file extensions
- Incorrect capitalization (e.g., `resume` instead of `Resume`)

## 🧪 Testing

Sample test data is included in `test_data/`:
- 4 sample applicants with varying file submission quality
- Covers edge cases: missing files, wrong capitalization, multiple formats

## 🚀 Future Enhancements

- [ ] Add support for .avi and .mov project files
- [ ] Implement fuzzy name matching for minor typos
- [ ] Add email notification system for rejected applicants
- [ ] Create GUI version using GTK or Qt
- [ ] Add database integration (SQLite)
- [ ] Support for batch processing (multiple form responses)

## 👤 Author

**Harsh Raj**
- GitHub: [@harshraj-labs](https://github.com/harshraj-labs)
- LinkedIn: [Harsh Raj](https://www.linkedin.com/in/harshrajlabs/)

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

## 🙏 Acknowledgments

- Built as a portfolio project to demonstrate C programming skills
- Inspired by real-world HR automation 
- Inspired by observing real-world placement and recruitment workflows.

---

**⭐ Star this repo if you find it useful!**
