#include <iostream>
#include <vector>

using namespace std;

class Tree
{
	struct MultiNode
	{
		double data; //��� ��������� ������
		int key; //�������������
		MultiNode * parent; //��������� �� ������������ ���������
		vector <MultiNode *> *children; //��������� ������ �� ��������
	};
public:
	int sum;
	int curr;
	Tree(int x);
	~Tree();
	void addNode(int x, int key);
	void del();
	void summ(MultiNode * ptr)
	MultiNode Tree::find(int key1, MultiNode * ptr);
};

	Tree(int x)
{
	root = new MultiNode;
	root->data = x;
	curr = 0;
	root->key = 0;
	root->parent = NULL;
	root->children = NULL;
	//cout << "������������� ����� = 0" << endl;
}
	~Tree()
{
	del();
}
	MultiNode Tree::find(int key1, MultiNode * ptr)
	{
		MultiNode * temp = NULL;
		if ((ptr->key) == key1)
			return ptr;
		else
		{
			if ((ptr->children) == NULL)
				return NULL;
			for (int i = 0; i <= (ptr->children)->size() - 1; i++)
			{
				temp = find(key1, (*(ptr->children))[i]);
				if (temp != NULL)
					return temp;
			}
		}
	}
	void Tree::addNode(int x, int key)
	{
		
		MultiNode * newNode = new MultiNode;
		MultiNode * p = find(key, root);
		if (p->children == NULL)
			p->children = new vector<MultiNode*>;
		(p->children)->push_back(newNode);
		newNode->parent = p;
		newNode->key = ++curr;
		newNode->data = x;
		newNode->children = NULL;
	
		
	}
	void Tree::del()
	{
		for (int i = curr; i >= 0; i--)
		{
			MultiNode * p = find(i, root);
			if (p->parent != NULL)
			{
				((p->parent)->children)->pop_back();
				if (((p->parent)->children)->size() == 0)
					(p->parent)->children = NULL;
			}
			delete p;
		}
		curr = -1;
	}
	void Tree::summ(MultiNode * ptr)
	{
		int i;
		if (ptr == NULL)
		{
			cout << "������ ����� =(" << endl;
		}


		if ((ptr->children) == NULL)
		{

			sum = sum + (ptr->data);
		}

		else
			for (int i = 0; i <= (ptr->children)->size() - 1; i++) {
				summ((*(ptr->children))[i]);



			}
		if (((ptr->children) != NULL) && (i = (ptr->children)->size() - 1)) {
			cout << sum << endl;
			
		}
	}

int main()
{
	setlocale(0, "");
	int x;
	cout << "Enter root:" << endl;
	cin >> x;
	Tree tree(x);
	cout << "Enter node root:" << endl;
	cin >> x;
	tree.addNode(x, 0);
	cout << "Enter node root:" << endl;
	cin >> x;
	tree.addNode(x, 0);
	cout << "Enter leaf for element 1:" << endl;
	cin >> x;
	tree.addNode(x, 1);
	cout << "Enter leaf for element 1 2:" << endl;
	cin >> x;
	tree.addNode(x, 2);
	cout << "Sum of leaf elements = ";
	tree.summ(tree.root);
	cout << endl;
	system("pause");
	
	return 0;
	system("pause");
}
