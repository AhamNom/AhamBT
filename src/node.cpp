export module bt;

export {

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

}
