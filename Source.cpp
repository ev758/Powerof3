#include<iostream>
using namespace std;

//function prototypes
bool isPowerOfThree(int userNumPar);

struct userNode {
	int item; //item of node
	userNode* link; //link to another node
};


int main() {

	//declarations
	int userNum;
	const int MAXWHOLENUM = 10;

	//creates the initial node for the head node
	userNode* head = new userNode; //points to the head node
	head->item = 3;
	head->link = nullptr;

	//creates an initial link list of numbers based on user input
	//get user input
	userNode* nextUserNode = new userNode;
	nextUserNode = head; //nextUserNode is first node

	for (int i = 0; i < MAXWHOLENUM; i++)
	{
		nextUserNode->link = new userNode; //creates a node at the end of the list
		nextUserNode = nextUserNode->link; //points to that node
		nextUserNode->link = nullptr;

		cout << "Enter number " << (i + 1) << ": ";
		cin >> nextUserNode->item;
	}

	//output
	//traverse the linked list and displays output
	cout << endl << "The following numbers are powers of 3: " << endl;
	nextUserNode = head->link;
	while (nextUserNode != nullptr) {
		if (isPowerOfThree(nextUserNode->item)) {
			cout << nextUserNode->item << " ";
			nextUserNode = nextUserNode->link;
		}
		else
			nextUserNode = nextUserNode->link;

	}

	//deletes the head node from the free store memory
	delete nextUserNode;
	nextUserNode = nullptr;

	delete head;
	head = nullptr;

	return 0;
}

//function definition
bool isPowerOfThree(int userNumPar) {
	if (userNumPar % 3 == 0) {

		while (userNumPar % 3 == 0) {
			userNumPar = userNumPar / 3;

		}

		if (userNumPar != 1) {
			return false;
		}

		return true;
	}
	else
		return false;
}