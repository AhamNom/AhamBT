class StrategyBase : public Node {
public:
    StrategyBase(const std::string& name, const std::vector<std::string>& children, Node* parent);
    ~StrategyBase();

    float getPrice() const;
    void setPrice(float price);
    void updatePrices();
    void allocateCapital();
    void calculateValue();
    void calculateNotionalValue();
    float getCapital() const;
    void setCapital(float capital);
    void setupUniverse();
    void updateUniverse();
    void addSecurity(Node* security);
    void removeSecurity(Node* security);

private:
    float price_;
    float value_;
    float notionalValue_;
    float capital_;
};

StrategyBase::StrategyBase(const std::string& name, const std::vector<std::string>& children, Node* parent)
    : Node(name, parent, children),
      price_(0.0f),
      value_(0.0f),
      notionalValue_(0.0f),
      capital_(0.0f) {}

StrategyBase::~StrategyBase() {}

float StrategyBase::getPrice() const {
    return price_;
}

void StrategyBase::setPrice(float price) {
    price_ = price;
}

float StrategyBase::getCapital() const {
    return capital_;
}

void StrategyBase::setCapital(float capital) {
    capital_ = capital;
}

void StrategyBase::addSecurity(Node* security) {
    addChildren({security->getName()});
}

void StrategyBase::removeSecurity(Node* security) {
    removeChildren({security->getName()});
}

// void StrategyBase::updatePrices() { }
// void StrategyBase::allocateCapital() { }
// void StrategyBase::calculateValue() { }
// void StrategyBase::calculateNotionalValue() { }
// void StrategyBase::setupUniverse() { }
// void StrategyBase::updateUniverse() { }
