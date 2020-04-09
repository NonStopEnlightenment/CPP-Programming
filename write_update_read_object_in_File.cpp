#include<iostream>
#include<fstream>
using namespace std;
class Employee
{
    int id;
    char name[20];
    float sal;
public:
    void set_emp();
    void get_emp();
    int get_id();
    void hike_sal(int);
};

void Employee :: set_emp()
{
    cout<<"Enter Name:";
    cin>>name;
    cout<<"Enter Id";
    cin>>id;
    cout<<"Enter Salary";
    cin>>sal;
}
int Employee :: get_id()
{
    return id;
}
void Employee :: get_emp()
{
    cout<<"Id: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Salary: "<<sal<<endl;
}
void Employee :: hike_sal(int per)
{
    sal = sal + (sal * per / 100);
}

int main()
{
    int n;
    cout<<"Enter the no of employees:";
    cin>>n;
    Employee* Emp = new Employee[n];

    int i = 0;
    while( i < n )
    {
        Emp[i].set_emp();
        i++;
    }
    
    fstream ofs ("Employee.txt",ios::out | ios::binary);
    ofs.write((char*)Emp,sizeof(Employee)*n );
    ofs.close();

    Employee Em[n];
    int id;
    fstream iofs ("Employee.txt",ios::in | ios::out | ios::binary);
    iofs.read((char*)Em,sizeof(Employee)*n );
    cout<<"Enter the emp id of the person to hike salary:";
    cin>>id;
    i = 0;
    while (i < n)
    {
        if (Em[i].get_id() == id)
        {
            Em[i].hike_sal(10);
            iofs.seekp(sizeof(Employee)*i,ios::beg);  //Offset , from where ios::beg, ios::cur, ios::end
            iofs.write((char*)&Em[i],sizeof(Employee));
            break;
        }
        i++;
    }
    iofs.close();
    Employee E[n];
    fstream ifs("Employee.txt",ios::in | ios::binary);
    ifs.read((char*)E,sizeof(Employee)*n );
    i = 0;
    while (i < n)
    {
        E[i].get_emp();
        i++;
    }
    ifs.close();
    return 0;
}
