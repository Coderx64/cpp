#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct student
{
    string FirstName;
    string SecondName;
    string Patronymic;
    int    Rates[5];
};

int main()
{
    setlocale( LC_ALL,"Russian" );

    ifstream in("input.txt");
    ofstream out("output.txt");

    student St;
    student Tmp;

    int GroupNumber;
    int StudentsCount;
    vector<student> Group;

    if (in.is_open()) cout<<"File is successfully opened!"<<endl; else return -1;

    in>>GroupNumber;
    in>>StudentsCount;

    for (int i = 0; i<StudentsCount; i++)
    {
        in>>St.FirstName>>St.SecondName>>St.Patronymic>>St.Rates[0]>>St.Rates[1]>>St.Rates[2]>>St.Rates[3]>>St.Rates[4];
        Group.push_back(St);
    }

    for (int i=0; i<Group.size(); i++)
    {
        out<<Group[i].FirstName<<" "<<Group[i].SecondName<<" "<<Group[i].Patronymic<<" "<<
            Group[i].Rates[0]<<" "<<Group[i].Rates[1]<<" "<<Group[i].Rates[2]<<" "<<
            Group[i].Rates[3]<<" "<<Group[i].Rates[4]<<endl;
    }


    for (int i=0; i<StudentsCount; i++)
    {
        for (int j=0; j<StudentsCount; j++)
        {
            if (Group[i].SecondName<Group[j].SecondName)
            {
                Tmp.FirstName = Group[i].FirstName;
                Tmp.SecondName = Group[i].SecondName;
                Tmp.Patronymic = Group[i].Patronymic;
                Tmp.Rates[0] = Group[i].Rates[0];
                Tmp.Rates[1] = Group[i].Rates[1];
                Tmp.Rates[2] = Group[i].Rates[2];
                Tmp.Rates[3] = Group[i].Rates[3];
                Tmp.Rates[4] = Group[i].Rates[4];

                Group[i].FirstName = Group[j].FirstName;
                Group[i].SecondName = Group[j].SecondName;
                Group[i].Patronymic = Group[j].Patronymic;
                Group[i].Rates[0] = Group[j].Rates[0];
                Group[i].Rates[1] = Group[j].Rates[1];
                Group[i].Rates[2] = Group[j].Rates[2];
                Group[i].Rates[3] = Group[j].Rates[3];
                Group[i].Rates[4] = Group[j].Rates[4];

                Group[j].FirstName = Tmp.FirstName;
                Group[j].SecondName = Tmp.SecondName;
                Group[j].Patronymic = Tmp.Patronymic;
                Group[j].Rates[0] = Tmp.Rates[0];
                Group[j].Rates[1] = Tmp.Rates[1];
                Group[j].Rates[2] = Tmp.Rates[2];
                Group[j].Rates[3] = Tmp.Rates[3];
                Group[j].Rates[4] = Tmp.Rates[4];
            }
        }
    }

    out<<"After sort"<<endl;

    for (int i=0; i<Group.size(); i++)
    {
        out<<Group[i].FirstName<<" "<<Group[i].SecondName<<" "<<Group[i].Patronymic<<" "<<
            Group[i].Rates[0]<<" "<<Group[i].Rates[1]<<" "<<Group[i].Rates[2]<<" "<<
            Group[i].Rates[3]<<" "<<Group[i].Rates[4]<<endl;
    }

    out.close();

    return 0;
}
