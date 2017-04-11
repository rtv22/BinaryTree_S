#include <iostream> 
#include <string> 
#include <fstream> 
#include <cstdint>

using namespace std;

template<typename T>
struct Node
{
	T	data;
	Node *left;
	Node *right;
};


template<typename T>
class BinaryTree
{
private:
	Node<T> *root;
public:
	BinaryTree();
	~BinaryTree();
	Node<T> *search(const T&);
	void add_node(const T&, Node<T>*&);
	void reading(const std::string);
	void outfile(Node<T>*, ostream&)const;
	void writing(const std::string);
};