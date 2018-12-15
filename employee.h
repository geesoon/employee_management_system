#ifndef EMPLOYEE_H
#define EMPLOYEE_H
using namespace std;

class payroll;

struct details{
    string name;
    string age;
    string job;
    string enrollDate;
    string salary;
    string cv;
};

class employee{
    private:
        payroll proll;
        Performance perform;
        details info;
    public:
    	string getName(){ return info.name; }
    	string getAge(){ return info.age; }
    	string getJob(){ return info.job; }
    	string getEnrolldate(){ return info.enrollDate; }
    	string getSalary(){ return info.salary; }
    	string getCv(){ return info.cv; }
		
		
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
            cout 	<< info.name << "\n" 
					<< info.age << "\n" 
					<< info.job << "\n" 
					<< info.enrollDate << "\n" 
					<< info.salary << "\n" 
					<< info.cv << endl<<endl;
        }
        
        void createGoal() { perform.createGoal();
		}
		void updateGoal() { perform.updateProgress();
		}
		void printGoal() 
		{ 
			cout<<info.name<<endl;
			perform.printGoal();
		}
		void deleteGoal() { perform.deleteGoal();
		}
		void outputGoal() { perform.outputgoal();
		}
		void insertgoal(string desc,float prog) {perform.insertGoal(desc,prog);			
		}
};


#endif
