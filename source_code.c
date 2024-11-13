#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
// Department structure
typedef struct {
    int id;
    char sch_id[15];
    char dept_code[10];
    char dept_name[50];
    char dept_location[100];
    char dept_email[50];
} Department;
// Global array to store department data and a counter
Department departments[MAX];
int department_count = 0;
// File name for storing the details
const char* FILE_NAME = "department_setting.txt";
// Function declarations
void defenders_department_create();
void defenders_department_update();
void defenders_department_retrieve();
void defenders_department_delete();
void defenders_department_storing();
void defenders_department_sortbycode();
void defenders_department_searchbycode();
// Function to load data from the file into the departments array
void load_from_file() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return; // No file exists yet
    }
    department_count = 0;
    while (fscanf(file, "%d %s %s %s %s %s\n", &departments[department_count].id,
    departments[department_count].sch_id,
    departments[department_count].dept_code,
    departments[department_count].dept_name,
    departments[department_count].dept_location,
    departments[department_count].dept_email) == 6) {
        department_count++;
    }
    fclose(file);
}
// Function to save data to the file
void defenders_department_storing() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < department_count; i++) {
        fprintf(file, "%d %s %s %s %s %s\n", departments[i].id,
        departments[i].sch_id, departments[i].dept_code,
        departments[i].dept_name, departments[i].dept_location,
        departments[i].dept_email);
    }
    fclose(file);
}
// Function to create a university record
void defenders_department_create() {
    if (department_count >= MAX) {
        printf("Department list is full!\n");
        return;
    }

    Department d;
    printf("Enter Department ID: ");
    scanf("%d", &d.id);
    printf("Enter School ID: ");
    scanf("%s", d.sch_id);
    printf("Enter Department Code: ");
    scanf("%s", d.dept_code);
    printf("Enter Department Name: ");
    scanf("%s", d.dept_name);
    printf("Enter Department Location: ");
    scanf("%s", d.dept_location);
    printf("Enter Department Email: ");
    scanf("%s", d.dept_email);
    departments[department_count++] = d;
    defenders_department_storing();
    printf("Department created successfully!\n");
}
// Function to update a university record
void defenders_department_update() {
    int id;
    printf("Enter Department ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < department_count; i++) {
        if (departments[i].id == id) {
            printf("Enter new School ID: ");
            scanf("%s", departments[i].sch_id);
            printf("Enter new Department Code: ");
            scanf("%s", departments[i].dept_code);
            printf("Enter new Department Name: ");
            scanf("%s", departments[i].dept_name);
            printf("Enter new Department Address: ");
            scanf("%s", departments[i].dept_location);
            printf("Enter new Department Email: ");
            scanf("%s", departments[i].dept_email);
            defenders_department_storing();
            printf("Department updated successfully!\n");
            return;
        }
    }
    printf("Department with ID %d not found.\n", id);
}
// Function to retrieve all department records
void defenders_department_retrieve() {
    printf("\nList of Departments:\n");
    for (int i = 0; i < department_count; i++) {
        printf("ID: %d\nSchool_ID: %s\nCode: %s\nName: %s\nLocation: %s\nEmail: %s\n\n",
        departments[i].id, departments[i].sch_id,
        departments[i].dept_code, departments[i].dept_name,
        departments[i].dept_location, departments[i].dept_email);
    }
}
// Function to delete a university record
void defenders_department_delete() {
    int id;
    printf("Enter Department ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < department_count; i++) {
        if (departments[i].id == id) {
            for (int j = i; j < department_count - 1; j++) {
                departments[j] =departments[j + 1];
            }
            department_count--;
            defenders_department_storing();
            printf("Department deleted successfully!\n");
            return;
        }
    }
     printf("Department with ID %d not found.\n", id);
}
// Function to search department by code
void defenders_department_searchbycode() {
    char code[10];
    printf("Enter Department Code to search: ");
    scanf("%s", code);
    for (int i = 0; i < department_count; i++) {
        if (strcmp(departments[i].dept_code, code) == 0) {
            printf("ID: %d\nSchool_ID: %s\nCode: %s\nName: %s\nLocation: %s\nEmail: %s\n\n",
            departments[i].id, departments[i].sch_id,
            departments[i].dept_code, departments[i].dept_name,
            departments[i].dept_location, departments[i].dept_email);
            return;
        }
    }
    printf("Department with code %s not found.\n", code);
}
// Bubble sort by department code
void defenders_department_sortbycode() {
    for (int i = 0; i < department_count - 1; i++) {
        for (int j = 0; j < department_count - i - 1; j++) {
            if (strcmp(departments[j].dept_code, departments[j + 1].dept_code) > 0) {
                Department temp = departments[j];
                departments[j] = departments[j + 1];
                departments[j + 1] = temp;
            }
        }
    }
    printf("Departments sorted by code!\n");
    defenders_department_retrieve();
}
int main() {
    load_from_file();
    int choice;
    while (1) {
        printf("\n1. Create Department\n2. Update Department\n3. Retrieve Department\n4. Delete Department\n5. Search by Code\n6. Sort by Code\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                defenders_department_create();
                break;
            case 2:
                defenders_department_update();
                break;
            case 3:
                defenders_department_retrieve();
                break;
            case 4:
                defenders_department_delete();
                break;
            case 5:
                defenders_department_searchbycode();
                break;
            case 6:
                defenders_department_sortbycode();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
