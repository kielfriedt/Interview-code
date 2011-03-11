/*
 Adding a integer element to an link list, no duplicates and the array is sorted smalled to largest.
 
 Cases: Adding integer 10 to the list
 1) head -> null
 2) head -> 2 -> null
 3) head -> 2 -> 10 
 4) head -> 11 -> 12
 5) head -> 8 -> 11
 
 This is quick code for an interview with Mentor Graphics, if more time was given i would make classes.
 */

struct node {
	int val;
	node * next;
}


int main(int argc, char * const argv[]){
	int value = 10;
	node * head = NULL;
	node * ptr;
	node * ptr2;
	if (head == NULL) {
		head = new node;
		head -> val = value
		head -> next = NULL;
	}else {
		ptr = head;
		ptr2 = head -> next;
		while (ptr2 != NULL){
			if(ptr -> val < value){
				if(ptr2 == NULL) // ptr < value but ptr equals null
				{
					ptr2 = new node;
					ptr2 -> val = value;
					ptr2 -> next = NULL;
					break;
				}else if (ptr2 -> val != value) {  //ptr < value and ptr != value, move on
					ptr = ptr -> next;
					ptr2 = ptr -> next;
					continue;
				}else if( ptr2 -> val == value) //ptr2 -> val equals value
					break;
			}else if( ptr -> val == value){  //ptr -> val equals value
				break;
			}else{  // ptr -> val > value
				ptr -> next = new node;
				int temp = ptr -> val;
				ptr -> val = value;
				ptr = ptr -> next;
				ptr -> val = temp;
				ptr -> next = ptr2;
			}
		}
	}
	if (ptr2 == NULL) {
		ptr2 = new node;
		ptr2 -> val = value;
		ptr2 -> next = NULL;
	}
}







return 1;
}


