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

    cout << "输入help并按下ENTER键" << endl;
    while (true) {
        cout << prompt;
        cin >> cmd;
        transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

        if (cmd == hlp) {
            cout << "md=新建文件夹" << endl
                 << "rename=重命名文件" << endl
                 << "copy=复制文件" << endl
                 << "del=删除最后一个文件" << endl
                 << "dir=显示所有文件" << endl
                 << "srch=查找文件是否存在" << endl
                 << "clear=清除所有文件" << endl
                 << "cls=清屏"<< endl 
                 << "exit=退出" << endl
                 << "help=显示此列表" << endl;
            cout << endl;
        } else if (cmd == dir) {
            if (disk.empty()) {
                cout << "磁盘为空！" << endl;
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
                cout << "删除文件：" << disk.back() << endl;
                disk.pop_back();
            } else {
                cout << "磁盘为空！" << endl;
            }
        } else if (cmd == md) {
            cout << "文件名：";
            cin >> name_1;
            disk.push_back(name_1);
        } else if (cmd == exit) {
            system("cls");
    		cout<<"欢迎下次再使用C++-DOS！";
    		return 0;  
        } else if (cmd == clr) {
            cout << "你确定吗？这将会清除所有文件！(y/n): ";
            char y_a_n;
            do {
                cin >> y_a_n;
                if (y_a_n == 'y') {
                    disk.clear();
                    cout << "完毕！磁盘已清空。" << endl;
                    break;
                } else if (y_a_n == 'n') {
                    cout << endl;
                    break;
                } else {
                    cout << "无效字母！请输入有效字符（y/n）：";
                }
            } while (true);
        } else if (cmd == rnm) {
            if (!disk.empty()) {
                cout << "输入要重命名的文件现在的文件名：";
                cin >> name_1;
                auto it = find(disk.begin(), disk.end(), name_1);
                if (it != disk.end()) {
                    cout << "请输入新的文件名：";
                    cin >> name_2;
                    *it = name_2;
                } else {
                    cout << "没有此文件！请重新使用rename命令" << endl;
                }
            } else {
                cout << "磁盘为空！" << endl;
            }
        } else if (cmd == cpy) {
            if (!disk.empty()) {
                cout << "请输入要复制的文件名：";
                cin >> copy_name;
                auto it = find(disk.begin(), disk.end(), copy_name);
                if (it != disk.end()) {
                    disk.push_back(*it);
                } else {
                    cout << "要复制的文件名不存在！请重新使用copy命令" << endl;
                }
            } else {
                cout << "磁盘为空！" << endl;
            }
        } else if (cmd == srh) {
            cout << "请输入要搜索的文件名：";
            string search_name;
            cin >> search_name;
            bool found = false;
            for (const auto& file : disk) {
                if (file == search_name) {
                    found = true;
                    cout << "文件 " << file << " 存在于磁盘中。" << endl;
                    break;
                }
            }
            if (!found) {
                cout << "文件 " << search_name << " 不存在。" << endl;
            }
        } else {
            cout << "无效命令！请重新输入有效的命令，如果想知道那些命令可用，使用help命令" << endl;
        }
    }
}

