#include <iostream> 
#include <string> 
#include <fstream> 
#include <cstdint> 

using namespace std;

template <typename T>
struct Node {
	Node *left;
	Node *right;
	T data;
};

template <typename T>
 class BinaryTree;
 template <typename T>
 std::ostream& operator<<(std::ostream&, const BinaryTree<T>&);

template <typename T>
class BinaryTree
{
private:
	Node<T>*root;
	int CountElements;

public:
	BinaryTree();
	~BinaryTree();
	Node<T>* root_()const;
	unsigned int count() const;
	void insert_node(const T&x);
	Node<T> *find_node(const T&, Node<T>*)const;
	void deleteNode(Node<T>* temp);
	void writing(const std::string& filename)const;
	void remove_element(const T& temp);
	Node<T>* _deleteRoot(Node<T>* temp);
	friend std::ostream& operator<<<>(std::ostream&, const BinaryTree<T>&);
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
	CountElements = 0;
}

template<typename T>
Node<T>* BinaryTree<T>::root_() const
{
	return root;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	deleteNode(root);
}


template<typename T>
void BinaryTree<T>::insert_node(const T&x)
{
	if (find_node(x, root_())) return;
	Node<T>* MyTree = new Node<T>;
	MyTree->data = x;
	MyTree->left = MyTree->right = 0;
	Node<T>* buff = root;
	Node<T>* temp = root;
	while (temp)
	{
		buff = temp;
		if (x < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if (!buff)
		root = MyTree;
	else
	{
		if (x < buff->data)
			buff->left = MyTree;
		else
			buff->right = MyTree;
	}
	++CountElements;
}


template<typename T>
Node<T>* BinaryTree<T>::find_node(const T& value, Node<T>* temp) const
{
	if (temp == 0 || value == temp->data)
		return temp;
	if (value > temp->data)
		return find_node(value, temp->right);
	else
		return find_node(value, temp->left);
}

template<typename T>
unsigned int BinaryTree<T>::count()const
{
	return CountElements;
}

template<typename T>
void BinaryTree<T>::deleteNode(Node<T>* temp)
{
	if (!temp)
	{
		return;
	}
	if (temp->left)
	{
		deleteNode(temp->left);
		temp->left = nullptr;
	}

	if (temp->right)
	{
		deleteNode(temp->right);
		temp->right = nullptr;
	}
	delete temp;
}

template<typename T>
void BinaryTree<T>::writing(const std::string& filename)const
{
	ofstream file_1(filename);
	file_1 << CountElements << "\t";
	output(file_1, root);
	file_1.close();
}


template <typename T>
std::ostream& output(std::ostream& ost, const Node<T>* node, unsigned int level)
{
	if (!node)
		return ost;
	output(ost, node->right, level + 1);
	for (unsigned int i = 0; i < level; i++)
		ost << "\t";
	ost << node->data << std::endl;
	output(ost, node->left, level + 1);
	return ost;
}


template <typename T>
std::ostream& operator<<(std::ostream& ost, const BinaryTree<T>& temp)
{
	output(ost, temp.root, 0);
	return ost;
}

template <typename T>
Node<T>* BinaryTree<T>::_deleteRoot(Node<T>* temp)
{
	Node<T>* buff, *parent;
	if (temp)
	{
		buff = temp->right;
		if (!buff)
		{
			buff = temp->left;
		}
		else
		{
			if (buff->left)
			{
				parent = temp;
				while (buff->left)
				{
					parent = buff;
					buff = buff->left;
				}
				parent->left = buff->right;
				buff->right = temp->right;
			}
			buff->left = temp->left;
		}
		delete temp;
		return buff;
	}
	return nullptr;
}

template <typename T>
void BinaryTree<T>::remove_element(const T& temp)
{
	Node<T>* buff = root, *parent;
	if (root)
	{
		if (root->data == temp)
		{
			root = _deleteRoot(root);
		}
		else
		{
			parent = root;
			if (temp < parent->data) buff = parent->left;
			else buff = parent->right;
			while (buff)
			{
				if (buff->data == temp)
				{
					if (temp < parent->data) parent->left = _deleteRoot(parent->left);
					else parent->right = _deleteRoot(parent->right);
					return;
				}
				parent = buff;
				if (temp < parent->data) buff = parent->left;
				else buff = parent->right;
			}
		}
		--CountElements;
	}
}
