#pragma once
#include <queue>
#include <string>
using namespace std;

class Buffer
{
private:
	queue<string> data;
public:
	/// <summary>
	/// ���������� ������ ������ � ������� � � ������ 
	/// </summary>
	string extract_data();
	bool is_empty();
	/// <summary>
	/// ��������� str � �����
	/// </summary>
	void upload(string str);
};

