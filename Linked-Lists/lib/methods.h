class List {
protected:
    struct Node {
        int data;
        Node *next;
    };

    Node *Head;

public:
    List(); 
    void Node_insFirst(int);
    void Node_insLast(int);
    void Node_insBefore(int, int);
    void Node_insAfter(int, int);
    void Node_Delete();
    void List_Show();
};

class DS_Linked : public List {
protected:
    struct Node {
        int data;
        Node *next, *previous;
    };
};

class SC_Linked : public List { }

class DC_Linked : public DS_Linked { }
