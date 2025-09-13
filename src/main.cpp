#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
int* arrayofrollnum(int*, int);
double* array_percentage_num(int*, int*, int);
char* array_grade(double*, int);
void templete_display(int*, int*, int*, double*, char*, int);
void final_templete_display(int*, int*, int*, double*, char*, int, char**);
void final_templete_display2(int*, int*, int*, double*, char*, int);
int* update_roll_num(int*, int);
int* update_cs_math(int*, int*, int);
bool present(int*, int, int);
int* update_all_cs_math(int*, int);
void sorting(int*, int*, int*, double*, char*, int);
int* deletion1(int*, int, int);
double* deletion2(double*, int, int);
char* deletion3(char*, int, int);
int main()
{
	
	int color;
	cout << "if you want to change console color press , then press 1 : or press any other digit :";
	cin >> color;
	if (color == 1)
	{
		int pause = 0;
		cout << "Please wait , program is loading . . . ." << endl;
		for (int i = 0; i < 50; i++)
		{
			cout << "\xDb\xDb";
			Sleep(100 + i + pause);
			pause = pause + 7;
		}
		cout << endl;
		cout << "press 1 for green console" << endl;
		cout << "press 2 for aqua console" << endl;
		cout << "press 3 for red console" << endl;
		cout << "press 4 for purple console" << endl;
		cout << "press 5 for white console" << endl;
		int color2;
		cin >> color2;
		if (color2 == 1)
			system("color 2F");
		else if (color2 == 2)
			system("color 3F");
		else if (color2 == 3)
			system("color 4F");
		else if (color2 == 4)
			system("color 5F");
		else if (color2 == 5)
			system("color F0");
		else
			cout << "you have entered invalid operator" << endl;
	}
	cout << "Project Title: Student Grade Report" << endl;
	char a;
	a = 'y';
	char b;
	int student_num = 1;
	int roll_num;
	int mark_cs;
	int mark_math;
	int size = 1;
	int num_num = 0;
	int* arr_math = NULL;
	int* arr_cs = NULL;
	int* arr_roll = NULL;
	double* arr_percentage = NULL;
	char* arr_grade = NULL;
	char** arr_name = NULL;
	bool fff = false;
	while (a != 'n' && a != 'N')
	{
		cout << "enter the record of student:" << student_num << endl;
		cout << "enter the roll number :";
		cin >> roll_num;

		for (int i = 0; i < 1; i++)
		{
			cout << "enter the marks of computer science of student " << student_num << " marks should be less than or equal to 100 :";
			cin >> mark_cs;
			if (mark_cs > 100 || mark_cs < 0)
			{
				cout << "you have entered invalid number, please enter the correct marks" << endl;
				i--;
			}

		}
		for (int i = 0; i < 1; i++)
		{
			cout << "enter the marks of mathematics of student " << student_num << " marks should be less than or equal to 100 :";
			cin >> mark_math;
			if (mark_math > 100 || mark_math < 0)
			{
				cout << "you have entered invalid number, please enter the correct marks" << endl;
				i--;
			}

		}
		if (student_num == 1)
		{
			arr_roll = new int[1];
			arr_roll[0] = roll_num;
			arr_cs = new int[1];
			arr_cs[0] = mark_cs;
			arr_math = new int[1];
			arr_math[0] = mark_math;
		}
		else
		{
			arr_roll = arrayofrollnum(arr_roll, student_num);
			arr_roll[student_num - 1] = roll_num;
			arr_cs = arrayofrollnum(arr_cs, student_num);
			arr_cs[student_num - 1] = mark_cs;
			arr_math = arrayofrollnum(arr_math, student_num);
			arr_math[student_num - 1] = mark_math;

		}


		for (int i = 0; i < 1; i++)
		{
			cout << "press Y/y to continue adding student data or press N/n to stop it: ";//press only one character
			cin >> a;
			if (a == 'Y' || a == 'y')
			{
				student_num++;
				size = student_num;
			}
			else if (a == 'N' || a == 'n')
			{
				cout << "entries are terminated" << endl;
			}
			else
			{
				cout << "you have entered invalid operator , please entred the valid operator" << endl;
				i--;
			}
		}
	}
	arr_percentage = array_percentage_num(arr_cs, arr_math, size);
	arr_grade = array_grade(arr_percentage, size);
	cout << endl << endl;
	templete_display(arr_roll, arr_cs, arr_math, arr_percentage, arr_grade, size);
	cout << endl << endl;
	cout << "if you want to perform further operation, then press Y/y or if you are not interested, then  press any other key :";
	cin >> b;
	while (b == 'Y' || b == 'y')
	{
		cout << "Press 1 to update Roll Number of a particular Student." << endl;
		cout << "Press 2 to update marks of a particular student for CS" << endl;
		cout << "Press 3 to update marks of CS for all students who are already enrolled" << endl;
		cout << "Press 4 to update marks for Mathematics." << endl;
		cout << "Press 5 to update marks of Mathematics for all students who are already enrolled." << endl;
		cout << "Press 6 to sort the data on the basis of generated percentages. The data must be sorted in ascending order." << endl;
		//cout << "Also make sure that all the record should be sorted on the basis on percentage." << endl;
		cout << "Press 7 to delete the record of a particular student" << endl;
		cout << "press 8 to clear previous console" << endl;
		int num;
		cin >> num;
		if (num == 1)
		{
			arr_roll = update_roll_num(arr_roll, size);
		}
		else if (num == 2)
		{
			arr_cs = update_cs_math(arr_roll, arr_cs, size);
			arr_percentage = array_percentage_num(arr_cs, arr_math, size);
			arr_grade = array_grade(arr_percentage, size);
		}
		else if (num == 3)
		{
			arr_cs = update_all_cs_math(arr_cs, size);
			arr_percentage = array_percentage_num(arr_cs, arr_math, size);
			arr_grade = array_grade(arr_percentage, size);
		}
		else if (num == 4)
		{
			arr_math = update_cs_math(arr_roll, arr_math, size);
			arr_percentage = array_percentage_num(arr_cs, arr_math, size);
			arr_grade = array_grade(arr_percentage, size);
		}
		else if (num == 5)
		{
			arr_math = update_all_cs_math(arr_math, size);
			arr_percentage = array_percentage_num(arr_cs, arr_math, size);
			arr_grade = array_grade(arr_percentage, size);
		}
		else if (num == 6)
		{
			sorting(arr_roll, arr_cs, arr_math, arr_percentage, arr_grade, size);
		}
		else if (num == 7)
		{
			cout << "enter student roll number to delete his record : ";
			int num2;
			cin >> num2;
			if (present(arr_roll, size, num2) == 1)
			{
				int index = 0;
				for (int i = 0; i < size; i++)
				{
					if (num2 == arr_roll[i])
						index = i;
				}
				arr_roll = deletion1(arr_roll, size, index);
				arr_cs = deletion1(arr_cs, size, index);
				arr_math = deletion1(arr_math, size, index);
				arr_percentage = deletion2(arr_percentage, size, index);
				arr_grade = deletion3(arr_grade, size, index);
				size = size - 1;

			}
			else
				cout << "roll number is not present" << endl;

		}
		else if (num == 8)
			system("cls");
		else
			cout << "you have enter invalid operator" << endl;
		cout << "latest output / updated output" << endl << endl;
		templete_display(arr_roll, arr_cs, arr_math, arr_percentage, arr_grade, size);
		cout << endl << endl;
		if (size != 0)
		{
			cout << "if you want to continue this programme , then press Y/y  or if you want to stop it ,then press N/n : ";
			cin >> b;
			if (b == 'N' || b == 'n')
			{
				b = 'N';
				cout << "This program is terminated" << endl;
			}
			else if (b == 'y' || b == 'Y')
			{
				//cout << "";
			}
			else
			{
				b = 'N';
				cout << "you have enterd invalide opretor and this programme is terminated" << endl;
			}
		}

		else
			break;
	}

	cout << "if you want to enter student name , then press 1  or if you are not interested then press other digit :";
	cin >> num_num;
	if (num_num == 1)
	{


		arr_name = new char* [size];
		cin.ignore();
		for (int i = 0; i < size; i++)
		{
			arr_name[i] = new char[20];
			cout << "enter the name of " << i + 1 << endl;
			cin.getline(arr_name[i], 20);
		}
		system("cls");
		fff = true;
		cout << "final display" << endl;
		final_templete_display(arr_roll, arr_cs, arr_math, arr_percentage, arr_grade, size, arr_name);

	}
	else
	{
		system("cls");
		cout << "final display" << endl;
		final_templete_display2(arr_roll, arr_cs, arr_math, arr_percentage, arr_grade, size);
	}
	cout << "Latest Record alsp stored in Data.txt" << endl;

	delete[] arr_roll;
	delete[] arr_cs;
	delete[] arr_math;
	delete[] arr_percentage;
	delete[] arr_grade;
	if (fff == true)
	{
		cout << "condiotion run" << endl;
		for (int i = 0; i < size; i++)
			delete[] arr_name[i];
		delete[]arr_name;
	}
	//system("pause");
	return 0;
}
int* arrayofrollnum(int* oldarr, int size)
{
	int* newarr = new int[size];
	for (int i = 0; i < size - 1; i++)
	{
		newarr[i] = oldarr[i];
	}
	delete[]oldarr;
	oldarr = NULL;
	return newarr;
}
double* array_percentage_num(int* arr_cs, int* arr_math, int size)
{
	double* array_cs = new double[size];
	double* array_math = new double[size];
	double* arr = new double[size];
	for (int i = 0; i < size; i++)
	{
		array_cs[i] = arr_cs[i];
		array_math[i] = arr_math[i];
		arr[i] = (array_cs[i] + array_math[i]) / 2;
	}
	return arr;
}
char* array_grade(double* arr_percentage, int size)
{
	char* grade = new char[size];
	for (int i = 0; i < size; i++)
	{
		if (arr_percentage[i] >= 91 && arr_percentage[i] <= 100)
		{
			grade[i] = 'A';
		}
		else if (arr_percentage[i] < 91 && arr_percentage[i] >= 75)
		{
			grade[i] = 'B';
		}
		else if (arr_percentage[i] < 75 && arr_percentage[i] >= 60)
		{
			grade[i] = 'C';
		}
		else if (arr_percentage[i] < 60 && arr_percentage[i] >= 50)
		{
			grade[i] = 'D';
		}
		else if (arr_percentage[i] < 50)
		{
			grade[i] = 'F';
		}
	}
	return grade;
}
void templete_display(int* arr_roll, int* arr_cs, int* arr_math, double* arr_percentage, char* arr_grade, int size)
{
	for (int i = 0; i < 46; i++)
	{
		cout << "**";
	}
	cout << endl;
	for (int i = 0; i < 46; i++)
	{
		cout << "**";
	}
	cout << endl;

	cout << "student number" << "\t" << "roll number" << "\t" << "cs marks" << "\t" << "math mark" << "\t" << "percentage" << "\t" << "grade";
	cout << endl;
	for (int i = 0; i < 46; i++)
	{
		cout << "--";
	}
	cout << endl << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "student:" << i + 1 << "\t" << arr_roll[i] << "\t\t" << arr_cs[i] << "\t\t" << arr_math[i] << "\t\t" << arr_percentage[i] << "\t\t" << arr_grade[i];
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < 46; i++)
	{
		cout << "==";
	}
	cout << endl;
	for (int i = 0; i < 46; i++)
	{
		cout << "~~";
	}
	cout << endl;

}
int* update_roll_num(int* arr_roll, int size)
{
	cout << "enter the student roll number :" << endl;
	int num;
	cin >> num;
	if (present(arr_roll, size, num) == true)
	{
		cout << "enter the new roll number" << endl;
		int num2;
		cin >> num2;
		for (int i = 0; i < size; i++)
		{
			if (arr_roll[i] == num)
			{
				arr_roll[i] = num2;
			}
		}
	}
	else
		cout << "entred roll number is not present" << endl;
	return arr_roll;
}
bool present(int* arr, int size, int num)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num)
		{
			return 1;
		}
	}
	return 0;
}
int* update_cs_math(int* arr_roll, int* arr, int size)
{
	cout << "enter the student roll number whose marks you want to updated :";
	int num;
	cin >> num;
	if (present(arr_roll, size, num) == 1)
	{
		for (int i = 0; i < 1; i++)
		{
			cout << "entered new marks:";
			int num2;
			cin >> num2;
			if (num2 >= 0 && num2 <= 100)
			{
				for (int j = 0; j < size; j++)
				{
					if (num == arr_roll[j])
						arr[j] = num2;
				}
			}
			else
			{
				cout << "you have enter invalid number, please enter the correct marks" << endl;
				i--;
			}
		}
	}
	else
		cout << "entred roll number is not present" << endl;
	return arr;
}
int* update_all_cs_math(int* arr, int size)
{
	int num;
	for (int i = 0; i < size; i++)
	{
		cout << "enter the new marks of student " << i + 1 << " :";
		cin >> num;
		if (num >= 0 && num <= 100)
			arr[i] = num;

		else
		{
			cout << "you have enterd invalide marks, please enter the correct marks" << endl;
			i--;
		}

	}
	return arr;
}
void sorting(int* arr_roll, int* arr_cs, int* arr_math, double* arr_percentage, char* arr_grade, int size)
{
	double num_percent = 0;
	int roll = 0;
	char temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr_percentage[i] > arr_percentage[j])
			{
				num_percent = arr_percentage[i];
				arr_percentage[i] = arr_percentage[j];
				arr_percentage[j] = num_percent;

				roll = arr_cs[i];
				arr_cs[i] = arr_cs[j];
				arr_cs[j] = roll;

				roll = arr_math[i];
				arr_math[i] = arr_math[j];
				arr_math[j] = roll;

				roll = arr_roll[i];
				arr_roll[i] = arr_roll[j];
				arr_roll[j] = roll;

				temp = arr_grade[i];
				arr_grade[i] = arr_grade[j];
				arr_grade[j] = temp;

			}

		}
	}
}

