#include <conio.h>

int sum(int* arr, int size)
{
	int ans = 0;
	for (int* i = arr + size; arr < i; arr++)
	{
		ans += *arr;
	}
	return ans;
}

void reverse(int* left, int size)
{
	int* right = left + size - 1;
	while (left < right)
	{
		int temp = right[0];
		right[0] = left[0];
		left[0] = temp;

		left++;
		right--;
	}
}


void print(const char* s)
{
	for (; *s != 0; s++)
	{
		_putch(*s);
	}
}


void read(char* buf, int maxSize)
{
	const char* const pEnd = buf + maxSize;
	for (char c = _getch(); c != 13 && (buf + 1 < pEnd); c = _getch(), buf++)
	{
		_putch(c);
		*buf = c;
	}
	*buf = 0;
}

int str2int(const char* s)
{
	//scan to start point
	const char* p = s;
	for (; *p >= '0' && *p <= '9'; p++);
	p--;
	int val = 0;
	int place = 1;

	//convert place values and accumulate
	for (; p >= s; p--)
	{
		val += (*p - '0') * place;
		place *= 10;
	}

	return val;
}


void strrev(char* pl)
{
	char* pr = pl;
	for (; *pr != 0; pr++);
	pr--;

	for (; pl < pr; pl++, pr--)
	{
		const char temp = *pl;
		*pl = *pr;
		*pr = temp;
	}


}

void int2str(int i, char* buf, int size)
{
	char* const pStart = buf;
	char* const pEnd = buf + size;
	for (; i > 0 && buf + 1 < pEnd; i /= 10, buf++)
	{

		*buf = '0' + i % 10;
	}
	*buf = 0;
	strrev(pStart);
}

int fib(int f)
{
	if (f <= 1) {
		return f;
	}
	return fib(f - 2) + fib(f - 1);
}

int main()
{

	print("Enter number? ");
	char answer[69];
	read(answer, 69);

	const int count = str2int(answer);
	print("\n");

	int a = fib(count);
	char test[100];
	int2str(a, answer, 100);
	print(answer);

	while ((!_kbhit));
	return 0;
}