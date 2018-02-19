#include <ROOT/TPodioDS.hxx>

#include <gtest/gtest.h>

using namespace ROOT::Experimental;
using namespace ROOT::Experimental::TDF;

TEST(TPodioDS, Constructor)
{
   TPodioDS ds("myTree","myglob*.root");
}
