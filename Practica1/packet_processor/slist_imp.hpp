#pragma once

#include "slist.hpp"
#include <sstream>
#include <stdexcept>
#include <cassert>

template <class T>
SNode<T>::SNode (T const& it)
{
    //TODO
    _item = it;
    _next = nullptr;
    //
    assert(!has_next());
}

template <class T>
SNode<T>::SNode (T const& it, SNode<T>::Ref& next)
{
    //TODO
    _item = it;
    _next = next;
    //
}

template <class T>
SNode<T>::~SNode()
{
    //TODO
    //hint: if std::shared_ptr is used for the references, nothing todo.

    //
}

template <class T>
typename SNode<T>::Ref SNode<T>::create(T const& it, SNode<T>::Ref next)
{
    return std::make_shared<SNode<T>> (it, next);
}

template <class T>
T SNode<T>::item() const
{
    T it;
    //TODO
    it = _item;
    //
    return it;
}

template <class T>
bool SNode<T>::has_next() const
{
    bool has = false;
    //TODO
    if(_next != nullptr){
        has = true;
    }
    //
    return has;
}

template <class T>
typename SNode<T>::Ref SNode<T>::next() const
{
    SNode<T>::Ref n;
    //TODO
    n = _next;
    //
    return n;
}

template <class T>
void SNode<T>::set_item(const T& new_it)
{
    //TODO
    _item = new_it;
    _next = nullptr;
    //
    assert(item()==new_it);
}

template <class T>
void SNode<T>::set_next(SNode<T>::Ref n)
{
    //TODO
    _next = n;
    //
    assert(n == next());
}

template<class T>
SList<T>::SList ()
{
    //TODO

    _head = nullptr;
    _curr = nullptr;
    _prev = nullptr;
    _size = 0;
    //
    assert(is_empty());
}

template<class T>
SList<T>::~SList()
{
    //TODO



    //

}

template<class T>
typename SNode<T>::Ref SList<T>::head() const
{
    typename SNode<T>::Ref h;
    //TODO
    h = _head;
    //
    return h;
}

template<class T>
typename SList<T>::Ref SList<T>::create()
{
    return std::make_shared<SList<T>> ();
}

template<class T>
typename SList<T>::Ref SList<T>::create(std::istream& in) noexcept(false)
{
    auto list = SList<T>::create();
    std::string token;
    in >> token;

    //TODO
    //Hint: use std::istriongstream to convert from "string" to template
    // parameter T type.
    // Throw std::runtime_error("Wrong input format.") exception if a input
    // format error was found.

    auto list_aux = SList<T>::create();

    if (token == "[]"){
        return list;
    }
    if (token != "["){
        throw std::runtime_error("Wrong input format.");
    }

    T new_item;
    while (in >> token && token != "]"){

        std::istringstream string(token);
        string >> new_item;
        list_aux->push_front(new_item);
        if(string.fail()){
            throw std::runtime_error("Wrong input format.");
        }
    }

    while (!list_aux->is_empty()){
        list->push_front(list_aux->front());
        list_aux->pop_front();
    }

    if (token != "]"){
        throw std::runtime_error("Wrong input format.");
    }

//std::isstringstream iss(token);
//iss >> value;

    //
    return list;
}

template<class T>
bool SList<T>::is_empty () const
{
    bool ret_val = true;
    //TODO
    if (_head != nullptr){
        ret_val=false;
        }
    //
    return ret_val;
}

template<class T>
size_t SList<T>::size () const
{
    size_t ret_val = 0;
    //TODO
    ret_val = _size;
    //
    return ret_val;
}

template<class T>
T SList<T>::front() const
{
    assert(!is_empty());
    T f;
    //TODO
    f = _head->item();
    //
    return f;
}

template<class T>
T SList<T>::current() const
{
    assert(! is_empty());
    T c;
    //TODO
    c = _curr->item();
    //
    return c;
}

template<class T>
bool SList<T>::has_next() const
{
    assert(!is_empty());
    bool ret_val = false;
    //TODO
    if(_curr->next()!=nullptr){
        ret_val=true;
    }
    //
    return ret_val;
}

template<class T>
T SList<T>::next() const
{
    assert(has_next());
    T ret_val = false;
    //TODO
    if(_curr->next()!=nullptr){
        ret_val=_curr->next()->item();
    }
    //
    return ret_val;
}


template<class T>
bool SList<T>::has(T const& it) const
{
    bool found = false;
    //TODO
    //Hint: you can reuse SList::find() but remebering restore cursors to
    //assure not modify the state of the list.
    //Hint: use const_cast<> to remove constness of this.
    typename SNode<T>::Ref aux=_head;
    while (aux!=nullptr) {
        if (aux->item()==it) {
        found=true;
        }
    aux=aux->next();
    }
    //
    return found;
}

