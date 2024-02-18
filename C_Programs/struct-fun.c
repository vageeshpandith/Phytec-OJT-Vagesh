#include <stdio.h>
#include<string.h>
struct employee
{
    char name[100];
    int age;
    float salary;
    void (*display)(struct employee *);
};
void display(struct employee *emp)
{
    printf("Name: %s\n", emp->name);
    printf("Age: %d\n", emp->age);
    printf("Salary: %f\n", emp->salary);
}

int main() 
{
    struct employee emp1;
    strcpy(emp1.name, "Emin Riyaz");
    emp1.age = 23;
    emp1.salary = 50000.0;
    emp1.display = display;
    emp1.display(&emp1);
}

