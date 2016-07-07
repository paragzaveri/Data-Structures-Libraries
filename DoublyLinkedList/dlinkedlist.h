#ifndef D_LINKED_LIST_H
#define D_LINKED_LIST_H


template <typename E>
class DNode;


//Class for Creating a Doubly Linked List
template <typename E>
class DLinkedList
{
private:
	//node for the header of the list
	DNode<E> * header;
	//node for the trailer of the list
	DNode<E> * trailer;
protected:
	/*Method for adding a node to a list

	Take a pointer to a node and a constant referenec
	to an element as arguments.

	Inserts node into list in front of node passed in.

	Return type is void

	*/
	void add(DNode<E> * v, const E & e);


	/* Method for removing a node from a list.

	Removes the node that is passed in as an argument.

	Takes a pointer to the node passed in.

	Points the node in front of the node to remove to the node
	after the node to remove.  Does the same with the node after
	pointing before it.

	Deallocates the dynamic memory of the node.

	Does alter the calling object.
		
	*/
	void remove(DNode<E> * v);
public:
	/*Default Constructor
	creates a header and trailer node's dynamic memory
	from the member variables header and trailer

	creates the empty list by setting head next to trailer
	and trailer prev to header

	finally, sets the prev for header and the next for trailer
	to null, signifying nothing comes before or after those nodes
	respectively
	*/
	DLinkedList();


	/*Destructor
	Deletes allocated dynamic memory for 
	the header and trailer

	Removes items from the front of the list
	which uses the removeFront then remove methods
	in which another delete is called also
	deallocating that dynamic memory usage
	*/
	~DLinkedList();


	/*Copy Constructor

	Creates new list from an existing list.

	First creates an empty list, then adds to it

	Uses addBack to add new elements to empty list.
	Loops through existing list and copies its elements
	to the new list using a helper node.

	*/
	DLinkedList(const DLinkedList<E> & copy);


	/* Method that checks if list is empty

	If the element after the header is the trailer,
	the list is empty.  Returns true if empty.

	Does not alter calling object.

	Takes no arguments.

	*/
	bool empty() const;


	/*Method that returns the element in the node
	at the front of the list.

	Return type is of type E, which is the type
	the list was created as.

	Does not alter calling object.

	Takes no arguments

	*/
	const E& front() const;



	/*Method that returns the element in the node
	at the back of the list.

	Return type is of type E, which is the type
	the list was created as.

	Does not alter calling object.

	Take no arguments

	*/
	const E& back() const;


	/*Method to get element of a node give
	and "index" value of the list.  Allows list to
	be an alternative to using an array.

	Return type is of type E, which is the type
	the list was created as.

	Does not alter calling object.

	Takes one arguement which is the "index" of the list

	If caller uses an index beyond the scope of the list,
	the method will just return element in the last node.

	*/
    E getNode(const size_t & index) const;


	/* Method for printing a list

	Cycles through list and prints the element
	at each node.

	Uses helper node so to not change list and 
	the method does not change the calling object.

	Prints from within the list.

	Takes no arguments.

	Return type is void.

	*/
	void printList() const;


	/* Method for converting a linked list
	into an array.

	Does not alter calling object.

	Takes a pointer to an array and a constant
	reference to the size of the array.

	Return type is void.

	*/
	void createArray(E * arr, const size_t & count) const;


	/* Method for adding a node to the front of list

	Simply uses the add method and passes a pointer to 
	the node after header as a reference to where to create
	the new node.

	Takes an argument for the element to pass into the new node

	Does alter calling object.

	*/
	void addFront(const E& e);


	/* Method for adding a node to the back of the list

	Simply uses the add method and passes a pointer to
	the node before trailer as a reference to where to create
	the new node.

	Takes an argument for the element to pass into the new node

	Does alter the calling object.

	*/
	void addBack(const E& e);

	
	/* Method for removing the node in front of the list

	Use the remove method and pass in the node after the 
	header.  This is the first element in the list.

	Makes sure that the list is not empty before calling remove
	method.

	Takes no arguments.

	Does alter calling object.

	Deallacotes memroy after removal.

	*/
	void removeFront();


	/* Method for removing the node in the back of the list

	Use the remove method and pass in the node before the 
	trailer.  This si the last element in the list.

	Makes sure that the list is not empty before calling
	remove method.

	Takes no arguments.

	Does alter calling object.

	Deallocates memory after removal.

	*/
	void removeBack();

	
};

#include "dlinkedlist.cpp"

#endif
