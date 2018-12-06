#ifndef PERFORMANCE_H
#define PERFORMANCE_H

using namespace std;


struct Goal{
	
	string goal_desc;
	float progress;
	Goal * next;
};

class Performance{
	private:
		Goal goal[size];
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
	string temp;
	cout<<"Please enter the goal description.\n";
	getline(cin,temp);
	goal[goal_cnt].goal_desc=temp;
	goal[goal_cnt].progress=0;
	goal_cnt++;	
}

void Performance::printGoal()
{
	float tot=0;
	for(int i=0;i<goal_cnt;i++)
	{
		cout<<goal[i].goal_desc<<" \t\t "<<goal[i].progress<<endl;
		tot+=goal[i].progress;
	}
			
	cout<<"Overall progess score = "<< (tot/goal_cnt)<<endl;
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
