//binary search tree implementation in C
#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

void inorder_traverse(struct node* node){
	if(node->left != NULL){
		inorder_traverse(node->left);
	}

	printf(" -> %d",node->data);
	
	if(node->right != NULL){
		inorder_traverse(node->right);
	}
}

void insert_node(int data, struct node* start){
	if(start->left == NULL )

	if(data < start->data){
		//also have to check start->left is not null i.e
		if(start->left != null){
			insert_node(data, start->left);
		} else {
			start->left = ())
		}
	}
	else {
		//also have to check start->right is not null
		insert_node(data, start->right);
	}
}

int main() {
	int choice;

	do {
		printf("make a selection...\n");
		printf("	1. insert node in the tree\n	2. delete a node from the tree\n	3. search a node in tree\n	4: traverse the tree\n	99. exit the program\n");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				break;

			case 2:
				break;

			case 3:
				break;

			default:
				break;
		}

	}while(choice != 99);
	
	return 0;
}
