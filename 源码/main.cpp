#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <cctype> 

using namespace std;

int main() {
    string name_1;
    string name_2;
    list<string> disk;
    string cmd;
    string srh = "srch";
    string hlp = "help";
    string dir = "dir";
    string del = "del";
    string md = "md";
    string exit = "exit";
    string clr = "clear";
    string rnm = "rename";
    string cls = "cls";
    string cpy = "copy";
    string copy_name;
    char prompt[] = "DISK>";

    cout << "����help������ENTER��" << endl;
    while (true) {
        cout << prompt;
        cin >> cmd;
        transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

        if (cmd == hlp) {
            cout << "md=�½��ļ���" << endl
                 << "rename=�������ļ�" << endl
                 << "copy=�����ļ�" << endl
                 << "del=ɾ�����һ���ļ�" << endl
                 << "dir=��ʾ�����ļ�" << endl
                 << "srch=�����ļ��Ƿ����" << endl
                 << "clear=��������ļ�" << endl
                 << "cls=����"<< endl 
                 << "exit=�˳�" << endl
                 << "help=��ʾ���б�" << endl;
            cout << endl;
        } else if (cmd == dir) {
            if (disk.empty()) {
                cout << "����Ϊ�գ�" << endl;
            } else {
                for (const auto& file : disk) {
                    cout << file << endl;
                }
                cout << endl;
            }
        } else if(cmd == cls) {
        	system("cls");
		} else if (cmd == del) {
            if (!disk.empty()) {
                cout << "ɾ���ļ���" << disk.back() << endl;
                disk.pop_back();
            } else {
                cout << "����Ϊ�գ�" << endl;
            }
        } else if (cmd == md) {
            cout << "�ļ�����";
            cin >> name_1;
            disk.push_back(name_1);
        } else if (cmd == exit) {
            system("cls");
    		cout<<"��ӭ�´���ʹ��C++-DOS��";
    		return 0;  
        } else if (cmd == clr) {
            cout << "��ȷ�����⽫����������ļ���(y/n): ";
            char y_a_n;
            do {
                cin >> y_a_n;
                if (y_a_n == 'y') {
                    disk.clear();
                    cout << "��ϣ���������ա�" << endl;
                    break;
                } else if (y_a_n == 'n') {
                    cout << endl;
                    break;
                } else {
                    cout << "��Ч��ĸ����������Ч�ַ���y/n����";
                }
            } while (true);
        } else if (cmd == rnm) {
            if (!disk.empty()) {
                cout << "����Ҫ���������ļ����ڵ��ļ�����";
                cin >> name_1;
                auto it = find(disk.begin(), disk.end(), name_1);
                if (it != disk.end()) {
                    cout << "�������µ��ļ�����";
                    cin >> name_2;
                    *it = name_2;
                } else {
                    cout << "û�д��ļ���������ʹ��rename����" << endl;
                }
            } else {
                cout << "����Ϊ�գ�" << endl;
            }
        } else if (cmd == cpy) {
            if (!disk.empty()) {
                cout << "������Ҫ���Ƶ��ļ�����";
                cin >> copy_name;
                auto it = find(disk.begin(), disk.end(), copy_name);
                if (it != disk.end()) {
                    disk.push_back(*it);
                } else {
                    cout << "Ҫ���Ƶ��ļ��������ڣ�������ʹ��copy����" << endl;
                }
            } else {
                cout << "����Ϊ�գ�" << endl;
            }
        } else if (cmd == srh) {
            cout << "������Ҫ�������ļ�����";
            string search_name;
            cin >> search_name;
            bool found = false;
            for (const auto& file : disk) {
                if (file == search_name) {
                    found = true;
                    cout << "�ļ� " << file << " �����ڴ����С�" << endl;
                    break;
                }
            }
            if (!found) {
                cout << "�ļ� " << search_name << " �����ڡ�" << endl;
            }
        } else {
            cout << "��Ч���������������Ч����������֪����Щ������ã�ʹ��help����" << endl;
        }
    }
}

