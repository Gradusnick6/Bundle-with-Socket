#include "API_Socket_Server.h"
#include <string>
using namespace std;

bool validate(int data)
{
     return data > 99 && data % 32 == 0;
}

string get_str_result(bool result)
{
    if (result)
        return "data received";
    else
        return "data error";
}

bool is_int(string str)
{
    if (str.length() == 0) return false;
    for (int i = 0; i < str.length(); i++)
        if ((int) str[i] < '1' || (int) str[i] > '9')
            return false;
    return true;
}

int main()
{
    API_Socket_Server api_socket;
    api_socket.init("127.0.0.1", 1234);
    api_socket.connect_client();

    int msg_num = 1;
    bool result;
    string msg;
    while (true)
    {
        if (api_socket.recv_msg(msg))
        {
            if (is_int(msg))
            {
                result = validate(stoi(msg));
                cout << "Message Number " << msg_num++ << " - " << get_str_result(result);
                if (result)
                    cout << ": " << msg;
                cout << endl;
            }
        }
        else
        {
            cout << "Client disconnected\n";
            api_socket.connect_client();
        }
    }
}

