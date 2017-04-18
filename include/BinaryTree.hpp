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
	uint16_t CountElements = 0;
public:
	BinaryTree();
	~BinaryTree();
	void deleteNode(Node<T>* temp);
	void insert_node(const T&);
	void print()const;
	Node<T>*root_();
	Node<T> *find_node(const T&, Node<T>*)const;
	void reading(const std::string&);
	void output(std::ostream&,const Node<T>*);
	void writing(const std::string&)const;
	bool search_result(const T& value)const;
	Node<T>* get_pointer(const T& value, Node<T>* temp)const;
	friend std::ostream& show(std::ostream&, Node<T>*, unsigned int);
	friend std::ostream& operator<<(ostream&, BinaryTree<T>&);

};

template<typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	deleteNode(root);
}

template<typename T>
Node<T> *BinaryTree<T>::get_pointer(const T& value, Node<T>* temp)const
{
	if (temp == 0 || value == temp->data)
		return temp;
	if (value > temp->data)
		return get_pointer(value, temp->right);
	else return get_pointer(value, temp->left);
}

template<typename T>
bool BinaryTree<T>::search_result(const T& value)const
{
	return get_pointer(value, root);
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
void output(std::ostream& ost,const Node<T>* temp)
{
	if (temp == nullptr)
	{
		return;
	}
	else
	{	
		ost << temp->data << "	";
		output(ost, temp->left);
		output(ost, temp->right);
	}
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
void BinaryTree<T>::writing(const std::string& filename)const
{
	ofstream file_1(filename);
	file_1 << CountElements << "\t";
	output(file_1, root);
	file_1.close();
}

template<typename T>	
std::ostream& show(std::ostream& ost, Node<T>* temp, unsigned int level)
{
	show(ost, temp->right, level + 1);
	for (unsigned int i = 0; i < level; i++)
	ost << "\t";
	ost << temp->data << std::endl;
	show(ost, temp->left, level + 1);
	return ost;
}

template<typename T>	
std::ostream& operator<<(ostream& ost, BinaryTree<T>& temp)
{
	show(ost, temp.root, 0);
	return ost;
}
