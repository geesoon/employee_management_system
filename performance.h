#ifndef PERFORMANCE_H
#define PERFORMANCE_H

using namespace std;

class Performance{
	private:
		Goal goal[size];
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
	
	goal_cnt++;	
}

void Performance::printGoal()
{	
	goallist.display(goal_cnt);
}

void Performance::updateProgress()
{
	int index,newscore;	
		
	cout<<"Enter goal index >> "; cin>>index;
			
	if(index > goal_cnt || index < 0)
	{
		cout<<"Error, index out of bound\n";
		return;
	}
	
	
	
	cout<<"Enter new progress score >> "; cin>>newscore;
	
	if(newscore < 0 || newscore > 100)
	{
		cout<<"Error, input out of bound\n";
		return ;
	}
	
	goal[index].progress=newscore;
	cout<<"New score update sucessful.\n";
}


#endif
