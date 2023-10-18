export module bt;

export {

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

}

// void StrategyBase::updatePrices() { }
// void StrategyBase::allocateCapital() { }
// void StrategyBase::calculateValue() { }
// void StrategyBase::calculateNotionalValue() { }
// void StrategyBase::setupUniverse() { }
// void StrategyBase::updateUniverse() { }
