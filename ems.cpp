#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int size = 100;

struct details{
    string name;
    string age;
    string job;
    string enrollDate;
    string salary;
    string cv;
};

class payroll{

};

class performance{

};

class employee{
    private:
        payroll proll;
        performance perform;
        details info;
    public:
		void setinfo(details *file_info)
        {
            info.name = file_info->name;
            info.age = file_info->age;
            info.job = file_info->job;
            info.enrollDate = file_info->enrollDate;
            info.salary = file_info->salary;
            info.cv = file_info->cv;
        }
        void getinfo()
        {
            cout 	<< info.name << "\t" 
					<< info.age << "\t" 
					<< info.job << "\t" 
					<< info.enrollDate << "\t" 
					<< info.salary << "\t" 
					<< info.cv << endl;
        }
};

class stack
{
	private:
		int top;
		employee data[size];
	public:
		void createStack()
		{
			top = -1;
		}
		void push(employee emp)
		{
			if(isFull())
			{
				//cout << "Cannot push item. Stack is now full!"<<endl;
			}
			else
			{
				top = top + 1;
				data[top]= emp;
				//cout << data[top] << " has been push to the stack.";
			}
		}
		employee pop()
		{
			if(isEmpty())
			{
				//cout << "Cannot pop item. Stack is empty!"<< endl;
			}
			else
			{
				//cout << "Popped value : " << data[top] << endl;
				int temp = top;
				top = top-1;
				return data[temp];
			}
		}
		employee stackTop()
		{
			if(isEmpty())
			{
				//cout << "Stack is empty!"<< endl;
			}
			else
				return data[top];
		}
		bool isFull()
		{
			return (top==size-1);
		}
		bool isEmpty()
		{
			return (top==-1);
		}
};


int main()
{
    fstream infile("employee.txt",ios::in);
    employee emp[10];
    stack emply;

    details *temp;
    if (!infile)
    { 
        cout << "ERROR! Cannot open file\n";
        exit(1); 
    }
    
    int i =0;
    while(!infile.eof())
    {
        temp = new details;
        getline(infile, temp->name,'\t');
        getline(infile, temp->age,'\t');
        getline(infile, temp->job,'\t');
        getline(infile, temp->enrollDate,'\t');
        getline(infile, temp->salary,'\t');
        getline(infile, temp->cv,'\t');
    	emp[i].setinfo(temp);
        delete temp;
        i++;
    }
	
    for(int i=0;i<10; i++)
    {
        emply.createStack();
    }

    for(int i=0; i<10; i++)
    {
        emp[i].getinfo();
    }
    
    infile.close();
    return 0;
}
