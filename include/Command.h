#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

using namespace std;

class Command
{
	public:
		Command();

		string title;

		string& operator[](const string& key);
		const string& operator[](const string& key) const;

	private:
		vector<string> keys;
		vector<string> value;

		
};

#endif
