#pragma once
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
using namespace std;

class API_Socket_Server
{
private:
	int erStat;
	PCSTR ip_adress;
	int port;
	SOCKET sock;
	SOCKET client_sock;
	IN_ADDR ip_to_num;

public: 
	/// <returns>true - ����� ���������������; false - ����� �� ���������������</returns>
	bool init(PCSTR ip_adress, int port);
	/// <returns>true - ���������� �����������; false - ������ ����������</returns>
	bool connect_client();
	bool recv_msg(string& out_msg);
	~API_Socket_Server();
};
