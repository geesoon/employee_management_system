#ifndef GOALLIST_H
#define GOALLIST_H

using namespace std;



class List{
	private:
		Goal * head;
		Goal * tail;
	
	public:
		List()
		{
			head=NULL;
			tail=NULL;
		}
		
		void createNode(string desc="",float prog=0)
		{
			Goal * temp =new Goal;
			temp->goal_desc = desc;
			temp->progress = prog;
			
			if(head==NULL)
			{
				head =temp;
				temp = NULL;
				tail= temp;
			
			}
			else
			{
				tail->next=temp;
				tail=temp;
			}
			delete temp;
		}
	
	void display()
	{
		Goal *temp = new Goal;
	    temp=head;
	    while(temp!=NULL)
	    {
	      cout<<temp->goal_desc<<"\t  "
		  	  <<temp->progress<<endl;
		  	  
	      temp=temp->next;
	    }
	    delete temp;
	}
};

#endif
