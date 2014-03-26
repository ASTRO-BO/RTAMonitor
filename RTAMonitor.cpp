// **********************************************************************
//
// Copyright (c) 2003-2013 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.5.1
//
// <auto-generated>
//
// Generated from file `RTAMonitor.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <RTAMonitor.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 305
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

namespace
{

const ::std::string __CTA__RTAMonitor__sendParameter_name = "sendParameter";

const ::std::string __CTA__RTAMonitor__sendLog_name = "sendLog";

const ::std::string __CTA__RTAMonitor__registerApp_name = "registerApp";

}

namespace Ice
{
}
::IceProxy::Ice::Object* ::IceProxy::CTA::upCast(::IceProxy::CTA::RTAMonitor* p) { return p; }

void
::IceProxy::CTA::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::CTA::RTAMonitor>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::CTA::RTAMonitor;
        v->__copyFrom(proxy);
    }
}

void
IceProxy::CTA::RTAMonitor::sendParameter(const ::CTA::Parameter& param, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __CTA__RTAMonitor__sendParameter_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::CTA::RTAMonitor* __del = dynamic_cast< ::IceDelegate::CTA::RTAMonitor*>(__delBase.get());
            __del->sendParameter(param, __ctx, __observer);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, true, __cnt, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::CTA::RTAMonitor::begin_sendParameter(const ::CTA::Parameter& param, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __CTA__RTAMonitor__sendParameter_name, __del, __cookie);
    try
    {
        __result->__prepare(__CTA__RTAMonitor__sendParameter_name, ::Ice::Idempotent, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(param);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::CTA::RTAMonitor::end_sendParameter(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __CTA__RTAMonitor__sendParameter_name);
}

void
IceProxy::CTA::RTAMonitor::sendLog(const ::CTA::LogMessage& msg, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __CTA__RTAMonitor__sendLog_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::CTA::RTAMonitor* __del = dynamic_cast< ::IceDelegate::CTA::RTAMonitor*>(__delBase.get());
            __del->sendLog(msg, __ctx, __observer);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, true, __cnt, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::CTA::RTAMonitor::begin_sendLog(const ::CTA::LogMessage& msg, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __CTA__RTAMonitor__sendLog_name, __del, __cookie);
    try
    {
        __result->__prepare(__CTA__RTAMonitor__sendLog_name, ::Ice::Idempotent, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(msg);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::CTA::RTAMonitor::end_sendLog(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __CTA__RTAMonitor__sendLog_name);
}

void
IceProxy::CTA::RTAMonitor::registerApp(::Ice::Int apid, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __CTA__RTAMonitor__registerApp_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::CTA::RTAMonitor* __del = dynamic_cast< ::IceDelegate::CTA::RTAMonitor*>(__delBase.get());
            __del->registerApp(apid, __ctx, __observer);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, true, __cnt, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::CTA::RTAMonitor::begin_registerApp(::Ice::Int apid, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __CTA__RTAMonitor__registerApp_name, __del, __cookie);
    try
    {
        __result->__prepare(__CTA__RTAMonitor__registerApp_name, ::Ice::Idempotent, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(apid);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::CTA::RTAMonitor::end_registerApp(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __CTA__RTAMonitor__registerApp_name);
}

const ::std::string&
IceProxy::CTA::RTAMonitor::ice_staticId()
{
    return ::CTA::RTAMonitor::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::CTA::RTAMonitor::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::CTA::RTAMonitor);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::CTA::RTAMonitor::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::CTA::RTAMonitor);
}

::IceProxy::Ice::Object*
IceProxy::CTA::RTAMonitor::__newInstance() const
{
    return new RTAMonitor;
}

void
IceDelegateM::CTA::RTAMonitor::sendParameter(const ::CTA::Parameter& param, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __CTA__RTAMonitor__sendParameter_name, ::Ice::Idempotent, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(param);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(__og.hasResponse())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.readEmptyParams();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::CTA::RTAMonitor::sendLog(const ::CTA::LogMessage& msg, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __CTA__RTAMonitor__sendLog_name, ::Ice::Idempotent, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(msg);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(__og.hasResponse())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.readEmptyParams();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::CTA::RTAMonitor::registerApp(::Ice::Int apid, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __CTA__RTAMonitor__registerApp_name, ::Ice::Idempotent, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(apid);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(__og.hasResponse())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.readEmptyParams();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateD::CTA::RTAMonitor::sendParameter(const ::CTA::Parameter& param, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::CTA::Parameter& __p_param, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_param(__p_param)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::CTA::RTAMonitor* servant = dynamic_cast< ::CTA::RTAMonitor*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->sendParameter(_m_param, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::CTA::Parameter& _m_param;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __CTA__RTAMonitor__sendParameter_name, ::Ice::Idempotent, __context);
    try
    {
        _DirectI __direct(param, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::CTA::RTAMonitor::sendLog(const ::CTA::LogMessage& msg, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::CTA::LogMessage& __p_msg, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_msg(__p_msg)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::CTA::RTAMonitor* servant = dynamic_cast< ::CTA::RTAMonitor*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->sendLog(_m_msg, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::CTA::LogMessage& _m_msg;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __CTA__RTAMonitor__sendLog_name, ::Ice::Idempotent, __context);
    try
    {
        _DirectI __direct(msg, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::CTA::RTAMonitor::registerApp(::Ice::Int apid, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int __p_apid, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_apid(__p_apid)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::CTA::RTAMonitor* servant = dynamic_cast< ::CTA::RTAMonitor*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->registerApp(_m_apid, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int _m_apid;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __CTA__RTAMonitor__registerApp_name, ::Ice::Idempotent, __context);
    try
    {
        _DirectI __direct(apid, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::Ice::Object* CTA::upCast(::CTA::RTAMonitor* p) { return p; }

namespace
{
const ::std::string __CTA__RTAMonitor_ids[2] =
{
    "::CTA::RTAMonitor",
    "::Ice::Object"
};

}

bool
CTA::RTAMonitor::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__CTA__RTAMonitor_ids, __CTA__RTAMonitor_ids + 2, _s);
}

::std::vector< ::std::string>
CTA::RTAMonitor::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__CTA__RTAMonitor_ids[0], &__CTA__RTAMonitor_ids[2]);
}

const ::std::string&
CTA::RTAMonitor::ice_id(const ::Ice::Current&) const
{
    return __CTA__RTAMonitor_ids[0];
}

const ::std::string&
CTA::RTAMonitor::ice_staticId()
{
    return __CTA__RTAMonitor_ids[0];
}

::Ice::DispatchStatus
CTA::RTAMonitor::___sendParameter(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::CTA::Parameter param;
    __is->read(param);
    __inS.endReadParams();
    sendParameter(param, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
CTA::RTAMonitor::___sendLog(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::CTA::LogMessage msg;
    __is->read(msg);
    __inS.endReadParams();
    sendLog(msg, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
CTA::RTAMonitor::___registerApp(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::Ice::Int apid;
    __is->read(apid);
    __inS.endReadParams();
    registerApp(apid, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

namespace
{
const ::std::string __CTA__RTAMonitor_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "registerApp",
    "sendLog",
    "sendParameter"
};

}

::Ice::DispatchStatus
CTA::RTAMonitor::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< const ::std::string*, const ::std::string*> r = ::std::equal_range(__CTA__RTAMonitor_all, __CTA__RTAMonitor_all + 7, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __CTA__RTAMonitor_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___registerApp(in, current);
        }
        case 5:
        {
            return ___sendLog(in, current);
        }
        case 6:
        {
            return ___sendParameter(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
CTA::RTAMonitor::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->endWriteSlice();
}

void
CTA::RTAMonitor::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->endReadSlice();
}

void 
CTA::__patch(RTAMonitorPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::CTA::RTAMonitorPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::CTA::RTAMonitor::ice_staticId(), v);
    }
}
