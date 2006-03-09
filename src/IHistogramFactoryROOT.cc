// #include <RAIDA/IHistogramROOT.h>
#include <RAIDA/IProfile1DROOT.h>
#include <RAIDA/IProfile2DROOT.h>
#include <RAIDA/IHistogram1DROOT.h>
#include <RAIDA/IHistogram2DROOT.h>
#include <RAIDA/IHistogram3DROOT.h>
#include <RAIDA/ICloud1DROOT.h>
#include <RAIDA/ICloud2DROOT.h>
#include <RAIDA/ICloud3DROOT.h>
#include <RAIDA/IHistogramFactoryROOT.h>
#include <RAIDA/PathName.h>

#include <TH1D.h>
#include <TH2D.h>

using namespace AIDA ;
using namespace std;

// nMax is for some Constructors of ICloud
const int IHistogramFactoryROOT::_nMaxDefault = -1;


IHistogramFactoryROOT::IHistogramFactoryROOT(ITree & tree)
{
  _usedTree = &tree;
}

IHistogram1D * IHistogramFactoryROOT::createHistogram1D(
               const std::string & path, 
               const std::string & title, 
               int nBins, 
               double lowerEdge, 
               double upperEdge, 
               const std::string & options) 
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  IHistogram1DROOT* histo = new IHistogram1DROOT(thePath.getName(),
					       title,nBins,lowerEdge,upperEdge,
					       options) ;

  _usedTree->cd( thePWD ) ;

  return histo;
}

IHistogram1D * IHistogramFactoryROOT::createHistogram1D
                                            (const std::string & pathAndTitle,
					     int nBins,
					     double lowerEdge,
					     double upperEdge) 
{
  PathName thePath(pathAndTitle);
  if (thePath.getName() == "") return NULL;
  return createHistogram1D(pathAndTitle,thePath.getName(),
			   nBins,lowerEdge,upperEdge);
}

IHistogram1D * IHistogramFactoryROOT::createCopy(const std::string & path,
						 const IHistogram1D & hist) 
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  const IHistogram1DROOT* phist = dynamic_cast<const IHistogram1DROOT*>(&hist);
  if (!phist) return NULL;
  IHistogram1DROOT* histogram = new IHistogram1DROOT(thePath.getName(),
						     *phist) ;

  _usedTree->cd( thePWD ) ;

  return histogram;
}

IHistogram2D * IHistogramFactoryROOT::createHistogram2D(
                                      const std::string & path,
				      const std::string & title,
				      int nBinsX,
				      double lowerEdgeX,
				      double upperEdgeX,
				      int nBinsY,
				      double lowerEdgeY,
				      double upperEdgeY,
				      const std::string & options) 
{
  PathName thePath(path);
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  IHistogram2DROOT* histo = new IHistogram2DROOT(thePath.getName(),
						 title,
						 nBinsX,lowerEdgeX,upperEdgeX,
						 nBinsY,lowerEdgeY,upperEdgeY,
						 options) ;

  _usedTree->cd( thePWD ) ;

  return histo;
}

IHistogram2D * IHistogramFactoryROOT::createHistogram2D(const std::string & pathAndTitle,
							int nBinsX,
							double lowerEdgeX,
							double upperEdgeX,
							int nBinsY,
							double lowerEdgeY,
							double upperEdgeY) 
{
  PathName thePath(pathAndTitle);
  if (thePath.getName() == "") return NULL;
  return createHistogram2D(pathAndTitle,thePath.getName(),
                           nBinsX,lowerEdgeX,upperEdgeX,
                           nBinsY,lowerEdgeY,upperEdgeY);
}

IHistogram2D * IHistogramFactoryROOT::createCopy(const std::string & path,
						 const IHistogram2D & hist) 
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  const IHistogram2DROOT* phist = dynamic_cast<const IHistogram2DROOT*>(&hist);
  if (!phist) return NULL;
  IHistogram2DROOT* histogram = new IHistogram2DROOT(thePath.getName(),
						     *phist) ;

  _usedTree->cd( thePWD ) ;

  return histogram;
}

IHistogram3D * IHistogramFactoryROOT::createHistogram3D
                                      (const std::string & path,
                                       const std::string & title,
                                       int nBinsX,
                                       double lowerEdgeX,
                                       double upperEdgeX,
                                       int nBinsY,
                                       double lowerEdgeY,
                                       double upperEdgeY,
                                       int nBinsZ,
                                       double lowerEdgeZ,
                                       double upperEdgeZ,
                                       const std::string & options) 
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  IHistogram3DROOT* histo = new IHistogram3DROOT(thePath.getName(),
						 title,
						 nBinsX,lowerEdgeX,upperEdgeX,
						 nBinsY,lowerEdgeY,upperEdgeY,
						 nBinsZ,lowerEdgeZ,upperEdgeZ,
						 options) ;

  _usedTree->cd( thePWD ) ;

  return histo;
}

