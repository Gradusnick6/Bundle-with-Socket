#pragma once
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
using namespace std;

class API_Socket_Client
{
private:
	int erStat;
	PCSTR ip_adress;
	int port;
	SOCKET sock;
	IN_ADDR ip_to_num;

public: 
	/// <returns>true - ����� ���������������; false - ����� �� ���������������</returns>
	bool init(PCSTR ip_adress, int port);
	/// <returns>true - ���������� �����������; false - ������ ����������</returns>
	bool connect_to_server();
	/// <summary> ������������ ������� SOCKET</summary>
	void socket_reboot();
	/// <returns>true - ��������� ����������; false - ��������� �� ����������</returns>
	bool send_msg(const char* msg);
	~API_Socket_Client();
};
