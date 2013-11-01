/* 
 * File:   copyStructure.h
 * Author: Gunendu Das
 *
 * Created on 10 September, 2012, 10:45 AM
 */

#include "dataTypes.h"


#ifndef COPYSTRUCTURE_H
#define	COPYSTRUCTURE_H



#endif	/* COPYSTRUCTURE_H */


class CcopyStructure{
    
public:
    
    RET_CODE static copyData(tagServerInfo &tsi,int lProcessList,int lSpaceList,int lineCount);
    RET_CODE static copyAdapterData(tapServerInfo &adapterInfo,int lcounter);
    RET_CODE static copyCommandData(lineDetails &ld,int number);
    CcopyStructure ();
    ~CcopyStructure();
};
