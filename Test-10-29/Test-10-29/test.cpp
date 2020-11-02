#include<iostream>
#include<stack>
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
protected:
	void RotateL(AVLNode<Type>*& ptr)
	{
		AVLNode<Type>* SubL = ptr;
		ptr = ptr->rightChild;
		SubL->rightChild = ptr->leftChild;
		ptr->leftChild = SubL;

		ptr->bf = SubL->bf = 0;
	}
	void RotateR(AVLNode<Type>*& ptr)
	{
		AVLNode<Type>* SubR = ptr;
		ptr = ptr->leftChild;
		SubR->leftChild = ptr->rightChild;
		ptr->rightChild = SubR;

		ptr->bf = SubR->bf = 0;
	}
	void RotateLR(AVLNode<Type>*& ptr)
	{
		AVLNode<Type>* SubR = ptr;
		AVLNode<Type>* SubL = ptr->leftChild;
		SubL->rightChild = ptr;

		//先左转
		SubL->rightChild= ptr->leftChild;
		ptr->leftChild = SubL;

		if (ptr->bf == 1)
			SubL->bf = -1;
		else
			SubL->bf = 0;

		//再右转
		SubR->leftChild = ptr->rightChild;
		ptr->rightChild = SubR;

		if (ptr->bf == -1)
			SubR->bf = 1;
		else
			SubR->bf = 0;



		ptr->bf = 0;
	}
	void RotateRL(AVLNode<Type>*& ptr)
	{
		AVLNode<Type>* SubL = ptr;
		AVLNode<Type>* SubR = ptr->rightChild;
		ptr = SubR->leftChild;

		//先右转
		SubR->leftChild = ptr->leftChild;
		ptr->rightChild = SubR;

		if (ptr->bf >= 0)
			SubR->bf = 0;
		else
			SubR->bf = 1;

		//再左转
		SubL->rightChild = ptr->leftChild;
		ptr->leftChild = SubL;

		if (ptr->bf <= 0)
			SubL->bf = 0;
		else
			SubL->bf = -1;

		ptr->bf = 0;

	}
private:
	AVLNode<Type>* root;

};
//实现方法
template<class Type>
//bool AVLTree<Type>::Insert(AVLNode<Type> *&t, const Type &x)
bool Insert(AVLNode<Type>*& t, const Type& x)
{
	AVLNode<Type>* pr = nullptr;//表示当前节点的父节点
	AVLNode<Type>* p = t;
	stack< AVLNode<Type>*> st;//通过栈的形式存储节点

	while (p != nullptr)
	{
		if (x == p->data)
			return false;

		pr = p;
		st.push(pr); //获取头节点，用栈的方式保存路径。

		if (x > p->data)
			p = p->rightChild;
		else
			p = p->rightChild;
	}


	p = new AVLNode<Type>(x);

	//判断插入的节点是否为根节点
	if (pr == nullptr)
	{
		t = p;
		return true;
	}
	//连接节点
	if (pr->data > x)
		pr->leftChild = p;
	else
		pr->rightChild = p;

	//调整平衡
	while (!st.empty())
	{
		pr = st.pop();
		st.pop();
		if (p == pr->leftChild)
			pr->bf--;
		else
			pr->bf++;

		if (pr->bf == 0)
			break;
		if (pr->bf == 1 || pr->bf == -1)
			p = pr;
		else
		{
			if (pr->bf > 0)
			{
				if (p->bf > 0)
				{
					RotateL(pr);              //   /   
				}
				else
				{
					RotateRL(pr);                  //   >
				}
			}
			if (pr->bf < 0)
			{
				if (p->bf > 0)
				{
					RotateLR(pr);              //   <
				}
				else
				{
					RotateR(pr);              //   /
				}
			}
		}
	}
	//重新连接父节点
	if (st.empty())
		t = pr;
	else
	{
		AVLNode<Type>* ppr = st.top();
		if (ppr->data > pr->data)
			ppr->leftChild = pr;
		else
			ppr->rightChild = pr;
	}
	return true;

}


int main()
{
	vector<int> iv{ 16,3,7,11,9,26,18,14,15 };
}