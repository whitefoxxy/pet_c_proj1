#include <stdio.h>
#include <stdlib.h>


#define C 0.65
#define N 1000

double a, b, t_nach, t1, t2, t3, t_kon, a1, b1, a2, b2, a3, b3, Uvh1, Uvh2;
int t[N];

void annotation()
{
	FILE *fin;
	char line[256];

	fopen_s(&fin, "annotation.txt", "r");

	while ((fgets(line, 256, fin)) != NULL)
	{
		printf("%s", line);
	}
	printf("\n");
};

void clear_console()
{
	system("cls");
};

void Uin(double* Uvh)
{
	for (int i = 0; i < (t_kon - t_nach + 1); i++)
	{
		if (t[i] <= t1)
			Uvh[i] = a * (t[i] - t_nach);
		else
			if (t1 < t[i] && t[i] <= t2)
				Uvh[i] = a * (t1 - t_nach);
			else
				if (t2 < t[i] && t[i] <= t3)
					Uvh[i] = a * (t1 - t_nach) - b * (t[i] - t2);
				else
					Uvh[i] = 0.;
	}
	for (int i = 0; i < (t_kon - t_nach + 1); i++)
		printf("%lf ", Uvh[i]);
	printf("\n");
};

void Uout(double* Uvih, double* Uvh)
{	
	for (int i = 0; i < (t_kon - t_nach + 1); i++)
	{
		if (Uvh[i] <= Uvh1)
			Uvih[i] = a1 * Uvh[i] + b1;
		else
			if (Uvh[i] <= Uvh2)
				Uvih[i] = a2 * Uvh[i] + b2;
			else
				Uvih[i] = a3 * Uvh[i] + b3;
	}
	for (int i = 0; i < (t_kon - t_nach + 1); i++)
		printf("%lf ", Uvih[i]);
	printf("\n");
};

void Create_Time()
{
	for (int i = t_nach, j = 0; i <= t_kon; i++, j++)
		t[j] = i;
};

void Write_file(int q, double* U)
{
	if (q == 1)
	{
		FILE* fp;
		fopen_s(&fp, "Uvh.txt", "w");
		for (int i = 0; i < (t_kon - t_nach + 1); i++)
			fprintf(fp, "%lf ", U[i]);

	}
	else
	{
		FILE* fp;
		fopen_s(&fp, "Uvih.txt", "w");
		for (int i = 0; i < (t_kon - t_nach + 1); i++)
			fprintf(fp, "%lf ", U[i]);
	}

};

void Write_Table(double* Uvh, double* Uvih)
{
	for (int i = 0; i < (t_kon - t_nach + 1); i++)
		printf("%6d %6.1lf %6.1lf\n", t[i], Uvh[i], Uvih[i]);
};



void Chast(double* Uvih)
{
	double U = 0;
	int n = 0;

	for (int i = 0; i < (t_kon - t_nach + 1); i++)
		if (U < Uvih[i])
			U = Uvih[i];

	for (int i = 0; i < (t_kon - t_nach + 1); i++)
		if (Uvih[i] > (U * C))
			n++;
	printf("%lf\n", n / (t_kon - t_nach + 1));
};

void WriteFirst() {
	FILE* fp;
	char str[80];
	fopen_s(&fp, "vhod.txt", "r");

	fscanf_s(fp, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",  &a, &b, &t_nach, &t1, &t2, &t3, &t_kon, &a1, &b1, &a2, &b2, &a3, &b3, &Uvh1, &Uvh2);
	Create_Time();
};