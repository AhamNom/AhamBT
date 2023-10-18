import std;

export module bt;

export class Node {
public:
    Node(const std::string& name);
	Node(const std::string &name, const Node *parent, const std::vector<Node *> &children);
	~Node() = default;

    std::string get_name() const;
    Node* get_root() const;
    void set_root(Node* new_root);
    Node* get_parent() const;
    void set_parent(Node* new_parent);
    std::vector<Node*> get_children() const;
    void add_child(Node* child);
    void remove_child(Node* child);

private:
    std::string name;
    Node* root;
    Node* parent;
    std::vector<Node*> children;
};
