#include <stdio.h>
#include <string.h> // get method strcmp
#include <stdlib.h> //get function clear screen
#include <conio.h>  //include getchar with stop loop

typedef struct node
{
	int id;
	char name[45];
	double price;
	struct node *next;
} product;

/* function prototypes */
product *initnode(char *, int);
	void printnode(product *);
	void printlist(product *);
	void add(product *);
product *searchname(product *, char *);
	void deletenode(product *);
	void insertnode(product *);
 	void deletelist(product *);

product *head =NULL;
product *end = NULL;

product *initnode(int id, char *name, double price)//get data from int main && get new node
{
	//set new node 
	product *ptr;
	ptr = new product;
	ptr->id = id;
	strcpy(ptr->name, name);
	ptr->price = price;
	ptr->next = NULL;
	return ptr;
}

void printnode(product *ptr)
{
	printf("\t%d\n\t%s\n\t%.2lf\n", ptr->id, ptr->name, ptr->price); //show data 
}
//function travesal
void printlist(product *ptr)
{	
	printf("\tID\n\tNAME\n\tPRICE\n");
	//loop check if ptr there is a NULL
	while (ptr != NULL)
	{
		/* code */
		printnode(ptr);
		ptr = ptr->next; //pointer ptr equal to the next ptr
	}
	
}

void add(product *newptr)//get address, data from product 
{
	if(head == NULL)//check list is null   
	    head = newptr; //head equal the newptr
	else
		end->next = newptr; //pointer end to the next end = newptr
	end = newptr; //The last of node is equal to newptr.
}

product *searchname(product *ptr, char *name)
{
	if(head == NULL) return NULL; //check if head is NULL  return NULL
	while (strcmp(ptr->name, name) != 0) //Returns a value of 1 ,until it is equal to 0.
	{
		/* code */
		ptr = ptr->next; //pointer to next the ptr

		// check if ptr == NULL break loop   and return address ptr;
		if(ptr == NULL) 
			break;
		return ptr;
	}
	
}
//function deletenode for apply doubly linklist
void deletenode(product *ptr)
{
	product *start, *prev; ///declar pointer start and prev 
	start = ptr;///start point to start
	prev = head;//prev point to head
	if(start == prev) {
		head = head->next;//head point to head(index2)
		if(end == start)
		{
			end = end->next;
		}/// end point to NULL
		delete(start); ///retrive to memory
	}
	else
	{
		while(prev->next != start) {
			prev = prev->next; ///pointer end to the next end = newptr
						
		}
		prev->next = start->next;
		if (end == start) 
		{
			/* code */
			end = prev;
		}
		delete(start); ///retrive to memory
		
	}
	
}
//function insert node to sort data follow name
void insertnode(product *newptr)
{	
	
	product *start, *prev; ///declar pointer to apply search
	//step 1 :check nodeindex is NULL
	if(head == NULL){ 
		head = newptr; //add newptr to node head(index)
		end  = newptr; // add newptr to node end(last)
		return;
	}
	start = head; //pointer start  point to the (node index)

	while (strcmp(start->name, newptr->name) < 0) // return value 0 , 1 until value to 0  and return
	{
		start = start->next;
		if (start->next == NULL) {//check start equal lastnode gave break 
			break;
		}
		if(start == head) {
			newptr->next = head;
			head = newptr;
		}
		else{
			prev = head;
			while (prev->next != start) 
			{
				/* code */
				prev = prev->next;

			}
			prev->next = newptr;// prev equal address start
			newptr->next = start;// newptr equal address start
			if(end == prev) {
				end = newptr;
			}

		}
			
	}
}

//function del node and exit to program
void deletelist(product *ptr)
{
	product *start;
	while (ptr != NULL) 
	{
		/* code */
		start = ptr->next; //start point to  the next node ptr
		delete(ptr);// delete node ptr
		ptr = start; // node ptr equal start

	}
	head = NULL;// define node head is NULL 
	end = NULL;//define node end is NULL 
	
}

int main()
{
	int id;
	char name[20];
	double price;
	int ch = 1;
	product *ptr;

	while (ch != 0)
	{
		system("cls");//clear screen always to search
		printf("1 add a name \n");
		printf("2 delete a name \n");
		printf("3 list all names \n");
		printf("4 search for name \n");
		printf("5 insert a name \n");
		printf("0 quit\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter in id : ");
			scanf("%d", &id);
			printf("Enter in name : ");
			scanf("%s", name);
			printf("Enter in price : ");
			scanf("%d", &price);
			ptr = initnode(id, name, price);
			add(ptr);
			break;
		case 2:
			printf("Enter name product for del : ");
			scanf("%s", name);
			ptr = searchname(head, name);
			if(ptr == NULL) //check if ptr is NULL Afterwards return name in ptr
				printf("Name :%s NOT Found", name);
			else{
				deletenode(ptr);
				printf("Data deleted"); //delete value in ptr
			}
			getch();
			
			break;

		case 3:
			printlist(head);
			// getch(); //clear screen
			break;

		case 4:
			printf("Enter name product for del : ");
			scanf("%s", name);// get name to search
			ptr = searchname(head, name);//search name and return to ptr
			if (ptr == NULL) //check if ptr is NULL Afterwards return name in ptr
				printf("Name :%s NOT Found", name);
			else
			{
				printf("DATA Complete to SearchNode: "); 
				printnode(ptr);//show data from address ptr
			}
			getch();
			break;
		case 5:
			printf("Enter in id : ");
			scanf("%d", &id);
			printf("Enter in name : ");
			scanf("%s", name);
			printf("Enter in price : ");
			scanf("%d", &price);
			ptr = initnode(id, name, price);
			insertnode(ptr);
			break;
		}
	}
	deletelist(head);
}
