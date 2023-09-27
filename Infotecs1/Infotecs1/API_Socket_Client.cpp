#include "API_Socket_Client.h"
using namespace std;

bool API_Socket_Client::init(PCSTR ip_adress, int port)
{
	this->ip_adress = ip_adress;
	this->port = port;
	try
	{
		WSADATA wsaData;
		WORD dll_v = MAKEWORD(2, 2);
		erStat = WSAStartup(dll_v, &wsaData);
		if (erStat != 0) {
			cout << "Error WinSock version initializaion #" << WSAGetLastError() << endl;
			return false;
		}

		sock = socket(AF_INET, SOCK_STREAM, NULL);
		if (sock == INVALID_SOCKET)
			throw exception("Error initialization socket # ");
		else
			cout << "Server socket initialization is OK" << endl;

		erStat = inet_pton(AF_INET, ip_adress, &ip_to_num);
		if (erStat <= 0) {
			cout << "Error in IP translation to special numeric format" << endl;
			return false;
		}
		return true;
	}
	catch (exception& ex)
	{
		cout << ex.what() << WSAGetLastError() << endl;
		closesocket(sock);
		WSACleanup();
		return false;
	}
}

bool API_Socket_Client::connect_to_server()
{
	try
	{
		SOCKADDR_IN servInfo;
		ZeroMemory(&servInfo, sizeof(servInfo));
		
		servInfo.sin_family = AF_INET;
		servInfo.sin_addr = ip_to_num;
		servInfo.sin_port = htons(port);

		erStat = connect(sock, (sockaddr*)&servInfo, sizeof(servInfo));

		if (erStat != 0)
			throw exception("Connection to Server is FAILED. Error # ");
		else
			cout << "Connection established SUCCESSFULLY. Ready to send a message to Server" << endl;
		return true;
	}
	catch (exception& ex)
	{
		cout << ex.what() << WSAGetLastError() << endl;
		return false;
	}
}

void API_Socket_Client::socket_reboot()
{
	closesocket(sock);
	sock = socket(AF_INET, SOCK_STREAM, NULL);
	inet_pton(AF_INET, ip_adress, &ip_to_num);
}

bool API_Socket_Client::send_msg(const char* msg)
{
	short packet_size = send(sock, msg, sizeof(msg), 0);
	if (packet_size == SOCKET_ERROR)
	{
		cout << "Can't send message to Server.\n";
		return false;
	}
	return true;
}

API_Socket_Client::~API_Socket_Client()
{
	closesocket(sock);
	WSACleanup();
}