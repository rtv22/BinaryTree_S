#include "BinaryTree.hpp"


template<typename T>
Node<T> : data{ 0 }, left{ nullptr }, right{ nullptr }
{
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	delete *root;
}

template<typename T>
void BinaryTree<T>::add_node(const T& data, Node<T> *&MyTree)
{
	if (MyTree == NULL)
	{
		MyTree = new Node;
		MyTree->data = data;
		MyTree->left = MyTree->right = NULL;
	}
	if (data < MyTree->data)
	{
		if (MyTree->left != NULL)
			add_node(data, MyTree->left);
		else
		{
			MyTree->left = new Node;
			MyTree->left->left = MyTree->left->right = NULL;
			MyTree->left->data = data;
		}

	}
	if (data > MyTree->data)
	{
		if (MyTree->right != NULL)
		{
			add_node(data, MyTree->right);
		}
		else
		{
			MyTree->right = new Node;
			MyTree->right->left = MyTree->right->right = NULL;
			MyTree->right->data = data;
		}
	}
}

template<typename T>
Node<T> *search(const T& buff, Node<T> *&MyTree)
{
	*MyTree = root;
	if (MyTree == NULL)
	{
		return NULL;
	}
	if (MyTree->data == buff)
	{
		return MyTree;
	}
	if (MyTree->data > buff)
	{
		return search(buff, MyTree->left);
	}
	else
	{
		return search(buff, MyTree->right);
	}
}

template<typename T>
bool test(const T& buff)
{
	Node<T> * node;
	node = search(buff);
	if (node != nullptr)
		return true;
	else return false;
}

template<typename T> 
void BinaryTree<T>::reading(const std::string file_name)
{
	std::ifstream fin(file_name);
	T temp;
	fin >> temp;
	while (fin)
	{
		insert(temp);
		fin >> temp;
	}
	fin.close();
}

template<typename T> 
void outfile(Node<T> *node, ostream& ost)
{
	if (node != nullptr)
	{
		outfile(node->left, ost);
		ost << node->data << " ";
		outfile(node->right, ost);
	}
}

template<typename T> 
void BinaryTree<T>::writing(const std::string file_name)
{
	std::ofstream fout(file_name);
	outfile(outfile, root);
	fout.close();
}
