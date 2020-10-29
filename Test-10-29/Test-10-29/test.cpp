#include<iostream>






#include<vector>
using namespace std;


template<class Type> 
class AVLNode
{
public:
	AVLNode(Type d=Type(), AVLNode<Type>* left=nullptr, AVLNode<Type>* right=nullptr)
	:data(d), leftChild(left), rightChild(right),bf(0)
	{}
private:
	AVLNode<Type>* leftChild;
	AVLNode<Type>* rightChild;
	Type data;
	int bf;


};


template<class Type>
class AVLTree
{
public:
	AVLTree():root(nullptr)
	{}
public:
	bool Insert(const Type& x)
	{
		return Insert(root, x);
	}
	bool Remove(const Type& key)
	{
		return Remove(root, key);
	}
private:
	AVLNode<Type>* root;

};
//实现方法
template<class Type>
//bool AVLTree<Type>::Insert(AVLNode<Type> *&t, const Type &x)
  bool Insert(AVLNode<Type> *&t, const Type& x)
{
	  AVLNode<Type>* pr = nullptr;//表示当前节点的父节点
	  AVLNode<Type>* p = t;
	  stack< AVLNode<Type>*> st;//通过栈的形式存储节点


	  while (p != nullptr)
	  {
		  if (x == p->data)
			  return false;
		  if (x > p->data)
			p=  p->rightChild ;
		  else
			 p= p->rightChild ;
	  }
	  p = new AVLNode<Type>(x);

}
int main()
{
	vector<int> iv{ 16,3,7,11,9,26,18,14,15 };
}