#include <stdio.h>
void right_triangle_numbers(int n); void pyramid_stars(int n);
void pyramid_alphabets(int n);
void diamond_same_numbers(int n); int main()
{
int choice, n; while (1) {
printf("\n========== PATTERN MENU ==========\n");
printf("1. Right Angled Triangle with Same Numbers\n"); printf("2. Pyramid with *\n");
printf("3. Pyramid with Alphabets\n"); printf("4. Diamond with Same Numbers\n"); printf("5. Exit\n");
printf("Enter your choice (1-5): "); scanf("%d", &choice);
if (choice == 5) {
printf("\nExiting... Thank you!\n"); break;
}
if (choice < 1 || choice > 5) {
printf("\nInvalid choice! Please try again.\n"); continue;
 
printf("Enter number of rows: "); scanf("%d", &n);
switch (choice)
{
case 1:
right_triangle_numbers(n); break;
case 2:
pyramid_stars(n); break;
case 3:
pyramid_alphabets(n); break;
case 4:
diamond_same_numbers(n); break;
}
}


return 0;
}
void right_triangle_numbers(int n) { int i, j;
for (i = 1; i <= n; i++) { for (j = 1; j <= i; j++) {
printf("%d", i);
 
printf("\n");
}
}
void pyramid_stars(int n) { int i, j, space;
for (i = 1; i <= n; i++) {
for (space = i; space < n; space++) { printf(" ");
}
for (j = 1; j <= (2 * i - 1); j++) { printf("*");
}
printf("\n");
}
}
void pyramid_alphabets(int n) { int i, j, space;
char ch;
for (i = 1; i <= n; i++) {
for (space = i; space < n; space++) { printf(" ");
}
ch = 'A';
for (j = 1; j <= i; j++) { printf("%c", ch); ch++;
 
ch -= 2;
for (j = 1; j < i; j++) { printf("%c", ch); ch--;
}
printf("\n");
}
}
void diamond_same_numbers(int n) { int i, j, space;
for (i = 1; i <= n; i++) {
for (space = i; space < n; space++) { printf(" ");
}
for (j = 1; j <= (2 * i - 1); j++) {
printf("%d", i);
}
printf("\n");
}
for (i = n - 1; i >= 1; i--) {
for (space = n; space > i; space--) { printf(" ");
}
for (j = 1; j <= (2 * i - 1); j++) {
printf("%d", i);
}
 
printf("\n");
}
}
