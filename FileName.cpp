#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;



int year(int day_1, int month_1, int year_1, int day_2, int month_2, int year_2);

float Srednee(float arr[], int size);

void Fill(float arr[], int SIZE);

void PlusMinusZero(float arr[], int size);

void Bulls_and_cows();

int Bull( int &sum, int arr[]);

int Matrix();



int MaxDelit(int num1, int num2);

int Max_delitel(int num1, int num2, int small1);

int main() {
	setlocale(LC_ALL, "ru");

	cout << year(13, 4, 2024,9,5,1945)<<endl;
	cout << Matrix()<<endl;
	cout<<MaxDelit(72,18);

	Bulls_and_cows();//быки и коровы

	return 0;
}


int year(int day_1, int month_1, int year_1, int day_2, int month_2, int year_2) {

	int all_day_1 = 0, all_day_2 = 0, year, year_now = year_2, all_day, year_razn = 0, day_razn = 0;

	year = year_1 - year_2 - 1;
	for (int i = month_2 + 1; i < 13; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			all_day_2 += 31;
		}
		else if (i == 4 || i == 6 || i == 9 || i == 11) {
			all_day_2 += 30;
		}
		else {
			if (year_now % 4 == 0) {
				all_day_2 += 29;
			}
			else {
				all_day_2 += 28;
			}

		}


	}
	year_now = year_1;
	for (int i = 0; i < month_1 - 1; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) {
			all_day_1 += 31;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10) {
			all_day_1 += 30;
		}
		else {
			if (year_now % 4 == 0) {
				all_day_1 += 29;
			}
			else {
				all_day_1 += 28;
			}

		}


	}
	for (int i = year_2; i < year_1; i++)
	{
		if (i % 4 == 0)
		{
			year_razn++;
		}
	}
	if (month_2 == 1 || month_2 == 3 || month_2 == 5 || month_2 == 7 || month_2 == 8 || month_2 ==  10|| month_2 == 12) {
		day_razn = 31 - day_2;
	}
	else if (month_2 == 4 || month_2 == 6 || month_2 == 9 || month_2 == 11) {
		day_razn = 30 - day_2;
	}
	else {
		if (month_2 % 4 == 0) {
			day_razn = 29 - day_2;
		}
		else {
			day_razn = 28 - day_2;
		}


	}
		all_day = all_day_1 + all_day_2 + year * 365 + year_razn + day_1 + day_razn;
		return all_day;
}

float Srednee(float arr[], int size) {
	float sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += i;



	}
	return sum / size;

}

void Fill(float arr[], int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = i - 2;
	}


}



void PlusMinusZero(float arr[], int size)
{
	int plus = 0, minus = 0, zero = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0) {
			plus++;
		}
		else if (arr[i] == 0) {
			zero++;
		}
		else {
			minus++;
		}

	}
	cout << "Больше 0: " << plus << endl;
	cout << "Меньше 0: " << minus << endl;
	cout << "Равно 0: " << zero << endl;

}

void Bulls_and_cows()
{
	srand(time(NULL));
	int number = rand() % 9001 + 1000;
	int sum = 0;
	const int SIZE = 4;
	int arr[SIZE];
	cout << endl << number;
	for (int i = 0; i < SIZE; i++)
	{
		if (i == 0)
		{

			arr[i] = number / pow(10, 3 - i);
		}
		else if (i == 1) {
			arr[i] = number / pow(10, 3 - i) - arr[i - 1] * 10;


		}
		else if (i == 2)
		{
			arr[i] = number / pow(10, 3 - i) - (arr[i - 1] * 10 + arr[i - 2] * 100);

		}
		else if (i == 3)
		{
			arr[i] = number - (arr[i - 3] * 1000 + arr[i - 2] * 100 + arr[i - 1] * 10);

		}
	}
	cout << endl;


	Bull( sum,arr);
	cout <<endl<<"Количество попыток: " << sum;
	cout << endl << "Загданное число: " << number;

}

int Matrix() {//я не понял зачем перегружать и как перегружать
	const int width = 5;
	const int height = 5;
	int max = 0;
	int min = 255555544;
	int arr[width][height]{ {},{} } ;
	int min_str = 0,max_str = 0;


	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (i == 0&&j==0)
			{
				arr[i][j] = 0;

			}
			else {
				arr[i][j] = arr[i][j - 1] + 1;
			}
		}
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == i) {
				if (min > arr[i][j]) {
					min = arr[i][j];
				
				}
				else if (max < arr[i][j]) {
					max = arr[i][j];
				}

			}
		}
	}

	cout << "Максимальное " << max;
	cout << "Минимальное " << min;
	





	return 0;

}


int MaxDelit(int num1, int num2)//делитель
{
	if (num1>num2)
	{

		return Max_delitel(num1, num2, num2);
	}
	else{

	return Max_delitel(num1, num2, num1);
	}
}

int Max_delitel(int num1, int num2, int small1) {
	int max, min=small1, small;
	if (num1 > num2)
	{
		max = num1;//находим макс и мин число

		small = num2;
	}
	else
	{
		max = num2;

		small = num1;
	}


	if (min % small == 0 && max % small == 0)
	{
		return small;
	}
	else
	{
		if (num2 < num1) {
			Max_delitel(num1, num2 - 1,small1);//уменьшаем 1 из чисел
		}
		else {
			Max_delitel(num1 - 1, num2, small1);//уменьшаем 1 из чисел

		}
	}
}

int Bull( int &sum, int arr[]) {
	int number;
	int place = 0, guessed = 0;
	const int SIZE = 4;
	int num_arr[SIZE];

	cout <<endl<< "Введите четырехзначное число: ";
	cin >> number;
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{

			num_arr[i] = number / pow(10, 3 - i);
		}
		else if (i == 1) {
			num_arr[i] = number / pow(10, 3 - i) - num_arr[i - 1] * 10;


		}
		else if (i == 2)
		{
			num_arr[i] = number / pow(10, 3 - i) - (num_arr[i - 1] * 10 + num_arr[i - 2] * 100);

		}
		else if (i == 3)
		{
			num_arr[i] = number - (num_arr[i - 3] * 1000 + num_arr[i - 2] * 100 + num_arr[i - 1] * 10);

		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		cout << num_arr[i] << " ";
	}

	for (int i = 0; i < SIZE; i++)//есть ли вообще
	{
		if (num_arr[0] == arr[i])   
		{
			guessed++;
		}
		else if (num_arr[1] == arr[i])
		{
			guessed++;
		}
		else if (num_arr[2] == arr[i])
		{
			guessed++;
		}
		else if (num_arr[3] == arr[i])
		{
			guessed++;
		}
	}
	if (num_arr[0] == arr[0])//на месте ли
	{
		place++;
	}
	if (num_arr[1] == arr[1])
	{
		place++;
	}
	if (num_arr[2] == arr[2])
	{
		place++;
	}
	if (num_arr[3] == arr[3])
	{
		place++;
	}
	
	guessed -= place;
	if (place == 3)
	{
		guessed = 0;
	}
	cout << endl << "угаднно: "<<guessed;
	cout << endl << "На месте: " << place;
	sum++;
	if (place == 4)
	{
		return place;
	}
	Bull(sum, arr);


}