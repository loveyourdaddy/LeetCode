// 0 ms / 6.6 MB
// char to string : string(1, char)
// 숫자 string -> int :  digits[i] - '0'
// string 합치기 + 로 가능 
class Solution {
public:
	vector<string> intToString = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<int> inputDigit;
	vector<string> ans;

	vector<string> letterCombinations(string digits) {
		// if string size == 0
		if (digits.size() == 0)
			return vector<string>();

		// change digit -> vector int 
		for (int i = 0; i < digits.size(); i++)
		{
			inputDigit.push_back(digits[i] - '0');
		}

		//find all combination 
		int first_depth_len = intToString[inputDigit[0]].size();
		int startDigit = inputDigit[0];

		for (int i = 0; i < first_depth_len; i++) //첫번째 digit의 각 문자에 대해 반복  // input digit 숫자에 대해서 반복문 
		{
			string s(1, intToString[startDigit][i]); //s에 depth 0 삽입 
			GetCombination(1, s);
		}

		return ans;
	}

	//recursive function 
	void GetCombination(int depth, string s) {

		if (depth == inputDigit.size())
		{
			ans.push_back(s);
			return;
		}
		
		int curDigit = inputDigit[depth];
		string curString = intToString[curDigit];
		for (int i = 0; i < curString.size(); i++) // string 1개 안에 문자들에 대한 반복
		{
			GetCombination(depth+1, s+curString[i]); // s 에 depth 1 부터 삽입 
		}		
	}		
};
