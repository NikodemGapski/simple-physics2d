#pragma once
#include <unordered_set>

// forward declaration
class GameObject;

class HierarchyTree {
public:
	HierarchyTree();
	HierarchyTree(GameObject* obj, HierarchyTree* parent);
	~HierarchyTree();
	// the gameobject this node represents (NULL if this is the root node)
	GameObject* obj;
	// the parent in the tree (NULL if this is the root node)
	HierarchyTree* parent;
	
private:
	struct Hash {
		size_t operator()(const HierarchyTree* node) const;
	};
public:
	// the children in the tree
	std::unordered_set<HierarchyTree*, Hash> children;

	// check if the node is the root
	bool is_root() const;
	// change the node's parent
	void change_parent(HierarchyTree* new_parent);
	// insert the node as the child
	void insert_child(HierarchyTree* node);
	// remove the node as the child
	void remove_child(HierarchyTree* node);
	// make a copy of the tree structure
	HierarchyTree* copy() const;
	// destroy, deallocate the tree structure and detach as child
	void destroy();
};