#include <BinaryTree.hpp>
#include <catch.hpp>

SSCENARIO ("init", "[init]")
{
  BinaryTree<int> obj;
  REQUIRE(obj.root() == NULLPTR);
  REQUIRE(obj.data() == 0);
}
