#include "ResourceData.h"

const vector<string> splitString(const string& data, const string& delimiter)
{
    string value = data;
    size_t pos = 0;
    string token;
    vector<string> elements;
    while ((pos = value.find(delimiter)) != string::npos)
    {
        token = value.substr(0, pos);
        elements.push_back(token);
        token = value.erase(0, pos + delimiter.length());
    }
    elements.push_back(token);
    return elements;
}
