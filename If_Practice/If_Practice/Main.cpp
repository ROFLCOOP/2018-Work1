#include <iostream>
#include <random>
#include <ctime>

void calculator()
{
	int numberOne = 0;
	int numberTwo = 0;
	char operation = 0;

	char quit = 'n';

	std::cout << "Enter first number: ";
	std::cin >> numberOne;



	while (quit == 'n')
	{
		std::cout << "Enter second number: ";
		std::cin >> numberTwo;

		std::cout << "Enter operation you'd like to do: ";
		std::cin >> operation;

		switch (operation)
		{
		case '+':
		{
			std::cout << numberOne << " + " << numberTwo << " = " << numberOne + numberTwo << std::endl;
			break;
		}
		case '-':
		{
			std::cout << numberOne << " - " << numberTwo << " = " << numberOne - numberTwo << std::endl;
			break;
		}
		case '*':
		{
			std::cout << numberOne << " * " << numberTwo << " = " << numberOne * numberTwo << std::endl;
			break;
		}
		case '/':
		{
			std::cout << numberOne << "/" << numberTwo << " = " << numberOne / numberTwo << std::endl;
			break;
		}
		default:
		{
			std::cout << "WRONG!\n";
		}
		}

		std::cout << "Would you like to quit?\n";
		std::cin >> quit;
	}
}

void ifTest()
{
	bool isHealthy = true; //or false
	int currentAmmo = 10;

	bool shouldAttack = currentAmmo > 3 && isHealthy;

	
	if (shouldAttack)  //should only attack with more than 3 ammo
	{
		std::cout << "Shoot the bad guy!/n";
	}
	else
	{
		std::cout << "We need to fall back!\n";
	}
}




int randomBetween(int min, int max)
{
	if (min == max)
	{
		return min;
	}
	else if (min > max)
	{
		randomBetween(max, min);
	}

	int range = max - min;

	int randomValue = rand() % (range + 1);
	randomValue += min;

	return randomValue;
}

int doAttack(int curArmour, int curAccuracy, int curDamage) //Two Knights Fighting, where the health and armour are of the defending knight,
{																		   //and the accuracy and damage are of the attacking knight.
	int randHit = randomBetween(1, curAccuracy);
	int randAC = randomBetween(1, curArmour);

	std::cout << randHit << " Attack VS " << randAC << " AC\n";

	if (randHit >= randAC)
	{
		int randDamage = randomBetween(1, curDamage);
		std::cout << "The defending knight was hit for " << randDamage << " damage!\n";
		return randDamage;
	}
	else
	{
		std::cout << "The attacking missed\n";
		return 0;
	}
}

void draw(int knightOne, int knightTwo)
{
	std::cout << "\nSir Francis:\t" << knightOne << "\nSir Peter:\t" << knightTwo << std::endl;
}

int main()
{
	//char orsomething = 'y';
	//while (orsomething == 'y')
	//{
	//	int randomValue = randomBetween(1, 10);
	//
	//	std::cout << randomValue << std::endl;
	//	std::cin >> orsomething;
	//}
	//calculator();
	//ifTest();
	bool yourTurn = true;
	bool surrender = false;

	char action = 0;
	//Knight One: Francis
	//int knightOneHealth = 100;
	//int knightOneDamage = 8;
	//int knightOneAccuracy = 20;
	//
	////Knight One: Peter
	//int knightTwoHealth = 100;
	//int knightTwoDamage = 8;
	//int knightTwoAccuracy = 20;

	int knightStats[2][4] = { {100, 20, 20, 8},   //Identifier(in future), Health, Armour, Accuracy, Damage
							  {100, 20, 20, 8} };
	

	std::cout << "Sir Francis Challenges Sir Peter to a duel!\n\nSir Francis has " << knightStats[0][0] << " hit points!\nSir Peter Has " << knightStats[1][0] << " hitspoints\n";

	std::cout << "\nPress A for Attack\nPress D for Defend\nPress S for Surrender\n\n";
	system("pause");

	//Attacking Phase
	while (knightStats[0][0] > 0 && knightStats[1][0] > 0 && !surrender)
	{
	knightStats[0][3] = 20;

		
		if (!surrender)
		{
			std::cout << "\nSir Francis's Turn!\n";
			std::cin >> action;
			switch (action)
			{
				case 'a':
				case 'A':
				{
					std::cout << "\nSir Francis attacks!\n";
					knightStats[1][0] -= doAttack(knightStats[1][1], knightStats[0][2], knightStats[0][3]); //if the attack hits, knight health = knight health - damage roll

					if (knightStats[1][0] < 0)
					{
						knightStats[1][0];
					}
					draw(knightStats[0][0], knightStats[1][0]);
					
					break;
				}
				case 'd':
				{
					std::cout << "Sir Francis Defends for this turn";
					knightStats[0][1] += 10;
					break;
				}
				case 's':
				{
					std::cout << "Sir Francis: I surrender! You have bested me!\n";
					surrender = true;
					break;
				}
				
			}
		}
		if(!surrender && knightStats[1][0] > 0)
		{
			std::cout << "\nSir Peter's Turn!\n";
			system("pause");
			std::cout << "\nSir Peter attacks!\n";
			knightStats[0][0] -= doAttack(knightStats[0][1], knightStats[1][2], knightStats[1][3]);
			if (knightStats[0][0] < 0)
			{
				knightStats[0][0] = 0;
			}
			draw(knightStats[0][0], knightStats[1][0]);
		}
		
	}

	system("pause");
	return 0;
}