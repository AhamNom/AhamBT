export module bt;

export struct algo_stack {
	std::vector<algo> algos;

	algo_stack() = default;
	algo_stack(std::vector<algo> algos) : algos(algos) {}

	bool operator()(const Node &root) {
		int16_t highest_level = -1;
		bool res = true;
		for (auto algo : algos) {
			if (algo.level > highest_level) {
				res = true;
				res &= algo(root);
			} else if (algo.level == highest_level) {
				res &= algo(root);
			}
		}
		return res;
	}
};

