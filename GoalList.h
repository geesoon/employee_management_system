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
	
	public:
		List()
		{
			head = NULL;
			tail = NULL;
		}
		
		void createNode(string desc="",float prog=0)
		{
			Goal * temp =new Goal;
			temp->goal_desc = desc;
			temp->progress = prog;
			temp->next = NULL;
			
			if(head==NULL)
			{
				head = temp;
				temp = NULL;
				tail = temp;
			
			}
			else
			{
				tail->next=temp;
				tail=temp;
			}
			delete temp;
		}
	
		void display(int goal_cnt);
		void deletegoal(int,int);
};

void List:: display(int goal_cnt)
{
	Goal *temp = new Goal;
	temp=head;
    float tot=0;
	while(temp!=NULL)
	{
		cout<<temp->goal_desc<<"\t  "
		<<temp->progress<<endl;
				
		tot+=temp->progress;
			  	  
		temp=temp->next;
	}
		    
		cout<<"Overall progess score = "<< (tot/goal_cnt)<<endl;
		delete temp;
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

#endif
