#include <stdio.h>
#include <string.h>
#define MAX 10
typedef struct 
{
    int roll_no;
    char name[50];
    float marks[3];
    float average;
} 
Student;
Student students[MAX];
int student_count = 0;
void insert_student() 
{
    if (student_count >= MAX) 
    {
        printf("Database is full. Cannot insert more students.\n");
        return;
    }
    printf("\nEnter details for student %d:\n", student_count + 1);
    printf("Roll No: ");
    scanf("%d", &students[student_count].roll_no);
    printf("Name: ");
    scanf(" %[^\n]", students[student_count].name);
    float sum = 0;
    for (int i = 0; i < 3; i++) 
    {
        printf("Marks of Subject %d: ", i + 1);
        scanf("%f", &students[student_count].marks[i]);
        sum += students[student_count].marks[i];
    }
    students[student_count].average = sum / 3.0;
    student_count++;
    printf("Student inserted successfully!\n");
}
void display_students() 
{
    if (student_count == 0) 
    {
        printf("No student records to display.\n");
        return;
    }
    printf("\n%-10s %-20s %-10s %-10s %-10s %-10s\n", "Roll No", "Name", "Mark1", "Mark2", "Mark3", "Average");
    for (int i = 0; i < student_count; i++) 
    {
        printf("%-10d %-20s %-10.2f %-10.2f %-10.2f %-10.2f\n",
               students[i].roll_no,
               students[i].name,
               students[i].marks[0],
               students[i].marks[1],
               students[i].marks[2],
               students[i].average);
    }
}
void search_student() 
{
    if (student_count == 0) 
    {
        printf("No students to search.\n");
        return;
    }
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < student_count; i++) 
    {
        if (students[i].roll_no == roll) 
        {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\n", students[i].roll_no);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f, %.2f, %.2f\n", students[i].marks[0], students[i].marks[1], students[i].marks[2]);
            printf("Average: %.2f\n", students[i].average);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}
void sort_students() 
{
    if (student_count < 2) 
    {
        printf("Not enough students to sort.\n");
        return;
    }
    for (int i = 0; i < student_count - 1; i++) 
    {
        for (int j = i + 1; j < student_count; j++) 
        {
            if (students[i].average < students[j].average) 
            {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Students sorted by average marks (descending).\n");
}
int main() 
{
    int choice;
    do 
    {
        printf("\n--- Student Database Menu ---\n");
        printf("1. Insert Student\n");
        printf("2. Search Student\n");
        printf("3. Sort Students by Average\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1: insert_student(); break;
            case 2: search_student(); break;
            case 3: sort_students(); break;
            case 4: display_students(); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
