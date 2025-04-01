#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string name,roll,fname,address,search;
    fstream file;
    public:
    void addstu();
    void searchstu();
    void viewstu();

}obj;
int main(){
    char choise;

    cout<<"1- Add Student Details\n";
    cout<<"2- show student Details\n";
    cout<<"3- view all student record\n";
    cout<<"4- Exit\n";
    cout<<"------------------------\n";

    cout<<"Enter your choise\n";
    cin>>choise;

    switch(choise){
        case '1':
         cin.ignore();
         obj.addstu();
        break;
        case '2':
        cin.ignore();
        obj.searchstu();
        break;
        case '3':
        cin.ignore();
        obj.viewstu();
        break;
        case '4':
            return 0;
        break;
        default:
          cout<<"Enter Valid Option";
    }
    return 0;
}

void temp::addstu(){
   cout<<"Enter Student Details\n";
   cout<<"Name: ";
   getline(cin,name);
   cout<<"Roll: "<<roll;
   getline(cin,roll);
   cout<<"father name: ";
   getline(cin,fname);
   cout<<"Address: ";
   getline(cin,address);

   file.open("Studentdetails.txt",ios::out|ios::app);
   file<<name<<'*'<<roll<<'*'<<fname<<'*'<<address<<endl;
   file.close();
}

void temp::viewstu(){
    cout<<"All Student Details \n";
    file.open("Studentdetails.txt",ios::in);
    getline(file,name,'*');
    getline(file,roll,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');
      
    while(!file.eof()){
        cout<<"\n";
      cout<<"Student name: "<<name<<endl;
      cout<<"Student Roll: "<<roll<<endl;
      cout<<"Student fathername: "<<fname<<endl;
      cout<<"Student Address: "<<address<<endl;

    getline(file,name,'*');
    getline(file,roll,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');
    }
    file.close();
}

void temp::searchstu(){
    cout<<"Enter Student Roll No :";
    getline(cin,search);
    file.open("Studentdetails.txt",ios::in);
    getline(file,name,'*');
    getline(file,roll,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');

    while(!file.eof()){
        if(search==roll){
            cout<<"\n";
            cout<<"Student name: "<<name<<endl;
            cout<<"Student Roll: "<<roll<<endl;
            cout<<"student father name: "<<fname<<endl;
            cout<<"Student Address: "<<address<<endl;

        }
           getline(file,name,'*');
            getline(file,roll,'*');
            getline(file,fname,'*');
            getline(file,address,'\n');
    }
    file.close();

}