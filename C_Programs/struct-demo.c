#include<stdio.h>
#include<string.h>
//#include "emp.h"
typedef struct emp
{
	int eid;
	float sal;
	char name[20];
}emp;

int main()
{
	emp e1,e2;
	e1.eid=12342;
	strcpy(e1.name,"Vagesh ");
	e1.sal=95000;
	
	e2.eid=24236;
	e2.sal=85000;
	strcpy(e2.name,"Emin ");
	showemp(&e1);
	showemp(&e2);
}
void showemp(emp *ptr)
{
	printf("Name=%s\n",ptr->name);
	printf("Eid=%d\n",ptr->eid);
	printf("Salary=%f\n",ptr->sal);
}
