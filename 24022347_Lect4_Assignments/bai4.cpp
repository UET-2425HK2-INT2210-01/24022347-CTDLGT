#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;
struct Student
{
    string name;
    string className;
};

unordered_map<int, Student> studentList;

void insertStudent(int id, const string& name, const string& className)
{
    studentList[id] = {name, className};
}

void deleteStudent(int id)
{
    studentList.erase(id);
}

void inforStudent(int id)
{
    if (studentList.find(id) != studentList.end())
    {
        cout << studentList[id].name << "," << studentList[id].className << endl;
    }
    else
    {
        cout << "NA,NA" << endl;
    }
}

int main()
{
    string input;
    while (getline(cin, input))
    {
        size_t start = input.find('(');
        size_t end = input.find(')');
        if (start == string::npos || end == string::npos) continue; // Kiểm tra định dạng

        string command = input.substr(0, start);
        string params = input.substr(start + 1, end - start - 1);

        stringstream ss(params);

        if (command == "Insert")
        {
            int id;
            string idStr, name, className;
            if (!getline(ss, idStr, ',') || !getline(ss, name, ',') || !getline(ss, className))
            {
            continue; // Bỏ qua nếu định dạng sai
            }
            try
            {
                id = stoi(idStr);
            }
            catch (...)
            {
                continue;
            }
            insertStudent(id, name, className);
        }
        else if (command == "Delete")
        {
            try
            {
                int id = stoi(params);
                deleteStudent(id);
            }
            catch (...)
            {
                continue;
            }
        }
        else if (command == "Infor")
        {
            try
            {
                int id = stoi(params);
                inforStudent(id);
            }
            catch (...)
            {
                continue;
            }
        }
    }
    return 0;
}