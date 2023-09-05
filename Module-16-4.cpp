﻿/*Задание 4. Механическое пианино
Что нужно сделать
Создайте упрощённую модель механического пианино. Всего у данного пианино семь клавиш, которые соответствуют семи нотам.
Каждая клавиша кодируется уникальной битовой маской, которая записывается в enum.
В начале программы пользователь вводит мелодию. Ввод осуществляется с помощью цифр на клавиатуре, от 1 до 7 включительно (от ноты до до ноты си).
В результате из чисел может быть составлена любая комбинация нот. К примеру 512 или 154. После ввода комбинации вводится следующая.
Всего таких комбинаций нот — 12. Как только все комбинации были введены пользователем, мелодия проигрывается.
Для этого каждая комбинация нот последовательно выводится на экран. Однако на этот раз она печатается «красиво», то есть все ноты указываются словами, а не цифрами.
При этом слова разделяются пробелами.

Рекомендации
Для вычленения отдельных символов-цифр из строки с нотами используйте оператор индексации строки.
Для дальнейшей конвертации символа в строку используйте соответствующий конструктор.
Для простоты, чтобы из индекса ноты получить саму ноту-флаг из enum, используйте оператор сдвига.
Общая формула такова: 1 << индекс ноты (начинается с нуля). К примеру, 1 << 0 — битовый флаг ноты до, 1 << 6 — битовая маска ноты си.

Перечисление, хранящее ноты, имеет вид:

enum note
{
	DO = 1,
	RE = 2,
	MI = 4,
	FA = 8,
	SOL = 16,
	LA = 32,
	SI = 64
};

Соответственно, когда мы проходим по всей мелодии и печатаем её на экран, очередную комбинацию (аккорд) проверяем так:

if (notes & DO)
		{
			std::cout << "DO";
		}

Где notes — это целое число, один звук нашей мелодии. Она состоит из 12 звуков и имеет вид int melody[12];*/

#include <iostream>
#include <sstream>

//создаём перечисление по степеням 2 с помощью оператора сдвига <<
enum pianoKey
{
	DO = 1 << 0,
	RE = 1 << 1,
	MI = 1 << 2,
	FA = 1 << 3,
	SOL = 1 << 4,
	LA = 1 << 5,
	SI = 1 << 6
};

//количество комбинаций нот
const int combinationNotes = 1;

//функция вывода названия ноты по её номеру
void pianoSound(int ch)
{
	int sound = 1 << ch;

	if (sound & DO) std::cout << "DO ";
	else if (sound & RE)  std::cout << "RE ";
	else if (sound & MI)  std::cout << "MI ";
	else if (sound & FA)  std::cout << "FA ";
	else if (sound & SOL) std::cout << "SOL ";
	else if (sound & LA)  std::cout << "LA ";
	else std::cout << "SI ";
}


int main()
{
	std::string temp;
	std::string combination;

	for (int i = 1; i <= combinationNotes; ++i)
	{
		std::cout << "Input " << i << " combination of notes from " << combinationNotes << ": ";
		std::cin >> temp;
		combination += temp;
	}

	int i = 0;
	while (i < combination.length())
	{
		if (((combination[i] - '0') < 1) || ((combination[i] - '0') > 7)) {
			std::cout << "Input notes is incorrect ";

		}
		else {
			pianoSound(combination[i] - '1');
		}
		++i;
	}
}