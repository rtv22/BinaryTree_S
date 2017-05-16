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
  REQUIRE( std::cout << tree );
}

SCENARIO("find_node", "[find_node]")
  {
    BinaryTree<int> obj;
    obj.insert_node(4);
    obj.insert_node(2);
    REQUIRE(obj.find_node(2, obj.root_()) != nullptr);
    REQUIRE(obj.find_node(2, obj.root_())->data == 2);
  }

SCENARIO("insert", "[insert]")
{
  BinaryTree<int> obj;
  obj.insert_node(3);
  REQUIRE(obj.find_node(3, obj.root_())->data == 3);
}

SCENARIO("removeElement", "[remEl]")
{
  BinaryTree<int> obj;
  obj.insert_node(1);
  obj.insert_node(2);
  obj.insert_node(3);
  obj.remove_element(1);
  REQUIRE(obj.find_node(1, obj.root_())== nullptr);
  REQUIRE(obj.find_node(2, obj.root_())== obj.root_());
  REQUIRE(obj.root_() != nullptr);
}

SCENARIO("DEL", "[Del]")
{
  BinaryTree<int> obj;
  obj.insert_node(1);
  obj.insert_node(2);
  obj.remove_element(2);
  REQUIRE(obj.count() == 1);
}
