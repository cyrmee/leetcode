﻿internal class Program
{
    private static void Main(string[] args)
    {
        char[] array = ['a', 'b', 'c'];
        var num = 1534236469;
        var result = Reverse(num);
        Console.WriteLine(result);
    }

    public static int Reverse(int x)
    {
        if (x == 0 || x < int.MinValue || x > int.MaxValue) return 0;

        var result = 0;
        var isNumNegative = false;
        if (x < 0)
        {
            x *= -1;
            isNumNegative = true;
        };

        while (x > 0)
        {
            var digit = x % 10;
            x = Convert.ToInt32(Math.Floor(Convert.ToDouble(x) / 10));
            result = result * 10 + digit;
        }

        return isNumNegative ? result *= -1 : result;
    }

    public static void ReverseString(char[] s)
    {
        if (s.Length == 0 || s == null) return;

        for (int i = 0; i < s.Length / 2; i++)
        {
            int j = s.Length - 1 - i;
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
            if (dictionary.ContainsKey(num))
                dictionary[num]++;
            else dictionary.Add(num, 1);
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
        for (int i = 0; i < nums.Length; i++)
        {
            if (!dictionary.TryAdd(nums[i], 1))
                dictionary[nums[i]]++;
        }
        return dictionary.First(x => x.Value == 1).Key;
    }

    public static bool ContainsDuplicate(int[] nums)
    {
        var dictionary = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++)
            if (!dictionary.TryAdd(nums[i], 1))
                return true;
        return false;
    }

    public static void Rotate(int[] numbers, int k)
    {
        if (k > numbers.Length) k %= numbers.Length;
        var firstHalf = numbers.TakeLast(k).ToArray();
        var secondHalf = numbers.Take(numbers.Length - k).ToArray();
        numbers = [.. firstHalf, .. secondHalf];
    }
}
