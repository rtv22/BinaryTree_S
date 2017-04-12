#include <BinaryTree.hpp>
#include <catch.hpp>

SCENARIO ("init", "[init]")
{
  BinaryTree<int> obj;
  REQUIRE(obj.root_() == nullptr);
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

SCENARIO ("reading/writing", "[read/write]")
{
  BinaryTree<int> obj;
  obj.insert_node(1);
  obj.insert_node(2);
  obj.writing("file2.txt");
  Tree<int> obj_1;
  obj_1.reading("file2.txt");
  REQUIRE(obj_1.find_node(1, obj_1.root_())!= nullptr);
  REQUIRE(obj_1.find_node(2, obj_1.root_())!= nullptr);
}
