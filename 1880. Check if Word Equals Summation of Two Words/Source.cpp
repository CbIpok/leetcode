#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
namespace task1880
{
    class Solution {
    public:
        bool isSumEqual(std::string firstWord, std::string secondWord, std::string targetWord) {
            return convertToInt(firstWord) + convertToInt(secondWord) == convertToInt(targetWord);
        }

    private:
        int convertToInt(const std::string& str)
        {
            int number = 0;
            for (auto c : str)
            {
                int diggit = c - 'a';
                number = number * 10 + diggit;
            }
            return number;
        }
    };
}

namespace task128
{
    static int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> num_set;
        for (auto& i : nums)
        {
            num_set.insert(i);

        }

        int max_sequence_lenght = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int current_num = nums[i];
            int current_sequence_lenght = 1;
            if (num_set.find(current_num - 1) == num_set.end())
                while (num_set.find(current_num + 1) != num_set.end())
                {
                    current_num += 1;
                    current_sequence_lenght += 1;
                }
            max_sequence_lenght = (std::max)(max_sequence_lenght, current_sequence_lenght);
        }
        return max_sequence_lenght;
    }
    
}