IHistogram3D * IHistogramFactoryROOT::createHistogram3D(const std::string & pathAndTitle,
							int nBinsX,
							double lowerEdgeX,
							double upperEdgeX,
							int nBinsY,
							double lowerEdgeY,
							double upperEdgeY,
							int nBinsZ,
							double lowerEdgeZ,
							double upperEdgeZ) 
{
  PathName thePath(pathAndTitle);
  if (thePath.getName() == "") return NULL;
  return createHistogram3D(pathAndTitle,thePath.getName(),
                           nBinsX,lowerEdgeX,upperEdgeX,
                           nBinsY,lowerEdgeY,upperEdgeY,
                           nBinsZ,lowerEdgeZ,upperEdgeZ);
}

IHistogram3D * IHistogramFactoryROOT::createCopy(const std::string & path,
						 const IHistogram3D & hist) 
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  const IHistogram3DROOT* phist = dynamic_cast<const IHistogram3DROOT*>(&hist);
  if (!phist) return NULL;
  IHistogram3DROOT* histogram = new IHistogram3DROOT(thePath.getName(),
						     *phist) ;

  _usedTree->cd( thePWD ) ;

  return histogram;
}

IProfile1D * IHistogramFactoryROOT::createProfile1D(const std::string & path,
						    const std::string & title,
						    int nBins,
						    double lowerEdge,
						    double upperEdge,
						    const std::string & options) 
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  IProfile1DROOT* histo = new IProfile1DROOT(thePath.getName(),
					     title,
					     nBins,lowerEdge,upperEdge,
					     options) ;

  _usedTree->cd( thePWD ) ;

  return histo;
}

IProfile1D * IHistogramFactoryROOT::createProfile1D(const std::string & path,
						    const std::string & title,
						    int nBins,
						    double lowerEdge,
						    double upperEdge,
						    double lowerValue,
						    double upperValue,
						    const std::string & options) 
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  IProfile1DROOT* histo = new IProfile1DROOT(thePath.getName(),
					     title,
					     nBins,lowerEdge,upperEdge,
					     lowerValue,upperValue,
					     options) ;

  _usedTree->cd( thePWD ) ;

  return histo;
}

IProfile1D * IHistogramFactoryROOT::createProfile1D(const std::string & pathAndTitle,
						    int nBins,
						    double lowerEdge,
						    double upperEdge) 
{
  PathName thePath(pathAndTitle);
  if (thePath.getName() == "") return NULL;
  return createProfile1D(pathAndTitle,thePath.getName(),
			 nBins,lowerEdge,upperEdge);
}

IProfile1D * IHistogramFactoryROOT::createProfile1D(const std::string & pathAndTitle,
						    int nBins,
						    double lowerEdge,
						    double upperEdge,
						    double lowerValue,
						    double upperValue) 
{
  PathName thePath(pathAndTitle);
  if (thePath.getName() == "") return NULL;
  return createProfile1D(pathAndTitle,thePath.getName(),
			 nBins,lowerEdge,upperEdge,lowerValue,upperValue);
}

IProfile1D * IHistogramFactoryROOT::createCopy(const std::string & path,
					       const IProfile1D & profile) 
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  const IProfile1DROOT* pprof = dynamic_cast<const IProfile1DROOT*>(&profile);
  if (!pprof) return NULL;
  IProfile1DROOT* profhist = new IProfile1DROOT(thePath.getName(),
						 *pprof) ;

  _usedTree->cd( thePWD ) ;

  return profhist;
}


IProfile2D * IHistogramFactoryROOT::createProfile2D(const std::string & path,
						    const std::string & title,
						    int nBinsX,
						    double lowerEdgeX,
						    double upperEdgeX,
						    int nBinsY,
						    double lowerEdgeY,
						    double upperEdgeY,
						    const std::string & options)
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  IProfile2DROOT* histo = new IProfile2DROOT(thePath.getName(),
					     title,
					     nBinsX,lowerEdgeX,upperEdgeX,
					     nBinsY,lowerEdgeY,upperEdgeY,
					     options) ;

  _usedTree->cd( thePWD ) ;

  return histo;
}

IProfile2D * IHistogramFactoryROOT::createProfile2D(const std::string & path,
						    const std::string & title,
						    int nBinsX,
						    double lowerEdgeX,
						    double upperEdgeX,
						    int nBinsY,
						    double lowerEdgeY,
						    double upperEdgeY,
						    double lowerValue,
						    double upperValue,
						    const std::string & options) 
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  IProfile2DROOT* histo = new IProfile2DROOT(thePath.getName(),
					     title,
					     nBinsX,lowerEdgeX,upperEdgeX,
					     nBinsY,lowerEdgeY,upperEdgeY,
					     lowerValue,upperValue,
					     options) ;

  _usedTree->cd( thePWD ) ;

  return histo;
}

IProfile2D * IHistogramFactoryROOT::createProfile2D(const std::string & pathAndTitle,
						    int nBinsX,
						    double lowerEdgeX,
						    double upperEdgeX,
						    int nBinsY,
						    double lowerEdgeY,
						    double upperEdgeY) 
{
  PathName thePath(pathAndTitle);
  if (thePath.getName() == "") return NULL;
  return createProfile2D(pathAndTitle,thePath.getName(),
			 nBinsX,lowerEdgeX,upperEdgeX,
			 nBinsY,lowerEdgeY,upperEdgeY);
}

