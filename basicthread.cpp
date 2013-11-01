#include "includes.h"

extern CLogger g_cSystemLogger;

RET_CODE CBasicThread::Start() {
    m_bShutdownFlag = false;
    m_bIsExitComplete = false;
    int lnReturnValue = pthread_create(&m_nThreadId,
            &m_stThreadAttributes,
            ThreadProc,
            this);
    if (THREAD_API_SUCCESS != lnReturnValue) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: ThreadStart failed(%s)", LOG_LOCATION, strerror(lnReturnValue));
        return FAILURE;
    }

    if (SYSTEM_CALL_ERROR == sem_wait(&m_cThreadStartWait)) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Wait for ThreadStart failed(%s)", LOG_LOCATION, strerror(errno));
        return FAILURE;
    }

    return SUCCESS;
}

RET_CODE CBasicThread::Join() {
    if (m_bIsExitComplete) {
        return SUCCESS;
    }

    if (false == m_bShutdownFlag) {
        SetShutdown();
    }

    int lnReturnValue = pthread_join(m_nThreadId, NULL);
    if (THREAD_API_SUCCESS != lnReturnValue) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Thread Join failed(%s)", LOG_LOCATION, strerror(lnReturnValue));
        //return FAILURE;
    }

    m_bIsExitComplete = true;

    return SUCCESS;
}

void* CBasicThread::ThreadProc(void* pcBasicThread) {
    CBasicThread* lpcBasicThread = static_cast<CBasicThread*> (pcBasicThread);
    lpcBasicThread->NotifyThreadStartEvent();
    void* lpcThreadParam = lpcBasicThread->GetThreadParam();
    if (FAILURE == lpcBasicThread->Process(lpcThreadParam)) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Thread Process failed", LOG_LOCATION);
    }

    pthread_exit(NULL);
}

void CBasicThread::NotifyThreadStartEvent() {
    if (SYSTEM_CALL_ERROR == sem_post(&m_cThreadStartWait)) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: semaphore post failed(%s)", LOG_LOCATION, strerror(errno));
    }
}

CBasicThread::~CBasicThread() {
    Join();
    int lnReturnValue = pthread_attr_destroy(&m_stThreadAttributes);
    if (THREAD_API_SUCCESS != lnReturnValue) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Thread attribute destroy failed(%s)", LOG_LOCATION, strerror(lnReturnValue));
    }

    if (SYSTEM_CALL_ERROR == sem_destroy(&m_cThreadStartWait)) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: semaphore destroy failed(%s)", LOG_LOCATION, strerror(errno));
    }
}