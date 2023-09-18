class Node {
 public:
  Node(const std::string& name, const std::string& parent, const std::vector<std::string>& children);
  ~Node();

  void addChildren(const std::vector<std::string>& children);
  void removeChildren(const std::vector<std::string>& children);
  void update(const std::string& date, const std::string& data);
  void print();

 private:
  std::string name_;
  std::string parent_;
  std::vector<std::string> children_;
};

Node::Node(const std::string& name, const std::string& parent, const std::vector<std::string>& children) {
  name_ = name;
  parent_ = parent;
  children_ = children;
}

void Node::addChildren(const std::vector<std::string>& children) {
  for (auto& child : children) {
    children_.push_back(child);
  }
}

void Node::removeChildren(const std::vector<std::string>& children) {
  for (auto& child : children) {
    auto it = std::find(children_.begin(), children_.end(), child);
    if (it != children_.end()) {
      children_.erase(it);
    }
  }
}

// void Node::update(const std::string& date, const std::string& data) { }
// Node::~Node() { }
