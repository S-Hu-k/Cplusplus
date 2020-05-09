#include<iostream>
#include<assert.h>
#include<vector>
#include<string>
using namespace std;


template<class Type>
class BSTree;

template<class Type>
class BSTNode
{
	friend class BSTree<Type>;
public:
	BSTNode(Type d = Type(), BSTNode<Type>* left = nullptr, BSTNode<Type>* right = nullptr)
		: data(d), leftChild(left), rightChild(right)
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
	BSTree() : root(nullptr)
	{}
public:
	Type& Max()const
	{
		return Max(root);
	}
	Type& Min()const
	{
		return Min(root);
	}
	void InOrder()const
	{
		InOrder(root);
	}
public:
	bool Insert(const Type& x)
	{
		return Insert(root, x);
	}
	bool Remove( const Type& key)
	{
		return Remove(root, key);
	}
	BSTNode<Type>* Search(const Type& key)
	{
		return Search(root, key);
	}
protected:
	BSTNode<Type>* Search(BSTNode<Type>* t,const Type& key)
	{
		if (t == nullptr)
			return nullptr;
		else if (key > t->data)
			Search(t, t->rightChild);
		else if (key < t->data)
			Search(t, t->leftChild);
		else
			return t;
	}
	Type& Max(BSTNode<Type>* t)const
	{
		assert(t);
		while (t->rightChild != nullptr)
		{
			t = t->rightChild;
			return t->data;
		}
	}
	Type& Min(BSTNode<Type>* t)const
	{
		assert(t);
		while (t->leftChild != nullptr)
		{
			t = t->leftChild;
			return t->data;
		}
	}
	void InOrder(BSTNode<Type>* t)const
	{
		
		if (t != nullptr)
		{
			InOrder(t->leftChild);
			cout << (t->data).first << "  "<<(t->data).second;
			InOrder(t->rightChild);
		}
	}
	bool Remove(BSTNode<Type>*& t, const Type& key)
	{
		if (t == nullptr)
			return false;
		if (key < t->data)
			Remove(t->leftChild, key);
		else if (key > t->data)
			Remove(t->rightChild, key);
		else
		{
			if (t->leftChild != nullptr && t->rightChild != nullptr)
			{
				BSTNode<Type>* p = t->leftChild;
				while (p->rightChild != nullptr)
					p = p->rightChild;

				t->data = p->data;
				Remove(t->leftChild, p->data);
			}
			else
			{
				BSTNode<Type>* tmp = t;
				if (t->leftChild != nullptr)
					t = t->leftChild;
				else
					t = t->rightChild;
				delete tmp;
				return true;
			}
		}
	}
	bool Insert(BSTNode<Type>*& t, const Type& x)
	{
		if (t == nullptr)
		{
			t = new BSTNode<Type>(x);
			return true;
		}
		else if (x < t->data)
			Insert(t->leftChild, x);
		else if (x > t->data)
			Insert(t->rightChild, x);
		else
			return false;
	}
private:
	BSTNode<Type>* root;
};
void main()
{
	pair<string, string> v[] = { {"1.1", "元旦节"}, {"5.1", "劳动节"} };
	int n = sizeof(v) / sizeof(v[0]);

	BSTree<pair<string, string> > bst;
	for (int i = 0; i < n; ++i)
		bst.Insert(v[i]);

	bst.InOrder();
}
	/*bool Remove(BSTNode<Type>*& t,  const Type& key)
	{
		if (t == nullptr)
			return false;
		 if (key > t->data)
		{
			Remove(t->rightChild, key);
		}
		 if (key < t->leftChild)
		{
			Remove(t->leftChild, key);
		}
		else
		{
			//删除节点
			if (t->leftChild == nullptr && t->rightChild == nullptr)
			{
				delete t; 
				t = nullptr;
			}
			else if (t->leftChild != nullptr && t->rightChild == nullptr)
			{
				BSTNode<Type>* tmp = t;
				t = t->leftChild;
				delete tmp;
			}
			else if (t->leftChild == nullptr && t->rightChild != nullptr)
			{
				BSTNode<Type>* tmp = t;
				t = t->rightChild;
				delete tmp;
			}
			else
			{
				BSTNode<Type>* p = t->leftChild;
				while (p->rightChild != nullptr)
					p = p->rightChild;

				t->data = p->data;
				Remove(t->leftChild, p->data);
			}
		}
	}*/
/*
int main()
{
	//int ar[] = { 12 ,2,3,45,56,24,30,1,16,59 };
	//int n = sizeof(ar) / sizeof(int);
	vector<int> ar = { 12 ,3,45,56,24,30,16,59 };
	BSTree<int> bst;

	for (const auto& e : ar)
		bst.Insert(e);


	bst.InOrder();
	cout<<"Max = "<<bst.Max();
	cout << "Min = " << bst.Min();

	bst.Remove(12);

	BSTNode<int>* p = bst.Search(56);
	bst.InOrder();
	return 0;

}*/
/*template<class Type>
class BSTree;

template<class Type>
class BSTNode
{
	friend class BSTree<Type>;
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
			t = new BSTNode<Type>(x);
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
}*/