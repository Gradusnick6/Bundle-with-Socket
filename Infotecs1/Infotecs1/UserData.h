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
	/// str ������ �������� ������ �� ���� � �� ��������� 64 �������
	/// </summary>
	/// <returns>true - ������������ �����������; false - �� ������������ ����������</returns>
	static bool validate(string str);
	/// <summary>
	/// ���������� �� ��������
	/// ������ �������� �������� �� ��������� ��»
	/// </summary>
	static string process(string str);
public:
	static void run(Buffer &buffer, Thread_Synchronizer& ts);
};

