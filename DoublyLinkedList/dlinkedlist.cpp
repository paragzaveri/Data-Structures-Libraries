
#include "dnode.h"

/*Default Constructor

creates a header and trailer node's dynamic memory
from the member variables header and trailer

creates the empty list by setting head next to trailer
and trailer prev to header

finally, sets the prev for header and the next for trailer
to null, signifying nothing comes before or after those nodes
respectively


*/
template <typename E>
DLinkedList<E>::DLinkedList(void)
	//member initialization list allocates new memory
    : header(new DNode<E>), trailer(new DNode<E>(E(),header))
{
	//set up empty list
	header->next = trailer;
}



/*Destructor

Deletes allocated dynamic memory for 
the header and trailer

Removes items from the front of the list
which uses the removeFront then remove methods
in which another delete is called also
deallocating that dynamic memory usage

*/
template <typename E>
DLinkedList<E>::~DLinkedList(void)
{
	//continue removing items to make list empty
	while(!empty()) 
	{
		/*function for removing items after the headher
		and before trailer*/
		removeFront();
	}
		
	//deallocated dynamic memory
	delete header;
	delete trailer;
}



/*Copy Constructor

Creates new list from an existing list.

First creates an empty list, then adds to it

Uses addBack to add new elements to empty list.
Loops through existing list and copies its elements
to the new list using a helper node.

*/
template <typename E>
DLinkedList<E>::DLinkedList(const DLinkedList<E> & copy)
    : header(new DNode<E>), trailer(new DNode<E>(E(),header))
{
	header->next = trailer;

	//Above Code Is Creation of Empty List

	//Helper Node to cycle through list
	DNode<E> * node = copy.header;
	//Loop until existing list reaches trailer
	while(node->next != copy.trailer)
	{
		//add the existing lists elements to new list
		addBack(node->next->elem);
		//move through list
		node = node->next;
	}
	
}



/* Method that checks if list is empty

If the element after the header is the trailer,
the list is empty.  Returns true if empty.

Does not alter calling object.

Takes no arguments.

*/
template <typename E>
bool DLinkedList<E>::empty() const
{
	//return true if empty, false otherwise
	return (header->next == trailer);
}



/*Method that returns the element in the node
at the front of the list.

Return type is of type E, which is the type
the list was created as.

Does not alter calling object.

Takes no arguments

*/
template <typename E>
const E& DLinkedList<E>::front() const
{
	//return element in first node after header
	return header->next->elem;
}



/*Method that returns the element in the node
at the back of the list.

Return type is of type E, which is the type
the list was created as.

Does not alter calling object.

Take no arguments

*/
template <typename E>
const E& DLinkedList<E>::back() const
{
	//return element in first node before trailer
	return trailer->prev->elem;
}




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
template <typename E>
E DLinkedList<E>::getNode(const size_t & index) const
{

	//helper node to cycle through list
	DNode<E> * node = header;
	//cylce through list
	for (size_t i = 0; i <= index; i++)
	{	
		//if call is beyond scope, will not advance node
		if (node->next != trailer)
		{
			node = node->next;
		}	
	}

	//return selected nodes element
	return node->elem;
}




/* Method for printing a list

Cycles through list and prints the element
at each node.

Uses helper node so to not change list and 
the method does not change the calling object.

Prints from within the list.

Takes no arguments.

Return type is void.

*/
template <typename E>
void DLinkedList<E>::printList() const
{
	//helper node to cycle through list
	DNode<E> * node = header;
	//stops looping if next node is trailer
	while (node->next != trailer)
	{
		//cycle through memory locations
		node = node->next;
		//printing operation
		std::cout << node->elem << " " << std::flush;
	}
	//new line
	std::cout << std::endl;
	return;
}



/* Method for converting a linked list
into an array.

Does not alter calling object.

Takes a pointer to an array and a constant
reference to the size of the array.

Return type is void.

*/
template <typename E>
void DLinkedList<E>::createArray(E * arr, const size_t & count) const
{
	//helper node to cycle through list
	DNode<E> * node = header->next;

	//insert current memory locations' element into array
	for (size_t i = 0; i != count; i++)
	{
		arr[i] = node->elem;
		//move to next node
		node = node->next;
	}

	return;
}




/*Method for adding a node to a list

Take a pointer to a node and a constant referenec
to an element as arguments.

Inserts node into list in front of node passed in.

Return type is void

*/

template <typename E>
void DLinkedList<E>::add(DNode<E> * v, const E& e)
{
	/*constructs new node which is located in front 
	of existing node*/
	DNode<E> * u = new DNode<E>(e,v->prev,v);
	//sets surrounding node's next and prev to point to new node
	u->prev->next = v->prev = u;
}



/* Method for adding a node to the front of list

Simply uses the add method and passes a pointer to 
the node after header as a reference to where to create
the new node.

Takes an argument for the element to pass into the new node

Does alter calling object.

*/
template <typename E>
void DLinkedList<E>::addFront(const E& e)
{
	//call add method to insert after header
	add(header->next, e);
}



/* Method for adding a node to the back of the list

Simply uses the add method and passes a pointer to
the node before trailer as a reference to where to create
the new node.

Takes an argument for the element to pass into the new node

Does alter the calling object.

*/
template <typename E>
void DLinkedList<E>::addBack(const E& e)
{
	//call add method to insert before trailer
	add(trailer, e);
}



/* Method for removing a node from a list.

Removes the node that is passed in as an argument.

Takes a pointer to the node passed in.

Points the node in front of the node to remove to the node
after the node to remove.  Does the same with the node after
pointing before it.

Deallocates the dynamic memory of the node.

Does alter the calling object.
	
*/
template <typename E>
void DLinkedList<E>::remove(DNode<E>* v)
{
	/*Create two helper nodes that take the memory
	locations of before and after the node to delete*/
	DNode<E>* u = v->prev;
	DNode<E>* w = v->next;

	//Point the node before and after to each other to link out
	u->next = w;
	w->prev = u;

	//deallocate dynamic memory
	delete v;
}




/* Method for removing the node in front of the list

Use the remove method and pass in the node after the 
header.  This is the first element in the list.

Makes sure that the list is not empty before calling remove
method.

Takes no arguments.

Does alter calling object.

Deallacotes memroy after removal.

*/
template <typename E>
void DLinkedList<E>::removeFront()
{
	//makes sure list is not empty
	if (header->next != trailer)
	{
		//call remove method with first node
		remove(header->next);
	}
}



/* Method for removing the node in the back of the list

Use the remove method and pass in the node before the 
trailer.  This si the last element in the list.

Makes sure that the list is not empty before calling
remove method.

Takes no arguments.

Does alter calling object.

Deallocates memory after removal.

*/
template <typename E>
void DLinkedList<E>::removeBack()
{
	//makes sure list is not empty
	if (trailer->prev != header)
	{
		//call remove method with last node
	    remove(trailer->prev);
	}
}


