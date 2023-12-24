#include <iostream>
using namespace std;

void mainOne()
{
	bool isLive = true;
	while (isLive)
	{
		int selectNum;
		cout << "Please, Select a number to display memory size data types: \n";
		cout << "\t 1 - int\n";
		cout << "\t 2 - short int\n";
		cout << "\t 3 - long int\n";
		cout << "\t 4 - float\n";
		cout << "\t 5 - double\n";
		cout << "\t 6 - long double\n";
		cout << "\t 7 - char\n";
		cout << "\t 8 - bool\n";
		cout << "Number: ";
		cin >> selectNum;

		switch (selectNum)
		{
		case 1:
			cout << "size int: " << sizeof(int) << " bytes\n";
			break;
		case 2:
			cout << "size short int: " << sizeof(short int) << " bytes\n";
			break;
		case 3:
			cout << "size long int: " << sizeof(long  int) << " bytes\n";
			break;
		case 4:
			cout << "size float: " << sizeof(float) << " bytes\n";
			break;
		case 5:
			cout << "size double: " << sizeof(double) << " bytes\n";
			break;
		case 6:
			cout << "size long double: " << sizeof(long double) << " bytes\n";
			break;
		case 7:
			cout << "size char: " << sizeof(char) << " bytes\n";
			break;
		case 8:
			cout << "size bool: " << sizeof(bool) << " bytes\n";
			break;
		default:
			cout << "Error select number\n";
			break;
		}
		cout << "\n";

		int numberUserInt, tempNumber;
		cout << "Enter please value int number for set some value bit: ";
		cin >> numberUserInt;
		tempNumber = numberUserInt;
		int order = sizeof(numberUserInt) * 8 - 1;
		int mask = 1 << order;

		cout << "Number value: " << numberUserInt << "\n"
			<< "Number link: " << &numberUserInt << "\n"
			<< "Count rank: " << order << "\n"
			<< "Bitwise comparison mask: " << mask << "\n";

		for (int i = 0; i <= order; i++)
		{
			cout << ((numberUserInt & mask) ? 1 : 0);
			numberUserInt <<= 1;
			if (!i || (i + 1) % 8 == 0)
			{
				cout << " ";
			}
		}
		cout << "\n\n";

		numberUserInt = tempNumber;

		int positionUser;
		cout << "Enter please position bit starting from one: ";
		cin >> positionUser;

		int numberBit;
		cout << "Enter please number bit for change: ";
		cin >> numberBit;

		cout << "Enter please position bit = " << positionUser << " for set on " << numberBit << ".\n\n";
		switch (numberBit)
		{
		case 0:
			numberUserInt = (numberUserInt ^ (1 << positionUser - 1));
			break;
		case 1:
			numberUserInt = (numberUserInt | (1 << positionUser - 1));
			break;
		default:
			cout << "You entered a bit different from zero or one";
			break;
		}

		cout << "Number value: " << numberUserInt << "\n"
			<< "Number link: " << &numberUserInt << "\n"
			<< "Count rank: " << order << "\n"
			<< "Bitwise comparison mask: " << mask << "\n";

		for (int i = 0; i <= order; i++)
		{
			cout << ((numberUserInt & mask) ? 1 : 0);
			numberUserInt <<= 1;
			if (!i || (i + 1) % 8 == 0)
			{
				cout << " ";
			}
		}
		cout << "\n\n";


		float tempFloat;
		union binaryRepresFloat {
			int unionInt;
			float unionFloat;
		};

		binaryRepresFloat brf;
		cout << "Enter float number for display binary representation in memory: ";
		cin >> brf.unionFloat;
		tempFloat = brf.unionFloat;
		for (int i = 0; i <= order; i++) {
			cout << ((brf.unionInt & mask) ? 1 : 0);
			brf.unionInt <<= 1;
			if (!i || (i + 1) % 8 == 0) {
				cout << " ";
			}
		};
		cout << "\n\n";
		brf.unionFloat = tempFloat;

		cin.clear();

		cout << "Enter please position bit starting from one: ";
		cin >> positionUser;

		cout << "Enter please number bit for change: ";
		cin >> numberBit;

		cout << "Enter please position bit = " << positionUser << " for set on " << numberBit << ".\n\n";
		switch (numberBit)
		{
		case 0:
			brf.unionInt = (brf.unionInt ^ (1 << positionUser - 1));
			break;

		case 1:
			brf.unionInt = (brf.unionInt | (1 << positionUser - 1));
			break;
		default:
			cout << "You entered a bit different from zero or one";
			break;
		}

		for (int i = 0; i <= order; i++) {
			cout << ((brf.unionInt & mask) ? 1 : 0);
			brf.unionInt <<= 1;
			if (!i || (i + 1) % 8 == 0) {
				cout << " ";
			}
		};
		cout << "\n\n";


		double tempDouble;
		union binaryRepresDouble {
			int unionIntArr[2];
			double unionDouble;
		};
		binaryRepresDouble brd;
		cout << "Enter double number for display representation in memory: ";
		cin >> brd.unionDouble;
		tempDouble = brd.unionDouble;
		int orderArray = sizeof(brd.unionIntArr) * 4 - 1;
		int sizeIntegerArray = (sizeof(brd.unionIntArr) / sizeof(*brd.unionIntArr));
		mask = 1 << orderArray;

		swap(brd.unionIntArr[0], brd.unionIntArr[1]);

		for (int i = 0; i < sizeIntegerArray; i++) {
			for (int j = 0; j <= orderArray; j++) {
				cout << ((brd.unionIntArr[i] & mask) ? 1 : 0);
				brd.unionIntArr[i] <<= 1;
				if (!i && j == 11 || !i && !j || !i && j == 31) {
					cout << " ";
				}
			}
		}
		brd.unionDouble = tempDouble;
		cout << "\n\n";

		swap(brd.unionIntArr[0], brd.unionIntArr[1]);

		cin.clear();

		cout << "Enter please position bit starting from one: ";
		cin >> positionUser;

		cout << "Enter please number bit for change: ";
		cin >> numberBit;

		cout << "Enter please position bit = " << positionUser << " for set on " << numberBit << ".\n\n";
		switch (numberBit)
		{
		case 0:
			if (positionUser - 1 <= 32)
				brd.unionIntArr[1] = brd.unionIntArr[1] ^ (1 << positionUser - 1);
			else
				brd.unionIntArr[0] = brd.unionIntArr[0] ^ (1 << (positionUser - 1 - 32));

			break;
		case 1:
			if (positionUser - 1 <= 32)
				brd.unionIntArr[1] = brd.unionIntArr[1] | (1 << positionUser - 1);
			else
				brd.unionIntArr[0] = brd.unionIntArr[0] | (1 << (positionUser - 1 - 32));

			break;
		default:
			cout << "You entered a bit different from zero or one";
			break;
		}

		for (int i = 0; i < sizeIntegerArray; i++) {
			for (int j = 0; j <= orderArray; j++) {
				cout << ((brd.unionIntArr[i] & mask) ? 1 : 0);
				brd.unionIntArr[i] <<= 1;
				if (!i && j == 11 || !i && !j || !i && j == 31) {
					cout << " ";
				}
			}
		}
		cout << "\n\n";

		int decisionUser;
		cout << "Do you want continue proccess working programm?\n";
		cout << "\t 1 - Yes\n";
		cout << "\t 2 - No\n";
		cin >> decisionUser;
		switch (decisionUser)
		{
		case 1:
			cout << "You select number 1. Let's start over!";
			system("cls");
			break;
		case 2:
			cout << "You select number 2. Finishing the proccess!";
			isLive = false;
			break;
		default:
			cout << "Error select number\n";
			break;
		}
	}
}