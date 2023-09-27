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
	/// возвращает первую строку и удаляет её с буфера 
	/// </summary>
	string extract_data();
	bool is_empty();
	/// <summary>
	/// загружает str в буфер
	/// </summary>
	void upload(string str);
};

