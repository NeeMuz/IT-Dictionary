using System;
using System.Collections.Generic;

namespace ConsoleApp2
{
    class ITDictionary
    {
        Dictionary<string, string> dictionary = new Dictionary<string, string>();

        public int Count => dictionary.Count;

        public void AddTerm(string term, string definition)
        {
            if (!dictionary.ContainsKey(term))
            {
                dictionary.Add(term, definition);
                Console.WriteLine($"Term '{term}' has been added.");
            }
            else
            {
                Console.WriteLine($"Term '{term}' already exists.");
            }
        }

        public string SearchTerm(string term)
        {
            if (dictionary.ContainsKey(term))
            {
                return $"{term}: {dictionary[term]}";
            }
            else
            {
                return $"Term '{term}' not found.";
            }
        }

        public override string ToString()
        {
            string result = "";
            foreach (var pair in dictionary)
            {
                result += pair.Key + ": " + pair.Value + "\n";
            }
            return result;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            ITDictionary dictionary = new ITDictionary();
            string command;
            do
            {
                Console.WriteLine("Enter a command (add/search/exit):");
                command = Console.ReadLine();
                if (command == "add")
                {
                    Console.WriteLine("Enter a term:");
                    string term = Console.ReadLine();
                    Console.WriteLine("Enter a definition:");
                    string definition = Console.ReadLine();
                    dictionary.AddTerm(term, definition);
                }
                else if (command == "search")
                {
                    Console.WriteLine("Enter a term to search:");
                    string term = Console.ReadLine();
                    Console.WriteLine(dictionary.SearchTerm(term));
                }
            } while (command != "exit");

            Console.WriteLine("Dictionary:");
            Console.WriteLine(dictionary.ToString());
            Console.ReadLine();
        }
    }
}
