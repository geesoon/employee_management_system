#include<iostream>
#include<string>
#include<fstream>
#include <cstdlib>
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
	char choice;
	cout << "EMPLOYEE MANAGEMENT SYSTEM" << endl
		 << "1. Search employee" << endl
		 << "2. Employee payroll" << endl
		 << "3. Evaluate performance" << endl
		 << "Enter the index of the operation : ";
	cin  >> choice;
	return choice;
}

employee search_engine( string val, int type, int empcnt, employee emp [] )
{
	int index = 0;
	
	switch(type)
	{
		case 0 : 
		while(index < empcnt)
		{
			if(emp[index].getName() == val)
				return emp[index];
			else 
				index++;		
		}
		break;
	
		case 1 : 
		while(index < empcnt)
		{
			if(emp[index].getAge() == val)
				return emp[index];
			else 
				index++;		
		}
		break;
	
		case 2 : 
		while(index < empcnt)
		{
			if(emp[index].getJob() == val)
				return emp[index];
			else 
				index++;		
		}
		break;
	
		case 3 : 
		while(index < empcnt)
		{
			if(emp[index].getEnrolldate() == val)
				return emp[index];
			else 
				index++;		
		}
		break;
	
		case 4 : 
		while(index < empcnt)
		{
			if(emp[index].getSalary() == val)
				return emp[index];
			else 
				index++;		
		}
		break;
		
		}// end of switch
	
		cout<<"Sorry no result found. Returning first entry.\n\n";
		return emp[0];
}


void search(int empcnt,employee emp[])
{
	char search_type;
	employee search_result;
	string query;
	
	cout << "Search by:" << endl		
		<< "1.Name" << endl
		<< "2.Age" << endl
		<< "3.Job" << endl
		<< "4.Enrollment Date (eg: 12/12/2012)" << endl
		<< "5.Salary (eg: 4000)" << endl;
	cin >> search_type;

	cin.ignore();
	switch(search_type)
	{
		case '1': 
					cout << "Enter the name to be search: ";
				  	getline(cin,query);
					search_result=search_engine(query,0,empcnt,emp);
					break;
		case '2':
					cout << "Enter the age to be search: ";
					cin >>query;
					search_result = search_engine(query,1,empcnt,emp);
					break;
		case '3':
					cout << "Enter the job to be search: ";
					getline(cin,query);	
					search_result = search_engine(query,2,empcnt,emp);
					break;
		case '4':
					cout << "Enter the enrollment date to be search: ";
					cin >>query;
					search_result = search_engine(query,3,empcnt,emp);
					break;
		case '5':
					cout << "Enter the salary amount to be search: ";
					cin >> query;
					search_result = search_engine(query,4,empcnt,emp);
					break;

	}
	
	search_result.getinfo();
}

void writegoalfile(employee emp[],int empcnt)
{
	fstream out;												//***
	out.open("employeegoal.txt",ios::out| ios::trunc);			// Clear existing data		
	out.close();												//***
	
	for(int i=0;i<empcnt;i++)  //todo: replace counter breakpoint with empcnt
	{
		emp[i].outputGoal();
	}
	
}

void readgoalfile(employee emp[],int empcnt)
{
	int goalcnt;
	float prog;     //store extracted data temperory
	string desc;
	
	fstream in;
	in.open("employeegoal.txt",ios::in);
	
	if (!in)
    { 
        cout << "ERROR! Cannot open file\n";
        exit(1); 
    }
    
    for(int i=0;i<empcnt;i++)
    {
    	in>>goalcnt;
    	
		for(int j=0;j<goalcnt;j++)
    	{
    		getline(in,desc,'\t');
    		in>>prog;
			emp[i].insertgoal(desc,prog);
			in.ignore();
		}	
	}
	in.close();
}

void empPerformance(int empcnt, employee emp[])
{
	int index;
	char choice;
	
	cout<<"Select Option:\n"
		<<"[1] View goal and performace\n"
		<<"[2] Create new goal\n"
		<<"[3] Update progress\n"
		<<"[4] Delete Goal\n"
		<<"Choice  >>  ";cin>>choice;
		
	cout<<"Select employee :\n";
	for(int i=0;i<empcnt;i++)
	{
		cout<<"[ "<<i<<" ] "<< emp[i].getName()<<endl;
	}
	
	cin>>index;
	
	if (index<0||index>=empcnt)
	{
		cout<<"index out of bound\n";
		return;
	}
	cin.ignore();
	switch(choice)
	{
		case '1':
				emp[index].printGoal();
				break;
		case '2': 
				emp[index].createGoal();
				break;
		case '3': 
				emp[index].updateGoal();
				break;
		case '4': 
				emp[index].deleteGoal();
				break;
	}//end switch
	
}

void empPayroll(int empcnt,employee emp[])
{
	int index;
	float totalpay=0;
	cout<<"Select employee :\n";
	for(int i=0;i<empcnt;i++)
	{
		cout<<"[ "<<i<<" ] "<< emp[i].getName()<<endl;
	}
	cin>>index;
	if (index<0||index>=empcnt)
	{
		cout<<"index out of bound\n";
		return;
	}
	
	cout<<"The total pay for this month is  RM "<<emp[index].getNetPay()<<endl<<endl;
	
	
}

int main()
{
	//Channel text info into stack//
    fstream infile("employee.txt",ios::in);
    employee emp[10];
    int empcnt = 0 ;
    int i =0;
    stack emply;
    emply.createStack();
    details * temp;
    
	if (!infile)
    { 
        cout << "ERROR! Cannot open file\n";
        exit(1); 
    }
    

    while(!infile.eof())
    {
        temp = new details;
        getline(infile, temp->name,'\t');
        getline(infile, temp->age,'\t');
        getline(infile, temp->job,'\t');
        getline(infile, temp->enrollDate,'\t');
        getline(infile, temp->salary,'\t');
        getline(infile, temp->cv,'\n');
    	emp[i].setinfo(temp);
    	
    	empcnt++;	//number of existing employee record
        
		delete temp;
        i++;
    }
    
	for(int i=0; i<empcnt; i++)
    {
        emply.push(emp[i]);
        emp[i].setSalary();
    }
    

	readgoalfile(emp,empcnt);
	

    //main menu//
	char choice = menu();

	switch(choice)
	{
		case '1': 	search(empcnt,emp);break;
		case '2':	empPayroll(empcnt,emp);break;
		case '3':	empPerformance(empcnt,emp);break;
		default : cout<<"Invalid choice\n";
	}
    

	
	
	writegoalfile(emp,empcnt);
	infile.close();
    return 0;
}
