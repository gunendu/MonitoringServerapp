/* 
 * File:   customthread.h
 * Author: siddharth
 *
 * Created on 10 July, 2012, 10:29 AM
 */

#ifndef BASICTHREAD_H
#define	BASICTHREAD_H



class CBasicThread
{
private:
    pthread_t         m_nThreadId;
    pthread_attr_t    m_stThreadAttributes;
    void*             m_pThreadParam;
    bool              m_bShutdownFlag;
    bool              m_bIsExitComplete;
    sem_t             m_cThreadStartWait;
    
private:
    
    
public:
    
    CBasicThread() : m_pThreadParam(NULL)
    {
        pthread_attr_init(&m_stThreadAttributes);
        pthread_attr_setdetachstate(&m_stThreadAttributes, PTHREAD_CREATE_JOINABLE);
        sem_init(&m_cThreadStartWait, 0, 0);
        m_bShutdownFlag = false;
        m_bIsExitComplete = false;
    }
    
    explicit CBasicThread(void* ThreadParam)
    {
        assert(ThreadParam);
        m_pThreadParam = ThreadParam;
        pthread_attr_init(&m_stThreadAttributes);
        pthread_attr_setdetachstate(&m_stThreadAttributes, PTHREAD_CREATE_JOINABLE);
        sem_init(&m_cThreadStartWait, 0, 0);
        m_bShutdownFlag = false;
        m_bIsExitComplete = false;
    }
    
    virtual ~CBasicThread();
    
    RET_CODE Start();
    RET_CODE Join();
    
    inline void NotifyThreadStartEvent();
    
    inline void* GetThreadParam()
    {
        return m_pThreadParam;
    }
    
    inline void SetShutdown()
    {
        m_bShutdownFlag = true;
        m_bIsExitComplete = false;
    }
    
    
    inline bool IsThreadInShutdown()
    {
        return static_cast<bool>(m_bShutdownFlag);
    }
    
    inline pthread_t getthreadId()
    {
        return m_nThreadId;
    }
    
    virtual RET_CODE Process(void* pcThreadParam = NULL) = 0;
    
    static void* ThreadProc(void* pcBasicThread);
    
};

#endif	/* BASICTHREAD_H */
