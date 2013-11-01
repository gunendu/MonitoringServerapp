
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from Monitoring.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#ifndef MonitoringSupport_1808175700_h
#define MonitoringSupport_1808175700_h

/* Uses */
#include "Monitoring.h"



#ifdef __cplusplus
#ifndef ndds_cpp_h
  #include "ndds/ndds_cpp.h"
#endif
#else
#ifndef ndds_c_h
  #include "ndds/ndds_c.h"
#endif
#endif


namespace MONITORING{
        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) ::DDSTypeSupport;
  class __declspec(dllimport) ::DDSDataWriter;
  class __declspec(dllimport) ::DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(lineDetailsTypeSupport, lineDetails);

DDS_DATAWRITER_CPP(lineDetailsDataWriter, lineDetails);
DDS_DATAREADER_CPP(lineDetailsDataReader, lineDetailsSeq, lineDetails);


#else

DDS_TYPESUPPORT_C(lineDetailsTypeSupport, lineDetails);
DDS_DATAWRITER_C(lineDetailsDataWriter, lineDetails);
DDS_DATAREADER_C(lineDetailsDataReader, lineDetailsSeq, lineDetails);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) ::DDSTypeSupport;
  class __declspec(dllimport) ::DDSDataWriter;
  class __declspec(dllimport) ::DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(pslInfoTypeSupport, pslInfo);

DDS_DATAWRITER_CPP(pslInfoDataWriter, pslInfo);
DDS_DATAREADER_CPP(pslInfoDataReader, pslInfoSeq, pslInfo);


#else

DDS_TYPESUPPORT_C(pslInfoTypeSupport, pslInfo);
DDS_DATAWRITER_C(pslInfoDataWriter, pslInfo);
DDS_DATAREADER_C(pslInfoDataReader, pslInfoSeq, pslInfo);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) ::DDSTypeSupport;
  class __declspec(dllimport) ::DDSDataWriter;
  class __declspec(dllimport) ::DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(ipSequenceTypeSupport, ipSequence);

DDS_DATAWRITER_CPP(ipSequenceDataWriter, ipSequence);
DDS_DATAREADER_CPP(ipSequenceDataReader, ipSequenceSeq, ipSequence);


#else

DDS_TYPESUPPORT_C(ipSequenceTypeSupport, ipSequence);
DDS_DATAWRITER_C(ipSequenceDataWriter, ipSequence);
DDS_DATAREADER_C(ipSequenceDataReader, ipSequenceSeq, ipSequence);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) ::DDSTypeSupport;
  class __declspec(dllimport) ::DDSDataWriter;
  class __declspec(dllimport) ::DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(leaseProcessStartTypeSupport, leaseProcessStart);

DDS_DATAWRITER_CPP(leaseProcessStartDataWriter, leaseProcessStart);
DDS_DATAREADER_CPP(leaseProcessStartDataReader, leaseProcessStartSeq, leaseProcessStart);


#else

DDS_TYPESUPPORT_C(leaseProcessStartTypeSupport, leaseProcessStart);
DDS_DATAWRITER_C(leaseProcessStartDataWriter, leaseProcessStart);
DDS_DATAREADER_C(leaseProcessStartDataReader, leaseProcessStartSeq, leaseProcessStart);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) ::DDSTypeSupport;
  class __declspec(dllimport) ::DDSDataWriter;
  class __declspec(dllimport) ::DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(leaseLineInfoTypeSupport, leaseLineInfo);

DDS_DATAWRITER_CPP(leaseLineInfoDataWriter, leaseLineInfo);
DDS_DATAREADER_CPP(leaseLineInfoDataReader, leaseLineInfoSeq, leaseLineInfo);


#else

DDS_TYPESUPPORT_C(leaseLineInfoTypeSupport, leaseLineInfo);
DDS_DATAWRITER_C(leaseLineInfoDataWriter, leaseLineInfo);
DDS_DATAREADER_C(leaseLineInfoDataReader, leaseLineInfoSeq, leaseLineInfo);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) ::DDSTypeSupport;
  class __declspec(dllimport) ::DDSDataWriter;
  class __declspec(dllimport) ::DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(tapServerInfoTypeSupport, tapServerInfo);

DDS_DATAWRITER_CPP(tapServerInfoDataWriter, tapServerInfo);
DDS_DATAREADER_CPP(tapServerInfoDataReader, tapServerInfoSeq, tapServerInfo);


#else

DDS_TYPESUPPORT_C(tapServerInfoTypeSupport, tapServerInfo);
DDS_DATAWRITER_C(tapServerInfoDataWriter, tapServerInfo);
DDS_DATAREADER_C(tapServerInfoDataReader, tapServerInfoSeq, tapServerInfo);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) ::DDSTypeSupport;
  class __declspec(dllimport) ::DDSDataWriter;
  class __declspec(dllimport) ::DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(tagProcessInfoTypeSupport, tagProcessInfo);

DDS_DATAWRITER_CPP(tagProcessInfoDataWriter, tagProcessInfo);
DDS_DATAREADER_CPP(tagProcessInfoDataReader, tagProcessInfoSeq, tagProcessInfo);


#else

DDS_TYPESUPPORT_C(tagProcessInfoTypeSupport, tagProcessInfo);
DDS_DATAWRITER_C(tagProcessInfoDataWriter, tagProcessInfo);
DDS_DATAREADER_C(tagProcessInfoDataReader, tagProcessInfoSeq, tagProcessInfo);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) ::DDSTypeSupport;
  class __declspec(dllimport) ::DDSDataWriter;
  class __declspec(dllimport) ::DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(tagSpaceInfoTypeSupport, tagSpaceInfo);

DDS_DATAWRITER_CPP(tagSpaceInfoDataWriter, tagSpaceInfo);
DDS_DATAREADER_CPP(tagSpaceInfoDataReader, tagSpaceInfoSeq, tagSpaceInfo);


#else

DDS_TYPESUPPORT_C(tagSpaceInfoTypeSupport, tagSpaceInfo);
DDS_DATAWRITER_C(tagSpaceInfoDataWriter, tagSpaceInfo);
DDS_DATAREADER_C(tagSpaceInfoDataReader, tagSpaceInfoSeq, tagSpaceInfo);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) ::DDSTypeSupport;
  class __declspec(dllimport) ::DDSDataWriter;
  class __declspec(dllimport) ::DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(tagServerInfoTypeSupport, tagServerInfo);

DDS_DATAWRITER_CPP(tagServerInfoDataWriter, tagServerInfo);
DDS_DATAREADER_CPP(tagServerInfoDataReader, tagServerInfoSeq, tagServerInfo);


#else

DDS_TYPESUPPORT_C(tagServerInfoTypeSupport, tagServerInfo);
DDS_DATAWRITER_C(tagServerInfoDataWriter, tagServerInfo);
DDS_DATAREADER_C(tagServerInfoDataReader, tagServerInfoSeq, tagServerInfo);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


} /* namespace MONITORING */


#endif  /* MonitoringSupport_1808175700_h */
