
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

template<class Type>
class AVLTree;

template<class Type>
class AVLNode
{
	friend class AVLTree<Type>;
public:
	AVLNode(Type d = Type(), AVLNode<Type>* left = nullptr, AVLNode<Type>* right = nullptr)
		:data(d), leftChild(left), rightChild(right), bf(0)
	{}
	~AVLNode()
	{}
public:
	//�����ڴ������Զ��庯��
private:
	Type           data;
	AVLNode<Type>* leftChild;
	AVLNode<Type>* rightChild;
	int            bf; //ƽ������ 0 -1 1 -2 2
};

template<class Type>
class AVLTree
{
public:
	AVLTree() : root(nullptr)
	{}
public:
	bool Inerst(const Type& x)
	{
		return Inerst(root, x);
	}
protected:
	bool Inerst(AVLNode<Type>*& t, const Type& x);
protected:
	void RotateL(AVLNode<Type>*& ptr)
	{
		AVLNode<Type>* subL=ptr;
		ptr = ptr->rightChild;
		 subL->rightChild= ptr->leftChild;
		ptr->leftChild = subL;

		ptr->bf = subL->bf = 0;
	}
	void RotateRL(AVLNode<Type>*& ptr)
	{
		AVLNode<Type>* subL = ptr;
		AVLNode<Type>* subR = ptr->rightChild;
		ptr = subR->leftChild;

		//����ת
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;

		//����ת
		subL->leftChild = ptr->leftChild;
		ptr->leftChild = subL;

		ptr->bf = 0;




	}
	void RotateR(AVLNode<Type>*& ptr)
	{
		AVLNode<Type>* subR=ptr;
		ptr = ptr->leftChild;
		 ptr->rightChild=subR->leftChild;
		ptr->rightChild = subR; 

		ptr->bf = subR->bf = 0;
	}
	void RotateLR(AVLNode<Type>*& ptr);

private:
	AVLNode<Type>* root;
};


//����ʵ�ַ���
template<class Type>
bool AVLTree<Type>::Inerst(AVLNode<Type>*& t, const Type& x)
{
	//1.�ڵ�Ĳ���  ����bst����
	AVLNode<Type>* pr = nullptr;
	AVLNode<Type>* p = t;
	stack<AVLNode<Type>*> st;


	while (p != nullptr)
	{
		if (x == p->data)

			return false;

		pr = p;
		st.push(pr);
		if (x < p->data)
			p = p->leftChild;
		else if (x > p->data)
			p = p->rightChild;


	}

	p = new AVLNode<Type>(x);
	if (pr == nullptr)
	{
		t = p;
		return true;
	}

	//���ӽڵ�
	if (pr->data > x)
		pr->leftChild = p;
	if (pr->rightChild)
		pr->rightChild = p;


	//2.����ƽ������
	while (!st.empty())
	{
		pr = st.top();
		st.pop();
		if (p == pr->leftChild)
			pr->bf--;
		else if (p == pr->rightChild)
			pr->bf++;

		if (pr->bf == 0)
			break;
		if (pr->bf == 1 || pr->bf == -1)
			p = pr;
		else
		{
			//��ת����
			if (pr->bf > 0)
			{
				if (p->bf > 0)
				{
					RotateL(pr);
					//                 \			
				}
				else
				{
					RotateRL(pr);
					//cout << "RotateRL" << endl;                      //            >
				}
			}
			else
			{
				if (p->bf < 0)
				{
					RotateR(pr);
					//cout << "RotateR" << endl;                       //            /
				}
				else
				{
					RotateLR(pr);
					//cout << "RotateLR" << endl;                     //              <
				}
			}
			break;
		}
		//�������Ӹ��ڵ�
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
		
	}return true;
}

int main()
{
	//vector<int> iv{ 10,3,6,8,9,5,4,7,2,1 };
	vector<int> iv{ 10 ,6,2 };
	AVLTree<int> avl;
	for (auto& e : iv)
		avl.Inerst(e);
	return 0;

	
}