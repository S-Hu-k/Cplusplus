#include<iostream>
#include<vector>
using namespace std;


template<class Type>
class BSTree;
template<class Type>
class BSTNode
{
	friend class BSTree<type>;
public:
	
	BSTNode(Type d = Type(), BSTNode<Type>* leftChild = nullptr, BSTNode<Type>* rightChild = nullptr)
	:data(d),leftChild(left),rightChild(right)
	{}
	~BSTNode()
	{}
private:
	Type data;
	BSTNode<Type>* leftChild;
	BSTNode<Type>* rightChild;
};

template<class Type>
class BSTree
{
public: 
	BSTree():root(nullptr)
	{}
public:
	bool Inerst(const Type& x)
	{
		return Inerst(root, x);
	}
protected:
	bool Inerst(BSTNode<Type>*& t, const Type& x)
	{
		if (t == nullptr)
		{
			t = new BSTree<Type>(x);
			return true;
		}
		else if (x > t->data)
			Inerst(t->rightChild, x);
		else if (x < t->data)
			Inerst(t->leftChild, x);
		else
			return false;
	}
private:
	BSTNode<Type>* root;
};
int main()
{
	//int ar[] = { 12 ,2,3,45,56,24,30,1,16,59 };
	//int n = sizeof(ar) / sizeof(int);
	vector<int> ar= { 12 ,2,3,45,56,24,30,1,16,59 };
	BSTree<int> bst;
	for (const auto& e : ar)
		bst.Inerst(e);
}