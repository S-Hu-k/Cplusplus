#include<iostream>
#include<vector>
using namespace std;


typedef enum {red =0,black =1 }type_color;


template<class Type>
class RBTree;



template <class Type>
class RBTreeNode
{
	friend class RBTree<Type>;
public:
	RBTreeNode(const Type &d=Type()) 
		:data(d),leftChild (nullptr), rightChild (nullptr), parent (nullptr),color(red)
	{}
	~RBTreeNode()
	{}

private:
	Type    data;
	RBTreeNode<Type>* leftChild;
	RBTreeNode<Type>* rightChild;
	RBTreeNode<Type>* parent;
	type_color      color;

};

template <class Type>
class RBTree
{
public:
	RBTree() : root(NIL), NIL(_BuyNode()), end_node(_BuyNode())
	{
		NIL->parent = NIL->leftChild = NIL->rightChild = nullptr;
		NIL->color = black;
		end_node->leftChild = end_node->rightChild = end_node->parent = NIL;
	}
public:
	bool Inerst(const Type& x)
	{
		return Inerst(root, x);
	}
protected:
	bool Insert(RBTreeNode<Type>*& t, const Type& x);
	void Inerst_Fixup(RBTreeNode<Type>*& t, RBTreeNode<Type>*& x);
protected:
	RBTreeNode<Type>* _BuyNode(const Type& x = Type())
	{
		RBTreeNode<Type>* s = new RBTreeNode<Type>(x);
		s->leftChild = s->rightChild = NIL;
		return s;
	}
private:
	RBTreeNode<Type>* NIL;    //C++ 变量声明的顺序影响其构造    1
	RBTreeNode<Type>* root;                         //          2
	RBTreeNode<Type>* end_node;
};
template<class Type>
void Inerst_Fixup(RBTreeNode<Type>*& t, RBTreeNode<Type>*& x)
{
	RBTreeNode<Type>* s;
	while()


}

template<class Type>
bool RBTree<Type>::Insert(RBTreeNode<Type>*& t, const Type& x)
{
	RBTreeNode<Type>* pr = NIL;
	RBTreeNode<Type>* s = t;
	while (s != NIL)
	{
		if (x == s->data)
			return false;
		pr = s;
	     if (x > s->data)
			s = s->rightChild;
		else
			s = s->leftChild;
	}
	s = _BuyNode(x);
	if (pr == NIL)//表示插入的节点为根节点
	{
		t = s;
		pr->parent = NIL;
	}
	if (x > pr->data)
		pr->rightChild = s;
	else
		pr->leftChild = s;
	s->parent = pr;
	//调整平衡
	Inerst_Fixup(t, s);
	return true;

}
void main()
{

	vector<int> iv{ 10, 7, 8, 4, 2, 20, 15, 11,12,13 };
}