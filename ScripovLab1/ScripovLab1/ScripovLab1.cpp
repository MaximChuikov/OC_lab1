#include <iostream>
#include <Windows.h>
using namespace std;
struct Anketa
{

    string firstName;
    string midName;
    string lastName;
    unsigned int stage;
    int id;
    Anketa(int id, unsigned int stage, string firstName, string midName, string lastName)
    {
        this->id = id;
        this->firstName = firstName;
        this->midName = midName;
        this->lastName = lastName;
        this->stage = stage;
    }
};

HANDLE hFile;
DWORD error;
char szMessage[100];
void CreateMyFile(DWORD access, DWORD share)
{
    hFile = CreateFile(L"Anketa.dat",
        access,
        share,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        printf("Файл не открыт!\n");
    error = GetLastError();
    FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM,
        0,
        error,
        LANG_SYSTEM_DEFAULT,
        szMessage,
        100,
        0);
    printf("%s", szMessage);
}

void WriteFile()
{
    CreateMyFile(GENERIC_ALL, NULL);
    Anketa ank = Anketa(1, 10, "Иван", "Иванов", "Иванович");

}

void ReadFile()
{

}

int main()
{
    setlocale(LC_ALL, "Russian");

    


    cout << "Hello World!\n";

}


