#include <iostream>
#include "Linked-List.h"


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