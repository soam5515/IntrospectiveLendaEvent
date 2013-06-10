/*
//
// Class providing the map between variable names and their instances
// in the child classes
//
*/

#ifndef __INTROSPECTIVE_HH
#define __INTROSPECTIVE_HH

#include "TObject.h"
#include <map>
#include <string>
#include <utility> 
#include "CorrectionInfo.hh"
using namespace std;



class Introspective : public TObject {

public:
  Introspective();
  
  Int_t correctionCount;
  //for adding a single entry to the table outside of 
  //deineMap method
  void AddMapEntry(std::string,void*);

  //Define pure virutal method for defining the table
  virtual void DefineMap()=0;//method defining the variables in the map should be auto-generated
  
  void * Get(std::string);

  void DefineCorrection(string time, string otherVar,vector<Double_t> coefs,Int_t channel);
  void DumpCorrectionsMap();
  void DumpMappedVariables();
  void DumpResultMap();
  void DumpIntrospective();
  void DumpResultVector();

  void PrintCorrection(string in);
  vector< pair<string,CorrectionInfo> > correctionsMap;

  void ApplyDynamicCorrections(); // MAgic function
  void Reset();
  map <std::string,void*> theMap;
  vector <Double_t> theDynamicCorrectionResults;


  map <string,int> mapForCorrectionResults;
private:

public:

};

#endif

