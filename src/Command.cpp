#include "../include/Command.h"

using namespace std;

Command::Command():title("")
{}

const string& Command::operator[](const string& key) const
{
	for(int i(0); i!=keys.size(); i++)
	{
		if(keys[i] == key)
		{
			return value[i];
		}
	}
}

string& Command::operator[](const string& key)
{
	for(int i(0); i!=keys.size(); i++)
	{
		if(keys[i] == key)
		{
			return value[i];
		}
	}

	//if key is not exist, create it

	keys.push_back(key);
	value.push_back("");
	
	return value.back();
}
