#include<iostream>
using namespace std;

	//void delete1(int &h);
	//void bubble(int &n);
	//void linearsearch(int &n);
	//void binarysearch(int &n);
int count1=0;

	class node
	{
	    public:int data;
	    node *next;
	    node *prev;
	};

    node* delete1(node *head);
    node* insert1(node *head);
    node* llsort(node *head);
	node* insert_position(node *head);
	void display(node *head);
node* last=NULL;
int main()
{

    node *head=NULL,*last=NULL;
	int n,c;
    display(head);
	do
	{       cout<<"\n*********************************\n";

		cout<<"\n\n\n enter your choice \n 1:insert. \n 2.accept at a particular position \n 3.delete from a particular postion. \n 4.display sort. \n 5.sort \n 0.exit.";
		cin>>c;
		switch(c)
		{
			case 1:{
				head=insert1(head);
				display(head);
				count1++;
				break;
				}
            case 2:{
				head=insert_position(head);
				display(head);
				count1++;
				break;
				}
			case 3:{
				head=delete1(head);
				count1--;
				break;
				}
			case 4:{
				display(head);
				break;
				}
			case 5:{
				head=llsort(head);
				break;
				}
 /*
			case default:{
					cout<<"\n wrong input entered!!!";
					break;
				      }
*/
		}
	    cout<<"\n___________________________________________________\n";
	}while(c!=0 && c<6 && c>0);
	return 0;
}

    node* llsort(node *head){
        node *s,*ptr,*nextptr,*end1,*checkend1;
        s=ptr=head;
        end1=last;
        nextptr=ptr->next;
        checkend1=last;

       do
            {
                ptr=head;
                nextptr=ptr->next;
                if(ptr->data>nextptr->data && nextptr->prev==head){
                    nextptr->next->prev=ptr;//
                    ptr->next=nextptr->next;//
                    ptr->prev=nextptr;//
                    nextptr->prev=NULL;//
                    nextptr->next=ptr;//
                    head=nextptr;
                    s=head;
                    nextptr=ptr;
                    ptr=s;//to move ptr back anf move nextptr ahead and get them in seq ptr n then nextptr

                    ptr=nextptr;
                    nextptr=nextptr->next;// move both pointers ahead

                }else
                {
                    ptr=nextptr;
                    nextptr=nextptr->next;// move both pointers ahead
                }
                 cout<<"\n tttttttttttttttt  befor while:::: end"<<end1->data;
                  while(ptr->next!=last)
                        {
                         cout<<"\n ;;;"<<ptr->data;
                         cout<<"\n ;;;]]]"<<nextptr->data;
                         cout<<"\n ;;;]]]___"<<ptr->prev->data;
                    if(ptr->data>nextptr->data )
                    {   cout<<"\n....";
                        ptr->prev->next=nextptr;
                        nextptr->next->prev=ptr;

                        nextptr->prev=ptr->prev;
                        ptr->next=nextptr->next;

                        ptr->prev=nextptr;
                        nextptr->next=ptr;



                         ptr=nextptr;
                         nextptr=nextptr->next;//to move ptr back anf move nextptr ahead and get them in seq ptr n then nextptr


                        cout<<"\n before"<<ptr->data;
                         cout<<"\n ;;;]]],cccc,,"<<nextptr->data;

                         ptr=nextptr;
                         nextptr=nextptr->next;// move both pointers ahead


                         cout<<"\n aftter"<<ptr->data;
                         cout<<"\n ;;;]]],cccc,,"<<nextptr->data;

                    }else
                    {   cout<<"\n  move both pointers ahead";
                         ptr=nextptr;
                         nextptr=nextptr->next;// move both pointers ahead
                    }
                         cout<<"\n ;;;"<<ptr->data;
                         cout<<"\n ;;;]]],cccc,,"<<nextptr->data;

                    }
                    cout<<"\n tttttttttttttttt  befor while:::: end"<<end1->data;

                    cout<<"\n ;;;"<<ptr->data;
                         cout<<"\n ;;;]]],,,"<<nextptr->data;

                    if(nextptr->next==NULL && end1==last)
                    {

                        if(ptr->data>nextptr->data)
                         {
                             ptr->prev->next=nextptr;
                             nextptr->prev=ptr->prev;
                             ptr->next=NULL;
                             last=ptr;
                             nextptr->next=ptr;
                             ptr->prev=nextptr;
                             end1=last;
                         }
                    }
             checkend1=checkend1->prev;
            }while(checkend1!=NULL);
     return head;
    }

    void display(node *head)
		{
			if(head==NULL)
            {
                cout<<"\n the link list is empty!!!";
            }else
            {
                node *currnode=head;
                while(currnode!=NULL)
                {
                    cout<<currnode->data<<"  ";
                    currnode=currnode->next;
                }

                cout<<"\n...reverse";
                currnode=last;
                int x=0;
                while(currnode!=NULL)
                { x++;
                    cout<<currnode->data<<"  ";
                    currnode=currnode->prev;
                }

            }
		}

    node* delete1(node *head)
    {
       int value;
        node *temp=head,*nexttemp=temp->next;
        cout<<"\n enter the value to be deleted:";
        cin>>value;
        if(temp->data==value && temp==head)
        {
            head=head->next;
            if(head!=NULL)
                head->prev=NULL;
        }
        else
        {
            while(temp->next!=NULL && temp->next->data!=value)
                {
                    temp=temp->next;
                }
                 if(temp->next==NULL){
                        cout<<"\n the value is not found!!!";
                    }
                else
                    {
                        nexttemp=temp->next;
                        if(nexttemp->next!=NULL)
                            {
                                temp->next=nexttemp->next;
                                nexttemp->next->prev=temp;

                            }else
                            {   if(nexttemp->next==NULL)
                                {
                                    temp->next=NULL;
                                }
                            }
                    }
        }
        return head;
    }

	node* insert1(node *head)
	{   node *currnode=head;
        if(head==NULL)
        {
            node *a;
            a=new(node);
            cout<<"\n enter the value:";
			cin>>a->data;
			a->next=NULL;
			a->prev=NULL;
			head=last=a;
        }else
        {
            node *a;
            a=new(node);
            cout<<"\n enter the value:";
			cin>>a->data;
			a->prev=NULL;
			a->next=head;
			head->prev=a;
			head=a;
        }
            return head;
	}

    node* insert_position(node *head){
        int pos;
        node *temp=head;
        cout<<"\n enter the position to be inserted:";
        cin>>pos;
            node *a;
            a=new(node);
            cout<<"\n enter the value:";
			cin>>a->data;
			a->next=NULL;

        if(pos==1)
        {
            a->prev=NULL;
            a->next=head;
			head->prev=a;
			head=a;

        }else
            {
                if(pos<=count1+1){
                for(int i=1;i<pos-1;i++)
                {
                    temp=temp->next;
                }
                a->next=temp->next;
                a->prev=temp;
                temp->next=a;
                if(pos==count1+1)
                    {
                        last=a;
                    }
                }
                else
                {
                    cout<<"\n position out of bound!!!";
                }
            }
        return head;
    }
