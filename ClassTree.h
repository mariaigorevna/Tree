#pragma once
#include <vector>
template <typename myTip>
class Tree
{
	struct MultiNode
	{
		myTip data; //тип элементов дерева
		int key2; //идентификатор
		MultiNode * parent; //указатель на родительскую структуру
		vector  <MultiNode*> *children;//контейнер ссылок на потомков
	};
	

	int curr;
	MultiNode * find(int key, MultiNode * ptr)
	{
		MultiNode * temp = NULL;
		if ((ptr->key2) == key)
			return ptr;
		else
		{
			if ((ptr->children) == NULL)
				return NULL;
			for (int i = 0; i <= (ptr->children)->size() - 1; i++)
			{
				temp = find(key, (*(ptr->children))[i]);
				if (temp != NULL)
					return temp;
			}
		}
	}
public:
	MultiNode * root;
	int addNode(myTip x, int key)
	{
		MultiNode * newNode = new MultiNode;
		MultiNode * p = find(key, root);
		if (p->children == NULL)
			p->children = new vector<MultiNode*>;
		(p->children)->push_back(newNode);
		newNode->parent = p;
		newNode->key2 = ++curr;
		newNode->data = x;
		newNode->children = NULL;
		cout << "Идентификатор этого элемента = " << curr << endl;
		return curr;
	}
	void del()
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
	void list(MultiNode * ptr)
	{
		if (ptr == NULL)
		{
			cout << "Дерево пусто =(" << endl;
			return;
		}
		if ((ptr->children) == NULL)
		{
			cout << ptr->data << ' ' << endl;
		}
		else
		{
			for (int i = 0; i <= (ptr->children)->size() - 1; i++)
				list((*(ptr->children))[i]);
		}
	}
	Tree(myTip x)
	{
		root = new MultiNode;
		root->data = x;
		curr = 0;
		root->id = 0;
		root->parent = NULL;
		root->children = NULL;
		cout << "Идентификатор корня = 0" << endl;
	}
	~Tree()
	{
		del();
	}
};

