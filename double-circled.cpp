// Manejo de listas circulares, doblemente enlazadas

#include <iostream>

struct Node {
	int data;
	Node *next;
	Node *previous;
};

class List {
	private:
		Node *Head;
	
	public:
		List();
		void node_insFirst(int &);
		void node_insLast(int &);
		void node_insBefore(int &, int &);
		void node_insAfter(int &, int &);
		void node_delete(int &);
		void List_itShow();
};


int main() {
	List Objeto;
	char Opcion;
	int data;

	do {
		std::cout << "MENU\n\n";
		std::cout << "a) Insertar nodo al inicio\n";
		std::cout << "b) Insertar nodo al final\n";
		std::cout << "c) Insertar nodo antes de otro nodo especifico\n";
		std::cout << "d) Insertar nodo despues de otro nodo especifico\n";
		std::cout << "e) Borrar nodo especifico\n";
		std::cout << "f) Mostrar lista iterativa\n";
		std::cout << "Su opcion es: ";

		std::cin >> Opcion;

		if(Opcion == 'i')
			break;
		
		else

			switch(Opcion) {
				case 'a':

					std::cout << "Quit ctrl-d\n\n";

					while(std::cin >> data)
						Objeto.node_insFirst(data);
					
					break;

				case 'b':
					std::cout << "Quit ctrl-d\n\n";

					while(std::cin >> data)
						Objeto.node_insLast(data);
					break;
				
				case 'c': {
					int dataRF;
					std::cout << "Insert data, dataRF\n";
					std::cin >> data >> dataRF;
					Objeto.node_insBefore(data, dataRF);
					break;
				}
				case 'd':
					int dataRF;
					std::cout << "Insert data, dataRF\n";
					std::cin >> data >> dataRF;
					Objeto.node_insAfter(data, dataRF);
					break;
				
				case 'e':
					std::cout << "Select node: ";
					std::cin >> data;
					Objeto.node_delete(data);
					break;
				
				case 'f':
					Objeto.List_itShow();
					break:

			}
			
		std::cin.clear();
		std::cin.ignore();

	} while(true);

}

List::List() {
	Head = NULL;
}

void List::node_insFirst(int &data) {
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

	Temp->next = New;
	New->previous = Temp;
	Head->previous = New;
	New->next = Head;
	Head = New;
}

void List::node_insLast(int &data) {

	if(!Head)
		return List::node_insFirst(data);
	
	Node *Temp = Head;

	while(Temp->next != Head)
		Temp = Temp->next;

	Node *New = new Node;
	New->data = data;

	Temp->next = New;
	New->previous = Temp;
	New->next = Head;
	Head->previous = New;
}

void List::node_insBefore(int &data, int &dataRF) {

	if(!Head)
		return List::node_insFirst(data);

	Node *Temp = Head;

	if(Temp->data == dataRF) 
		return List::node_insFirst(data);


	while(Temp->next != Head && (Temp->next)->data != dataRF)
		Temp = Temp->next;
	
	if((Temp->next)->data == dataRF) {
		Node *New = new Node;
		New->data = data;
		New->next = Temp->next;
		(Temp->next)->previous = New;
		New->previous = Temp;
		Temp->next = New;
	}
}

void List::node_insAfter(int &data, int &dataRF) {

	if(!Head)
		return List::node_insLast(data);
	
	Node *Temp = Head;

	while(Temp->next != Head && Temp->data != dataRF)
		Temp = Temp->next;
	
	if(Temp->next == Head && Temp->data == dataRF)
		return List::node_insLast(data);
	
	if(Temp->data == dataRF) {
		Node *New = new Node;
		New->data = data;
		New->next = Temp->next;
		New->previous = Temp;
		Temp->next->previous = New;
		Temp->next = New;
	}
}

void List::node_delete(int &data) {

	if(!Head)
		return;
	
	Node *Temp1 = Head, *Temp2 = Head; 	

	if(Temp1->data == data) {

		if(Temp1->next == Head) {
			delete(Temp1);
			Head = NULL;
		}

		else {
			while(Temp2->next != Head) 
				Temp2 = Temp2->next;
			
			Head = Head->next;
			Temp2->next = Head;
			delete(Temp1);
		}
	}

	else {
		do {
			
			Temp1 = Temp1->next;

		} while(Temp1 != Head && (Temp1->next)->data != data);

		Temp2 = Temp1;

		if((Temp1->next)->data == data) {
			Temp2 = Temp1->next;
			Temp1->next = (Temp1->next)->next;
			delete(Temp2);
		}
	}
}
 
void List::List_itShow() {

	if(!Head) {
		std::cout << "Lista vacia\n";
		return;
	}

	Node *Temp1 = Head, *Temp2 = Head;

	std::cout << "Orden normal\n\n";

	do {

		std::cout << Temp1->data << '\n';
		Temp2 = Temp1;
		Temp1 = Temp1->next;

	} while(Temp1 != Head);

	std::cout << "Orden inverso\n\n";

	while(true) {

		if(Temp2 == Head) {
			std::cout << Temp2->data << '\n';
			break;
		}

		std::cout << Temp2->data << '\n';
		Temp2 = Temp2->previous;
		
	}
}