IProfile2D * IHistogramFactoryROOT::createProfile2D(const std::string & pathAndTitle,
						    int nBinsX,
						    double lowerEdgeX,
						    double upperEdgeX,
						    int nBinsY,
						    double lowerEdgeY,
						    double upperEdgeY,
						    double lowerValue,
						    double upperValue) 
{
  PathName thePath(pathAndTitle);
  if (thePath.getName() == "") return NULL;
  return createProfile2D(pathAndTitle,thePath.getName(),
			 nBinsX,lowerEdgeX,upperEdgeX,
			 nBinsY,lowerEdgeY,upperEdgeY,
			 lowerValue,upperValue);
}

IProfile2D * IHistogramFactoryROOT::createCopy(const std::string & path,
					       const IProfile2D & profile) 
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  const IProfile2DROOT* pprof = dynamic_cast<const IProfile2DROOT*>(&profile);
  if (!pprof) return NULL;
  IProfile2DROOT* profhist = new IProfile2DROOT(thePath.getName(),
						 *pprof) ;

  _usedTree->cd( thePWD ) ;

  return profhist;
}

ICloud1D * IHistogramFactoryROOT::createCloud1D(
           const std::string & path,
	   const std::string & title,
	   int nMax,
	   const std::string & options) 
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  ICloud1DROOT* histo = new ICloud1DROOT(thePath.getPathName(),
					 title,nMax,_usedTree,options);

  _usedTree->cd( thePWD ) ;

  return histo;
}

ICloud1D * IHistogramFactoryROOT::createCloud1D(const std::string & pathAndTitle) 
{
  PathName thePath(pathAndTitle);
  if (thePath.getName() == "") return NULL;
  return createCloud1D(pathAndTitle,thePath.getName(),_nMaxDefault,"");
}

ICloud1D * IHistogramFactoryROOT::createCopy(const std::string & path,
					     const ICloud1D & cloud) 
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  const ICloud1DROOT* pcloud = dynamic_cast<const ICloud1DROOT*>(&cloud);
  if (!pcloud) return NULL;
  ICloud1DROOT* newCloud = new ICloud1DROOT(thePath.getPathName(),
					    _usedTree,*pcloud);

  _usedTree->cd( thePWD ) ;

  return newCloud;
}

ICloud2D * IHistogramFactoryROOT::createCloud2D(const std::string & path,
			          const std::string & title,
			          int nMax,
			          const std::string & options) 
{
  PathName thePath(path);
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  ICloud2DROOT* histo = new ICloud2DROOT(thePath.getPathName(),
					 title,nMax,_usedTree,options);

  _usedTree->cd( thePWD ) ;

  return histo;
}

ICloud2D * IHistogramFactoryROOT::createCloud2D(const std::string & pathAndTitle) 
{
  PathName thePath(pathAndTitle);
  if (thePath.getName() == "") return NULL;
  return createCloud2D(pathAndTitle,thePath.getName(),_nMaxDefault,"");
}

ICloud2D * IHistogramFactoryROOT::createCopy(const std::string & path,
					     const ICloud2D & cloud) 
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  const ICloud2DROOT* pcloud = dynamic_cast<const ICloud2DROOT*>(&cloud);
  if (!pcloud) return NULL;
  ICloud2DROOT* newCloud = new ICloud2DROOT(thePath.getPathName(),
					    _usedTree,*pcloud);

  _usedTree->cd( thePWD ) ;

  return newCloud;
}

ICloud3D * IHistogramFactoryROOT::createCloud3D(const std::string & path,
						const std::string & title,
						int nMax,
						const std::string & options)
{
  PathName thePath(path);
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  ICloud3DROOT* histo = new ICloud3DROOT(thePath.getPathName(),
					 title,nMax,_usedTree,options);

  _usedTree->cd( thePWD ) ;

  return histo;
}

ICloud3D * IHistogramFactoryROOT::createCloud3D(const std::string & pathAndTitle) 
{
  PathName thePath(pathAndTitle);
  if (thePath.getName() == "") return NULL;
  return createCloud3D(pathAndTitle,thePath.getName(),_nMaxDefault,"");
}

ICloud3D * IHistogramFactoryROOT::createCopy(const std::string & path,
					     const ICloud3D & cloud) 
{
  PathName thePath(path);
  //cout << "L" << thePath.getPath() << "r" << endl;
  if (thePath.getName() == "") return NULL;

  string thePWD = _usedTree->pwd();

  if ( !thePath.onlyName() )
    {
      if (!_usedTree->cd(thePath.getPath()) ) return NULL;
    }

  const ICloud3DROOT* pcloud = dynamic_cast<const ICloud3DROOT*>(&cloud);
  if (!pcloud) return NULL;
  ICloud3DROOT* newCloud = new ICloud3DROOT(thePath.getPathName(),
					    _usedTree,*pcloud);

  _usedTree->cd( thePWD ) ;

  return newCloud;
}
