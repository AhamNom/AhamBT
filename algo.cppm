import node;

export struct algo {
	unsigned int8_t level;

	algo() : level(0) {}
	algo(int level) : level(level) {}

	bool operator(const Node &root) = delete;
};
