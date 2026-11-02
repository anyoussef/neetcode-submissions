class Solution {
public:
	bool isValid(string s) {
		vector<char> stack;
		
		for (size_t i = 0; i < s.size(); ++i) {
			if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
				stack.push_back(s[i]);
			}
			else {
				if (stack.empty())
					return false;	
				else if (stack.back() == '(' && s[i] != ')')
					return false;
				else if (stack.back() == '[' && s[i] != ']')
					return false;
				else if (stack.back() == '{' && s[i] != '}')
					return false;
				else
					stack.pop_back();
			}
		}
		if (!stack.empty())
			return false;
		return true;
	}
};