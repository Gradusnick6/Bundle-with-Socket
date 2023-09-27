#include "UserData.h"

bool UserData::validate(string str)
{
    if (str.length() > 64)
        return false;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

string UserData::process(string str)
{
    string newStr = "";
    newStr.reserve(128);
    sort(str.begin(), str.end(), greater<>());

    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] - '0') % 2 == 0)
        {
            newStr.push_back('K');
            newStr.push_back('B');
        }
        else
            newStr.push_back(str[i]);
    }
    return newStr;
}

void UserData::run(Buffer &buffer, Thread_Synchronizer& ts)
{
    string s;
    cin >> s;
    if (validate(s))
    {
        s = process(s);
        buffer.upload(s);
        ts.notify_one();
    }
}