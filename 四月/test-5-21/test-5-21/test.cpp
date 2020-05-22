#include<iostream>
using namespace std;

typedef enum { RED = 0, BLACK = 1 }Colour_type;

template<class	Type>
class RBTree;

template<class	Type>
class RBTreeNode
{
	friend class RBTree<Type>;

public:
	RBTreeNode(const Type&d=Type())
		:data(d),leftChild(nullptr),rightChild(nullptr),parent(nullptr),colour(RED)
	{}
	~RBTreeNode()
	{}
private:
	Type data;
	RBTreeNode<Type>* leftChild;
	RBTreeNode<Type>* rightChild;
	RBTreeNode<Type>*  parent;
	Colour_type        colour;

};

template<class	Type>
class RBTree
{
public:
	RBTree():root(NIL),NIL(_BuyNode)
	{
		NIL->leftChild = NIL->rightChild = NIL;
		NIL->colour = BLACK;
	}
protected:
	RBTreeNode<Type>* _BuyNode(const Type&x=Type())
	{

		RBTreeNode<Type>* s = new RBTreeNode<Type>(x);
		s->leftChild = s->rightChild = NIL;	
		return s;
	}

private:

	RBTreeNode<Type>* NIL;
	RBTreeNode<Type>* root;


};
int  main()
{
	RBTree<int> rb;
	return 0;
}