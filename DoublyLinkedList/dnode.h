#ifndef D_NODE_H
#define D_NODE_H

template <typename E>
class DLinkedList;

//class for creating a node in a doubly linked list
template <typename E>
class DNode 
{
private:
	//Element stored in the node
	E elem;

	//pointer for previous node in a list
	DNode<E>* prev;

	//pointer for the next node in a list
	DNode<E>* next;

	//class is friends with the doubly linked list
	friend class DLinkedList<E>;
public:

	/*Default Constructor 

	Takes optional arguments for the element, prev, and next.

	If nothing is provided element is set to the default and prev
	and next are set to NULL

	*/
	DNode(const E & el = E(), DNode<E>* pr = NULL, DNode<E>* nx = NULL)
		/*member initialization list sets member variables to 
		default or provided values*/
	    : elem(el), prev(pr), next(nx)
    {
    }

	/*Fix this destructor*/
	//     ~DNode() 
	//     {	
	//     	delete prev;
	//     	delete next;
	//     }
};

#endif
