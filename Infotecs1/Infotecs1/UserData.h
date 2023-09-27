#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Buffer.h"
#include "Thread_Synchronizer.h"
using namespace std;

class UserData
{
private:
	/// <summary>
	/// str должна состоять только из цифр и не превышать 64 символа
	/// </summary>
	/// <returns>true - соответсвует требованиям; false - не соответсвует требования</returns>
	static bool validate(string str);
	/// <summary>
	/// сортировка по убыванию
	/// чётные значения заменены на латинские «КВ»
	/// </summary>
	static string process(string str);
public:
	static void run(Buffer &buffer, Thread_Synchronizer& ts);
};

