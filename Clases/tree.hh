#ifndef TREE_HH
#define TREE_HH

#include <cstddef>
#include <list>

using namespace std;

template <class T>

class tree {

private:

	struct node {
		T root;
		list<node*> nodes;
	};

	typedef typename std::__cxx11::list<tree<T>::node*>::iterator list_node_pointer_iterator;
	typedef typename std::__cxx11::list<tree<T> >::iterator list_tree_iterator;
	typedef typename std::__cxx11::list<tree<T> >::const_iterator list_tree_const_iterator;

	node* n;

	static node* cp_node(node* tn)
	/* Coste: lineal respecto al número de nodos enlazados a 'tn' */
	/* Pre: cierto */
	/* Post: devuelve NULL si 'tn' es NULL;
			 en otro caso, devuelve un puntero al nodo raíz de una
			 jerarquía de nodos copia de la jerarquía de nodos del nodo
			 apuntado por 'tn' */
	{
		node* aux;
		if(tn == NULL) {
			aux = NULL;
		}
		else {
			aux = new node;
			aux->root = tn->root;
			list_node_pointer_iterator it = tn->nodes.begin();
			while(it != tn->nodes.end()) {
				aux->nodes.insert(aux->nodes.end(), cp_node(*it));
				++it;
			}
		}
		return aux;
	}

	static void rm_node(node* tn)
	/* Coste: lineal respecto al número de nodos enlazados a 'tn' */
	/* Pre: cierto */
	/* Post: no hace nada si 'tn' es NULL;
			 en otro caso, libera el espacio de todos los nodos de la
			 jerarquía de nodos que tiene el nodo apuntado por 'tn' como
			 raíz */
	{
		if(tn != NULL) {
			list_node_pointer_iterator it = tn->nodes.begin();
			while(it != tn->nodes.end()) {
				rm_node(*it);
				++it;
			}
			delete tn;
		}
	}

public:

	tree()
	/* Coste: constante */
	/* Pre: cierto */
	/* Post: crea un árbol vacío */
	{
		n = NULL;
	}

	tree(const tree& t)
	/* Coste: lineal respecto al número de nodos enlazados a 'tn' */
	/* Pre: cierto */
	/* Post: crea un árbol copia de 't' */
	{
		if(this != &t) {
			n = cp_node(t.n);
		}
	}

	~tree()
	/* Coste: lineal respecto al número de nodos enlazados al parámetro
			  implícito */
	/* Pre: cierto */
	/* Post: libera los recursos locales del parámetro implícito al salir
			 de un ámbito de visibilidad */
	{
		rm_node(n);
	}

	tree& operator=(const tree& t)
	/* Coste: lineal respecto al número de nodos enlazados al parámetro
			  implícito y a 't' */
	/* Pre: cierto */
	/* Post: elimina todos los nodos de la jerarquía de nodos del
			 parámetro implícito y asigna una copia de la jerarquía de
			 nodos de 't' al parámetro implícito */
	{
		if(this != &t) {
			rm_node(n);
			n = cp_node(t.n);
		}
		return *this;
	}

	void clear()
	/* Coste: lineal respecto al número de nodos enlazados al parámetro
			  implícito */
	/* Pre: cierto */
	/* Post: el parámetro implícito está vacío */
	{
		rm_node(n);
		n = NULL;
	}

	void swap(tree& t)
	/* Coste: constante */
	/* Pre: 't' = T, parámetro implícito = P */
	/* Post: el parámetro implícito es T;
			 't' es P */
	{
		node* aux = t.n;
		t.n = n;
		n = aux;
	}

	void seed(const T& rt, list<tree>& tl)
	/* Coste: lineal respecto al tamaño de 'tl' */
	/* Pre: el parámetro implícito está vacío y es diferente de cualquier
			elemento de 'tl';
			los elementos de 'tl' son diferentes entre sí */
	/* Post: el parámetro implícito tiene 'rt' como raíz y los elementos
			 de 'tl' como ramas;
			 los elementos de 'tl' están vacíos */
	{
		if(n == NULL) {
			node* aux = new node;
			aux->root = rt;
			list_tree_iterator it = tl.begin();
			while(it != tl.end()) {
				if(this == &(*it)) {
					ErrHandl("ERROR: the implicit parameter must be different from any element on the list");
				}
				aux->nodes.insert(aux->nodes.end(),it->n);
				it->n = NULL;
				++it;
			}
			n = aux;
		}
		else {
			ErrHandl("ERROR: the implicit parameter must be empty");
		}
	}

	void branches(list<tree>& tl)
	/* Coste: lineal respecto al número de ramas del parámetro implícito */
	/* Pre: parámetro implícito = P;
			el parámetro implícito no está vacío;
			'tl' está vacía */
	/* Post: los elementos de 'tl' son las ramas enlazadas a P;
			 el parámetro implícito está vacío */
	{
		if(n != NULL and tl.empty()) {
			list_node_pointer_iterator it = this->n->nodes.begin();
			tree aux;
			while(it != this->n->nodes.end()) {
				aux.n = *it;
				tl.insert(tl.end(),aux);
				++it;
			}
		}
		else if(n == NULL) {
			ErrHandl("ERROR: empty trees have no branches");
		}
		else {
			ErrHandl("ERROR: the branches list must be empty");
		}
	}

	T root() const
	/* Coste: constante */
	/* Pre: el parámetro implícito no está vacío */
	/* Post: devuelve la raíz del parámetro implícito */
	{
		if(n != NULL) {
			return n->root;
		}
		else {
			ErrHandl("ERROR: empty trees have no root");
		}
	}

	bool empty() const
	/* Coste: constante */
	/* Pre: cierto */
	/* Post: devuelve cierto si el parámetro implícito está vacío;
			 en otro caso, devuelve falso */
	{
		return (n == NULL);
	}

};

#endif
