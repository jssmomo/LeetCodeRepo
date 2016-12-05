public class Solution {
    public string FrequencySort(string s) {
        if (s.Length <= 2)
        {
            return s;
        }
        
        Dictionary<char, int> freqDict = new Dictionary<char, int>();
        int max = 0;
        for (int i = 0; i< s.Length; i++)
        {
            if (freqDict.ContainsKey(s[i]))
            {
                freqDict[s[i]] += 1;
            }
            else
            {
                freqDict.Add(s[i], 1);
            }
            max = Math.Max(max, freqDict[s[i]]);
        }
        
        List<char>[] countList = new List<char>[max + 1];
        foreach (var key in freqDict.Keys)
        {
            int count = freqDict[key];
            if (countList[count] == null)
            {
                countList[count] = new List<char>();
            }
            countList[count].Add(key);
        }
        string result = string.Empty;
        for (int i = max;i>0;i--)
        {
            if (countList[i] != null)
            {
                foreach (char c in countList[i])
                {
                    for (int j = 0 ;j<i;j++)
                    {
                        result += c;
                    }
                }
            }
        }
        return result;
    }
}