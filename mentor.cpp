/*
 Mentor Graphics interview code
 Adding a integer element to an link list, no duplicates and the array is sorted smalled to largest.
 This is quick code for an interview with Mentor Graphics, if more time was given i would make classes.
 */

struct node {
	int val;
	node * next;
}

int main(int argc, char * const argv[]){
	node * tempptr = new node;
	tempptr ->val = value;
	tempptr->next = null;
	
	node * ptr2 = head;
	node * ptr = NULL;
	
	if(head == NULL){
		head = new node;
		head->val = value;
		head->next = NULL;
	}
	else{
		while(ptr2 != null)
		{
			if(ptr2->val >= tempptr->val)
				break;
			ptr = ptr2;
			ptr2 = ptr2->next;
		}
		if(ptr == null)
		{
			tempptr->next = head;
			head = tempptr;
		}
		else if(ptr2->val != value)
		{
			ptr2->next = tempptr;
		}
	}
	
	return 1;
}
