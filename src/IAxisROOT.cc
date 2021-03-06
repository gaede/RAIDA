#include <RAIDA/IAxisROOT.h> 
#include <RAIDA/RAIDAUtil.h>
#include <iostream>
#include <TAxis.h>
#include <float.h>

using namespace AIDA ;
using namespace std;

IAxisROOT::IAxisROOT(TAxis* axis)
  : _axis(axis),
    _fixedBinning(true)
{
}

void IAxisROOT::setFixedBinning() 
{
  _fixedBinning = true;
}

void IAxisROOT::setVariableBinning() 
{
  _fixedBinning = false;
}

bool IAxisROOT::isFixedBinning() const 
{
  return _fixedBinning;
}

double IAxisROOT::lowerEdge() const 
{
  return (double)_axis->GetBinLowEdge( 1 );
}

double IAxisROOT::upperEdge() const 
{
  return (double)_axis->GetBinUpEdge( _axis->GetNbins() );
}

int IAxisROOT::bins() const 
{
  return (int)_axis->GetNbins();
}

double IAxisROOT::binLowerEdge(int index) const 
{
  // check if index is in range
  if (index <= IAxis::UNDERFLOW_BIN) 
    return -DBL_MAX;
  if (index >= _axis->GetNbins() || index == IAxis::OVERFLOW_BIN) 
    return (double)_axis->GetBinUpEdge( _axis->GetNbins() );
  return (double)_axis->GetBinLowEdge( RAIDAUtil::binIndexAIDA2ROOT(index,bins()) );
}

double IAxisROOT::binUpperEdge(int index) const 
{
  // check if index is in range
  if (index <= IAxis::UNDERFLOW_BIN)
    return (double)_axis->GetBinLowEdge( 1 );
  if (index >= _axis->GetNbins() || index == IAxis::OVERFLOW_BIN)
    return DBL_MAX;
  return (double)_axis->GetBinUpEdge( RAIDAUtil::binIndexAIDA2ROOT(index,bins()) );
}

double IAxisROOT::binWidth(int index) const 
{
  // check if index is in range
  if (index <= 0) return 0;
  if (index > _axis->GetNbins() ) return 0;
  return (double)_axis->GetBinWidth( index );
}

int IAxisROOT::coordToIndex(double coord) const 
{
  return (int)_axis->FindFixBin(coord);
}
