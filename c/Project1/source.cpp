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
	
	

}

void appendNewLine(const char* file) {

	std::ofstream out(file, std::ios_base::app);
	const char newLine[] = "\n";
	for (char c : newLine)
	{
		out.put(c);
	}
}

void writeChar(const char* file, char c)
{
	std::ofstream out(file, std::ios_base::app);
	out.put(c);

}


void print()
{
	std::ifstream in("temp.txt");
	saff::print("\n");
	for (char c = in.get(); in.good(); c = in.get())
	{
		_putch(c);
	}
}

void save(const char* file)
{
	std::ifstream in("temp.txt");
	for (char c = in.get(); in.good(); c = in.get())
	{
		writeChar(file, c);
	}
}

void activatedb()
{
	char buffer[256];
	char current[256];
	int toggle = 1;

	while (toggle == 1)
	{
		saff::print("\n(l)oad (s)ave (a)dd (q)uit or (p)rint? \n");
		saff::read(buffer, 256);

		switch (buffer[0])
		{
		case 'a':
			saff::print("\nEnter name: ");
			write("temp.txt");
			saff::print("\nEnter amount: ");
			saff::read(buffer, 256);

			for (int i = 0; i < saff::str2int(buffer); i++)
			{
				writeChar("temp.txt", '=');
			}
			appendNewLine("temp.txt");
			break;
		case 'q':
			clear("temp.txt");
			toggle = 0;
			//return 0;
			break;
		case 's':
			saff::print("\nEnter file name: ");
			saff::read(buffer, 256);
			clear(buffer);
			save(buffer);

			break;
		case 'p':
			print();
			break;
		case 'l':
			clear("temp.txt");
			saff::print("\nEnter file name: ");
			saff::read(buffer, 256);
			std::ifstream in(buffer);
			for (char c = in.get(); in.good(); c = in.get())
			{
				writeChar("temp.txt", c);
			}
			break;

		}
	}




	while (!_kbhit());
}


int main()
{
	std::ifstream warp_file("warp.txt");
	constexpr int file_size = 3359405 + 1;
	char* warp_string = new char[file_size];

	//read file into array
	int i = 0;
	for (char c = warp_file.get(); warp_file.good(); c = warp_file.get())
	{
		warp_string[i++] = c;
	}
	//i = num characters
	warp_string[i] = 0;

	//display actual number of bytes copied into array
	char buffer[256];
	saff::int2str(i, buffer, sizeof(buffer));
	saff::print(buffer);

	delete [] warp_string;

	while (!_kbhit());
	return 0;
}