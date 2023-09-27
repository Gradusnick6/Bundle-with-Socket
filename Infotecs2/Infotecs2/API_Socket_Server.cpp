#include "API_Socket_Server.h"
using namespace std;

bool API_Socket_Server::init(PCSTR ip_adress, int port)
{
	this->ip_adress = ip_adress;
	this->port = port;
	client_sock = INVALID_SOCKET;
	try
	{
		WSADATA wsaData;
		WORD DLL_V = MAKEWORD(2, 2);
		erStat = WSAStartup(DLL_V, &wsaData);
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

		SOCKADDR_IN servInfo;
		ZeroMemory(&servInfo, sizeof(servInfo));

		servInfo.sin_family = AF_INET;
		servInfo.sin_addr = ip_to_num;
		servInfo.sin_port = htons(port);

		erStat = bind(sock, (sockaddr*)&servInfo, sizeof(servInfo));
		if (erStat != 0)
			throw exception("Error Socket binding to server info. Error # ");
		else
			cout << "Binding socket to Server info is OK" << endl;

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

bool API_Socket_Server::connect_client()
{
	try
	{
		erStat = listen(sock, SOMAXCONN);
		if (erStat != 0)
			throw exception("Can't start to listen to. Error # ");
		else
			cout << "Listening..." << endl;

		SOCKADDR_IN clientInfo;
		ZeroMemory(&clientInfo, sizeof(clientInfo));
		int clientInfo_size = sizeof(clientInfo);
		client_sock = accept(sock, (sockaddr*)&clientInfo, &clientInfo_size);

		if (client_sock == INVALID_SOCKET) {
			closesocket(client_sock);
			throw exception("Client detected, but can't connect to a client. Error # ");
		}
		else
			cout << "Connection to a client established successfully" << endl;
		return true;
	}
	catch (exception& ex)
	{
		cout << ex.what() << WSAGetLastError() << endl;
		return false;
	}
}

bool API_Socket_Server::recv_msg(string& out_msg)
{
	char msg[4];
	short packet_size = recv(client_sock, msg, sizeof(msg), 0);
	if (packet_size == SOCKET_ERROR || msg[0] == 'M') {
		cout << "Can't receive message from Client. Error # " << WSAGetLastError() << endl;
		return false;
	}
	out_msg = msg;
	return true;
}

API_Socket_Server::~API_Socket_Server()
{
	if (client_sock == INVALID_SOCKET)
		closesocket(client_sock);
	closesocket(sock);
	WSACleanup();
}