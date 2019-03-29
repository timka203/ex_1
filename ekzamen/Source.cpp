#include<iostream>
#include<locale.h>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
struct animal
{
	char name[30];
	char type[30];
	char name2[30];
};
int func1(int *&a,int g)
{
	int c=0;
	for (size_t i = 0; i < g; i++)
	{
		if (a[i] != 0)
		{
			c++;
		}
	}
	int *tmp;
	tmp = new int[c];
	int y = 0;
	for (size_t i = 0; i < g; i++)
	{
		if (a[i] != 0)
		{
			tmp[y] = a[i];
			y++;
		}
	}
	delete[] a;
	a = tmp;
	return c;
}
bool func2(int a, int g)
{
	int h = g;
 	while (g < a)
	{
		if (g-a==0)
		{
			return true;
		}
		g = g * h;
	}
	return false;
}
void task1()
{
	char str[30];
	cin.ignore();
	cin.getline(str, 30);
	int s;
	s = strlen(str);
	for (size_t i = 0; i < s; i++)
	{
		if (str[i] > 64 && str[i] < 91)
		{
			str[i] = str[i] + 32;
		}

	}
	cout << str << endl;
}
void task2()
{
	int g;
	cout << "сколько чисел?" <<endl;
	cin >> g;
	int *a;
	a = new int[g];
	for (size_t i = 0; i <g; i++)
	{
		cout << "ввидите число" << endl;
		cin >> a[i];
	}
	int h = func1(a, g);
	for (size_t i = 0; i < h; i++)
	{
		cout << a[i] << endl;
	}
}
void task3()
{
	int g;
	cout << "сколько чисел?" << endl;
	cin >> g;
	int *a;
	a = new int[g];
	int c=0;
	for (size_t i = 0; i <g; i++)
	{
		a[i] = 1 + rand() % 100;
		cout << a[i] << endl;
	}
	cout << "-----------------------" << endl;
	for (size_t i = 1; i < g; i++)
	{
		if (a[i]<a[i-1])
		{
			cout << a[i] << endl;
			c++;
		}
	}
	cout << c << endl;


}
void task4()
{
	int g;
	cout << "какое число?" << endl;
	cin >> g;
	int a[10];
	int c = 0;
	for (size_t i = 0; i <10; i++)
	{
		a[i] = 1 + rand() % 100;
		cout << a[i] << endl;
	}
	cout << "-----------------------" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout<<func2(a[i], g)<<endl;
	}
}
void task5()
{
	cout << " 5.	Дана матрица размера M × N и целое число K (1 ≤ K ≤ N). Вывести
		элементы K - го столбца данной матрицы
		" << endl;
	int  h;
	cout << "Ввидите число до 10 " << endl;
	cin >> h;
	int a[10][10];
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0;j <10; j++)
		{
			a[i][j] = 1 + rand() % 100;
			cout << a[i][j] <<" ";
		}
		cout << endl;
	}
	for (size_t i = 0; i < 10; i++)
	{
		cout << a[i][h-1] << endl;
	}
}
void func_voice(char *t)
{
	char str[10] = { "Dog" };
	char str1[10] = { "Cat" };

	if (strcmp(t,str)==0)
	{
		cout << "Wooof" << endl;
	}
	if (strcmp(t, str1) == 0)
	{
		cout << "myah" << endl;
	}
}
void task6()
{
	cout << "6.	Разработать структуру, которая описывает животное (название, класс, кличка). Создать функции для работы с этой структурой:" << endl;
	ifstream in("out.txt");
	animal *s;
	s = new animal[3];
	for (size_t i = 0; i < 3; i++)
	{
		in >> s[i].name;
		in >> s[i].type;
		in >> s[i].name2;
	}
	for (size_t i = 0; i < 3; i++)
	{
		cout << s[i].name << " " << s[i].type << " " << s[i].name2 << endl;
		func_voice(s[i].name);
	}
}
int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int a, d;
	do
	{
		printf("Which task");
		scanf_s("%d", &d);
		switch (d)
		{

		case 1: task1(); break;
		case 2: task2(); break;
		case 3: task3(); break;
		case 6: task6(); break;
		case 5: task5(); break;
		case 4: task4(); break;
		default:
			break;
		}
		printf(" do you want continue y(1)/no(2)");
		scanf_s("%d", &a);
	} while (a == 1);
	system("pause");
}