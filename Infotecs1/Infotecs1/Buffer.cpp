#include "Buffer.h"
using namespace std;

string Buffer::extract_data()
{
    string str = data.front();
    data.pop();
    return str;
}

bool Buffer::is_empty()
{
    return data.empty();
}

void Buffer::upload(string str)
{
    data.push(str);
}