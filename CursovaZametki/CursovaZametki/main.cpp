#include "Header.h"


using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Notes> notebook;
	char* timme = new char;
		
	//

	const char* way = getenv("USERNAME");
	string username = way;

	string place = "C:\\Users\\" + username + "\\Desktop\\��� �������";
	char* chplace = new char [place.length()+1];
	strcpy(chplace, place.c_str());

	if(existDir((const char*) chplace)) _mkdir((const char*)chplace);
	else
	{
		for (auto const& dir_entry : std::filesystem::directory_iterator(place))
		{
			string entry = dir_entry.path().string();
			ifstream file(entry);
			string authh;
			getline(file, authh);
			string tags;
			getline(file, tags);
			string tcr;
			getline(file, tcr);
			string empt;
			getline(file, empt);
			string tch;
			getline(file, tch);
			char* timecr = new char[tcr.length() + 1];
			strcpy_s(timecr, tcr.length() + 1,tcr.c_str());
			char* timech = new char[tch.length() + 1];
			strcpy_s(timech, tcr.length() + 1,tch.c_str());
			notebook.push_back(Notes(entry, authh, timecr, timech, tags));

		}

	}
	


	while (true)
	{
		cout << "�������� �������� � ���������:" << endl;
		cout << "1 - ������� �������" << endl;
		cout << "2 - ��������� �������" << endl;
		cout << "3 - �������� �������" << endl;
		cout << "4 - ����� ������� �� ������" << endl;
		cout << "5 - ����� ������� �� ����" << endl;
		cout << "6 - ���������� �� ���� � ������� �������� (�� ����� � ������)" << endl;
		cout << "7 - ���������� �� ���� � ������� ��������� (�� ����� � ������)" << endl;
		cout << "e - �����" << endl;
		cout << endl;

		char c;
		
		cin >> c;

		switch (c)
		{
		case('1'): //�������� �������
		{
			
			cout << "������� �������� �������" << endl;
			string name;
			cin.ignore();
			getline(cin,name);
			name ="\\"+ name+ ".txt";
			string fullname = place + name;
			if (!notebook.empty())
			{
				auto notefindif = find_if(notebook.begin(), notebook.end(), [fullname](Notes note)
					{
						return note.GetFilename() == fullname;
					});
				if (notefindif != notebook.end())
				{
					cout << "����� ������� ��� ����������" << endl;
					break;
				}
			}
			cout << "������� ������" << endl;
			string author;
			getline(cin,author);
			cout << "������� �������" << endl;
			string text;
			getline(cin,text);

			
			ofstream outfile(fullname);
			outfile << author << endl;

			cout << endl;
			cout << "�������� ����" << endl;
			cout << "0 - ��" << endl;
			cout << "1 - ���" << endl;
			cout << endl;
			int ans;
			cin >> ans;
			string tag;
			if (ans == 0)
			{
				cout << "����������� ���� (����� ��� � ������� ����� ��� �������):" << endl;
				cin.ignore();
				getline(cin,tag);
			}
			else if (ans != 1)
			{
				cout << endl;
				cout << "������������ ����. ���� �� ����� ���������." << endl;
			}

			time_t* timer = new time_t;
			time(timer);
			ctime_s(timme, 26, timer);

			outfile << tag << endl;
			outfile << timme << endl;
			outfile << timme << endl;
			outfile << endl;
			outfile << text << endl;
			outfile.close();
			notebook.push_back(Notes(fullname, author, timme, timme, tag));


			cout << endl;
			break;
		}
		case('2'): //������ �������
		{
			if (!notebook.empty())
			{
				cout << "������� �������� �������" << endl;
				string name;
				cin.ignore();
				getline(cin,name);
				name = place + "\\" + name + ".txt";
				string content;
				ifstream openfile(name);
				auto notefindif = find_if(notebook.begin(), notebook.end(), [name](Notes note)
					{
						return note.GetFilename() == name;
					});
				if (notefindif != notebook.end())
				{
					cout << endl;

					if (openfile.is_open())
					{
						while (!openfile.eof())
						{
							getline(openfile, content);
							cout << content << endl;
						}
					}
				}
				else
				{
					cout << "����� ������� ���" << endl;
				}
			}
			else cout << "�������� ������ �����" << endl;
			cout << endl;
			break;
		}
		case('3'): //��������� �������
		{
			if (!notebook.empty())
			{
				cout << "������� �������� �������" << endl;
				string name;
				cin.ignore();
				getline(cin, name);
				name = place + "\\" + name + ".txt";
				auto notefindif = find_if(notebook.begin(), notebook.end(), [name](Notes note)
					{
						return note.GetFilename() == name;
					});
				if (notefindif != notebook.end())
				{
					ifstream openfile(name);
					string changeauth;
					getline(openfile, changeauth);
					string changetags;
					getline(openfile, changetags);
					string crtime;
					getline(openfile, crtime);
					char* ttime = (char*)crtime.c_str();
					string content;

					cout << "������� ��������� �������:" << endl;
					getline(cin, content);

					ofstream file(name);

					file << changeauth << endl;
					file << changetags << endl;
					file << crtime << endl;
					file << endl;

					time_t* timer = new time_t;
					time(timer);
					ctime_s(timme, 26, timer);
					file << timme << endl;
					file << content << endl;
					file.close();

					for_each(notebook.begin(), notebook.end(), [name,timme](Notes note)
						{
							if (note.GetFilename() == name) { note.ChangeChTime(timme); }
						});

				}
				else
				{
					cout << "����� ������� ���" << endl;
				}

			}
			else cout << "�������� ������ �����" << endl;
			cout << endl;
			break;
		}
		case('4'): //����� ������� �� ������
		{
			if (!notebook.empty())
			{
				cout << "������� ������ �������" << endl;
				string author;
				cin.ignore();
				getline(cin,author);
				for_each(notebook.begin(), notebook.end(), [author](Notes note)
					{
						if (note.GetAuthor() == author) { cout << note <<endl; }
					});
			}
			else cout << "�������� ������ �����" << endl;
			cout << endl;
			break;
		}
		case('5'): //����� ������� �� ����
		{
			if (!notebook.empty())
			{
				cout << "������� ������� ���:" << endl;
				string searchtag;
				cin.ignore(); 
				getline(cin,searchtag);
				for_each(notebook.begin(), notebook.end(), [searchtag](Notes note)
					{
						if (note.GetTaggs().find(searchtag) != std::string::npos)
						{
							cout << note << endl;
						}
					});
			}
			else cout << "�������� ������ �����" << endl;
			cout << endl;
			break;
		}
		case('6'): //���������� �� ���� � ������� ��������
		{
			if (!notebook.empty())
			{
				sort(notebook.begin(), notebook.end(), [](Notes note1, Notes note2)
					{
						return note1.GetCrTime() > note2.GetCrTime();
					});
				for_each(notebook.begin(), notebook.end(), [](Notes note)
					{
						cout << note;
					});
			}
			else cout << "�������� ������ �����" << endl;
			cout << endl;
			break;
		}
		case('7'): //���������� �� ������� ���������
		{
			if (!notebook.empty())
			{
				sort(notebook.begin(), notebook.end(), [](Notes note1, Notes note2)
					{
						return note1.GetChTime() > note2.GetChTime();
					});
				for_each(notebook.begin(), notebook.end(), [](Notes note)
					{
						cout << note;
					});
			}
			else cout << "�������� ������ �����" << endl;
			cout << endl;
			break;
		}
		case ('e'):
		{
			return 0;
		}
		default:
			cout << "������������ ����" << endl;
			break;
		}
	};

	return 0;
}