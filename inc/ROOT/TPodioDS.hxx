#ifndef ROOT_TPODIODS
#define ROOT_TPODIODS

#include "ROOT/TDataFrame.hxx"
#include "ROOT/TDataSource.hxx"

#include "RStringView.h"
#include "ROOT/RMakeUnique.hxx"

namespace ROOT {
namespace Experimental {
namespace TDF {

class TPodioDS final : public ROOT::Experimental::TDF::TDataSource {
private:
   unsigned int fNSlots = 0U;
   ULong64_t fSize = 0ULL;
   std::vector<std::pair<ULong64_t, ULong64_t>> fEntryRanges;
   std::vector<std::string> fColNames;
   Record_t GetColumnReadersImpl(std::string_view name, const std::type_info &)
   {
      return Record_t();
   };

public:
   TPodioDS(std::string_view treeName, std::string_view fileNameGlob) {};
   ~TPodioDS() {};
   const std::vector<std::string> &GetColumnNames() const {return std::vector<std::string>();};
   bool HasColumn(std::string_view colName) const {return false;};
   std::string GetTypeName(std::string_view) const {return "void";};
   std::vector<std::pair<ULong64_t, ULong64_t>> GetEntryRanges() {return std::vector<std::pair<ULong64_t, ULong64_t>>();};
   void SetEntry(unsigned int slot, ULong64_t entry) {};
   void SetNSlots(unsigned int nSlots) {};
   void Initialise() {};
};

TDataFrame MakePodioDataFrame(std::string_view treeName, std::string_view fileNameGlob)
{
   ROOT::Experimental::TDataFrame tdf(std::make_unique<TPodioDS>(treeName, fileNameGlob));
   return tdf;
}

} // ns TDF
} // ns Experimental
} // ns ROOT

#endif
