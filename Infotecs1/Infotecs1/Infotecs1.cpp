#pragma once
#include <thread>
#include "UserData.h"
#include "DataProcessor.h"
using namespace std;

int main()
{
	API_Socket_Client api_socket;
	api_socket.init("127.0.0.1", 1234);
	api_socket.connect_to_server();

	Buffer buffer;

	Thread_Synchronizer ts;
	thread thr2([&]() { DataProcessor::run(buffer, ts, api_socket); });
	thr2.detach();
	while (true)
		UserData::run(buffer, ts);
}