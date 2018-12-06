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
        
        void createGoal() { perform.createGoal();
		}
		void updateGoal() { perform.updateProgress();
		}
		void printGoal() { perform.printGoal();
		}
		void deleteGoal() { perform.deleteGoal();
		}
};


#endif
