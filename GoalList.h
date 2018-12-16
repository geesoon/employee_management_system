#ifndef GOALLIST_H
#define GOALLIST_H

using namespace std;


struct Goal{
	
	string goal_desc;
	float progress;
	Goal * next;
};


class List{
	private:
		Goal * head;
		Goal * tail;
		friend class Performance;
	public:
		List()
		{
			head = NULL;
			tail = NULL;
		}
		
		void createNode(string ,float);
		void display(int goal_cnt);
		void updateScore(int,float);
		void deletegoal(int,int);
		char getgrade(float);

};

void List::createNode(string desc="",float prog=0)
{
	int currIndex = 0;
	Goal * currnode = head;
	Goal * prevnode = NULL;
	Goal * newnode = new Goal;
	newnode->goal_desc = desc;
	newnode->progress = prog ;
			
	while(currnode)
	{
		prevnode = currnode;
		currnode = currnode->next;
		currIndex++;	
	}
			
	if (currIndex == 0)
	{
		newnode->next = head;
		head = newnode;
	}
	else
	{
		newnode->next = prevnode->next;
		prevnode->next = newnode;
	}		
}

void List:: display(int goal_cnt)
{
	Goal *temp = new Goal;
	temp=head;
    float tot=0;
    
    cout<<setw(8)<<right<<"Goal"<<setw(18)<<"Progress"<<endl
    	<<"==============================================================\n";
	while(temp!=NULL)
	{
		cout<<temp->goal_desc<<"\t  "
		<<temp->progress<<endl;
				
		tot+=temp->progress;
			  	  
		temp=temp->next;
	}
		tot=tot/goal_cnt;    
		cout<<"\nOverall progess score = "<< tot<<endl;
		cout<<"Performance grade => "<<getgrade(tot)<<endl;
		
		delete temp;
}

void List::updateScore(int index,float newscore)
{
	Goal * currnode = head;
	for(int i=0;i<index;i++)
	{
		currnode= currnode->next;
	}
	
	currnode->progress = newscore;
}

void List::deletegoal(int index,int cnt)
{
	Goal * curr, * prev;
	int i=0;
	curr=head;
	
	if(index>=cnt|| index < 0)
	{
		cout<<"Index out of bound\n";
		return;
	}
	
	if(head==NULL)
	{
		cout<<"Listed already empty\n";
		return ;
	}
	
	if(index==0)
	{
		curr=head;
		head=head->next;
		delete curr;
	}
	
	else
	{
		while(i!=index)
		{
			prev=curr;
			curr=curr->next;
			i++;
		}
		
		prev->next=curr->next;
		delete curr;
	}
}

char List::getgrade(float score)
{
	if(score>=80)
		return 'A';
	else if (score>=60)
		return 'B';
	else if (score>=40)
		return 'C';
	else if (score>=20)
		return 'D';
	else 
		return 'F';
}

#endif
