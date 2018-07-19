#include "idle_clicker_helper.h"

bool shouldRun = true;   //a boolean is a variable is basically "yes" or "no", otherwise know as "true" or "false"

int bits = 0;
int bytes = 0;
int kiloBytes = 0;

int cpus = 0;
int gpus = 0;
int chassis = 0;

int cost[] = { 16, 32, 64, 128 };

void conversion()
{
	while (bits >= 8)
	{
		bits = bits - 8; //or "bits -= 8;"
		bytes++;
	}
	while (bytes >= 1024)
	{
		bytes -= 1024;
		kiloBytes++;
	}
}

void update()	//this is where the bit adding from cpus, gpus, etc. gets programmed
{
	bits += cpus * 1;

	bits += gpus * 5;

	bytes += chassis * 4;
}

void draw() //this is where the outputs are programmed
{
	system("cls");
	std::cout << "You have " << bits << " bits!" << std::endl;
	if (bytes > 0)
	{
		std::cout << "You Have " << bytes << " bytes!" << std::endl;
	}

	if (kiloBytes > 0)
	{
		std::cout << "You Have " << kiloBytes << " kilobytes!" << std::endl;
	}

	if (cpus > 0)
	{
		std::cout << "\nYou Have " << cpus << " CPUs!" << std::endl;
	}

	if (gpus > 0)
	{
		std::cout << "You Have " << gpus << " GPUs!" << std::endl;
	}

	if (chassis > 0)
	{
		std::cout << "You Have " << chassis << " cases!" << std::endl;
	}
}

void handleKey(char c)               //this is where the keypresses are used
{
	//std::cout << "You pressed " << c << std::endl;
	//if the user hits "Q", the program will terminate
	if (c == 'q')
	{
		std::cout << "Should quit!" << std::endl;
		shouldRun = false;
	}

	if (c == '1')
	{
		bits++;

		conversion();

		draw();
	}

	if (c == '2')
	{
		if (bytes >= cost[0])
		{
			bytes -= cost[0];
			cpus++;
			draw();
		}
		else
		{
			std::cout << "You need 16 bytes to buy a CPU, you need " << cost[0] - bytes << " more bytes to buy a CPU!" << std::endl;
		}
	}

	if (c == '3')
	{
		if (bytes >= cost[1])
		{
			bytes -= cost[1];
			gpus++;
			draw();
		}
		else if (kiloBytes)
		{
			kiloBytes--;
			gpus++;
			draw();
		}
		else
		{
			std::cout << "You need 32 bytes to buy a GPU, you need " << cost[1] - bytes << " more bytes to buy a GPU!" << std::endl;
		}
	}

	if (c == '4')
	{
		if (bytes >= cost[2])
		{
			bytes -= cost[2];

			chassis++;
			draw();
		}
		else if (kiloBytes > 0)
		{
			kiloBytes--;
			chassis++;
			draw();
		}
		else
		{
			std::cout << "You need 64 bytes to buy a case, you need " << cost[2] - bytes << " more bytes to buy a case!" << std::endl;
		}
	}
}

int main()
{

	AsyncKeyboard::setupKeyboard(handleKey);

	while (shouldRun)
	{
		update();

		conversion();

		draw();
		std::this_thread::sleep_for(1s);
	}

	AsyncKeyboard::shutdown();

	return 0;
}