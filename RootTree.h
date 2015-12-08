#ifndef RootTree_h
#define RootTree_h

#include <vector>
#include <string>
#include "TTree.h"

using namespace std;

struct RootTree
{
 public:
  RootTree();
  ~RootTree();

  void book(TTree* tree); // book leaves to fill the tree
  void clear();
  typedef std::vector<string> strings;
  typedef strings* stringsP;


public:
  TTree* tree_;
  double value_;
  double value2_;
  int runnumber_;
  int dpid_,hhmmss_;
  string yyyyMMdd_;
  long date_;
  stringsP name_;
 
};
//#endif

//#ifdef RootTree_cxx
RootTree::RootTree()
{
   name_  = new strings;
}
void RootTree::book(TTree* tree)
{
  tree_ = tree;
  tree_->Branch("runnumber", &runnumber_, "runnumber/I");
  tree_->Branch("dpid", &dpid_, "dpid/I");
  tree_->Branch("hhmmss", &hhmmss_, "hhmmss/I");
  tree_->Branch("yyyyMMdd", &yyyyMMdd_);
  tree_->Branch("date", &date_, "date/L");
  tree_->Branch("value", &value_, "value/D");
  tree_->Branch("value2", &value2_, "value2/D");
  tree_->Branch("name",  name_  );
}
void RootTree::clear()
{
   name_->clear();
   date_=-999;
   date_=0;
   value_=-9999.;
   value2_=-9999.;
}
RootTree::~RootTree()
{
}
#endif
