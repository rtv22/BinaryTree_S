#include <BinaryTree.hpp>
#include <catch.hpp>

SCENARIO ("init", "[init]")
{
  BinaryTree<int> obj;
  REQUIRE(obj.root_() == nullptr);
}

SCENARIO ("output to cout", "<<")
{
  BinaryTree<int> tree;
  tree.insert_node(3);
  REQUIRE(tree.show(tree.root_())->data == 3, 3);
}


SCENARIO("insert", "[insert]")
{
  BinaryTree<int> obj;
  obj.insert_node(3);
  REQUIRE(obj.find_node(3, obj.root_())->data == 3);
}

SCENARIO("find_node", "[find_node]")
{
  BinaryTree<int> obj;
  obj.insert_node(2);
  REQUIRE(obj.find_node(2, obj.root_()) != nullptr);
  REQUIRE(obj.find_node(2, obj.root_())->data == 2);
}

SCENARIO("get root", "[get root]")
{
  BinaryTree<int> obj;
  obj.insert_node(4);
  REQUIRE(obj.root_() != 0);
}
