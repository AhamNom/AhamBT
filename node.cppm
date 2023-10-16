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

Node::Node(const std::string& name) : name(name), root(this), parent(nullptr) {}

Node::Node(const std::string &name, const Node *parent, const std::vector<Node *> &children) :
	name(name), parent(const_cast<Node *>(parent)), children(children) {}

std::string Node::get_name() const { return name; }

Node* Node::get_root() const { return root; }

void Node::set_root(Node* new_root) { root = new_root; }

Node* Node::get_parent() const { return parent; }

void Node::set_parent(Node* new_parent) { parent = new_parent; }

std::vector<Node*> Node::get_children() const { return children; }

void Node::add_child(Node* child) {
    children.push_back(child);
    child->set_parent(this);
    child->set_root(this->root);
}

void Node::remove_child(Node* child) {
    children.erase(std::remove(children.begin(), children.end(), child), children.end());
    child->set_parent(nullptr);
    child->set_root(child);
}

// void Node::update(const std::string& date, const std::string& data) { }
// Node::~Node() { }
