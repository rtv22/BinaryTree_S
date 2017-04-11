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
	Node<T> *find_node(const T&, Node<T>*)const;
	void show(Node<T>*, unsigned int)const;
	void reading(const std::string&);
	void output(std::ostream& ost, Node<T>*)const;
	void writing(const std::string&)const;
};
