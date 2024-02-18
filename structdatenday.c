	#include<stdio.h>
	type struct
	{	
		int d,y;

		char m[];
	};
	void display_1()
	{
		printf("%d,%d,%d",dd,mm,yyyy);
	}
	void display_2()
	{
		printf("%s,%d,%d"mon,mm,yyyy);
	}

	int main()
	{
		date d1,d2;
		d1.dd=27;
		d1.mm=06;
		d1.yyyy=2023;
		display_1();
		strcpy(d2.mon,July);
		display_2();
	}
	
