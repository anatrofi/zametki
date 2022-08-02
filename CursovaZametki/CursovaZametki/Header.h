#pragma once

#include<iostream>
#include <sstream>
#include<Windows.h>
#include<sys/stat.h>
#include <string>
#include <direct.h>
#include<vector>
#include <ctime>
#include <fstream>
#include <filesystem>
#include<io.h>
#include <cstdlib>


using namespace std;
using namespace std::filesystem;
using std::string;

bool existDir(const char * name);
time_t TimeTransformation(char* time);


class Notes
{
private:
	string filename;
	string author;
	char* creationtime;
	char* changetime;
	string taggs;
public:

	Notes() :filename(""), author(""), creationtime(0), changetime(0), taggs() {};
	Notes(string fname, string auth, char* tcr, char* tch, string tag) : Notes()
	{
		filename = fname;
		author = auth;
		creationtime = tcr;
		changetime = tch;
		taggs = tag;
	}
	~Notes() {};
	string GetFilename() const { return filename; }
	string GetAuthor() const { return author; }
	time_t GetCrTime() const { return (TimeTransformation(creationtime)); }
	time_t GetChTime() const { return (TimeTransformation(changetime)); }
	string GetTaggs() const { return taggs; }
	void ChangeChTime(char* ctt) { strcpy_s(changetime, 26, ctt); }
	friend std::ostream& operator <<(std::ostream& os, const Notes& note)
	{
		os << note.filename << endl;
		return os;
	}
	
};

