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
    this->item_=it;
    this->parent_=parent;
    this->left_=left;
    this->right_=right;
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
    height=this->height_;
    //
    return height;
}

template <class T>
int AVLTNode<T>::balance_factor() const
{
    int bf = 0;
    //TODO
    int lheight=0;
    int rheight=0;
    if(this->left()!=nullptr){
        left_->compute_height();
        lheight=left_->height()+1;
    }
    if(this->right()!=nullptr){
        right_->compute_height();
        rheight=right_->height()+1;
    }
    bf=rheight-lheight;
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
    int lheight=-1, rheight=-1;
    if(this->left()!=nullptr){
        lheight=this->left_->height();
    }
    if(this->right()!=nullptr){
        rheight=this->right_->height();
    }
    if(this->height()==1 + std::max(lheight, rheight)){
        ret_val=true;
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
	this->parent_=new_parent;
    this->compute_height();
    //
    assert(parent()==new_parent);
}


template <class T>
void AVLTNode<T>::set_left(AVLTNode<T>::Ref new_child)
{
    //TODO
    //Remember to update the height property.
	this->left_=new_child;
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
	this->right_=new_child;
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
	if(right()==nullptr && left()==nullptr){
        height_=0;
        if(parent()!=nullptr){
            parent_->compute_height();
        }
    }
    else{
        int lheight=0, rheight=0;
        if(this->left()!=nullptr){
            lheight=this->left_->height()+1;
        }
        if(this->right()!=nullptr){
            rheight=this->right_->height()+1;
        }
        if(this->parent()!=nullptr){
            this->parent_->compute_height();
        }
        if(lheight>rheight){
            height_=lheight;
        }
        else{
            height_=rheight;
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
       root_=nullptr;
       parent_=nullptr;
       current_=nullptr;
    //
    assert(is_a_binary_search_tree());
    assert(is_a_balanced_tree());
    assert(is_empty());
}

template <class T>
AVLTree<T>::AVLTree (T const& item)
{
    //TODO
      this->root_=typename AVLTNode<T>::Ref(new AVLTNode<T>(item,nullptr,nullptr,nullptr));
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
    in >> token;
    if(!in){
        throw std::runtime_error("Wrong input format.");
    }
    if(token=="["){
        T new_item;
        in >> token;
        std::istringstream aux(token);
        aux>>new_item;
        if(aux.fail()){
          throw std::runtime_error("Wrong input format.");
        }
        tree->create_root(new_item);
        tree->set_left(create(in));
        tree->set_right(create(in));
        in >> token;
        if(token != "]"){
            throw std::runtime_error("Wrong input format.");
        }
    }
    else if(token != "[]"){
        throw std::runtime_error("Wrong input format.");
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
    if((end-begin) > 0){
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
      if(root_==nullptr){
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
        value=root_->item();
    //
    return value;
}

template <class T>
std::ostream& AVLTree<T>::fold(std::ostream& out) const
{
    //TODO
    if(this->root_ == nullptr){
        out << "[]";
    }
    else{
       out << "[ ";
       out << this->root_->item();
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
        if(current_!=nullptr){
            exists=true;
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
    auto node_aux = this->root_; //Creamos un nodo que tendra el valor de root_ y nos servira de ayuda
        while (this->current_ != node_aux)
        {
            if (node_aux->item() > this->current_->item()){ //Entramos si el item del nodo es mayor que el item de current
                node_aux = node_aux->left();
             }
            else if (this->current_->item() > node_aux->item()){//Entramos si el item del nodo es menor que el item de current
                node_aux = node_aux->right();
              }
            level++;
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
    subtree=AVLTree<T>::create();
    subtree->root_=root_->left();
    //
    return subtree;
}

template <class T>
typename AVLTree<T>::Ref AVLTree<T>::right() const
{

    assert(!is_empty());
    typename AVLTree<T>::Ref subtree;
    //TODO
    subtree=AVLTree<T>::create();
    subtree->root_=root_->right();
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
    if(!this->is_empty()){
      h=this->root_->height();
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

  auto aux = current_;
  if(!const_cast<AVLTree<T>*>(this)->search(k)){
    found=false;
  }
  const_cast<AVLTree<T>*>(this)->current_=aux;
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
    if(node!=nullptr){
      retVal= retVal && infix_process<T, Processor>(node->left(),p);
      retVal= retVal && p(node);
      retVal= retVal && infix_process<T, Processor>(node->right(),p);
    }
    if(node==nullptr){
      retVal=true;
    }
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
     bool first=true;
     T prenum;
     auto p= [&first,&prenum](typename AVLTNode<T>::Ref node)mutable ->bool{
       if(first){
         prenum=node->item();
         first=false;
         return true;
       }
       if(prenum < node->item()){
         prenum=node->item();
         return true;
       }
       return false;
     };
     is_bst=infix_process<T>(root_,p);
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
        root_=AVLTNode<T>::create(v);
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
                if (this->current_->item() < k){ //Si el tenemos es menor que el que buscamos, tenemos que ir a la derecha
                    this->current_ = this->current_->right();
                }
                else{ //Si el que tenemos es mayor que el que buscamos, tenemos que ir a la izquierda
                    this->current_ = this->current_->left();
                }
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
        if(this->is_empty()){
            this->current_=AVLTNode<T>::create(k,nullptr,nullptr,nullptr);
            this->root_=this->current_;
        }
        else{
            this->current_=AVLTNode<T>::create(k,this->parent_,nullptr,nullptr);
            if(this->parent_->item()<k){
                this->parent_->set_right(this->current_);
            }
            else{
                this->parent_->set_left(this->current_);
            }
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
    if (!current_->left() && !current_->right()){
            subtree = nullptr;
        }
        else if (!current_->right())
            subtree = current_ -> left();
        else if (!current_->left())
            subtree = current_ -> right();
        else
            replace_with_subtree = false;

        //

        if (replace_with_subtree)
        {
            //TODO
            //Manage cases 0,1,2
            if(parent_ == nullptr){
                root_ = subtree;
            }
            else if (parent_ -> right() == current_){
                parent_ -> set_right(subtree);
            }
            else{
                parent_ -> set_left(subtree);
            }

            current_ = nullptr;
            //
            make_balanced();
        }
    else
    {
        //TODO
        //Manage case 3.
        auto aux=this->current_;
        parent_ = current_;
            current_ = current_->right(); //El sucesor es el siguiente mayor, por lo que primero deberemos ir a la derecha

            while (current_->left()!=nullptr) //Despues de ir a la derecha, iremos todo lo que podamos a la izquierda
            {
                parent_ = current_;
                current_ = current_->left();
            }
        aux->set_item(this->current_->item());
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

    if(subtree->is_empty())
    {
       root_->set_left(nullptr);
    }
    else{
        root_->set_left(subtree->root_);
        subtree->root_->set_parent(root_);
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
    if(subtree->is_empty())
    {
       root_->set_right(nullptr);
    }
    else{
        //Remenber to set parent's link of the subtree root to this.
        root_->set_right(subtree->root_);
        //va del root arbol principal al root del subarbol
        subtree->root_->set_parent(root_);
        //va del root subarbol al root del arbol principal
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
    parent_ = current_;
        current_ = current_->right(); //El sucesor es el siguiente mayor, por lo que primero deberemos ir a la derecha

        while (current_->left()!=nullptr) //Despues de ir a la derecha, iremos todo lo que podamos a la izquierda
        {
            parent_ = current_;
            current_ = current_->left();
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
    auto lC = node->left();

    if(node->parent()==nullptr)
    {
        root_ = lC;
    }
    else if(node->parent()->right() == node)
    {
        node->parent()->set_right(lC);
    }
    else
    {
        node->parent()->set_left(lC);
    }

    lC->set_parent(node->parent());

    if( lC->right()!=nullptr)
    {
        node->set_left(lC->right());
        lC->right()->set_parent(node);
    }
    else
    {
        node->set_left(nullptr);
    }

    lC->set_right(node);
    node->set_parent(lC);

    node->compute_height();
    lC->compute_height();
}

template <class T>
void AVLTree<T>::rotate_right(typename AVLTNode<T>::Ref node)
{
    assert(node->right()!=nullptr);
    //TODO
    //Remenber: when set a node A as child of a node B, also is needed set
    // node B as parent of node A.
    //Remenber: update the node height at the end.
    auto rC = node->right();

    if(node->parent()==nullptr )
    {
        root_ = rC;
    }
    else if(node->parent()->right() == node)
    {
        node->parent()->set_right(rC);
    }
    else
    {
        node->parent()->set_left(rC);
    }

    rC->set_parent(node->parent());

    if(rC->left()!=nullptr)
    {
        node->set_right(rC->left());
        rC->left()->set_parent(node);
    }
    else
    {
        node->set_right(nullptr);
    }

    rC->set_left(node);
    node->set_parent(rC);

    node->compute_height();
    rC->compute_height();
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
while (parent_!=nullptr)
    {
        parent_->compute_height();
        int bfP = parent_->balance_factor();

        if (bfP < -1)
        {
            auto child = parent_->left();
            int bfC = child->balance_factor();

            if (bfC <= 0)
            {
                rotate_left(parent_);
            }
            else
            {
                rotate_right(child);
                rotate_left(parent_);
            }
        }
        else if (bfP > 1)
        {
            auto child = parent_->right();
            int bfC = child->balance_factor();

            if (bfC >= 0)
            {
                rotate_right(parent_);
            }
            else
            {
                rotate_left(child);
                rotate_right(parent_);
            }
        }
        else
        {
            parent_ = parent_->parent();
        }
    }

    if(current_exists())
    {
        parent_ = current_->parent();
    }

    //

    assert(!current_exists() || current_node()->parent()==parent_node());
#endif //__ONLY_BSTREE__
}
