// Double circular-linked list functions

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
/*
		void list_delete();
		void recdelete(Node *);

		void list_recshow();
        void recshow(Node *);
*/
        void List_Show();
};


int main() {
    List object;
	int data, datarf;
	char option;

	do {
		std::cout << "menu\n\n";
		std::cout << "1) insert node at the beginning\n";
		std::cout << "2) insert node at the end\n";
		std::cout << "3) insert node before\n";
		std::cout << "4) insert node after\n";
		std::cout << "5) delete node\n";
		std::cout << "6) delete list\n";
		std::cout << "7) show list\n";
		std::cout << "8) show inverted list\n";
		std::cout << "9) salir\n\n";
		std::cout << "your option is: ";

		std::cin >> option;
		system("clear");

		if(option != '9') 

			switch(option) {
				
				case '1': 
					std::cout << "exit ctrl-d\n";
					while(std::cin >> data)
						object.Node_insFirst(data);
					break;
				
				case '2':
					std::cout << "exit ctrl-d\n";
					while(std::cin >> data)
						object.Node_insLast(data);
					break;
				
				case '3':
					std::cout << "enter data & datarrf\n";
					std::cin >> data >> datarf;
					object.Node_insBefore(data, datarf);
					break;
				
				case '4':
					std::cout << "enter data & datarrf\n";
					std::cin >> data >> datarf;
					object.Node_insAfter(data, datarf);
					break;
				
				case '5':
					std::cout << "enter datarf\n";
					std::cin >> datarf;
					object.Node_Delete(datarf);
					break;
				
/*				case '6':
					object.list_delete();
					break;

				
				case '7':
					object.list_show();
					break;
				
				case '8':
					object.list_recshow();
*/					
			}

		else 
			break;
		
		std::cout << '\n';
		object.List_Show();
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
        New->previous = Head;
        return;
    }

    Node *Temp = Head;

    while(Temp->next != Head) 
        Temp = Temp->next;

    New->next = Head;
    New->previous = Temp;
    Head->previous = New;
    Temp->next = New;
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
    New->previous = Temp;
    Temp->next = New;
    Head->previous = New;
}

void List::Node_insBefore(int &data, int &dataRF) {
    if(!Head || Head->data == dataRF)
        return Node_insFirst(data);

    Node *Temp = Head;

    while(Temp->next != Head && Temp->next->data != dataRF)
        Temp = Temp->next;


    if( (Temp->next)->data == dataRF) {
        Node *New = new Node;
        New->data = data;
        New->next = Temp->next;
        New->previous = Temp;
        (New->next)->previous = New;
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
        New->previous = Temp;
        (New->next)->previous = New;
        Temp->next = New;
    }
}

void List::Node_Delete(int &dataRF) {
    if(!Head)
        return;

    Node *Temp1 = Head, *Temp2 = NULL;

    if(Temp1->data == dataRF) {
        
        if(Temp1->next = Head) {
            delete Temp1;
            Head = NULL;
        }

        else {
            Temp2 = Head;

            while(Temp2->next != Head)
                Temp2 = Temp2->next;

            Head = Head->next;
            Head->previous = Temp2;
            Temp2->next = Head;
            delete Temp1;
        }

        return;
    }

    while(Temp1->next != Head && (Temp1->next)->data != dataRF)
        Temp1 = Temp1->next;

    if( (Temp1->next)->data == dataRF) {
        Temp2 = Temp1->next;

        if(Temp2->next == Head) {
            Temp1->next = Head;
            Head->previous = Temp1;
            delete Temp2;
        }

        else {
            (Temp2->next)->previous = Temp1;
            Temp1->next = (Temp1->next)->next;
            delete Temp2;
        }
    }
}

void List::List_Show() {
    if(!Head) {
        std::cout << "Empty list\n";
        return;
    }

    Node *Temp1 = Head, *Temp2 = NULL;

    do {
        std::cout << Temp1->data << '\n';
        Temp2 = Temp1;
        Temp1 = Temp1->next;
    } while(Temp1 != Head);
    
    std::cout << "\n\n";

    while(true) {
        std::cout << Temp2->data << '\n';
        Temp2 = Temp2->previous;

        if(Temp2 == Head) {
            std::cout << Temp2->data << '\n';
            break;
        }
    }
}
