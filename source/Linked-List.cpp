#ifndef IOSTREAM
#define IOSTREAM

#include <iostream>

#endif

#include "Linked-List.h"


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
