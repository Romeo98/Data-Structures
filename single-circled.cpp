// Basic circular single-linked list functions

#include <iostream>

struct Node {
	int data;
	Node *next;
};

class List {
	private:
		Node *Head;
	
	public:
		List() : Head(NULL)
		{ }

		void Node_insFirst(int &);
		void Node_insLast(int &);
		void Node_insBefore(int &, int &);
		void Node_insAfter(int &, int &);
		void Node_Delete(int &);
/*
		void list_delete();
		void recdelete(Node *);

		void list_recshow();
        void recshow(Node *);
*/		
		void List_Show();
};


int main() {
    List Object;
	int data, dataRF;
	char option;

	do {
		std::cout << "MENU\n\n";
		std::cout << "1) Insert node at the beginning\n";
		std::cout << "2) Insert node at the end\n";
		std::cout << "3) Insert node before\n";
		std::cout << "4) Insert node after\n";
		std::cout << "5) Delete node\n";
		std::cout << "6) Delete list\n";
		std::cout << "7) Show list\n";
		std::cout << "8) Show inverted list\n";
		std::cout << "9) Salir\n\n";
		std::cout << "Your option is: ";

		std::cin >> option;
		system("clear");

		if(option != '9') 

			switch(option) {
				
				case '1': 
					std::cout << "Exit ctrl-d\n";
					while(std::cin >> data)
						Object.Node_insFirst(data);
					break;
				
				case '2':
					std::cout << "Exit ctrl-d\n";
					while(std::cin >> data)
						Object.Node_insLast(data);
					break;
				
				case '3':
					std::cout << "Enter data & datarRF\n";
					std::cin >> data >> dataRF;
					Object.Node_insBefore(data, dataRF);
					break;
				
				case '4':
					std::cout << "Enter data & datarRF\n";
					std::cin >> data >> dataRF;
					Object.Node_insAfter(data, dataRF);
					break;
				
				case '5':
					std::cout << "Enter dataRF\n";
					std::cin >> dataRF;
					Object.Node_Delete(dataRF);
					break;
				
/*				case '6':
					Object.List_Delete();
					break;

				
				case '7':
					Object.List_Show();
					break;
				
				case '8':
					Object.List_recShow();
*/					
			}

		else 
			break;
		
		std::cout << '\n';
		Object.List_Show();
		std::cin.clear();
		std::cin.ignore();

    } while(true);

}


void List::Node_insFirst(int &data) {
	Node *New = new Node;
	New->data = data;

	if(!Head) {
		Head = New;
		New->next = Head;
		return;
	}
	
	Node *Temp = Head;

	while(Temp->next != Head) 
		Temp = Temp->next;

	Temp->next = New;
	New->next = Head;
	Head = New;
}

void List::Node_insLast(int &data) {
	if(!Head)
		return Node_insFirst(data);

	Node *Temp = Head;

	while(Temp->next != Head)
		Temp = Temp->next;
	
	Node *New = new Node;
	New->data = data;
	New->next = Head;
	Temp->next = New;
}

void List::Node_insBefore(int &data, int &dataRF) {
	if(!Head || Head->data == dataRF)
		return Node_insFirst(data);
	
	Node *Temp = Head;

	while(Temp->next != Head && (Temp->next)->data != dataRF)
		Temp = Temp->next;

	if( (Temp->next)->data == dataRF) {
		Node *New = new Node;
		New->data = data;
		New->next = Temp->next;
		Temp->next = New;
	}
}

void List::Node_insAfter(int &data, int &dataRF) {
	if(!Head)
		return Node_insFirst(data);
	
	Node *Temp = Head;

	while(Temp->next != Head && Temp->data != dataRF)
		Temp = Temp->next;

	if(Temp->data == dataRF) {
		if(Temp->next == Head)
			return Node_insLast(data);
		
		Node *New = new Node;
		New->data = data;
		New->next = Temp->next;
		Temp->next = New;
	}
}

void List::Node_Delete(int &dataRF) {
	if(!Head)
		return;
	
	Node *Temp1 = Head, *Temp2 = NULL;

	if(Temp1->data == dataRF) {
		
		if(Temp1->next == Head) {
			delete Temp1;
			Head = NULL;
			return;
		}
		
		Temp2 = Head;

		while(Temp2->next != Head)
			Temp2 = Temp2->next;
		
		Head = Head->next;
		Temp2->next = Head;
		delete Temp1;
		return;
	}
	
	while(Temp1->next != Head && (Temp1->next)->data != dataRF)
		Temp1 = Temp1->next;
	

	if( (Temp1->next)->data == dataRF) {
		Temp2 = Temp1->next;
		Temp1->next = (Temp1->next)->next;
		delete Temp2;
	}	
}

void List::List_Show() {
	if(!Head) {
		std::cout << "Empty List\n";
		return;
	}

	Node *Temp= Head;

	std::cout << "\n\n";

	do {
		std::cout << Temp->data << '\n';
		Temp = Temp->next;
	} while(Temp != Head);
}

