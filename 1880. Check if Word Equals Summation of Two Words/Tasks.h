#pragma once
#include <string>
#include <vector>
#include <algorithm>
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
    class Solution {
    public:
        static int longestConsecutive(std::vector<int>& nums) {
            if (nums.size() == 0)
            {
                return 0;
            }
            std::sort(nums.begin(), nums.end());
            int maxSequenceLen = 0;
            for (size_t i = 0; i < nums.size() - 1; i++)
            {
                int prev = nums[i];
                int sequenceLen = 1;
                for (size_t j = i + 1; j < nums.size(); j++)
                {
                    int now = nums[j];
                    if (now - prev == 1)
                    {
                        prev = nums[j];
                        sequenceLen += 1;
                    }
                }
                maxSequenceLen = (std::max)(maxSequenceLen, sequenceLen);
            }
            return maxSequenceLen;
        }
    };
}

