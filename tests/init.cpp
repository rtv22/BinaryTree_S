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
  Tree<int> test1;
  test1.insert_node(4);
  test1.insert_node(3);
  test1.writing("file2.txt");
  Tree<int> test2;
  test2.reading("file2.txt");
  REQUIRE(test2.find_node(4, test2.root_())!= nullptr);
  REQUIRE(test2.find_node(3, test2.root_())!= nullptr);
  REQUIRE(test1.get_count() == test2.get_count());
}
