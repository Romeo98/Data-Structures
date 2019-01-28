#include <iostream>

class Ilist {
protected:
    struct Node {
        int data;
        Node *next, *previous;
    };

    Node *Head;

public:

    Ilist() : Head(NULL) {}

    virtual void Node_insFirst(int) = 0;
    virtual void Node_insLast(int) = 0;
    virtual void Node_insBefore(int, int) = 0;
    virtual void Node_insAfter(int, int) = 0;
    virtual void Node_Delete(int) = 0;
    virtual void List_Show() = 0;
};

class SS : public Ilist {
public:
    void Node_insFirst(int) override;
    void Node_insLast(int) override;
    void Node_insBefore(int, int) override;
    void Node_insAfter(int, int) override;
    void Node_Delete(int) override;
    void List_Show() override;
};

class SD : public Ilist {
public:
    void Node_insFirst(int) override;
    void Node_insLast(int) override;
    void Node_insBefore(int, int) override;
    void Node_insAfter(int, int) override;
    void Node_Delete(int) override;
    void List_Show() override;
};

class CS : public Ilist {
public:
    void Node_insFirst(int) override;
    void Node_insLast(int) override;
    void Node_insBefore(int, int) override;
    void Node_insAfter(int, int) override;
    void Node_Delete(int) override;
    void List_Show() override;
};

class CD : public Ilist {
public:
    void Node_insFirst(int) override;
    void Node_insLast(int) override;
    void Node_insBefore(int, int) override;
    void Node_insAfter(int, int) override;
    void Node_Delete(int) override;
    void List_Show() override;
};

int main() {
   Ilist* List;
   int data, dataRF;
   char option;
   
   std::cout << "Choose type of list\n\n";
   std::cout << "1) Simple single\n";
   std::cout << "2) Simple double\n";
   std::cout << "3) Circular single\n";
   std::cout << "4) Circular double\n";
   std::cin >> option;

   switch(option) {

       case '1': {
            SS simple_single;
            List = &simple_single;
            break;
        }

       case 2: {
            SD simple_double;
            List = &simple_double;
            break;
       }

       case '3': {
            CS circular_simple;
            List = &circular_simple;
            break;
       }

       case '4': {
            CD circular_double;
            List = &circular_double;
            break;
       }
       
   }


	do {
		std::cout << "MENU\n\n";
		std::cout << "1) Insert node at the beginning\n";
		std::cout << "2) Insert node at the end\n";
		std::cout << "3) Insert node before\n";
		std::cout << "4) Insert node after\n";
		std::cout << "5) Delete node\n";
		std::cout << "6) Show list\n";
		std::cout << "7) Salir\n\n";
		std::cout << "Your option is: ";

		std::cin >> option;
		system("clear");

		if(option != '7') 

			switch(option) {
				
				case '1': 
					std::cout << "Exit ctrl-d\n";
					while(std::cin >> data)
						List->Node_insFirst(data);
					break;
				
				case '2':
					std::cout << "Exit ctrl-d\n";
					while(std::cin >> data)
						List->Node_insLast(data);
					break;
				
				case '3':
					std::cout << "Enter data & datarRF\n";
					std::cin >> data >> dataRF;
					List->Node_insBefore(data, dataRF);
					break;
				
				case '4':
					std::cout << "Enter data & datarRF\n";
					std::cin >> data >> dataRF;
					List->Node_insAfter(data, dataRF);
					break;
				
				case '5':
					std::cout << "Enter dataRF\n";
					std::cin >> dataRF;
					List->Node_Delete(dataRF);
					break;
				
				case '6':
					List->List_Show();
					break;
			}

		else 
			break;
		
		std::cout << '\n';
		List->List_Show();
		std::cin.clear();
		std::cin.ignore();
    } while(true);
    
}


void SS::Node_insFirst(int data) {
    Node *New = new Node;
    New->data = data;
    New->next = Head;
    Head = New;
}

void SS::Node_insLast(int data) {
    if(!Head)
        return Node_insFirst(data);

    Node *Temp = Head;

    while(Temp->next)
        Temp = Temp->next;

    Node *New = new Node;
    New->data = data;
    New->next = Temp->next;
    Temp->next = New;
}

