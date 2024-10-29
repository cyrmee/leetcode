using System.Text;

namespace LeetCode;

internal abstract class Program
{
    private static void Main()
    {
        char[] chars = ['a'];
        var result = Compress(chars);
        Console.WriteLine(result);
    }

    private static int Compress(char[] chars)
    {
        int index = 0, count = 0;

        while (index < chars.Length)
        {
            char currentChar = chars[index];
            var start = index;

            while (index < chars.Length && currentChar == chars[index])
            {
                index++;
            }

            chars[count++] = currentChar;

            int repeatLength = index - start;

            if (repeatLength > 1)
            {
                foreach (var character in repeatLength.ToString())
                {
                    chars[count++] = character;
                }
            }
        }

        return count;
    }

    public static bool CanPlaceFlowers(int[] flowerbed, int n)
    {
        int count = 0;
        for (int i = 0; i < flowerbed.Length; i++)
        {
            if (flowerbed[i] == 0)
            {
                bool emptyPrev = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyNext = (i == flowerbed.Length - 1) || (flowerbed[i + 1] == 0);

                if (emptyPrev && emptyNext)
                {
                    flowerbed[i] = 1;
                    count++;
                    i++;

                    if (count >= n)
                    {
                        return true;
                    }
                }
            }
        }

        return count >= n;
    }

    public static IList<bool> KidsWithCandies(int[] candies, int extraCandies)
    {
        var result = new List<bool>();
        var candiesList = new List<int>(candies);

        for (int i = 0; i < candies.Length; i++)
        {
            candiesList[i] += extraCandies;
            result.Add(candies[i] + extraCandies >= candiesList.Max());
            candiesList[i] -= extraCandies;
        }

        return result;
    }

    public static string ReverseWords(string s)
    {
        var result = new StringBuilder();

        foreach (var word in s.Split())
        {
            if (string.IsNullOrWhiteSpace(word))
                continue;
            result.Insert(0, word + " ");
        }

        return result.ToString().Trim();
    }

    public static string MergeAlternately(string word1, string word2)
    {
        var maxLength = word1.Length >= word2.Length ? word1.Length : word2.Length;
        StringBuilder mergedString = new();

        for (var i = 0; i < maxLength; i++)
        {
            if (i >= word1.Length)
            {
                mergedString.Append(word2[i..]);
                break;
            }

            if (i >= word2.Length)
            {
                mergedString.Append(word1[i..]);
                break;
            }

            mergedString.Append(word1[i]);
            mergedString.Append(word2[i]);
        }

        return mergedString.ToString();
    }

    public static int Reverse(int x)
    {
        if (x is 0) return 0;

        var result = 0;
        var isNumNegative = false;
        if (x < 0)
        {
            x *= -1;
            isNumNegative = true;
        }

        while (x > 0)
        {
            var digit = x % 10;
            x = Convert.ToInt32(Math.Floor(Convert.ToDouble(x) / 10));
            result = result * 10 + digit;
        }

        return isNumNegative ? result * -1 : result;
    }

    public static void ReverseString(char[] s)
    {
        if (s.Length is 0) return;

        for (var i = 0; i < s.Length / 2; i++)
        {
            var j = s.Length - 1 - i;
            (s[i], s[j]) = (s[j], s[i]);
        }
    }

    public static int[] TwoSum(int[] nums, int target)
    {
        Dictionary<int, int> seen = [];
        for (int i = 0; i < nums.Length; i++)
        {
            int complement = target - nums[i];
            if (seen.TryGetValue(complement, out int value))
            {
                return [value, i];
            }

            seen[nums[i]] = i;
        }

        throw new Exception("No two sum solution");
    }

    public static void MoveZeroes(int[] nums)
    {
        for (int i = 0; i < nums.Length; i++)
        for (int j = i; j < nums.Length; j++)
            if (nums[i] == 0)
                (nums[j], nums[i]) = (nums[i], nums[j]);
            else break;
    }

    public static int[] PlusOne(int[] digits)
    {
        if (digits[^1] < 9)
        {
            digits[^1]++;
            return digits;
        }
        else
        {
            var list = new List<int>(new int[digits.Length + 1]);
            for (int i = 0; i < digits.Length; i++)
                list[i + 1] = digits[i];
            list[^1] = 0;
            for (int i = list.Count - 2; i >= 0; i--)
            {
                if (list[i] == 9)
                    list[i] = 0;
                else
                {
                    list[i]++;
                    break;
                }
            }

            if (list[0] == 0)
                return [.. list[1..]];
            return [.. list];
        }
    }

    public static int[] Intersect(int[] nums1, int[] nums2)
    {
        var dictionary = new Dictionary<int, int>();
        foreach (int num in nums1)
        {
            if (!dictionary.TryAdd(num, 1))
                dictionary[num]++;
        }

        var list = new List<int>();
        foreach (var num in nums2)
        {
            if (dictionary.ContainsKey(num))
            {
                list.Add(num);
                dictionary[num]--;
                if (dictionary[num] == 0)
                    dictionary.Remove(num);
            }
        }

        return [.. list];
    }

    public static int SingleNumber(int[] nums)
    {
        var dictionary = new Dictionary<int, int>();
        foreach (var t in nums)
        {
            if (!dictionary.TryAdd(t, 1))
                dictionary[t]++;
        }

        return dictionary.First(x => x.Value == 1).Key;
    }

    public static bool ContainsDuplicate(int[] nums)
    {
        var dictionary = new Dictionary<int, int>();
        return nums.Any(t => !dictionary.TryAdd(t, 1));
    }

    public static void Rotate(int[] numbers, int k)
    {
        if (k > numbers.Length) k %= numbers.Length;
        var firstHalf = numbers.TakeLast(k).ToArray();
        var secondHalf = numbers.Take(numbers.Length - k).ToArray();
        numbers = [.. firstHalf, .. secondHalf];
    }
}