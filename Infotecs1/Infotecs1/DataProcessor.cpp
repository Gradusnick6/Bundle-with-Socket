#include "DataProcessor.h"

int DataProcessor::get_sum(string data)
{
	int sum = 0;
	for (int i = 0; i < data.length(); i++)
	{
		if (data[i] <= '9')
			sum += data[i] - '0';
		else
			i++;
	}
	return sum;
}

void DataProcessor::run(Buffer& buffer, Thread_Synchronizer& ts, API_Socket_Client& api_socket)
{
	string str;
	int sum;
	while (true)
	{
		if (buffer.is_empty())
			ts.wait();

		str = buffer.extract_data();
		cout << "\nreceived data: " << str << endl;
		sum = get_sum(str);
		while (!api_socket.send_msg(to_string(sum).c_str()))
		{
			this_thread::sleep_for(chrono::milliseconds(3000));
			cout << "Attempt to connect to the server...\n";
			api_socket.socket_reboot();
			api_socket.connect_to_server();
		}
	}
}