void SS::Node_insBefore(int data, int dataRF) {
    if(!Head || Head->data == dataRF)
        return Node_insFirst(data);

    Node *Temp = Head;

    while(Temp->next && (Temp->next)->data != dataRF)
        Temp = Temp->next;

    if( (Temp->next)->data == dataRF) {
        Node *New = new Node;
        New->data = data;
        New->next = Temp->next;
        Temp->next = New;
    }
}

void SS::Node_insAfter(int data, int dataRF) {
    if(!Head)
        return Node_insFirst(data);

    Node *Temp = Head;

    while(Temp->next && Temp->data != dataRF)
        Temp = Temp->next;

    if(Temp->data == dataRF) {
        Node *New = new Node;
        New->data = data;
        New->next = Temp->next;
        Temp->next = New;
    }
}

void SS::Node_Delete(int dataRF) {
    if(!Head)
        return;

    Node *Temp1 = Head, *Temp2 = NULL;
    
    if(Temp1->data == dataRF) {
        Head = Head->next;
        delete Temp1;
        return;
    }
    
    while(Temp1->next && (Temp1->next)->data != dataRF)
        Temp1 = Temp1->next;

    if(Temp1->next) {
        Temp2 = Temp1->next;
        Temp1->next = (Temp1->next)->next;
        delete Temp2;
    }
}

void SS::List_Show() {
    if(!Head) {
        std::cout << "Empty list\n";
        return;
    }

    Node *Temp = Head;

    while(Temp) {
        std::cout << Temp->data << '\n';
        Temp = Temp->next;
    }
}


void SD::Node_insFirst(int data) {
    Node *New = new Node;
    New->data = data;
    New->next = Head;
    New->previous = NULL;
	
	if(Head)
		Head->previous = New;

    Head = New;
}

void SD::Node_insLast(int data) {
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

void SD::Node_insBefore(int data, int dataRF) {
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

void SD::Node_insAfter(int data, int dataRF) {
    if(!Head)
        return Node_insFirst(data);
    
    Node *Temp = Head;

    while(Temp->next && Temp->data != dataRF) 
        Temp = Temp->next;

    if(Temp->data == dataRF) {
        if(!Temp->next) 
            return Node_insLast(data);

        Node *New  = new Node;
        New->data = data;
        New->next = Temp->next;
        New->previous = Temp;
        (Temp->next)->previous = New;
        Temp->next = New;
    }
}

void SD::Node_Delete(int dataRF) {
    if(!Head)
        return;
    
    Node *Temp1 = Head, *Temp2 = NULL;

    if(Temp1->data == dataRF) {
        Head = Head->next;
        if(Temp1->next)
            Head->previous = NULL;

        delete Temp1;
        return;
    }

    while(Temp1->next && (Temp1->next)->data != dataRF) 
        Temp1 = Temp1->next;

    if(Temp1->next->data == dataRF) {
        Temp2  = Temp1->next;
        Temp1->next = (Temp1->next)->next;
    
        if(Temp1->next)
            Temp1->next->previous = Temp1;

        delete Temp2;
    }
} 

void SD::List_Show() {
    if(!Head) {
        std::cout << "Empty List\n";
        return;
    }
    
    Node *Temp1 = Head, *Temp2 = NULL;

    while(Temp1) {
        std::cout << Temp1->data << '\n';
		Temp2 = Temp1;
        Temp1 = Temp1->next;
    }
    
    std::cout << "\n\n";
    
    
     while(Temp2) {
        std::cout << Temp2->data << '\n';
        Temp2 = Temp2->previous;
	}
}

void CS::Node_insFirst(int data) {
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

void CS::Node_insLast(int data) {
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

void CS::Node_insBefore(int data, int dataRF) {
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

void CS::Node_insAfter(int data, int dataRF) {
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

void CS::Node_Delete(int dataRF) {
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

void CS::List_Show() {
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

void CD::Node_insFirst(int data) {
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

void CD::Node_insLast(int data) {
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

void CD::Node_insBefore(int data, int dataRF) {
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

void CD::Node_insAfter(int data, int dataRF) {
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

void CD::Node_Delete(int dataRF) {
    if(!Head)
        return;

    Node *Temp1 = Head, *Temp2 = NULL;

    if(Temp1->data == dataRF) {
        
        if(Temp1->next == Head) {
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

void CD::List_Show() {
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
