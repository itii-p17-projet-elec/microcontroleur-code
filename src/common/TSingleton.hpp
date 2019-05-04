/**
 *  @file   TSingleton.hpp
 *  @brief  Class template to produce a singleton.
 *
 *  @note   Based on content of this page :
 *          https://come-david.developpez.com/tutoriels/dps/?page=Singleton
 */
#ifndef TSINGLETON_HPP
#define TSINGLETON_HPP

/* ########################################################################## */
/* ########################################################################## */

template<class T>   class   TSingleton
{
public:

    static T&   Instance()
    {
        return m_i;
    }



protected:
private:

    T&  operator= (const T&)    = delete;



public:
protected:

    static T    m_i;



private:

};

/* ########################################################################## */
/* ########################################################################## */

template <class T> T    TSingleton<T>::m_i=T();

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< TSINGLETON_HPP */
