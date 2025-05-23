
  #include<stdio.h>
  #include<stdlib.h>  //It has malloc() & free() declaration
  
  //Structure Declaration
  struct Node  //Self Referential Structure - It has a next pointer of its own type
  {
  	int data;  
  	struct Node *next;  
  }; 		

  void append(struct Node **,int); 
  void display(struct Node*);   
  int count(struct Node *);  
      
  int main()
  {
  	struct Node *start=NULL;    	
  	int x,option;
	char choice;	
	do
	{
		printf("Enter the option from following 1.Append/Create a Node 2.Display List 3.Count Nodes 4.Exit  \n");
		printf("Enter your option ");
		scanf("%d",&option);
		
		switch(option)
		{
					
			case 1 :
				     	printf("Enter a value to be stored in the new node ");
		                scanf("%d",&x); 
		                append(&start,x); 
				        break;
			case 2 :
				        display(start); 
				        break;
			case 3 :				        
				        printf("Number of Nodes in the list are %d\n",count(start));
				        break;		
			case 4 :
				        printf("Thanks for using our App");
				        exit(0); //#include<stdlib.h>				      
			
			default :
				        printf("Invalid Choice");
		}//end of switch
		
		fflush(stdin);  //To flush the stdin (input) buffer
		printf("Do you want to continue (y/n) ");
		scanf("%c",&choice);
	}while(choice=='y'||choice=='Y');	
	printf("Thank You");
}  //end of main()

        
  //append() - adds a new node at the end of the list
  void append(struct Node **ps,int x)  
  {  	
	struct Node *p,*temp;  
	
  	//NEW NODE CREATED WITH DATA AND NEXT SECTION VALUES
	p=(struct Node *)malloc(sizeof(struct Node));  //type casting of struct pointer
  	p->data=x;	//put value of x in the data section pointed by p
  	p->next=NULL;  //As of now its the last node hence put NULL in its next section
   	
   	//NOW CONNECT THIS NODE IN THE LIST
  	//This if is True only when 1st Node is created else always False  	
	if(*ps==NULL) //*ps means start (value at address pointed by ps) has NULL value
  	{
  	  *ps=p;   //Assign address of first node pointed by p to start by writing *ps
  	   return; 
	} //end of if
	else //Means its not the first node to be created
	{
	  //temp pointer pointing to the address of the first node for traversing the list
	  temp=*ps; 
	  /* a loop which travels from first node till last node where loop will stop and in the next of last node put NULL */
	   while(temp->next!=NULL) 
	   {
	    temp=temp->next;  //dont write temp++ because it will jump by 4bytes similar to i++ in loops   		
	   }
	   //once loop stops assign the address of new node currently pointed by p to the next pointer of the node pointed by temp which will become second last node in the list
	  temp->next=p;  	
    }//end of else
  } //end of append()
    
  //display() - the entire list
  void display(struct Node *p) //p pointing to start pointer and only p pointer is required in the body
  {
  	if(p==NULL)  //if True no node exist and if its False means atleast one node exist in the list
  	{
  	  printf("List is Empty\n");
  	  return;
	}
	
	//a loop runs from first node till the last node which has NULL value
	while(p!=NULL)
	{
	  printf("%d\n",p->data);  //print the data part of the node
	  p=p->next;  //p will now point to the next node in the list
	}
  } //end of display()
  
  //count() same as display() - returns number of nodes currently stored in the list
  int count(struct Node *p)
  {
  	int count=0;  //CHANGE IN display()	  	
	while(p!=NULL)
	{
	    count++;  //CHANGE IN display()
		p=p->next; //p will now point to the next node in the list
	}	
	return count; //CHANGE IN display()
  } //end of count()
  
   
