#include "functions.h"

#include <stdio.h>
#include <windows.h>

#define N 1000


void Write_Message()
{
	printf("Введите команду: 1 - Рассчитать и вывести на экран U_вх\n");
	printf("Введите команду: 2 - Рассчитать и вывести на экран U_вых\n");
	printf("Введите команду: 3 - Сохранить в файл U_вх\n");
	printf("Введите команду: 4 - Сохранить в файл U_вых\n");
	printf("Введите команду: 5 - Найти часть времени a от промежутка [tкон, tнач], в течение которого выходное напряжение превышает уровень CUmax\n");
	printf("Введите команду: 6 - Очистить консоль\n");
	printf("Введите команду: 7 - Вывести таблицу времени и напряжений\n");
	printf("Введите команду: 8 - Вывести аннотацию из файла\n");
	printf("Введите команду: 9 - Выйти\n");
//	printf("Введите команду: 0 - Выйти");
};

int main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double Uvh[N], Uvih[N];
	int n;
	int was_init_Uvh = 0;
	WriteFirst();
	
	while (1)
	{
		Write_Message();
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			Uin(Uvh);
			was_init_Uvh = 1;
			break;
		case 2:
			if (was_init_Uvh)
				Uout(Uvih, Uvh);
			else
				printf("Простите, но вы ещё не создали входное напряжение");
			break;
		case 3:
			Write_file(1, Uvh);
			break;
		case 4:
			Write_file(2, Uvih);
			break;
		case 5:
			Chast(Uvih);
			break;
		case 6:
			clear_console();
			break;
		case 7:
			Write_Table(Uvh, Uvih);
			break;
		case 8:
			annotation();
			break;
		case 9:
			return 0;
		case 0:
			return 0;
		default:
			break;
		}
	}
}