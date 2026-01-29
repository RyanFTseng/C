#include <conio.h>
#include <fstream>>

namespace saff
{
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
		//read keyboard input until non character key is pressed or max buffer size reached
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
}


void clear(const char* file)
{
	std::ofstream out(file);
}


void write(const char* file) 
{
	std::ofstream out(file, std::ios_base::app);

	for (char c = _getch(); c != 13; c = _getch())
	{
		_putch(c);
		out.put(c);
	}
	const char newLine[] = "\n";
	for (char c : newLine) 
	{
		if(c==0)
		{
			out.put(c);
		}
	}
	

}


int main()
{
	char buffer[256];
	char current[256];
	saff::print("(l)oad (s)ave (a)dd (q)uit or (p)rint? ");
	saff::read(buffer, 256);
	switch(buffer[0])
	{ 
		case 'a':
			saff::print("\n Enter Name: ");
			write("temp.txt");
			break;
		case 'q':
			clear("temp.txt");
			return 0;
			
	}


	std::ifstream in("wah.txt");
	if (!in)
	{
		saff::print("failed to open file");
		while (!_kbhit());
		return -1;
	}
	
	in.seekg(0, std::ios_base::end);
	const int length = in.tellg();
	in.seekg(0, std::ios_base::beg);

	for (char c = in.get(); in.good(); c = in.get())
	{
		_putch(c);
	}

	if (in.bad())
	{
		saff::print("\nerror");
	}
	else if (in.eof())
	{
		saff::print("\nreached end of file");
	}
	else
	{
		saff::print("\nfailure");
	}

	std::ofstream out("out.txt");

	for (char c = _getch(); c !=13; c = _getch())
	{
		_putch(c);
		out.put(c);
	}

	

	while (!_kbhit());
	return 0;
}