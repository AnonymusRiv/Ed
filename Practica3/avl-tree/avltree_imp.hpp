/**
 * @file avltree_imp.hpp
 *
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#pragma once
#include <cassert>

#include "avltree.hpp"

/****
 * AVLTNode class implementation.
 ****/


template <class T>
AVLTNode<T>::AVLTNode (T const& it, AVLTNode<T>::Ref parent,
                       AVLTNode<T>::Ref left, AVLTNode<T>::Ref right)
{
    //TODO
    this->compute_height();
    //
    assert(check_height_invariant());
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::create(T const& it,
                                              AVLTNode<T>::Ref parent,
                                              AVLTNode<T>::Ref left,
                                              AVLTNode<T>::Ref right)
{
    return std::make_shared< AVLTNode<T> > (it, parent, left, right);
}

template <class T>
T AVLTNode<T>::item() const
{
    T value;
    //TODO
    value=this->item_;
    //
    return value;
}

template <class T>
int AVLTNode<T>::height() const
{
    int height=0;
    //TODO
    height=height_;
    //
    return height;
}

template <class T>
int AVLTNode<T>::balance_factor() const
{
    int bf = 0;
    //TODO
    int lfth = 0;
    int rgth = 0;
    if (left_ != nullptr)
    {
        left_->compute_height();
        lfth = left_->height() + 1;
    }
    if (right_ != nullptr)
    {
        right_->compute_height();
        rgth = right_->height() + 1;
    }

    bf = rgth - lfth;
    //
    return bf;
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::parent() const
{
    AVLTNode<T>::Ref node;
    //TODO
    node=this->parent_;
    //
    return node;
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::left() const
{
    AVLTNode<T>::Ref node;
    //TODO
    node=this->left_;
    //
    return node;
}

template <class T>
typename AVLTNode<T>::Ref AVLTNode<T>::right() const
{
    AVLTNode<T>::Ref node;
    //TODO
    node=this->right_;
    //
    return node;
}

template <class T>
bool AVLTNode<T>::check_height_invariant () const
{
    bool ret_val = false;
    //TODO
    int left_height = -1, right_height = -1;

    if (this->left_ != nullptr){
        left_height = this->left_->height();
    }

    if (this->right_ != nullptr){
        right_height = this->right_->height();
    }

    if (this->height() == 1 + std::max(left_height, right_height)){
        ret_val = true;
    }
    //
    return ret_val;
}

template <class T>
void AVLTNode<T>::set_item(const T& new_it)
{
    //TODO
    item_=new_it;
    //
    assert(item()==new_it);
}

template <class T>
void AVLTNode<T>::set_parent(AVLTNode<T>::Ref new_parent)
{
    //TODO
    parent_=new_parent;
    this->compute_height();
    //
    assert(parent()==new_parent);
}


template <class T>
void AVLTNode<T>::set_left(AVLTNode<T>::Ref new_child)
{
    //TODO
    //Remember to update the height property.
    left_=new_child;
    this->compute_height();
    //
    assert(check_height_invariant());
    assert(left()==new_child);
}

template <class T>
void AVLTNode<T>::set_right(AVLTNode<T>::Ref new_child)
{
    //TODO
    //Remember to update the height property.
    right_=new_child;
    this->compute_height();
    //
    assert(check_height_invariant());
    assert(right()==new_child);
}

template <class T>
void AVLTNode<T>::compute_height()
{
    //TODO
    //Remember: we want O(1) here.
    if (this->right_ == nullptr && this->left_ == nullptr){
        this->height_ = 0;
        if (this->parent_ != nullptr){
            this->parent_->compute_height();
        }
    }

    else
    {
        int left_height = 0, right_height = 0;

        if (this->left_ != nullptr){
            left_height = this->left_->height() + 1;
        }

        if (this->right_!= nullptr){
            right_height = this->right_->height() + 1;
        }

        if (this->parent_ != nullptr){
            this->parent_->compute_height();
        }

        if (left_height > right_height){
            this->height_ = left_height;
        }

        else{
            this->height_ = right_height;
        }
    }
    //
    assert(check_height_invariant());
}

/***
 * AVLTree class implementation.
 ***/

template <class T>
AVLTree<T>::AVLTree ()
{
    //TODO
    this->root_ = nullptr;
    this->parent_ = nullptr;
    this->current_ = nullptr;
    //
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());
    assert(is_empty());
}

template <class T>
AVLTree<T>::AVLTree (T const& item)
{
    //TODO
    this->root_ = typename AVLTNode<T>::Ref(new AVLTNode<T>(item, nullptr, nullptr, nullptr));
    //
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());
    assert(!is_empty());
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::create ()
{
    return std::make_shared< AVLTree<T> >();
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::create (T const& item)
{
    return std::make_shared<AVLTree<T>> (item);
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::create(std::istream& in) noexcept(false)
{
    auto tree = AVLTree<T>::create();
    std::string token;
    //TODO
    if (!in){
        throw std::runtime_error("Wrong input format");
    }
    if (token == "["){
        T data;
        in >> data;
        tree = AVLTree<T>::create(data);

        auto l_subtree = AVLTree<T>::create(in);
        auto r_subtree = AVLTree<T>::create(in);
        tree->set_left(l_subtree);
        tree->set_right(r_subtree);

        in >> token;
    }
    else if (token != "[]"){
        throw std::runtime_error("Wrong input format");
    }
    //
    if (! tree->is_a_binary_search_tree())
        throw std::runtime_error("It is not a binary search tree");
    if (! tree->is_a_balanced_tree())
        throw std::runtime_error("It is not an avl bstree");
    return tree;
}

#ifdef __ONLY_BSTREE__
/**
 * @brief Create an perfectly balanced BSTree by inserting the median of
 *        an ordered sub sequence data[begin, end).
 * @param data is the ordered sequence of values.
 * @param begin,
 * @param end specify a [begin, end) indexing interval of array data to use.
 * @pre 0 <= begin <= end <=data.size()
 * @pre begin==end || data[begin]<data[end];
 */
template<class T>
void create_inserting_median(std::vector<T> const& data,
                             size_t begin,
                             size_t end,
                             typename AVLTree<T>::Ref& tree)
{
    assert(begin<=end);
    assert(end<=data.size());
    assert(begin==end || data[begin]<=data[end-1]);

    //TODO
    //Hint: if (end==begin) none thing must be done (it is an empty sub array)
    // else, insert the median in the tree and (recursively) process
    // the two sub sequences [begin, median_idx) and [median_idx+1, end)
    if((end-begin) >=1){
        tree->insert(data[begin + ((end - begin)/2)]);
        create_inserting_median(data, begin, begin + ((end - begin) /2), tree);
        create_inserting_median(data, (begin + ((end - begin) /2)) +1, end, tree);
    }
    //
}

template<class T>
typename AVLTree<T>::Ref
create_perfectly_balanced_bstree(std::vector<T> & data)
{
    typename AVLTree<T>::Ref tree = AVLTree<T>::create();
    //TODO
    //Remember: the empty tree is perfectly balanced.
    //Remember: first, an ordered sequence (using < order) of values is needed.
    //Then you should use the above create_inserting_median function
    //on a empty tree to recursively create the perfectly balanced bstree.
    //if(data.size()>0){
      //  tree->insert(data[data.size() /2]);
        //create(data[data.size() /2], tree);
        //create(data[data.size() /2], tree);
    //}
    std::sort(data.begin(), data.end());
    create_inserting_median(data, 0, data.size(), tree);
    //
    assert(tree != nullptr);
    return tree;
}
#endif //__ONLY_BSTREE__

template <class T>
bool AVLTree<T>::is_empty () const
{
    bool empty = false;
    //TODO
    if(this->root_==nullptr){
        empty=true;
    }
    //
    return empty;
}

template <class T>
T AVLTree<T>::item() const
{
    assert(!is_empty());
    T value;
    //TODO
    value=this->root_->item();
    //
    return value;
}

template <class T>
std::ostream& AVLTree<T>::fold(std::ostream& out) const
{
    //TODO
    if (this->root_ == nullptr){
        out << "[]";
    }

    else{
        out << "[ ";
        out << this->item();
        out << " ";
        this->left()->fold(out);
        out << " ";
        this->right()->fold(out);
        out << " ]";
    }
    //
    return out;
}

template <class T>
bool AVLTree<T>::current_exists() const
{
    bool exists = false;
    //TODO
    auto node_aux = this->root_;

    for (int i = 0; i == i; i++){
        if (this->current_ == nullptr){
            exists = false;
        }
    }
        //Vamos por la derecha
        if (node_aux->item() < this->current_->item()){
            if (node_aux->right() != nullptr){
                node_aux = node_aux->right();
            }
            else{
                exists = false;
            }
        }

        //Vamos por la izquierda
        else if (node_aux->item() > this->current_->item()){
            if (node_aux->left() != nullptr){
                node_aux = node_aux->left();
            }
            else{
                exists = false;
            }
        }
        else{
            exists = true;
        }
    //
    return exists;
}

template <class T>
T AVLTree<T>::current() const
{
    assert(current_exists());
    T value;
    //TODO
    value=this->current_->item();
    //
    return value;
}

template <class T>
int AVLTree<T>::current_level() const
{
    assert(current_exists());
    int level = 0;
    //TODO
    auto node_aux = this->root_;
    while (this->current_ != node_aux){
        if(node_aux->item() > this->current_->item()){
            node_aux = node_aux->left();
        }
        else if(this->current_->item() > node_aux->item()){
            node_aux = node_aux->right();
        }
    level ++;
    }
    //
    return level;
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::left() const
{
    assert(!is_empty());
    typename AVLTree<T>::Ref subtree;
    //TODO
    AVLTree<T>::Ref subleft = AVLTree<T>::create();

    if (this->root_->left() != nullptr)
    {
        subleft->create_root(root_->left()->item());
        subleft->root_->set_parent(nullptr);
        subleft->root_->set_left(root_->left()->left());
        subleft->root_->set_right(root_->left()->right());
    }
    //
    return subtree;
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::right() const
{
    assert(!is_empty());
    typename AVLTree<T>::Ref subtree;
    //TODO
    AVLTree<T>::Ref subright = AVLTree<T>::create();

    if (this->root_->right() != nullptr)
    {
        subright->create_root(root_->right()->item());
        subright->root_->set_parent(nullptr);
        subright->root_->set_left(root_->right()->left());
        subright->root_->set_right(root_->right()->right());
    }
    //
    return subtree;
}

template <class T>
int AVLTree<T>::size() const
{
    int s = 0;
    //TODO
    if (!this->is_empty()){
        s = right()->size() + left()->size() + 1;
    }
    //
    return s;
}

template <class T>
int AVLTree<T>::height() const
{
    int h = 0;
    //TODO
    //Remenber: we want O(1) here.
    if (!this->is_empty()){
        h = this->root_->height();
    }

    //
    return h;
}

template <class T>
int AVLTree<T>::balance_factor() const
{
#ifdef __ONLY_BSTREE__
    return 0;
#else
    int bf = 0;
    //TODO
    if(!is_empty()){
        bf = this->root_->balance_factor();
    }
    //
    return bf;
#endif
}

template <class T>
bool AVLTree<T>::has(const T& k) const
{
#ifndef NDEBUG
  bool old_current_exists = current_exists();
  T old_current;
  if (old_current_exists)
      old_current = current();
#endif

  bool found = true;

  //TODO
  //Hint: you can reuse the search method for this but in this case you will
  //      need to use "const_cast" to remove constness of "this" and
  //      save/restore the old state of current before returning.
auto node_aux = this->root_;

    for (int i = 0; i == i; i++) //Bucle infinito utilizamos los break para salir de el en caso de que hayamos terminado
    {
        if (node_aux->item() > k) //k esta por la izquierda
        {
            if (node_aux->left() != nullptr) //SI el nodo tiene izquierdo entramos
                node_aux = node_aux->left();
            else
            {
                found = false;
                break;
            }
        }
        else if (node_aux->item() < k) //k esta por la derecha
        {
            if (node_aux->right() != nullptr) //Si el nodo tiene derecho entramos
                node_aux = node_aux->right();
            else
            {
                found = false;
                break;
            }
        }
        else
            break;
    }

  //

#ifndef NDEBUG
  assert (!old_current_exists || old_current == current());
#endif
  return found;
}

/**
 * @brief infix process of a node.
 * The Processor must allow to be used as a function with a parameter  (the
 * item to be processed) and returning true if the process must continue or
 * false if not.
 * @param node is the node to be processed.
 * @param p is the Processor.
 * @return true if all the tree was in-fix processed.
 */
template <class T, class Processor>
bool
infix_process(typename AVLTNode<T>::Ref node, Processor& p)
{
    bool retVal = true;
    //TODO
    //Remember: if node is nullptr return true.

    //
    return retVal;
}

template <class T>
bool AVLTree<T>::is_a_binary_search_tree() const
{
    bool is_bst = true;
    //TODO
    //Remenber: a empty tree is a binary searh tree.
    //
    //Remenber: for a non empty binary search tree, the in-fix traversal from
    //the root node must follow an ordered sequence of items.
    //
    //Remember: use a lambda function with signature '(T v) -> bool' to
    // implement the Processor.
    //
if (!this->is_empty())
    {
        if (this->root_->left() != nullptr) //Entramos si tiene izquierdo
        {
            if (!(item() > left()->item()))
                is_bst = false;
        }

        if (this->root_->right() != nullptr){                      //Entramos si tiene derecho
            is_bst = is_bst && (item() < right()->item()); //Aqui tenemos que empezar a comparar con el valor anterior que tiene is_bst
        }
        //Aqui tambien tenemos que comparar el valor anterior de is_bst
        //No sera un bst si alguno de sus subarboles no lo es
        is_bst = is_bst && this->right()->is_a_binary_search_tree() && this->left()->is_a_binary_search_tree();
    }
    //
    return is_bst;
}

template <class T>
bool AVLTree<T>::is_a_balanced_tree() const
{
#ifdef __ONLY_BSTREE__
    return true;
#else
    bool is_balanced = true;
    //TODO
    //Remenber: a empty tree is balanced.
    //
    //Remenber: A non empty tree is balanced if both children are balanced
    //and the absolute value of the balance factor of the tree is less or
    //equal to one.
if (this->root_ != nullptr)
    {
        int balance_factor = std::abs(this->root_->balance_factor()); //Calculamos el balance factor en valor absoluto
        //Si no se cumple alguna de las condiciones del if, entonces el arbol no esta balanceado
        if (balance_factor > 1 || !this->right()->is_a_balanced_tree() || !this->left()->is_a_balanced_tree())
            is_balanced = false;
    }
    //
    return is_balanced;
#endif
}

template <class T>
void AVLTree<T>::create_root(T const& v)
{
    assert(is_empty());
    //TODO
    this->root_ = AVLTNode<T>::create(v, nullptr, nullptr, nullptr);
    //
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());
    assert(!is_empty());
    assert(item()==v);

}

template <class T>
bool AVLTree<T>::search(T const& k)
{
    bool found = false;
    //TODO
this->parent_ = nullptr;
    this->current_ = this->root_;
    while (this->current_ != nullptr) //Mientras current no sea nulo y no encontremos el valor entramos en el bucle
    {
        if (this->current_->item() == k) //Entramos en el bucle si encontramos el nodo
        {
            found = true;
            break;
        } //Si lo encontramos saldremos del bucle al acabar
        else
        {
            this->parent_ = this->current_; //EL padre sera nuestro actual current, ya que current pasara a ser o su hijo izq o dcho
            if (this->current_->item() < k) //Si el tenemos es menor que el que buscamos, tenemos que ir a la derecha
                this->current_ = this->current_->right();
            else //Si el que tenemos es mayor que el que buscamos, tenemos que ir a la izquierda
                this->current_ = this->current_->left();
        }
    }
    //
    assert(!found || current()==k);
    assert(found || !current_exists());
    return found;
}

template <class T>
void AVLTree<T>::insert(T const& k)
{
    //Check invariants.
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());

    if (!search(k))
    {        
        //TODO
    if (this->is_empty()) //Si no hay ruta, entramos
        {
            this->current_ = AVLTNode<T>::create(k, nullptr, nullptr, nullptr); //Creamos un nodo current que tendra de item k
            this->root_ = this->current_;                                       //Asignamos current a la raiz
        }
        else
        {
            this->current_ = AVLTNode<T>::create(k, this->parent_, nullptr, nullptr); //Creamos el nodo que tendra de item k tambien le asignamos el padre
            if (this->parent_->item() < k)
                this->parent_->set_right(this->current_);
            else
                this->parent_->set_left(this->current_);
        }
        //
        make_balanced();
    }

    //Check invariants.
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());

    //check postconditions.
    assert(current_exists());
    assert(current()==k);
}

template <class T>
void AVLTree<T>::remove ()
{
    //check preconditions.
    assert(current_exists());

#ifndef NDEBUG
    //the invariants only must be checked for the first recursive call.
    //We use a static variable to count the recursion levels.
    //see section "Static variables in a Function" in
    //ref https://www.geeksforgeeks.org/static-keyword-cpp/ for more info.
    static int recursion_count = 0;
    recursion_count++;
    if (recursion_count==1)
    {
        //Check invariants.
        assert(is_a_binary_search_tree());
        assert(is_a_balanced_tree());
    }
#endif //NDEBUG

    bool replace_with_subtree = true;
    typename AVLTNode<T>::Ref subtree;

    //TODO
    // Check which of cases 0,1,2,3 we have (see theorical class slides).
    if (this->current_->right() == nullptr && this->current_->left() == nullptr){ //Si no tenemos ni izq ni dcho, entramos
        subtree = nullptr;
    }
    else if (this->current_->left() == nullptr){ //Entramos si no tiene izq
        subtree = this->current_->right();
    }
    else if (this->current_->right() == nullptr){ //Entramos si no tiene dcho
        subtree = this->current_->left();
    }
    else{ //Entramos si tenemos izquierdo y derecho
        replace_with_subtree = false;
    }
    //

    if (replace_with_subtree)
    {   
        //TODO
        //Manage cases 0,1,2
    if (this->parent_ == nullptr) //Entramos si el padre es nulo
            this->root_ = subtree;

        else if (this->current_ == this->parent_->left()) //Entramos si el actual es igual al izq del padre
            this->parent_->set_left(subtree);

        else if (this->current_ == this->parent_->right()) //Entramos si el actual es igual al dcho del padre
            this->parent_->set_right(subtree);

        this->current_ = nullptr;
        //
        make_balanced();
    }
    else
    {
        //TODO
        //Manage case 3.
        auto x = this->current_;
        find_inorder_sucessor();
        x->set_item(this->current_->item());
        remove();
        //
    }

#ifndef NDEBUG
    //We come back so the recursion count must be decreased.
    recursion_count--;
    assert(recursion_count>=0);
    if (recursion_count==0)
    {
        //Only check for the last return.
        //Check invariants.
        assert(is_a_binary_search_tree());
        assert(is_a_balanced_tree());

        //Check postconditions.
        assert(! current_exists());
    }
#endif
}

template <class T>
AVLTree<T>::AVLTree (typename AVLTNode<T>::Ref root_node)
{
    //TODO
    this->root_ = root_node;
    //
    assert(!current_exists());
}

template <class T>
typename AVLTree<T>::Ref  AVLTree<T>::create (typename AVLTNode<T>::Ref root)
{
     AVLTree<T>::Ref ret_v (new AVLTree<T>(root));
     return ret_v;
}

template <class T>
void AVLTree<T>::set_left(Ref subtree)
{
    assert(!is_empty());
    //TODO
    //Remenber to set parent's link of the subtree root to this.
    if (subtree->is_empty()){ //Si le pasamos un arbol vacio, seteamos nullptr
        this->root_->set_left(nullptr);
    }
    else{
        this->root_->set_left(AVLTNode<T>::create(subtree->root_->item(), this->root_, subtree->root_->left(), subtree->root_->right()));
    }
    //
    assert(subtree->is_empty() || left()->item()==subtree->item());
    assert(!subtree->is_empty() || left()->is_empty());
}

template <class T>
void AVLTree<T>::set_right(Ref subtree)
{
    assert(!is_empty());
    //TODO
    //Remenber to set parent's link of the subtree root to this.
    if (subtree->is_empty()){ //Si le pasamos un arbol vacio, seteamos nullptr
        this->root_->set_right(nullptr);
    }
    else{
        this->root_->set_right(AVLTNode<T>::create(subtree->root_->item(), this->root_, subtree->root_->left(), subtree->root_->right()));
    }
    //
    assert(subtree->is_empty()|| right()->item()==subtree->item());
    assert(!subtree->is_empty()|| right()->is_empty());
}

template <class T>
typename AVLTNode<T>::Ref AVLTree<T>::current_node() const
{
    typename AVLTNode<T>::Ref node;
    //TODO
    node = this->current_;
    //
    return node;
}

template <class T>
typename AVLTNode<T>::Ref AVLTree<T>::root_node() const
{
    typename AVLTNode<T>::Ref node;
    //TODO
    node = this->root_;
    //
    return node;
}

template <class T>
typename AVLTNode<T>::Ref AVLTree<T>::parent_node() const
{
    typename AVLTNode<T>::Ref node;
    //TODO
    node = this->parent_;
    //
    return node;
}

template <class T>
void AVLTree<T>::find_inorder_sucessor()
{
    assert(current_exists());
    assert(is_a_binary_search_tree());

#ifndef NDEBUG
    T old_curr = current();
#endif
    //TODO
    this->parent_ = this->current_;
    this->current_ = this->current_->right(); //El sucesor es el siguiente mayor, por lo que primero deberemos ir a la derecha

    while (this->current_->left() != nullptr) //Despues de ir a la derecha, iremos todo lo que podamos a la izquierda
    {
        this->parent_ = this->current_;
        this->current_ = this->current_->left();
    }
    //
    assert(current_exists() && current_node()->left()==nullptr);
#ifndef NDEBUG
    assert(current()>old_curr);
#endif
}

template <class T>
void AVLTree<T>::rotate_left(typename AVLTNode<T>::Ref node)
{
    assert(node->left()!=nullptr);
    //TODO
    //Remenber: when set a node A as child of a node B, also is needed set
    // node B as parent of node A.
    //Remenber: update the node height at the end.
    auto lc = node->left(); //Creamos el nodo que tendra el valor del izquiedo

    if (node->parent() == nullptr) //Entramos si el nodo no tiene padre
        root_ = lc;

    else if (node == node->parent()->right()) //Entramos si el nodo es igual al derecho del padre de nodo
        node->parent()->set_right(lc);

    else if (node == node->parent()->left()) //Entramos si el nodo es igual al izquiedo del padre de nodo
        node->parent()->set_left(lc);

    lc->set_parent(node->parent()); //Seteamos el padre

    if (lc->right() != nullptr) //SI el nodo lc tiene derecho
    {
        node->set_left(lc->right());
        lc->right()->set_parent(node);
    }
    else{
     //   node->left_->remove();

    }

    lc->set_right(node);  //Seteamos el derecho de lc
    node->set_parent(lc); //Seteamos el padre de node

    //Calculamos la altura de estos nodos al acabar
    node->compute_height();
    lc->compute_height();
    //
}

template <class T>
void AVLTree<T>::rotate_right(typename AVLTNode<T>::Ref node)
{
    assert(node->right()!=nullptr);
    //TODO
    //Remenber: when set a node A as child of a node B, also is needed set
    // node B as parent of node A.
    //Remenber: update the node height at the end.
    auto rc = node->right(); //Creamos el nodo que tendra el valor del derecho

    if (node->parent() == nullptr) //Entramos si el nodo no tiene padre
        root_ = rc;

    else if (node == node->parent()->right()) //Entramos si el nodo es igual al derecho del padre de nodo
        node->parent()->set_right(rc);

    else if (node == node->parent()->left()) //Entramos si el nodo es igual al izquierdo del padre de nodo
        node->parent()->set_left(rc);

    rc->set_parent(node->parent()); //Seteamos el padre

    if (rc->left() != nullptr) //Si el nodo rc tiene izquierdo
    {
        node->set_right(rc->left());
        rc->left()->set_parent(node);
    }
    else{
        //node->right_->item()remove();
    }

    rc->set_left(node);   //Seteamos el izquierdo de rc
    node->set_parent(rc); //Seteamos el padre de node

    //Calculamos la altura de estos nodos al acabar
    node->compute_height();
    rc->compute_height();
    //
}

template <class T>
void AVLTree<T>::make_balanced()
{
#ifdef __ONLY_BSTREE__
    return;
#else
    //TODO
    //From current position, go up until root's node is achieved.
    //In each step, check if the current subtree is balanced and balance it
    //   if it is not.
    //Remenber: use parent_ to travel to the root and restore it properly at
    //the end.
    //
    while (this->parent_ != nullptr)
    {
        this->parent_->compute_height();          //COmputamos la altura de parent
        int bf = this->parent_->balance_factor(); //Calculamos el balance factor de parent

        if (bf <= -2) //Entramos si el balance factor es invalido (por abajo)
        {
            auto child = this->parent_->left();     //Creamos el nodo
            int bf_child = child->balance_factor(); //Calculamos el balance factor del nodo

            if (bf_child <= 0) //Si este balance factor es menor que 1, solo rotamos a la izquierda
                rotate_left(this->parent_);

            else //Aplicamos las rotaciones
            {
                rotate_right(child);
                rotate_left(this->parent_);
            }
        }
        else if (bf >= 2) //Entramos si el balance factor es invalido (por arriba)
        {
            auto child = this->parent_->right();    //Creamos el nodo
            int bf_child = child->balance_factor(); //Calculamos el balance factor del nodo

            if (bf_child >= 0) //Si este balance factor es menor que 1, solo rotamos a la derecha
                rotate_right(this->parent_);
            else //Aplicamos las rotaciones
            {
                rotate_left(child);
                rotate_right(this->parent_);
            }
        }
        else //Entramos si el balance factor es correcto
            this->parent_ = this->parent_->parent();
    }
    //
    assert(!current_exists() || current_node()->parent()==parent_node());
#endif //__ONLY_BSTREE__
}
