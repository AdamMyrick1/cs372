//This is my deletable tree. In my approach to making this work, you will see that the tree is no longer 
//immutable. Disclaimer, the size method is off. I meant to come back and fix it, but I had intended to do so
//after completing the other problems and simply forgot to and I ran out of time...
//Also note that this "deletable" tree is simply the refactored tree made to use smart pointers, 
//just expanded upon, so it should cover both Problem 1 and Problem 3

#pragma once

#include <memory>
#include <functional>
#include <cassert>
using namespace std;

template<class T>
class Tree
{
    struct Node
    {
        Node(std::shared_ptr<Node> const & lft
             , T val
             , std::shared_ptr<Node> const & rgt)
        : _lft(lft), _val(val), _rgt(rgt)
        {}

        std::shared_ptr<Node> _lft;
        T _val;
        std::shared_ptr<Node> _rgt;
    };

    explicit Tree(std::shared_ptr<Node> const & node)
      : _root(node) {}

  unsigned int numberOfNodes = 0;

public:
    Tree() {}

    Tree(Tree const & lft, T val, Tree const & rgt)
    : _root(std::make_shared<Node>(lft._root, val, rgt._root))
    {
        assert(lft.isEmpty() || lft.root() < val);
        assert(rgt.isEmpty() || val < rgt.root());
        numberOfNodes = lft.size() + rgt.size() + 1;
    }

    Tree(std::initializer_list<T> init) {
        Tree t;
        for (T v: init) {
            t = t.insert(v);
        }
        _root = t._root;
        numberOfNodes = t.size();
    }

    bool isEmpty() const { return !_root; }

    size_t size() const { return numberOfNodes; }

    T root() const {
        assert(!isEmpty());
        return _root->_val;
    }

    Tree left() const {
        assert(!isEmpty());
        return Tree(_root->_lft);
    }

    Tree right() const {
        assert(!isEmpty());
        return Tree(_root->_rgt);
    }

    Tree insert(T x) {
        if (isEmpty())
            return Tree(Tree(), x, Tree());
        T y = root();
        if (x < y)
            return Tree(left().insert(x), y, right());
        else if (y < x)
            return Tree(left(), y, right().insert(x));
        else
            return *this;
    }

    bool member(T x) const {
        if (isEmpty())
            return false;
        T y = root();
        if (x < y)
            return left().member(x);
        else if (y < x)
            return right().member(x);
        else
            return true;
    }

    bool find(T x, T &foundValue) const {
        if (isEmpty())
            return false;
        T y = root();
        if (x < y)
            return left().find(x, foundValue);
        else if (y < x)
            return right().find(x, foundValue);
        else {
          foundValue = y;
          return true;
        }
    }

    void preorder(std::function<void(T)> visit) const {
        if (isEmpty())
            return;
        T contents = root();
        visit(contents);
        left().preorder(visit);
        right().preorder(visit);
    }

    void inorder(std::function<void(T)> visit) const {
        if (isEmpty()) return;
        left().inorder(visit);
        T contents = root();
        visit(contents);
        right().inorder(visit);
    }

    void postorder(std::function<void(T)> visit) const {
        if (isEmpty()) return;
        left().postorder(visit);
        right().postorder(visit);
        T contents = root();
        visit(contents);
    }
    
    bool remove(T x) {
        bool found;
        _root = remove(_root, x, found);
        return found;
    }

private:
    std::shared_ptr<Node> _root;

    std::shared_ptr<Node> maxValueNode(std::shared_ptr<Node> node) const {
        std::shared_ptr<Node> current = node;
        while (current->_rgt)
            current = current->_rgt;
        return current;
    }

    std::shared_ptr<Node> remove(std::shared_ptr<Node> node, T x, bool &found) {
        found = false;
        if (!node)
            return node;
        if (x < node->_val)
            node->_lft = remove(node->_lft, x, found);
        else if (x > node->_val)
            node->_rgt = remove(node->_rgt, x, found);
        else {
            found = true;
            numberOfNodes--;
            if (!node->_lft)
                return node->_rgt;
            else if (!node->_rgt)
                return node->_lft;
            std::shared_ptr<Node> temp = maxValueNode(node->_lft);
            node->_val = temp->_val;
            node->_lft = remove(node->_lft, temp->_val, found);
        }
        return node;
    }
};
