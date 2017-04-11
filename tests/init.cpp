#include <BinaryTree.hpp>
#include <catch.hpp>

SCENARIO ("init", "[init]")
{
  Tree<int> obj;
  REQUIRE(obj.root_() == nullptr);
  REQUIRE(obj.get_count() == 0);
}
SCENARIO("insert", "[insert]")
{
  Tree<int> obj;
  obj.insert_node(3);
  REQUIRE(obj.find_node(3, obj.root_())->data == 3);
}
SCENARIO("find_node", "[find_node]")
{
  Tree<int> obj;
  test.insert_node(2);
  REQUIRE(obj.find_node(2, obj.root_()) != nullptr);
  REQUIRE(obj.find_node(2, obj.root_())->data == 4);
}
