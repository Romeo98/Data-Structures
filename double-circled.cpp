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

		void list_delete();
		void recdelete(Node *);

		void list_recshow();
        void recshow(Node *);

        void List_Show();
};


int main() {

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
    
    do {
        std::cout << Temp2->data << '\n';
        Temp2 = Temp2->previous;
    } while(Temp2 != Head);
}
