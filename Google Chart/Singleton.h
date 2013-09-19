#ifndef _SINGLETON_H_
#define _SINGLETON_H_

template <class TClass>
class Singleton
{
public:
    static TClass& Ref()
    {
        if (m_instancePtr == 0)
        {
            static TClass instance;
            m_instancePtr = &instance;
        }

        return *m_instancePtr;
    }

protected:
    Singleton(){};
    virtual ~Singleton(){};

    static TClass* m_instancePtr;
};

template <class TClass> TClass* Singleton<TClass>::m_instancePtr = 0;

#endif // _SINGLETON_H_

/*
#include "singleton.h"
class MyClass :
    public Singleton<MyClass>
{
private:
    friend class Singleton<MyClass>;
    #define g_MyClass MyClass::Ref()
    MyClass();
    ~MyClass();   
}
*/