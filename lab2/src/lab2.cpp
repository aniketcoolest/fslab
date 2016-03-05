#include <iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <string.h>
#include <stdlib.h>
using namespace std;
class student{
    string name;
    string USN;
    string branch;
    int sem;
public:
    void read()
    {
                cout <<"enter the USN"<<endl;
                cin >> USN;
                cout <<"enter the name"<<endl;
                cin >> name;
                cout <<"enter branch"<<endl;
                cin >> branch;
                cout <<"enter the sem"<<endl;
                cin >> sem;
    }
    friend void search(string filename, string usn);

    string pack()
    {
        string sem1,temp;
        stringstream out;
        out<<sem;
        sem1=out.str();
        temp+= USN +'|'+name+'|'+branch+'|'+sem1+"|";
        temp.resize(100,'$');
        return temp;
    }
    void unpack( char *buffer)
        {
            int i=0;
            string temp;
            while(buffer[i]!='|'){
                    USN+=buffer[i];
                    i++;
            }
            while(buffer[i]!='|'){
                    name+=buffer[i];
                    i++;
            }
            while(buffer[i]!='|'){
                    branch+=buffer[i];
                    i++;
            }
            while(buffer[i] != '|') {
                    temp += buffer[i];
                    i++;
            }
                    sem = atoi(temp.c_str());
        }
    void write(string filename)
    {
        ofstream f(filename.c_str());
        f << pack();
        f.close();
    }
#if 0
        for(int i=buffer.length();i<100;i++)
            temp+='$';
                    buffer+=temp;
                    cout<<buffer;
                    fstream fp1;
                    fp1.open("data1.txt",ios::out|ios::app);
                            // cout<<"\n frm write:"<<buffer;
                    fp1<<buffer;
                    fp1.close();
    }

    void write()
    {
    cout<<"\n from write";

    }
    int insert(string key)
    {
        f1.open("file.txt",ios::in);
        while(!f1.eof())
        {
            f1.getline(buffer,100);
            pos=file.tellp();
            unpack();
            if(key==USN)
                break; f=1}
        return pos;
    }
    void unpack()
    {
        while(buffer[i]!=='|')
                USN+=buffer[i];
        while(buffer[i]!=='|')
                name+=buffer[i];
        while(buffer[i]!=='|')
                branch+=buffer[i];
    }
#endif
};

void search(string filename, string usn)
{
    char buffer[101];
    ifstream f(filename.c_str());
    while ( f.read(buffer,100)) {
        buffer[101] = '\0';
        student s;
        s.unpack(buffer);
        if(s.USN == usn) {
            cout << "search successful" << endl;
        }
    }
    cout << "search failed" << endl;
    }



int main() {
    int choice;
    while ( 1) {
    cout << "enter ur choice (1.insert 2.search 3.modify 4.delete)"<<endl;
    cin >> choice;
    student s;
    string filename,usn;
    switch(choice)
    {
    case 1:
            s.read();
            cout << s.pack()<<endl;
            cout << "enter file name" << endl;
            cin >> filename;
            s.write(filename);
            break;
    case 2:
            cout << "enter filename" << endl;
            cin >> filename;
            cout << "enter usn" << endl;
            cin >> usn;
            search(filename,usn);
            //cout << s2.pack();

    }
    }
    //cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    return 0;
}
