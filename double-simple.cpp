// Double single-linked list functions

#include <iostream>

struct Node {
    int data;
    Node *previous, *next;
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

		void List_Delete();
		void recDelete(Node *);

		void List_recShow();
        void recShow(Node *);

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
				
				case '6':
					Object.List_Delete();
					break;
				
				case '7':
					Object.List_Show();
					break;
				
				case '8':
					Object.List_recShow();
					break;
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
    New->next = Head;
    New->previous = NULL;
    Head->previous = New;
    Head = New;
}

void List::Node_insLast(int &data) {
    if(!Head)
        return Node_insFirst(data);

    Node *Temp = Head;
    
    while(Temp->next)
        Temp = Temp->next;
    
    Node *New = new Node;
    New->data = data;
    New->next = Temp->next;
    New->previous = Temp;
    Temp->next = New;
}

void List::Node_insBefore(int &data, int &dataRF) {
    if(!Head || Head->data == dataRF)
        return Node_insFirst(data);

    Node *Temp = Head;

   while(Temp->next && (Temp->next)->data != dataRF) 
       Temp = Temp->next;
    
    if( (Temp->next)->data == dataRF) {
        Node *New = new Node;
        New->data = data;
        New->next = Temp->next;
        New->previous = Temp;
        (Temp->next)->previous = New;
        Temp->next = New;
    }
}

void List::Node_insAfter(int &data, int &dataRF) {
    if(!Head)
        return Node_insFirst(data);
    
    Node *Temp = Head;

    while(Temp->next && Temp->data != dataRF) 
        Temp = Temp->next;

    if(Temp->data == dataRF) {
        if(Temp->next)
            return Node_insLast(data);

        Node *New  = new Node;
        New->data = data;
        New->next = Temp->next;
        New->previous = Temp;
        (Temp->next)->previous = New;
        Temp->next = New;
    }
}

void List::Node_Delete(int &dataRF) {
    if(!Head)
        return;
    
    Node *Temp1 = Head, *Temp2 = NULL;

    if(Temp1->data == dataRF) {
        Head = Head->next;
        Head->previous = NULL;
        delete Temp1;
    }

    while(Temp1->next && (Temp1->next)->data != dataRF) 
        Temp1 = Temp1->next;

    if(Temp1->next) {
        Temp2 = Temp1->next;
        Temp1->next = (Temp1->next)->next;
        Temp1->next->previous = Temp1;
        delete Temp2;
    }
} 

void List::List_Delete() {
    recDelete(Head);
    Head = NULL;
}

void List::recDelete(Node *Temp) {
    if(!Head)
        return;

    if(Temp) 
        recShow(Temp->next);

    delete Temp;
}

void List::List_recShow() {
    recShow(Head);
}

void List::recShow(Node *Temp) {
    if(!Head)
        return;

    if(Temp) {
        recShow(Temp->next);
        std::cout << Temp->data << '\n';
    }
}

void List::List_Show() {
    if(!Head) {
        std::cout << "Empty List\n";
        return;
    }
    
    Node *Temp = Head;

    while(Temp) {
        std::cout << Temp->data << '\n';
        Temp = Temp->next;
    }
    
    std::cout << "\n\n";
    
    do {
        std::cout << Temp->data;
        Temp = Temp->previous;
    } while(Temp);
    
}
