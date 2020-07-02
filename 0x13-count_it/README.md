0x13. Count it!
===============

#### Count it!

Write a *recursive function* that queries the [Reddit API](https://www.reddit.com/dev/api/ "Reddit API"), parses the title of all hot articles, and prints a sorted count of given keywords (case-insensitive, delimited by spaces. Javascript should count as javascript, but java should not).


```
alexa@ubuntu:~/0x13-count_it $ cat 0-main.py
#!/usr/bin/python3
import sys

if __name__ == '__main__':
    count_words = __import__('0-count').count_words
    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv[0]))
        print("Ex: {} programming 'python java javascript'".format(sys.argv[0]))
    else:
        result = count_words(sys.argv[1], [x for x in sys.argv[2].split()])
alexa@ubuntu:~/0x13-count_it $ ./0-main.py programming 'python java javascript scala no_results_for_this_one'
java: 27
javascript: 20
python: 17
scala: 4
alexa@ubuntu:~/0x13-count_it $ ./0-main.py not_a_valid_subreddit 'python java javascript scala no_results_for_this_one'
alexa@ubuntu:~/0x13-count_it $ ./0-main.py not_a_valid_subreddit 'python java'
alexa@ubuntu:~/0x13-count_it $

```
