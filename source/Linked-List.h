#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Ilist {
protected:
	struct Node {
		int data;
		Node *next, *previous;
	};

	Node * Head;

public:
	Ilist()
	 : Head(NULL) {}

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

#endif