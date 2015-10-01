/*This assignment includes stack operations.
Name: Laura Machado
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// FYI - I added capacity, in order to determine whether the program can push a value onto the stack.
struct myStack{

	int *data;
	int size;
	int capacity;
};

typedef struct myStack Stack;

//Part A - Create a stack of a given size.
void Stack_Init(Stack *S, int size){
	
	S->data=malloc(size*sizeof(int));
	assert(S!=NULL);
	S->size=0;
	S->capacity=size;

}

//Part B - Returns the value of the element on top.
int peek(Stack *S){

	int value;
	assert(S->data!=NULL);
	value=S->data[S->size-1];

	return value;
}


// Part C - Pushes some integer onto the stack.
void Stack_Push(Stack *S, int d){
	
	if(S->size<S->capacity){
		S->data[S->size]=d;
		S->size+=1;
	}

}

//Part D - Returns the value of the element on top and removing it;
int Stack_Pop(Stack *S){
	
	int value;
	value=S->data[S->size-1];
	S->size-=1;
	return value;


}

//Part E - Doubles the size of the stack.
void DoubleSize(Stack *S){

	int temp[S->size];
	int newCapacity=S->capacity*2;
	int size=S->size;
	int i;

	for(i=0;i<S->size;i++){

		temp[i]=S->data[i];
	}


	S->data=malloc(newCapacity*(sizeof(int)));
	assert(S!=NULL);

	S->size=size;
	S->capacity=newCapacity;

	for(i=0;i<S->size;i++){

		S->data[i]=temp[i];

	}

}

//Part F - Halves the size of the stack.
void HalveSize(Stack *S){

	int newCapacity=S->capacity/2;
	int newSize;
	int temp[newCapacity];
	int i;

	if(S->size<=newCapacity){
		newSize=S->size;
	}else{
		newSize=newCapacity;
	}

	for(i=0;i<newSize;i++){

		temp[i]=S->data[i];
	}

	S->data=malloc(newCapacity*(sizeof(int)));
	assert(S!=NULL);

	S->size=newSize;
	S->capacity=newCapacity;


	for(i=0;i<newSize;i++){

		S->data[i]=temp[i];
	}

}

//Part G - Returns the index of element whose value is e.
int search(Stack *S, int e){

	int i;

	for(i=0;i<S->size;i++){

		if(S->data[i]==e){
			return i;
		}
	}

	return -1;

}

//Part H - Destroy the Memory allocated to the stack.
void destroy(Stack *S){

	int i;

	for(i=0;i<S->size;i++){
		free(S->data);
	}
	S->size=0;
	S->capacity=0;

}

//Part I - Returns 1 if stack is full, 0 if not full.
int stackFull(Stack *S){

	if(S->capacity==S->size){

		return 1;
	}else{

		return 0;
	}
}

//Part J - Reverse the order of the elements in the stack.
void Reverse(Stack *S){

	int i;
	int n;
	int value;
	Stack *P=malloc(sizeof(Stack));
	assert(P!=NULL);
	
	Stack_Init(P,S->size);
	n=S->size;
	

	for(i=0;i<n;i++){
		value=Stack_Pop(S);
		Stack_Push(P,value);
	}

	S->data=P->data;
	S->size=P->size;
	S=P;
	free(P);
	
}


int main (void){


	Stack *S;
	S=malloc(sizeof(Stack));
	assert(S!=NULL);

	int size=8;
	int i;

	Stack_Init(S,size);

	printf("Using push to insert values into the stack: ");
	for(i=0;i<size;i++){
		Stack_Push(S,i);
		printf("%d ", S->data[i]);
	}

	printf("\n\nTo demonstrate the peek function: %d", peek(S));

	printf("\n\nUsing pop to remove values from the stack: %d\nNew Stack: ", Stack_Pop(S));

	for(i=0;i<S->size;i++){

		printf("%d ", S->data[i]);
	}

	printf("\n\nTo demonstrate double in stack capacity: \nOld Capacity: %d\nOld Size: %d", S->capacity,S->size);

	DoubleSize(S);

	printf("\nNew Capacity: %d\nNew Size: %d", S->capacity, S->size);

	printf("\n\nTo demonstrate double in stack capacity: \nOld Capacity: %d\nOld Size: %d", S->capacity,S->size);

	HalveSize(S);

	printf("\nNew Capacity: %d\nNew Size: %d", S->capacity, S->size);

	printf("\n\nTo demonstrate search function: \nArray: ");
	
	for(i=0;i<S->size;i++){

		printf("%d ", S->data[i]);
	}

	printf("\nFind the index for 5: %d", search(S,5));

	printf("\n\nTo demonstrate reverse function: \nArray: ");

	for(i=0;i<S->size;i++){

		printf("%d ", S->data[i]);
	}

	Reverse(S);

	printf("\nReverse: "); 
		

	for(i=0;i<S->size;i++){

		printf("%d ", S->data[i]);
	}

	return 0;
}


