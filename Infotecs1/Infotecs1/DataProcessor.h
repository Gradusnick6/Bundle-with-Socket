#pragma once
#include <iostream>
#include <string>
#include "Buffer.h"
#include "API_Socket_Client.h"
#include "Thread_Synchronizer.h"
using namespace std;

class DataProcessor
{
private:
	/// <summary>
	/// возвращает сумму цифр строки data
	/// </summary>
	static int get_sum(string data);
public:
	static void run(Buffer& buffer, Thread_Synchronizer& ts, API_Socket_Client& api_socket);
};

