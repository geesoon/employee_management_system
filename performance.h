#ifndef PERFORMANCE_H
#define PERFORMANCE_H

using namespace std;

class Performance{
	private:
		List goallist;
		int goal_cnt;
	public:
		Performance() {goal_cnt = 0;}
		
		void createGoal();
		void deleteGoal(); //not done
		void printGoal();
		void updateProgress();
	
};

void Performance::createGoal()
{
	string str;	
	cout<<"Please enter the goal description.\n";
	
	getline(cin,str);
	goallist.createNode(str);
	cin.ignore();
	goal_cnt++;	
}

void Performance::printGoal()
{	
	if(goal_cnt== 0)
	{
		cout<<"There is no goal in entry\n"; return;
	}
	goallist.display(goal_cnt);
}

void Performance::updateProgress()
{
	int update_index;
	float newscore;
	cout<<"Enter index number of the goal you wish to change >> ";cin>>update_index;
	if(update_index < 0 || update_index >= goal_cnt)
	{
		cout<<"Index out of bound.\n";
		return;
	}
	
	cout<<"Enter new progress score >> "; cin>>newscore;
	goallist.updateScore(update_index,newscore);
	cout<<"Progress score sucessfully updated.\n";
}

void Performance::deleteGoal()
{
	goallist.deletegoal(0,goal_cnt);
	goal_cnt--;
}

#endif
