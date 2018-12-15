#include<iostream>
#include<string>
#include<fstream>
const int size = 100;

#include "GoalList.h"
#include "performance.h"
#include "payroll.h"
#include "employee.h"

using namespace std;

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

char menu()
{
	int choice;
	cout << "EMPLOYEE MANAGEMENT SYSTEM" << endl
		 << "1. Search employee" << endl
		 << "2. Employee payroll" << endl
		 << "3. Evaluate performance" << endl
		 << "4. Terminate employee" << endl //terminate the most recent appointed employee (LIFO)
		 << "Enter the index of the operation : ";
	cin  >> choice;
	return choice;
}

employee search_engine(string val){
	
}

void search()
{
	char search_type;
	cout << "Search by:" << endl		
		<< "1.Name" << endl
		<< "2.Age" << endl
		<< "3.Job" << endl
		<< "4.Enrollment Date (eg: 12/12/2012" << endl
		<< "5.Salary (eg: 4000)" << endl;
	cin >> search_type;

	employee search_result;
	string search_name;
	string search_age;
	string search_job;
	string search_date;
	string search_salary;
	switch(search_type)
	{
		case '1': 	
					cout << "Enter the name to be search: ";
				  	getline(cin,search_name);
					search_result = search_engine(search_name);
					break;
		case '2':	
					cout << "Enter the age to be search: ";
					cin >> search_age;
					search_result = search_engine(search_age);
					break;
		case '3':	
					cout << "Enter the job to be search: ";
					getline(cin, search_job);	
					search_result = search_engine(search_job);
					break;
		case '4':	
					cout << "Enter the enrollment date to be search: ";
					cin >> search_date;
					search_result = search_engine(search_date);
					break;
		case '5':	
					cout << "Enter the salary amount to be search: ";
					cin >> search_salary;
					search_result = search_engine(search_salary);
	}
}

int main()
{
	//Channel text info into stack//
    fstream infile("employee.txt",ios::in);
    employee emp[10];
    stack emply;
    emply.createStack();
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
    for(int i=0; i<10; i++)
    {
        emply.push(emp[i]);
		//emp[i].getinfo();
    }
    
	//Performance//
    /*
	emp[0].createGoal();
    emp[0].printGoal();
	emp[0].createGoal();
    emp[0].printGoal();
	emp[0].updateGoal();
	emp[0].printGoal();
	*/
   
    //main menu//
	char choice = menu();
	switch(choice)
	{
		case '1': 	search();	break;
		case '2':	break;
		case '3':	break;
	}
    infile.close();
    return 0;
}
