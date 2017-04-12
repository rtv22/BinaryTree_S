#include <iostream> 
#include <string> 
#include <fstream> 
#include <cstdint>

using namespace std;

template <class T> 
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;
};

template <class T> 
class BinaryTree
{
private:
	Node<T> *root;
public:
	BinaryTree();
	~BinaryTree();
	void deleteNode(Node<T>* temp);
	void insert_node(const T&);
	void print()const;
	Node<T>*root_()const;
	Node<T> *find_node(const T&, Node<T>*)const;
	void show(Node<T>*, unsigned int)const;
	void reading(const std::string&);
	void output(std::ostream& ost, Node<T>*)const;
	void writing(const std::string&)const;
};

template<typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

template<class T>
Node<T>*BinaryTree<T>::root_()const
{
	return root;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	deleteNode(root);
}

template<typename T>
void BinaryTree<T>::deleteNode(Node<T>* temp)
{
	if (!temp)
		return;
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
void BinaryTree<T>::reading(const std::string& filename)
{
	ifstream fin(filename);
	if (root != nullptr)
		deleteNode(root);

	int k;
	fin >> k;
	T temp;
	for (int i = 0; i < k; ++i)
	{
		fin >> temp;
		insert_node(temp);
	}
	fin.close();
}

template<typename T>
void BinaryTree<T>::print() const
{
	output(cout, this->root);
}

template<typename T>
void BinaryTree<T>::output(ostream& ost, Node<T>* temp)const
{
	if (!temp) return;
	ost << temp->data << " ";
	output(ost, temp-left);
	output(ost, temp->right);
}

template<typename T>
void BinaryTree<T>::writing(const std::string& filename)const
{
	ofstream fout(filename);
	output(fout, root);
	fout.close();
}

template<typename T>
void BinaryTree<T>::show(Node<T>* temp, unsigned int level)const
{

	if (temp)
	{
		show(temp->left, level + 1);
		for (unsigned int i = 0; i < level; i++)
			std::cout << "-";
		std::cout << temp->data << std::endl;
		show(temp->right, level + 1);
	}
}