template<class T>
void SList<T>::fold(std::ostream& out) const
{
    //TODO
    typename SNode<T>:: Ref aux=_head;
    if (is_empty()) {
        out<<"[]";
    }
    else{
        out<<"[ ";
        while (aux!=nullptr) {
            out<<aux->item()<<" ";
            aux=aux->next();
        }
        out<<"]";
    }
    //
}

template<class T>
void SList<T>::set_current(T const& new_v)
{
    assert(!is_empty());
    //TODO
    _curr->item()=new_v;
    //
    assert(current()==new_v);
}


template<class T>
void SList<T>::push_front(T const& new_it)
{
#ifndef NDEBUG
    size_t old_size = size();
#endif
    //TODO
    //Remeber to update current if current is in the head.
    if(is_empty()){
        _head=SNode<T>::create(new_it,_head);
        _curr=_head;
    }
    else{
        auto head=SNode<T>::create(new_it,_head);
        _head=head;
        _curr=_head;
    }
    _size++;
    //
    assert(front()==new_it);
    assert(size() == (old_size+1));
}

template<class T>
void SList<T>::insert(T const& new_it)
{
#ifndef NDEBUG
    bool old_is_empty = is_empty();
    size_t old_size = size();
    T old_item;
    if (!old_is_empty)
        old_item = current();
#endif
    //TODO
    if(is_empty()){
        push_front(new_it);
    }
    else{
        auto nodo=SNode<T>::create(new_it,_curr->next());
        _curr->set_next(nodo);
        _size++;
    }
    //
    assert(!old_is_empty || (front()==new_it && current()==new_it));
    assert(old_is_empty || (old_item == current() && has_next() && next()==new_it));
    assert(size()==(old_size+1));
}

template<class T>
void SList<T>::pop_front()
{
    assert(!is_empty());
#ifndef NDEBUG
    size_t old_size = size();
    auto old_head_next = head()->next();
#endif
    //TODO
    if(_head->has_next()){
        _head=_head->next();
        _curr=_head;
    }
    else{
        _head=nullptr;
        _curr=_head;
    }
    _size--;
    //
    assert(is_empty() || head() == old_head_next);
    assert(size() == (old_size-1));
}


template<class T>
void SList<T>::remove()
{
    assert(!is_empty());
#ifndef NDEBUG
    size_t old_size = size();
    bool old_has_next = has_next();
    T old_next;
    if (has_next())
        old_next=next();
#endif
    //TODO
    //Case 1: current is the head.
    if(_curr==_head){
        pop_front();
        _prev=nullptr;
        _curr=_head;
    }

    //Case 2: remove in a middle position.
    else{
        if(_curr->has_next()){
            _prev->set_next(this->_curr->next());
            _curr=_curr->next();
            }

    //Case 3: remove the last element.
    //Remenber to locate previous of prev_.
        else{
            find(this->_prev->item());
            this->_curr->set_next(nullptr);
        }
        _size--;
    }
    //
    assert(!old_has_next || current()==old_next);
    assert(size() == (old_size-1));
}

template<class T>
void SList<T>::goto_next()
{
    assert(has_next());
#ifndef NDEBUG
    auto old_next = next();
#endif
    //TODO
    _prev=_curr;
    _curr=_curr->next();
    //
    assert(current()==old_next);
}

template<class T>
void SList<T>::goto_first()
{
    assert(!is_empty());
    //TODO
    _curr = _head;
    _prev = nullptr;
    //
    assert(current()==front());
}

template<class T>
bool SList<T>::find(T const& it)
{
    assert(!is_empty());
    bool found = false;
    //TODO
    _curr=_head;
    while ((this->_curr->has_next()) && !found) {
        if (_curr->item()==it) {
        found=true;
        }
        else{
            _prev = _curr;
            _curr = _curr->next();
        }
    }
    if (_curr->item()==it) {
        found=true;
        }
    //
    assert(!found || current()==it);
    assert(found || !has_next());
    return found;
}

template<class T>
bool SList<T>::find_next(T const& it)
{
    assert(has_next());
    bool found = false;
    //TODO
        while (this->_curr->has_next() && !found){
            this->_prev = this->_curr;
            this->_curr = this->_curr->next();
            if (this->_curr->item() == it){
                found = true;
            }
        }
    //
    assert(!found || current()==it);
    assert(found || !has_next());
    return found;
}