int* deletion1(int* old_arr, int size, int index)
{
	int x = 0;
	int* arr = new int[size - 1];
	for (int i = 0; i < size; i++)
	{
		if (index != i)
		{
			arr[x] = old_arr[i];
			x++;
		}
	}
	delete[] old_arr;
	return arr;
}
double* deletion2(double* old_arr, int size, int index)
{
	int x = 0;
	double* arr = new double[size - 1];
	for (int i = 0; i < size; i++)
	{
		if (index != i)
		{
			arr[x] = old_arr[i];
			x++;
		}
	}
	delete[] old_arr;
	return arr;
}
char* deletion3(char* old_arr, int size, int index)
{
	int x = 0;
	char* arr = new char[size - 1];
	for (int i = 0; i < size; i++)
	{
		if (index != i)
		{
			arr[x] = old_arr[i];
			x++;
		}
	}
	delete[] old_arr;
	return arr;
}
void final_templete_display(int* arr_roll, int* arr_cs, int* arr_math, double* arr_percentage, char* arr_grade, int size, char** arr_name)
{
	ofstream fout;
	fout.open("data.txt");
	for (int i = 0; i < 49; i++)
	{
		cout << "**";
		fout << "**";
	}
	cout << endl;
	fout << endl;
	for (int i = 0; i < 49; i++)
	{
		cout << "**";
		fout << "**";
	}
	cout << endl;
	fout << endl;
	cout << "student number" << "\t" << "roll number" << "\t" << "student name" << "\t\t" << "cs marks" << "\t" << "math mark" << "\t" << "percentage" << "\t" << "grade";
	fout << "student number" << "\t" << "roll number" << "\t" << "student name" << "\t\t" << "cs marks" << "\t" << "math mark" << "\t" << "percentage" << "\t" << "grade";
	cout << endl;
	fout << endl;
	for (int i = 0; i < 49; i++)
	{
		cout << "--";
		fout << "--";
	}
	cout << endl << endl;
	fout << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "student:" << i + 1 << "\t" << arr_roll[i] << "\t\t" << arr_name[i] << "\t\t" << arr_cs[i] << "\t\t" << arr_math[i] << "\t\t" << arr_percentage[i] << "\t\t" << arr_grade[i];
		fout << "student:" << i + 1 << "\t" << arr_roll[i] << "\t\t" << arr_name[i] << "\t\t" << arr_cs[i] << "\t\t" << arr_math[i] << "\t\t" << arr_percentage[i] << "\t\t" << arr_grade[i];
		cout << endl;
		fout << endl;
	}
	cout << endl << endl;
	fout << endl << endl;
	for (int i = 0; i < 49; i++)
	{
		cout << "==";
		fout << "==";
	}
	cout << endl;
	fout << endl;
	for (int i = 0; i < 49; i++)
	{
		cout << "~~";
		fout << "~~";
	}
	cout << endl;
	fout << endl;

}
void final_templete_display2(int* arr_roll, int* arr_cs, int* arr_math, double* arr_percentage, char* arr_grade, int size)
{
	ofstream fout;
	fout.open("data.txt");
	for (int i = 0; i < 46; i++)
	{
		cout << "**";
		fout << "**";
	}
	cout << endl;
	fout << endl;
	for (int i = 0; i < 46; i++)
	{
		cout << "**";
		fout << "**";
	}
	cout << endl;
	fout << endl;
	cout << "student number" << "\t" << "roll number" << "\t" << "cs marks" << "\t" << "math mark" << "\t" << "percentage" << "\t" << "grade";
	fout << "student number" << "\t" << "roll number" << "\t" << "cs marks" << "\t" << "math mark" << "\t" << "percentage" << "\t" << "grade";
	cout << endl;
	fout << endl;
	for (int i = 0; i < 46; i++)
	{
		cout << "--";
		fout << "--";
	}
	cout << endl << endl;
	fout << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "student:" << i + 1 << "\t" << arr_roll[i] << "\t\t" << "\t" << arr_cs[i] << "\t\t" << arr_math[i] << "\t\t" << arr_percentage[i] << "\t\t" << arr_grade[i];
		fout << "student:" << i + 1 << "\t" << arr_roll[i] << "\t\t" << "\t" << arr_cs[i] << "\t\t" << arr_math[i] << "\t\t" << arr_percentage[i] << "\t\t" << arr_grade[i];
		cout << endl;
		fout << endl;
	}
	cout << endl << endl;
	fout << endl << endl;
	for (int i = 0; i < 46; i++)
	{
		cout << "==";
		fout << "==";
	}
	cout << endl;
	fout << endl;
	for (int i = 0; i < 46; i++)
	{
		cout << "~~";
		fout << "~~";
	}
	cout << endl;
	fout << endl;

}