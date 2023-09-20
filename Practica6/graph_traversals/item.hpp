/**
 * @file item.hpp
 */
#pragma once
#include <iostream>
#include <memory>

/**
 * @brief The a data Item[G] ADT.
 */
template<class T, class Key>
struct Item
{
    typedef Key key_t;
    typedef std::shared_ptr<Item<T,Key>> Ref;

    Item():
        data_()
    {}

    Item(const T& v):
        data_(v)
    {}

    static Ref create(const T& v)
    {
        return std::shared_ptr<Item<T,Key>>( new Item<T,Key>(v) );
    }

    key_t key () const
    {
        return static_cast<key_t>(data_);
    }
    bool operator==(const key_t& k) const
    {
        return key()==k;
    }
    bool operator<(const key_t& k) const
    {
        return key()<k;
    }
    T data_;
};

template<class T, class Key>
std::ostream& operator<< (std::ostream& out, const Item<T, Key>& v)
{
    out << v.data_;
    return out;
}

template<class T, class Key>
std::istream& operator>>(std::istream& in, Item<T, Key>& v)
{
    in >> v.data_;
    return in;
}

template<class T, class Key>
bool operator== (Item<T, Key> const& a, Item<T, Key> const& b)
{
    return a.key()==b.key();
}

template<class T, class Key>
bool operator<= (Item<T, Key> const& a, Item<T, Key> const& b)
{
    return a.key()<=b.key();
}

typedef Item<char, char> Char;
typedef Item<std::string, std::string> String;
typedef Item<int, int> Int;
