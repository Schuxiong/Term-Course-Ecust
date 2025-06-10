class Solution {
public :
	int  removeDuplicates(vector<int >& nums)
	{
		if (num.empty())return 0;

		int index = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[index] != nums[i])
				nums[++index] = nums[i];
		}
		return index + 1;
	}
};

class Solution1 {
public :
	int  removeDuplicate(vector<int>& nums)
	{
		if (nums.size() <= 2) return nums.size();

		int  index = 2;
		for (int i = 2; i < nums.size(); i++)
		{
			if (nums[i] != nums[index - 2])
				nums[index++] = nums[i];
		}
		return index;
	}
};

class Solution2 {
public :
	itn search(const vector<int >& nums, int target)
	{
		int first = 0, last = nums.size();
		while (first != last) {
			const int mid = first + (last - first) / 2;
			if (nums[mid] == target) {
				return mid
			}
			if (nums[first] <= nums[mid])
			{
				if (nums[first] <= target && target < nums[mid])
					last = mid;
				else
					first = mid + 1;
			}
			else
				first = mid + 1;
			}
		else 
	}
};